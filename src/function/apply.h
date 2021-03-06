#ifndef TYPEASVALUE_SRC_FUNCTION_APPLY_H_
#define TYPEASVALUE_SRC_FUNCTION_APPLY_H_

#include "operation/math.h"
#include "conditional/cond.h"

#include "detail/apply.h"

namespace tav {

typedef detail::placeholder<0> _0;
typedef detail::placeholder<1> _1;
typedef detail::placeholder<2> _2;
typedef detail::placeholder<3> _3;

template <
	template<typename...> class Function,
	typename...                 Arguments
>
using Apply = Cond<
	Branch<
		GreaterThan<detail::count_placeholders<Arguments...>, Size<2>>,
		detail::apply_variadic<Function, Arguments...>
	>,
	Branch<
		IsEqualValue<detail::count_placeholders<Arguments...>, Size<2>>,
		detail::apply_pair<Function, Arguments...>
	>,
	Branch<
		IsEqualValue<detail::count_placeholders<Arguments...>, Size<1>>,
		detail::apply_single<Function, Arguments...>
	>,
	Else<
		detail::apply_none<Function, Arguments...>
	>
>;

}

#endif  // TYPEASVALUE_SRC_FUNCTION_APPLY_H_
