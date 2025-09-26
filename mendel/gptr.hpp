#pragma once

#include "gdefs.hpp"

namespace mendel
{
    template<typename T>
    class gptr
    {
    public:
        gptr(T* inPtr)
        {
            gptr(inPtr, getGen(ptr));
        }

        gptr(const gptr<T>& inGptr)
        {
            gptr(inGptr.ptr, inGptr.gen);
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
        gptr(T* inPtr, intgen_t inGen)
        : ptr(inPtr)
        , gen(inGen)
        {}

        T* ptr;

        intgen_t gen;
    };
}
