#include <ciofxx/CliOptions.hpp>

// ciofxx
#include <ciofxx/FileSize.hpp>

// CLI11
#include <CLI/CLI.hpp>

namespace ciofxx {

auto ParseCli(int argc, char** argv) -> CliOptions {
    CliOptions opts;

    std::string max_size_string;

    CLI::App app{"AI context dumper"};

    app.add_option("--path", opts.paths, "Paths to search")->required();

    app.add_option("--extensions", opts.extensions, "File extensions to include")
        ->default_val(std::nullopt);

    app.add_option("--output", opts.output_file, "Output file");

    std::string format_str;
    app.add_option("--format", format_str, "Output format: plain, markdown, json");

    app.add_flag("--timestamps", opts.timestamps, "Include timestamps");

    app.add_flag("--relative-paths", opts.relative_paths, "Use relative paths");

    app.add_option("--max-file-size", max_size_string, "Maximum file size (e.g. 10KB, 5MB)");

    app.add_option("--exclude", opts.exclude, "Exclude directories");

    app.parse(argc, argv);

    if (!format_str.empty()) {
        opts.format = ParseOutputFormat(format_str);
    }

    if (!max_size_string.empty()) {
        opts.max_file_size = ParseFileSize(max_size_string);
    }

    return opts;
}

}  // namespace ciofxx
