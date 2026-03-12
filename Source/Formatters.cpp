#include <ciofxx/Formatters.hpp>

// ciofxx
#include <ciofxx/FileData.hpp>
#include <ciofxx/Utils.hpp>

// Std
#include <ostream>

namespace ciofxx {

void PlainFormatter::Write(std::ostream& out, std::span<const FileData> files) const {
    out << "===== Project Context Dump =====\n";
    out << "Generated: " << ciofxx::GetCurrentTimestamp() << "\n\n";
    for (const auto& file : files) {
        out << "===== FILE: " << file.path.generic_string() << " =====\n";
        out.write(file.contents.data(), static_cast<std::streamsize>(file.contents.size()));
        out << "\n\n";
    }
}

void MarkdownFormatter::Write(std::ostream& out, std::span<const FileData> files) const {
    out << "# Project Context Dump\n\n";
    out << "*Generated: " << ciofxx::GetCurrentTimestamp() << "*\n\n";

    for (const auto& file : files) {
        out << "## File: " << file.path.generic_string() << "\n\n";
        out << "``` \n";
        out.write(file.contents.data(), static_cast<std::streamsize>(file.contents.size()));
        out << "\n```\n\n";
    }
}

void JsonFormatter::Write(std::ostream& out, std::span<const FileData> files) const {
    out << "{\n";
    out << R"(  "generated": ")" << ciofxx::GetCurrentTimestamp() << "\",\n";
    out << "  \"files\": [\n";

    for (size_t i = 0; i < files.size(); ++i) {
        const auto& f = files[i];

        out << "    {\n";
        out << R"(      "path": ")" << f.path.generic_string() << "\",\n";
        out << R"(      "content": ")";

        for (char c : f.contents) {
            if (c == '"') {
                out << "\\\"";
            } else if (c == '\n') {
                out << "\\n";
            } else {
                out << c;
            }
        }

        out << "\"\n";
        out << "    }";

        if (i + 1 < files.size()) {
            out << ",";
        }

        out << "\n";
    }

    out << "  ]\n}\n";
}

}  // namespace ciofxx
