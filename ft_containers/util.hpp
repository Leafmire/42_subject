/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 03:02:12 by gson              #+#    #+#             */
/*   Updated: 2023/01/03 16:55:27 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTIL_HPP
#define UTIL_HPP

#include <cstddef>
namespace ft {

struct input_iterator_tag  {};
struct output_iterator_tag {};
struct forward_iterator_tag       : public input_iterator_tag         {};
struct bidirectional_iterator_tag : public forward_iterator_tag       {};
struct random_access_iterator_tag : public bidirectional_iterator_tag {};

template<class _Iter>
struct iterator_traits {
    typedef typename _Iter::difference_type      difference_type;
    typedef typename _Iter::value_type           value_type;
    typedef typename _Iter::pointer              pointer;
    typedef typename _Iter::reference            reference;
    typedef typename _Iter::iterator_category    iterator_category;
};

template<class T>
struct iterator_traits<T*> {
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef T*                          pointer;
    typedef T&                          reference;
    typedef random_access_iterator_tag  iterator_category;
};

template<class T>
struct iterator_traits<const T*> {
    typedef ptrdiff_t                   difference_type;
    typedef T                           value_type;
    typedef const T*                    pointer;
    typedef const T&                    reference;
    typedef random_access_iterator_tag  iterator_category;
};

/*
** enable_if
*/
template <bool, class T = void> struct enable_if {};
template <class T> struct enable_if<true, T> {typedef T type;};

/*
** is_integral
*/
template <class T, T v>
struct integral_constant {
    static const T              value = v;
    typedef T                   value_type;
    typedef integral_constant   type;
};
typedef integral_constant<bool, true>  true_type;
typedef integral_constant<bool, false> false_type;

template <class T>   struct is_integral                     : public ft::false_type {};
template <>          struct is_integral<bool>               : public ft::true_type {};
template <>          struct is_integral<char>               : public ft::true_type {};
template <>          struct is_integral<signed char>        : public ft::true_type {};
template <>          struct is_integral<unsigned char>      : public ft::true_type {};
template <>          struct is_integral<wchar_t>            : public ft::true_type {};
template <>          struct is_integral<short>              : public ft::true_type {};
template <>          struct is_integral<unsigned short>     : public ft::true_type {};
template <>          struct is_integral<int>                : public ft::true_type {};
template <>          struct is_integral<unsigned int>       : public ft::true_type {};
template <>          struct is_integral<long>               : public ft::true_type {};
template <>          struct is_integral<unsigned long>      : public ft::true_type {};
template <>          struct is_integral<long long>          : public ft::true_type {};
template <>          struct is_integral<unsigned long long> : public ft::true_type {};


template< class InputIt1, class InputIt2 >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2 ) {
    while (first1 != last1) {
        if (first2 == last2 || *first2 < *first1) {
            return false;
        }
        else if (*first1 < *first2) {
            return true;
        }
        ++first1;
        ++first2;
    }
    return (first2 != last2);
}

template< class InputIt1, class InputIt2, class Compare >
bool lexicographical_compare( InputIt1 first1, InputIt1 last1,
                              InputIt2 first2, InputIt2 last2, Compare comp ) {
    while (first1 != last1) {
        if (first2 == last2 || comp(*first2, *first1)) {
            return false;
        }
        else if (comp(*first1, *first2)) {
            return true;
        }
        ++first1;
        ++first2;
    }
    return (first2 != last2);   
}

template<class InputIt1, class InputIt2>
bool equal(InputIt1 first1, InputIt1 last1, 
           InputIt2 first2)
{
    while (first1 != last1) {
        if (!(*first1 == *first2)) {
            return false;
        }
        ++first1;
        ++first2;
    }
    return true;
}

template<class InputIt1, class InputIt2, class BinaryPredicate>
bool equal(InputIt1 first1, InputIt1 last1, 
           InputIt2 first2, BinaryPredicate p)
{
    while (first1 != last1) {
        if (!p(*first1, *first2)) {
            return false;
        }
        ++first1;
        ++first2;
    }
    return true;
}

template <class T1, class T2> struct pair {
    typedef T1 first_type;
    typedef T2 second_type;

    T1 first;
    T2 second;
    
    pair() : first(), second() {}

    pair(T1 const & t1, T2 const & t2) : first(t1), second(t2) {}

    template <class U1, class U2>
    pair(const pair<U1, U2>& p) : first(p.first), second(p.second) {}

    pair& operator=(pair const& p) {
        first = p.first;
        second = p.second;
        return *this;
    }
};
template <class T1, class T2>
  bool operator== (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first==rhs.first && lhs.second==rhs.second; }

template <class T1, class T2>
  bool operator!= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs==rhs); }

template <class T1, class T2>
  bool operator<  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return lhs.first<rhs.first || (!(rhs.first<lhs.first) && lhs.second<rhs.second); }

template <class T1, class T2>
  bool operator<= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(rhs<lhs); }

template <class T1, class T2>
  bool operator>  (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return rhs<lhs; }

template <class T1, class T2>
  bool operator>= (const pair<T1,T2>& lhs, const pair<T1,T2>& rhs)
{ return !(lhs<rhs); }

template <class T1, class T2> pair<T1,T2> make_pair (T1 x, T2 y) {
    return pair<T1, T2>(x, y);
}
}
#endif