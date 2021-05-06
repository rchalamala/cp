#ifndef POWER_HPP
#define POWER_HPP

#include <type_traits>

template<typename T1, typename T2> constexpr typename std::enable_if_t<(std::is_integral_v < T1 > && std::is_unsigned_v < T1 > && std::is_integral_v < T2 > && std::is_unsigned_v < T2 > ), typename std::common_type_t<T1, T2>>
power(T1
base,
T2 exponent
)
{
typename std::common_type_t<T1, T2> result{1};
while(exponent)
{
if(exponent & 1)
{
result *=
base;
}
base *=
base;
exponent >>= 1;
}
return
result;
}

template<typename T1, typename T2> constexpr typename std::enable_if_t<std::is_integral_v < T1>
&&
std::is_integral_v <T2>&& (std::is_signed_v<T1>
|| std::is_signed_v <T2>), typename std::common_type_t<T1, T2>>
power(T1
base,
T2 exponent
)
{
assert(exponent
>= 0);
typename std::common_type_t<T1, T2> result{1};
while(exponent)
{
if(exponent % 2)
{
result *=
base;
}
base *=
base;
exponent /= 2;
}
return
result;
}

#endif