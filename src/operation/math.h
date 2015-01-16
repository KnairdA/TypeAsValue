#ifndef TYPEASVALUE_SRC_OPERATION_MATH_H_
#define TYPEASVALUE_SRC_OPERATION_MATH_H_

#include "type.h"

namespace tav {

template <
	typename X,
	typename Y
>
using Add = typename std::integral_constant<
	decltype(X::value + Y::value),
	X::value + Y::value
>::type;

template <
	typename X,
	typename Y
>
using Substract = typename std::integral_constant<
	decltype(X::value - Y::value),
	X::value - Y::value
>::type;

template <
	typename X,
	typename Y
>
using Multiply = typename std::integral_constant<
	decltype(X::value * Y::value),
	X::value * Y::value
>::type;

template <
	typename X,
	typename Y
>
using Divide = typename std::integral_constant<
	decltype(X::value / Y::value),
	X::value / Y::value
>::type;

}

#endif  // TYPEASVALUE_SRC_OPERATION_MATH_H_
