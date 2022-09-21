#ifndef PAIR_HPP
# define PAIR_HPP

namespace	ft
{

template <typename T1, typename T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;


	first_type	_first;
	second_type	_second;

	pair(){};
	pair( const T1& x, const T2& y ) : _first(x), _second(y) {};
	template< class U1, class U2 >
	pair( const pair<U1, U2>& p ) : _first(p._first), _second(p._second);
	pair& operator=( const pair& other ) : _first(other._first), _second(other._second) {return (*this)};
};

template< class T1, class T2 >
pair<T1,T2> make_pair( T1 t, T2 u )
{
	return (pair(t, u))
};

template <typename _T1, typename _T2>
inline bool operator==(const pair<_T1, _T2> &lhs, const pair<_T1, _T2> &rhs)
{
    return (lhs._first == rhs._first && lhs._second == rhs._second);
};

template< class T1, class T2 >
bool operator!=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (!lhs == rhs);
};

template< class T1, class T2 >
bool operator<( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	if (lhs._first < rhs._first)
		return (true);
	if (lhs._first > rhs._first)
		return (false);
	if (lhs._second < rhs._second)
		return (true);
	return (false);
	
};

template< class T1, class T2 >
bool operator<=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (!(rhs < lhs));
};

template< class T1, class T2 >
bool operator>( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (rhs < lhs);
};

template< class T1, class T2 >
bool operator>=( const std::pair<T1,T2>& lhs, const std::pair<T1,T2>& rhs )
{
	return (!(lhs < rhs));
};


}

#endif