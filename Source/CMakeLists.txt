include(FetchContent)

FetchContent_Declare(
    CLI11
    GIT_REPOSITORY https://github.com/CLIUtils/CLI11.git
    GIT_TAG v2.4.2
)

FetchContent_MakeAvailable(CLI11)

target_sources(ciof PRIVATE
    Main.cpp

    CliOptions.cpp
    FileScanner.cpp
    FileSize.cpp
    OutputFormat.cpp
    OutputWriter.cpp

    Formatters.cpp
    FormatterFactory.cpp

    Utils.cpp
)

target_link_libraries(ciof PRIVATE CLI11::CLI11)
