#pragma once

#include "gDefs.hpp"

namespace mendel
{
    template<typename T>
    class gPtr
    {
    public:
        gPtr(T* inPtr)
        {
            gPtr(inPtr, getGen(ptr));
        }

        gPtr(const gPtr<T>& inGptr)
        {
            gPtr(inGptr.ptr, inGptr.gen);
        }

        T* get() const
        {
            return isValid() ? ptr : nullptr;
        }

        T* operator->() const
        {
            return get();
        }

        T& operator*() const
        {
            return *get();
        }

        bool isValid() const
        {
            return ptr && gen == getGen(ptr);
        }

        operator bool() const
        {
            return isValid();
        }

    private:
        gPtr(T* inPtr, intgen_t inGen)
        : ptr(inPtr)
        , gen(inGen)
        {}

        T* ptr;

        intgen_t gen;
    };
}
