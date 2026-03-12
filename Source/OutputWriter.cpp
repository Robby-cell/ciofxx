#include <ciofxx/OutputWriter.hpp>

// ciofxx
#include <ciofxx/CliOptions.hpp>
#include <ciofxx/Formatter.hpp>
#include <ciofxx/FormatterFactory.hpp>

// Std
#include <fstream>

namespace ciofxx {

void WriteOutput(std::span<const FileData> files, const CliOptions& options) {
    std::ofstream out(options.output_file);

    auto formatter = CreateFormatter(options.format);

    formatter->Write(out, files);
}

}  // namespace ciofxx
