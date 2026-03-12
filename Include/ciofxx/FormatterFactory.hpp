#pragma once

// ciofxx
#include <ciofxx/OutputFormat.hpp>

// Std
#include <memory>

namespace ciofxx {

class Formatter;

auto CreateFormatter(OutputFormat format) -> std::unique_ptr<Formatter>;

}  // namespace ciofxx
