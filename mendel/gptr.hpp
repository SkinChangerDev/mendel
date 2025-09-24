#include "gdefs.hpp"
#include "gobj.hpp"

template<typename T>
class gobj;

template<typename T>
class gptr
{
public:
    gptr(gobj<T>* inPtr)
    {
        ptr = inPtr;
        gen = inPtr->gen;
    }

    gptr(const gptr<T>& inGptr)
    : ptr(inGptr.ptr)
    , gen(inGptr.gen)
    {}

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
        return ptr && gen == ptr->gen;
    }

    operator bool() const
    {
        return isValid();
    }

private:
    gobj<T>* ptr;

    intgen_t gen;
};
