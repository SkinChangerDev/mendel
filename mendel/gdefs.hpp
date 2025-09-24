#include <stdint.h>

using intgen_t = uint64_t;
#define INTGEN_MAX UINT64_MAX
#define INTGEN_MIN UINT16_MIN
#define INTGEN_WIDTH UINT64_WIDTH

#define nullgen 0
// We increment the generation by a large number instead of 1 to increase pseudorandomness,
// thereby decreasing the possibility of a generation getting overridden by the same value later on.
// To prevent premature generation overflow, this increment is a prime number. This ensures we will
// iterate through all 2^64 possible generations before returning to the first generation.
#define genincr 160991227
