#pragma once

#include "gDefs.hpp"
#include "uniqueGen.hpp"

namespace mendel
{
    template<typename T>
    class gObj : public T
    {
    public:
        template<typename ... TArgs>
        gObj(TArgs ... args) : T(args ...)
        {
            gen = getUniqueGen();
        }

        ~gObj()
        {
            gen = NULLGEN;
        }

        bool operator==(const gObj<T>& other) const
        {
            return T::operator==(other);
        }

        bool operator!=(const gObj<T>& other) const
        {
            return !T::operator==(other);
        }

        gObj<T>& operator=(const gObj<T>& other) const
        {
            return T::operator=(other);
        }

        template<typename U>
        friend intgen_t getGen(gObj<U>* object)
        {
            return object->gen;
        }
    
    private:
        intgen_t gen;
    };
}
