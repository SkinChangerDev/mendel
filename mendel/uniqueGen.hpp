#pragma once

#include "gDefs.hpp"

namespace mendel
{
    inline intgen_t getUniqueGen()
    {
        static intgen_t uniqueGen;
        return uniqueGen += GENINCR;
    }
}
