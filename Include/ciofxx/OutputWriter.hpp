#pragma once

// Std
#include <span>

namespace ciofxx {

struct CliOptions;
struct FileData;

void WriteOutput(std::span<const FileData> files, const CliOptions& options);

}  // namespace ciofxx
