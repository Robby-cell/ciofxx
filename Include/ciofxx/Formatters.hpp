#pragma once

#include <ciofxx/Formatter.hpp>

namespace ciofxx {

class PlainFormatter : public Formatter {
   public:
    void Write(std::ostream& out, std::span<const FileData> files) const override;
};

class MarkdownFormatter : public Formatter {
   public:
    void Write(std::ostream& out, std::span<const FileData> files) const override;
};

class JsonFormatter : public Formatter {
   public:
    void Write(std::ostream& out, std::span<const FileData> files) const override;
};

}  // namespace ciofxx
