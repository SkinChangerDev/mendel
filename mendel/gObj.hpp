#pragma once

#include <utility>

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

        gObj(gObj& other) : T(other)
        {
            gen = getUniqueGen();
        }

        gObj(gObj&& other) : T(std::move(other.T))
        {
            gen = getUniqueGen();
        }

        gObj() : T()
        {
            gen = getUniqueGen();
        }

        ~gObj()
        {
            gen = NULLGEN;
        }

        gObj<T>& operator=(const gObj<T>& other)
        {
            T::operator=(other);
            return *this;
        }

        gObj<T>& operator=(gObj<T>&& other)
        {
            T::operator=(std::move(other.T));
            return *this;
        }


        bool operator==(const gObj<T>& other) const
        {
            return T::operator==(other);
        }

        bool operator!=(const gObj<T>& other) const
        {
            return !T::operator==(other);
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
