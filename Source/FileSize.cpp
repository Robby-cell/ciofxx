#include <ciofxx/FileSize.hpp>

// Std
#include <algorithm>
#include <cctype>
#include <cstddef>
#include <stdexcept>

namespace ciofxx {

constexpr inline size_t kStorageFactor = 1024;

static std::string ToUpper(std::string s) {
    std::ranges::transform(s.begin(), s.end(), s.begin(),
                           [](unsigned char c) -> int { return std::toupper(c); });
    return s;
}

FileSize ParseFileSize(const std::string& text) {
    if (text.empty()) {
        throw std::runtime_error("Invalid file size");
    }

    size_t pos = 0;

    while (pos < text.size() && (std::isdigit(text[pos]) != 0)) {
        ++pos;
    }

    auto numberPart = text.substr(0, pos);
    auto unit_part = ToUpper(text.substr(pos));

    uint64_t value = std::stoull(numberPart);

    uint64_t multiplier = 1;

    if (unit_part == "" || unit_part == "B") {
        multiplier = 1;
    } else if (unit_part == "KB") {
        multiplier = kStorageFactor;
    } else if (unit_part == "MB") {
        multiplier = kStorageFactor * kStorageFactor;
    } else if (unit_part == "GB") {
        multiplier = kStorageFactor * kStorageFactor * kStorageFactor;
    } else {
        throw std::runtime_error("Unknown size unit: " + unit_part);
    }

    return FileSize(value * multiplier);
}

}  // namespace ciofxx
