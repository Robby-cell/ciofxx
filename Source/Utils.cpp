#include <ciofxx/Utils.hpp>

// Std
#include <chrono>
#include <iomanip>
#include <sstream>

namespace ciofxx {

auto GetCurrentTimestamp() -> std::string {
    using namespace std::chrono;

    auto now = system_clock::now();
    auto t = system_clock::to_time_t(now);

    std::tm tm{};
#ifdef _WIN32
    localtime_s(&tm, &t);
#else
    localtime_r(&t, &tm);
#endif

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

}  // namespace ciofxx
