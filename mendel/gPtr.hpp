#pragma once

#include <type_traits>
#include "mendelTraits.hpp"
#include "gDefs.hpp"
#include "gObj.hpp"

namespace mendel
{
    template<typename T>
    class gPtr
    {
        //static_assert(std::is_base_of<gObj, T>(), "gPtr can only be used with children of gObj or incomplete types");
        static_assert(std::is_base_of<gObj, T>() || is_complete<T>(), "gPtr can only be used with children of gObj or incomplete types");


    public:
        gPtr()
        : ptr(nullptr)
        , gen(NULLGEN)
        {}
    
        explicit gPtr(T* inPtr)
        : ptr(inPtr)
        , gen(inPtr->gen)
        {}

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
            return ptr && gen == ptr->getGen;
        }

        operator bool() const
        {
            return isValid();
        }

    private:
        T* ptr;

        intgen_t gen;
    };
}
