#pragma once

// Std
#include <filesystem>
#include <vector>

namespace ciofxx {

struct FileData {
    std::filesystem::path path;
    std::vector<char> contents;
};

}  // namespace ciofxx
