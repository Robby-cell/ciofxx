#pragma once

// Std
#include <vector>

namespace ciofxx {

struct CliOptions;
struct FileData;

auto ScanFiles(const CliOptions& options) -> std::vector<FileData>;

}  // namespace ciofxx
