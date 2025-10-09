#pragma once

#include <utility>

#include "gDefs.hpp"
#include "uniqueGen.hpp"

namespace mendel
{
    class gObj
    {
    public:
        gObj(gObj& other)
        : gen(getUniqueGen())
        {}

        gObj(gObj&& other)
        : gen(getUniqueGen())
        {}

        gObj()
        : gen(getUniqueGen())
        {}

        ~gObj()
        {
            gen = NULLGEN;
        }

        gObj& operator=(const gObj& other)
        {
            return *this;
        }

        gObj& operator=(gObj&& other)
        {
            return *this;
        }

        intgen_t getGen() const
        {
            return gen;
        }

    private:
        intgen_t gen;
    };
}
