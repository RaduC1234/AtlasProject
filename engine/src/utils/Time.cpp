#include "Time.hpp"

#include <cstdint>

#ifdef _WIN32
#include "Windows.h"

#define EPOCH_DIFFERENCE 11644473600000LL  // Difference in milliseconds
#endif

double Time::getTime() {

#ifdef _WIN32
    FILETIME ft;
    GetSystemTimeAsFileTime(&ft);

    // Convert FILETIME to a 64-bit integer
    ULARGE_INTEGER li;
    li.LowPart = ft.dwLowDateTime;
    li.HighPart = ft.dwHighDateTime;

    uint64_t currentTimeInMillis = li.QuadPart / 10000;

    uint64_t unixTimeInMillis = currentTimeInMillis - EPOCH_DIFFERENCE;

    return static_cast<double>(unixTimeInMillis) / 1000.0;

#endif
    return 0.0;
}
