#include "gdefs.hpp"

template<typename T>
class gptr;

intgen_t getUniqueGen()
{
    static intgen_t uniqueGen;
    return uniqueGen += genincr;
}

template<typename T>
class gobj : public T
{
public:
    template<typename ... TArgs>
    gobj(TArgs ... args) : T(args ...)
    {
        gen = getUniqueGen();
    }

    ~gobj()
    {
        gen = nullgen;
    }

    bool operator==(const gobj<T>& other) const
    {
        return T::operator==(other);
    }

    bool operator!=(const gobj<T>& other) const
    {
        return !T::operator==(other);
    }

    gobj<T>& operator=(const gobj<T>& other) const
    {
        return T::operator=(other);
    }

private:
    intgen_t gen;

    friend class gptr<T>;
};
