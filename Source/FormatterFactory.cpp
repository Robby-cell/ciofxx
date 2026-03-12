#include <ciofxx/FormatterFactory.hpp>

// ciofxx
#include <ciofxx/Formatters.hpp>
#include <ciofxx/OutputFormat.hpp>

// Std
#include <memory>

namespace ciofxx {

auto CreateFormatter(OutputFormat format) -> std::unique_ptr<Formatter> {
    switch (format) {
        case OutputFormat::Plain: {
            return std::make_unique<PlainFormatter>();
        }

        case OutputFormat::Markdown: {
            return std::make_unique<MarkdownFormatter>();
        }

        case OutputFormat::Json: {
            return std::make_unique<JsonFormatter>();
        }
    }

    return nullptr;
}

}  // namespace ciofxx
