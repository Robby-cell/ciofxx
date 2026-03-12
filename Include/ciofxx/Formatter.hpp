#pragma once

#include <iosfwd>
#include <span>

namespace ciofxx {

struct FileData;

class Formatter {
   public:
    Formatter() = default;

    Formatter(const Formatter&) = default;
    Formatter(Formatter&&) = delete;

    auto operator=(const Formatter&) -> Formatter& = default;
    auto operator=(Formatter&&) -> Formatter& = delete;

    virtual ~Formatter() = default;

    virtual void Write(std::ostream& out, std::span<const FileData> files) const = 0;
};

}  // namespace ciofxx
