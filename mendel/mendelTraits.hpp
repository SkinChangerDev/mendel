#include <type_traits>

namespace mendel
{
    template<typename T>
    struct is_complete
    {
        template<typename U>
        static auto test(int) -> decltype(sizeof(U), std::true_type());

        template<typename U>
        static std::false_type test(...);

        static constexpr bool value = decltype(test<T>(0))::value;

        constexpr bool operator()() const noexcept
        {
            return value;
        }
    };
}
