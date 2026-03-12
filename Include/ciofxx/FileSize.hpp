#pragma once

// Std
#include <cstdint>
#include <string>

namespace ciofxx {

struct FileSize {
    uint64_t bytes = 0;

    constexpr FileSize() = default;
    constexpr explicit FileSize(uint64_t b) : bytes(b) {}

    static FileSize FromBytes(uint64_t b) {
        return FileSize(b);
    }

    [[nodiscard]] auto AsBytes() const -> uint64_t {
        return bytes;
    }
};

auto ParseFileSize(const std::string& text) -> FileSize;

}  // namespace ciofxx
