#pragma once

#include "gdefs.hpp"
#include "gobj.hpp"

template<typename T>
class gptr
{
public:
    gptr(gobj<T>* inPtr)
    {
        gptr(inPtr, inPtr->getGen);
    }

    gptr(const gptr<T>& inGptr)
    {
        gptr(inGptr.ptr, inGptr.gen);
    }

    gobj<T>* get() const
    {
        return *this ? ptr : nullptr;
    }

    gobj<T>* operator->() const
    {
        return get();
    }

    gobj<T>& operator*() const
    {
        return *get();
    }

    bool isValid() const
    {
        return ptr && gen == ptr->getGen();
    }

    operator bool() const
    {
        return isValid();
    }

private:
    gptr(gobj<T>* inPtr, intgen_t inGen)
    : ptr(inPtr)
    , gen(inGen)
    {}

    gobj<T>* ptr;

    intgen_t gen;
};
