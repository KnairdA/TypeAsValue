#ifndef TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_
#define TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_

#include "type.h"
#include "higher/query.h"
#include "function/apply.h"

namespace tav {

template <
	typename Element,
	typename List
>
using Contains = Any<
	Apply<EqualValue, tav::_0, Element>::template single_type,
	List
>;

}

#endif  // TYPEASVALUE_SRC_LIST_OPERATION_CONTAINS_H_
