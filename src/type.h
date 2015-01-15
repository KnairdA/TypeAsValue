#ifndef TYPEASVALUE_SRC_TYPE_H_
#define TYPEASVALUE_SRC_TYPE_H_

#include <type_traits>

namespace tav {

template <int Value>
using Int = typename std::integral_constant<int, Value>::type;

template <bool Value>
using Boolean = typename std::integral_constant<bool, Value>::type;

template <
	typename X,
	typename Y
>
using equal_type = typename std::integral_constant<
	bool,
	std::is_same<typename X::value_type, typename Y::value_type>::value
>::type;

}

#endif  // TYPEASVALUE_SRC_TYPE_H_
