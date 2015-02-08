#include "type.h"
#include "operation/math.h"
#include "operation/logic.h"
#include "conditional/if.h"

#include "list/cons.h"
#include "list/list.h"
#include "list/operation/reverse.h"
#include "list/operation/contains.h"
#include "list/operation/higher/map.h"
#include "list/operation/higher/filter.h"
#include "list/operation/higher/partition.h"
#include "list/operation/higher/query.h"
#include "list/operation/higher/find.h"
#include "list/operation/higher/take_while.h"
#include "list/operation/higher/drop_while.h"
#include "list/operation/higher/sort.h"
#include "list/generator/iota.h"
#include "list/generator/make_list.h"
#include "list/generator/higher/list_tabulate.h"
#include "list/operation/delete.h"

#include "function/apply.h"

int main(int, char **) { }

// equality

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::EqualType<tav::Int<1>, tav::Int<2>>
	>::value,
	"(EqualType 1 2) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::EqualType<tav::Int<1>, tav::Size<1>>
	>::value,
	"(EqualType (int 1) (size 2)) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::EqualValue<tav::Int<1>, tav::Size<1>>
	>::value,
	"(equal? (int 1) (size 1)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::EqualValue<tav::Int<1>, tav::Int<2>>
	>::value,
	"(equal? 1 2) != #f"
);

// basic math operations

static_assert(
	std::is_same<
		tav::Int<3>,
		tav::Add<tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(+ 1 2) != 3"
);

static_assert(
	std::is_same<
		tav::Int<4>,
		tav::Substract<tav::Int<10>, tav::Int<6>>::type
	>::value,
	"(- 10 6) != 4"
);

static_assert(
	std::is_same<
		tav::Int<42>,
		tav::Multiply<tav::Int<2>, tav::Int<21>>::type
	>::value,
	"(* 2 21) != 42"
);

static_assert(
	std::is_same<
		tav::Int<5>,
		tav::Divide<tav::Int<10>, tav::Int<2>>::type
	>::value,
	"(/ 10 2) != 42"
);

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Modulo<tav::Int<10>, tav::Int<3>>::type
	>::value,
	"(modulo 10 3) != 1"
);

static_assert(
	std::is_same<
		tav::Int<4096>,
		tav::Square<tav::Int<64>>::type
	>::value,
	"(square 64) != 4096"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Odd<tav::Int<1>>::type
	>::value,
	"(odd? 1) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Odd<tav::Int<2>>::type
	>::value,
	"(odd? 2) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::GreaterThan<tav::Int<2>, tav::Int<1>>::type
	>::value,
	"(> 2 1) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::GreaterThan<tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(> 1 2) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::LowerThan<tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(< 1 2) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::LowerThan<tav::Int<2>, tav::Int<1>>::type
	>::value,
	"(< 2 1) != #f"
);

// logic

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::And<tav::Boolean<true>, tav::Boolean<true>>::type
	>::value,
	"(and #t #t) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::And<tav::Boolean<false>, tav::Boolean<true>>::type
	>::value,
	"(and #f #t) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Or<tav::Boolean<true>, tav::Boolean<true>>::type
	>::value,
	"(or #t #t) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Or<tav::Boolean<false>, tav::Boolean<true>>::type
	>::value,
	"(or #f #t) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Or<tav::Boolean<false>, tav::Boolean<false>>::type
	>::value,
	"(or #f #f) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Xor<tav::Boolean<false>, tav::Boolean<true>>::type
	>::value,
	"(xor #f #t) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Xor<tav::Boolean<true>, tav::Boolean<true>>::type
	>::value,
	"(xor #t #t) != #f"
);

// conditionals

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::If<true, tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(if #t 1 2) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::If<false, tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(if #f 1 2) != 2"
);

// cons

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Car<
			tav::Cons<tav::Int<1>, void>::type
		>::type
	>::value,
	"(car (cons 1 void)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Car<
			tav::Cons<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(car (cons 1 2)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Cdr<
			tav::Cons<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(cdr (cons 1 2)) != 2"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Car<
			tav::Cdr<
				tav::Cons<tav::Int<1>, tav::Cons<tav::Int<2>, tav::Int<3>>::type>::type
			>::type
		>::type
	>::value,
	"(car (cdr (cons 1 (cons 2 3)))) != 2"
);

// list

static_assert(
	std::is_same<
		tav::Pair<tav::Int<1>, void>,
		tav::List<tav::Int<1>>::type
	>::value,
	"(list 1) != '(1)"
);

static_assert(
	std::is_same<
		tav::Pair<tav::Int<1>, tav::Pair<tav::Int<2>, void>>,
		tav::List<tav::Int<1>, tav::Int<2>>::type
	>::value,
	"(list 1 2) != '(1 . 2)"
);

static_assert(
	std::is_same<
		tav::Pair<tav::Int<1>, tav::Pair<tav::Int<2>, void>>,
		tav::List<void, tav::Int<1>, void, tav::Int<2>, void>::type
	>::value,
	"(list void 1 void 2 void) != '(1 . 2)"
);

// list of type

static_assert(
	std::is_same<
		tav::Pair<tav::Int<1>, void>,
		tav::ListOfType<int, 1>::type
	>::value,
	"(list 1) != (cons 1 void)"
);

static_assert(
	std::is_same<
		tav::Pair<tav::Int<1>, tav::Pair<tav::Int<2>, void>>,
		tav::ListOfType<int, 1, 2>::type
	>::value,
	"(list 1 2) != (cons 1 (cons 2 void))"
);

// list length

static_assert(
	std::is_same<
		tav::Size<1>,
		tav::Length<
			tav::List<tav::Int<1>>::type
		>::type
	>::value,
	"(length (list 1)) != 1"
);

static_assert(
	std::is_same<
		tav::Size<2>,
		tav::Length<
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(length (list 1 2)) != 2"
);

// list nth

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Nth<
			tav::Size<0>,
			tav::List<tav::Int<1>>::type
		>::type
	>::value,
	"(nth 0 (list 1)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<1>,
		tav::Nth<
			tav::Size<0>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(nth 0 (list 1 2)) != 1"
);

static_assert(
	std::is_same<
		tav::Int<2>,
		tav::Nth<
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(nth 1 (list 1 2)) != 2"
);

// list take

static_assert(
	std::is_same<
		tav::List<tav::Int<1>>::type,
		tav::Take<
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(take 1 (list 1 2)) != (list 1)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>>::type,
		tav::Take<
			tav::Size<2>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(take 2 (list 1 2)) != (list 1 2)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>>::type,
		tav::Take<
			tav::Size<3>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(take 3 (list 1 2)) != (list 1 2)"
);

// list drop

static_assert(
	std::is_same<
		tav::List<tav::Int<2>>::type,
		tav::Drop<
			tav::Size<1>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(drop 1 (list 1 2)) != (list 2)"
);

static_assert(
	std::is_same<
		void,
		tav::Drop<
			tav::Size<2>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(drop 2 (list 1 2)) != void"
);

static_assert(
	std::is_same<
		void,
		tav::Drop<
			tav::Size<3>,
			tav::List<tav::Int<1>, tav::Int<2>>::type
		>::type
	>::value,
	"(drop 3 (list 1 2)) != void"
);

// list append

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>>::type,
		tav::Append<
			tav::List<tav::Int<1>>::type,
			tav::List<tav::Int<2>>::type
		>::type
	>::value,
	"(append (list 1) (list 2)) != (list 1 2)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>, tav::Int<4>>::type,
		tav::Append<
			tav::List<tav::Int<1>, tav::Int<2>>::type,
			tav::List<tav::Int<3>, tav::Int<4>>::type
		>::type
	>::value,
	"(append (list 1 2) (list 3 4)) != (list 1 2 3 4)"
);

// list fold

static_assert(
	std::is_same<
		tav::Int<6>,
		tav::Fold<
			tav::Add,
			tav::Int<0>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(fold + 0 (list 1 2 3)) != 6"
);

// list map

template <typename Element>
using quadruple = tav::Multiply<tav::Int<4>, Element>;

static_assert(
	std::is_same<
		tav::List<tav::Int<4>, tav::Int<8>, tav::Int<12>>::type,
		tav::Map<
			quadruple,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(map quadruple (list 1 2 3)) != (list 4 8 12)"
);

// list filter

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<3>>::type,
		tav::Filter<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(filter odd? (list 1 2 3)) != (list 1 3)"
);

// list remove

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<3>>::type,
		tav::Remove<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(remove even? (list 1 2 3)) != (list 1 3)"
);

// list delete

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<3>>::type,
		tav::Delete<
			tav::Int<2>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(delete 2 (list 1 2 3)) != (list 1 3)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type,
		tav::Delete<
			tav::Int<4>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(delete 4 (list 1 2 3)) != (list 1 2 3)"
);

// list partition

static_assert(
	std::is_same<
		tav::Pair<
			tav::List<tav::Int<1>, tav::Int<3>>::type,
			tav::List<tav::Int<2>>::type
		>,
		tav::Partition<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(partition odd? (list 1 2 3)) != [(list 1 3) (list 2)]"
);

// list reverse

static_assert(
	std::is_same<
		tav::List<tav::Int<3>, tav::Int<2>, tav::Int<1>>::type,
		tav::Reverse<
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(reverse (list 1 2 3)) != (list 3 2 1)"
);

// list query

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Any<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(any odd? (list 1 2 3)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Any<
			tav::Odd,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>::type
		>::type
	>::value,
	"(any odd? (list 2 4 6)) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::All<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>::type
		>::type
	>::value,
	"(all even? (list 2 4 6)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::All<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(all odd? (list 1 2 3)) != #f"
);

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::None<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<5>>::type
		>::type
	>::value,
	"(none even? (list 1 3 5)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::None<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<3>, tav::Int<5>>::type
		>::type
	>::value,
	"(none even? (list 2 3 5)) != #f"
);

// list contains

static_assert(
	std::is_same<
		tav::Boolean<true>,
		tav::Contains<
			tav::Int<2>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(contains 2 (list 1 2 3)) != #t"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Contains<
			tav::Int<0>,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(contains 0 (list 1 2 3)) != #f"
);

// list concatenate

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>, tav::Int<4>, tav::Int<5>, tav::Int<6>>::type,
		tav::Concatenate<
			tav::List<
				tav::List<tav::Int<1>, tav::Int<2>>::type,
				tav::List<tav::Int<3>>::type,
				tav::List<tav::Int<4>, tav::Int<5>, tav::Int<6>>::type
			>::type
		>::type
	>::value,
	"(concatenate (list (list 1 2) (list 3) (list 4 5 6))) != (list 1 2 3 4 5 6)"
);

// list iota

static_assert(
	std::is_same<
		tav::List<tav::Int<1>>::type,
		tav::Iota<
			tav::Size<1>,
			tav::Int<1>,
			tav::Int<1>
		>::type
	>::value,
	"(iota 1 1 1) != (list 1)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type,
		tav::Iota<
			tav::Size<3>,
			tav::Int<1>,
			tav::Int<1>
		>::type
	>::value,
	"(iota 3 1 1) != (list 1 2 3)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<0>, tav::Int<2>, tav::Int<4>, tav::Int<6>, tav::Int<8>>::type,
		tav::Iota<
			tav::Size<5>,
			tav::Int<0>,
			tav::Int<2>
		>::type
	>::value,
	"(iota 5 0 2) != (list 0 2 4 6 8)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<5>, tav::Int<4>, tav::Int<3>, tav::Int<2>, tav::Int<1>>::type,
		tav::Iota<
			tav::Size<5>,
			tav::Int<5>,
			tav::Int<-1>
		>::type
	>::value,
	"(iota 5 5 -1) != (list 5 4 3 2 1)"
);

// make list

static_assert(
	std::is_same<
		tav::List<tav::Int<42>>::type,
		tav::MakeList<tav::Size<1>, tav::Int<42>>::type
	>::value,
	"(make-list 1 42) != (list 42)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<42>, tav::Int<42>, tav::Int<42>>::type,
		tav::MakeList<tav::Size<3>, tav::Int<42>>::type
	>::value,
	"(make-list 3 42) != (list 42 42 42)"
);

// list tabulate

static_assert(
	std::is_same<
		tav::List<tav::Size<0>, tav::Size<1>, tav::Size<4>, tav::Size<9>>::type,
		tav::ListTabulate<
			tav::Size<4>,
			tav::Square
		>::type
	>::value,
	"(list-tabulate 4 square) != (list 0 1 4 9)"
);

// list count

static_assert(
	std::is_same<
		tav::Size<2>,
		tav::Count<
			tav::Odd,
			tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type
		>::type
	>::value,
	"(count odd? (list 1 2 3)) != 2"
);

static_assert(
	std::is_same<
		tav::Size<0>,
		tav::Count<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<5>>::type
		>::type
	>::value,
	"(count even? (list 1 3 5)) != 0"
);

// list find

static_assert(
	std::is_same<
		tav::Int<4>,
		tav::Find<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<4>, tav::Int<6>>::type
		>::type
	>::value,
	"(find even? (list 1 3 4 6)) != 4"
);

static_assert(
	std::is_same<
		tav::Int<6>,
		tav::Find<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<5>, tav::Int<6>>::type
		>::type
	>::value,
	"(find even? (list 1 3 5 6)) != 6"
);

static_assert(
	std::is_same<
		tav::Boolean<false>,
		tav::Find<
			tav::Even,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<5>>::type
		>::type
	>::value,
	"(find even? (list 1 3 5)) != #f"
);

// list take while

static_assert(
	std::is_same<
		tav::List<tav::Int<2>, tav::Int<4>>::type,
		tav::TakeWhile<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<5>, tav::Int<6>>::type
		>::type
	>::value,
	"(take-while even? (list 2 4 5 6)) != (list 2 4)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>::type,
		tav::TakeWhile<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>::type
		>::type
	>::value,
	"(take-while even? (list 2 4 6)) != (list 2 4 6)"
);

static_assert(
	std::is_same<
		void,
		tav::TakeWhile<
			tav::Odd,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<5>, tav::Int<6>>::type
		>::type
	>::value,
	"(take-while odd? (list 2 4 5 6)) != void"
);

// list drop while

static_assert(
	std::is_same<
		tav::List<tav::Int<5>, tav::Int<6>>::type,
		tav::DropWhile<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<5>, tav::Int<6>>::type
		>::type
	>::value,
	"(drop-while even? (list 2 4 5 6)) != (list 5 6)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>::type,
		tav::DropWhile<
			tav::Odd,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>::type
		>::type
	>::value,
	"(drop-while odd? (list 2 4 6)) != (list 2 4 6)"
);

static_assert(
	std::is_same<
		void,
		tav::DropWhile<
			tav::Even,
			tav::List<tav::Int<2>, tav::Int<4>, tav::Int<6>>::type
		>::type
	>::value,
	"(drop-while even? (list 2 4 6)) != void"
);

// list sort

static_assert(
	std::is_same<
		tav::List<tav::Int<1>, tav::Int<2>, tav::Int<3>>::type,
		tav::Sort<
			tav::GreaterThan,
			tav::List<tav::Int<3>, tav::Int<2>, tav::Int<1>>::type
		>::type
	>::value,
	"(sort > (list 3 2 1)) != (list 1 2 3)"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<3>, tav::Int<2>, tav::Int<1>>::type,
		tav::Sort<
			tav::LowerThan,
			tav::List<tav::Int<1>, tav::Int<3>, tav::Int<2>>::type
		>::type
	>::value,
	"(sort < (list 1 3 2)) != (list 3 2 1)"
);

// function apply

static_assert(
	std::is_same<
		tav::Int<42>,
		tav::Apply<
			tav::Multiply,
			tav::Int<21>,
			tav::_0
		>::single_type<
			tav::Int<2>
		>::type
	>::value,
	"((lambda (x) (* 21 x)) 2) != 42"
);

static_assert(
	std::is_same<
		tav::List<tav::Int<10>, tav::Int<12>, tav::Int<14>>::type,
		tav::Map<
			tav::Apply<
				tav::Add,
				tav::_0,
				tav::Int<10>
			>::single_type,
			tav::List<tav::Int<0>, tav::Int<2>, tav::Int<4>>::type
		>::type
	>::value,
	"(map (lambda (x) (+ x 10)) (list 0 2 4)) != (list 10 12 14)"
);
