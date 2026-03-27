#include <ciofxx/FileScanner.hpp>

// ciofxx
#include <ciofxx/CliOptions.hpp>
#include <ciofxx/FileData.hpp>

// Std
#include <algorithm>
#include <filesystem>
#include <fstream>
#include <future>
#include <type_traits>

namespace ciofxx {

static auto ScanPath(const std::filesystem::path& path, const CliOptions& options)
    -> std::vector<FileData> {
    std::vector<FileData> results;

    for (const auto& entry : std::filesystem::recursive_directory_iterator(
             path, std::filesystem::directory_options::skip_permission_denied)) {
        const auto name = entry.path().filename().string();

        if (std::ranges::any_of(options.exclude, [&name](const auto& exclude) -> bool {
                return name.find(exclude) != std::remove_cvref_t<decltype(name)>::npos;
            })) {
            continue;
        }

        if (!entry.is_regular_file()) {
            continue;
        }

        auto ext = entry.path().extension().string();

        if (options.extensions) {
            bool match = false;

            for (const auto& allowed : *options.extensions) {
                if (ext == allowed) {
                    match = true;
                    break;
                }
            }

            if (!match) {
                continue;
            }
        }

        if (options.max_file_size.bytes > 0) {
            auto size = std::filesystem::file_size(entry.path());

            if (size > options.max_file_size.bytes) {
                continue;
            }
        }

        std::ifstream file(entry.path(), std::ios::binary);

        if (!file) {
            continue;
        }

        FileData data;
        data.path = entry.path();

        data.contents.assign(std::istreambuf_iterator<char>(file),
                             std::istreambuf_iterator<char>());

        results.push_back(std::move(data));
    }

    return results;
}

auto ScanFiles(const CliOptions& options) -> std::vector<FileData> {
    std::vector<std::future<std::vector<FileData>>> tasks;

    for (const auto& path : options.paths) {
        // NOLINTBEGIN(performance-inefficient-vector-operation)
        tasks.push_back(std::async(std::launch::async, ScanPath, path, std::cref(options)));
        // NOLINTEND(performance-inefficient-vector-operation)
    }

    std::vector<FileData> results;

    for (auto& task : tasks) {
        auto partial = task.get();

        results.insert(results.end(), std::make_move_iterator(partial.begin()),
                       std::make_move_iterator(partial.end()));
    }

    return results;
}

}  // namespace ciofxx
