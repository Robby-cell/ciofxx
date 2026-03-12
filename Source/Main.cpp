// ciofxx
#include <ciofxx/CliOptions.hpp>
#include <ciofxx/FileData.hpp>
#include <ciofxx/FileScanner.hpp>
#include <ciofxx/OutputWriter.hpp>

// Std
#include <iostream>

auto main(int argc, char** argv) -> int {
    try {
        auto options = ciofxx::ParseCli(argc, argv);

        auto files = ciofxx::ScanFiles(options);

        ciofxx::WriteOutput(files, options);

        std::cout << "Processed " << files.size() << " files\n";
    } catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;  // NOLINT
        return 1;
    }

    return 0;
}
