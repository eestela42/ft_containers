#ifndef ENABLE_IF_HPP
# define ENABLE_IF_HPP

namespace ft
{

template <bool, class IsTrue = void>
struct enable_if;

template <class IsTrue>
struct enable_if<true, IsTrue> {
	typedef IsTrue type;
};

}

#endif