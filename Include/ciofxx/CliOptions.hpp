#pragma once

// ciofxx
#include <ciofxx/FileSize.hpp>
#include <ciofxx/OutputFormat.hpp>

// Std
#include <filesystem>
#include <optional>
#include <string>
#include <vector>

namespace ciofxx {

struct CliOptions {
    std::vector<std::filesystem::path> paths;
    std::optional<std::vector<std::string>> extensions;

    std::string output_file = "context_dump";

    OutputFormat format = OutputFormat::Plain;

    bool timestamps = false;
    bool relative_paths = true;

    std::vector<std::string> exclude;

    FileSize max_file_size;
};

auto ParseCli(int argc, char** argv) -> CliOptions;

}  // namespace ciofxx
