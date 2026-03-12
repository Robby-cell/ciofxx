#include <ciofxx/OutputFormat.hpp>

// Std
#include <algorithm>
#include <stdexcept>
#include <string>

namespace ciofxx {

namespace {
auto ToLower(std::string s) -> std::string {
    std::ranges::transform(s, s.begin(), [](unsigned char c) -> int { return std::tolower(c); });
    return s;
}
}  // namespace

auto ParseOutputFormat(std::string_view value) -> OutputFormat {
    auto v = ToLower(std::string(value));

    if (v == "plain") {
        return OutputFormat::Plain;
    }
    if (v == "markdown" || v == "md") {
        return OutputFormat::Markdown;
    }
    if (v == "json") {
        return OutputFormat::Json;
    }

    throw std::runtime_error("Unknown output format: " + std::string(value));
}

}  // namespace ciofxx
