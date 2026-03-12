#pragma once

// Std
#include <cstdint>
#include <string_view>

namespace ciofxx {

enum class OutputFormat : uint8_t {
    Plain,
    Markdown,
    Json,
};

auto ParseOutputFormat(std::string_view value) -> OutputFormat;

}  // namespace ciofxx
