/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iterator.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/23 19:05:20 by gson              #+#    #+#             */
/*   Updated: 2022/12/26 18:12:56 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITERATOR_HPP
#define ITERATOR_HPP

#include "util.hpp"
#include <iostream>
#include <cstddef>

namespace ft {



template<class Iterator>
typename ft::iterator_traits<Iterator>::difference_type
    distance (Iterator first, Iterator last) {
    typename ft::iterator_traits<Iterator>::difference_type result = 0;
    while (first != last) {
        first++;
        result++;
    }
    return result;
};

template<class Iterator>
typename ft::iterator_traits<Iterator>::difference_type
    distance (Iterator first, Iterator last, ft::random_access_iterator_tag) {
    return last - first;
};


/*
** random iterator
*/

template<class _Iter>
class RandomAccessIterator {
    public:
        typedef _Iter                                                          iterator_type;
        typedef typename ft::iterator_traits<_Iter *>::iterator_category       iterator_category;
        typedef _Iter                                                          value_type;
        typedef typename ft::iterator_traits<_Iter *>::difference_type         difference_type;
        typedef typename ft::iterator_traits<_Iter *>::pointer                 pointer;
        typedef typename ft::iterator_traits<_Iter *>::reference               reference;

        RandomAccessIterator() : array(0) {};
        RandomAccessIterator(pointer ptr) : array(ptr) {};
        RandomAccessIterator(const RandomAccessIterator& x) : array(x.array) {};
        virtual ~RandomAccessIterator() {};

    public:
        pointer array;

    public:
        pointer    base() const {
            return array;
        }

        operator RandomAccessIterator<const _Iter>() {
            return RandomAccessIterator<const _Iter>(this->array);
        }

        RandomAccessIterator& operator=(const RandomAccessIterator &rhs) {
            this->array = rhs.array;
            return *this;
        }

        RandomAccessIterator    operator+(difference_type n) const {
            RandomAccessIterator tmp(*this);
            tmp.array += n;
            return tmp;
        }

        RandomAccessIterator    operator-(difference_type n) const {
            RandomAccessIterator tmp(*this);
            tmp.array -= n;
            return tmp;
        }

        // 전위 증감연산자
        RandomAccessIterator& operator++() {
            ++array;
            return *this;
        };
        RandomAccessIterator& operator--() {
            --array;
            return *this;
        };

        //후위 증감연산자
        RandomAccessIterator operator++(int) {
            RandomAccessIterator ret = *this;
            ++array;
            return ret;
        };
        RandomAccessIterator operator--(int) {
            RandomAccessIterator ret = *this;
            --array;
            return ret;
        };

        bool operator==(RandomAccessIterator rhs) const {
            return (array == rhs.array);
        };
        bool operator!=(RandomAccessIterator rhs) const {
            return !(*this == rhs);
        };

        reference operator*() const {
            return *array;
        };
        pointer   operator->() const {
            return array;
        }

        RandomAccessIterator& operator+=(difference_type n) {
            this->array += n;
            return *this;
        }
        RandomAccessIterator& operator-=(difference_type n) {
            this->array -= n;
            return *this;
        }
        reference         operator[](difference_type n) const {
            return *(*this + n);
        }
};

template <class Iterator1, class Iterator2>
bool                          
operator==(const RandomAccessIterator<Iterator1>& x, const RandomAccessIterator<Iterator2>& y) {
    return x.base() == y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator<(const RandomAccessIterator<Iterator1>& x, const RandomAccessIterator<Iterator2>& y) {
    return x.base() < y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator!=(const RandomAccessIterator<Iterator1>& x, const RandomAccessIterator<Iterator2>& y) {
    return x.base() != y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator>(const RandomAccessIterator<Iterator1>& x, const RandomAccessIterator<Iterator2>& y) {
    return x.base() > y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator>=(const RandomAccessIterator<Iterator1>& x, const RandomAccessIterator<Iterator2>& y) {
    return !(x.base() < y.base());
}

template <class Iterator1, class Iterator2>
bool                          
operator<=(const RandomAccessIterator<Iterator1>& x, const RandomAccessIterator<Iterator2>& y) {
    return !(x.base() > y.base());
}

template <typename T>
typename ft::RandomAccessIterator<T>::difference_type operator-(const ft::RandomAccessIterator<T> x,
    const ft::RandomAccessIterator<T> y) {
    return (x.array - y.array);                                                      
}

template <typename LHS, typename RHS>
typename ft::RandomAccessIterator<LHS>::difference_type operator-(const ft::RandomAccessIterator<LHS> x,
    const ft::RandomAccessIterator<RHS> y) {
    return (x.array - y.array);                                                      
}

template <class Iterator>
ft::RandomAccessIterator<Iterator>
operator+(typename RandomAccessIterator<Iterator>::difference_type n,
          const RandomAccessIterator<Iterator>& x) {
    return (x.base() + n);
}


/*
** reverse iterator
*/
template <class _Iter>
class reverse_iterator
{
protected:
    _Iter current;
public:
    typedef _Iter                                            iterator_type;
    typedef typename iterator_traits<_Iter>::difference_type difference_type;
    typedef typename iterator_traits<_Iter>::reference       reference;
    typedef typename iterator_traits<_Iter>::pointer         pointer;

    reverse_iterator() : current() {}
    explicit reverse_iterator(_Iter x) : current(x) {}
    template <class U> reverse_iterator(const reverse_iterator<U>& u) : current(u.base()) {}
    reverse_iterator& operator=(const reverse_iterator& u) {
        current = u.base();
        return *this;
    }
    _Iter    base() const {
        return current;
    }
    reference operator*() const {
        _Iter tmp = current;
        return *--tmp;
    }
    pointer   operator->() const {
        return &(operator*());
    }
    reverse_iterator& operator++() {
       --current;
       return *this;
    }
    reverse_iterator  operator++(int) {
        reverse_iterator tmp(*this);
        --current;
        return tmp;      
    }
    reverse_iterator& operator--() {
       ++current;
       return *this;
    }
    reverse_iterator  operator--(int) {
        reverse_iterator tmp(*this);
        ++current;
        return tmp;   
    }
    reverse_iterator    operator+(difference_type n) const {
        reverse_iterator tmp(*this);
        tmp.current -= n;
        return tmp;
    }
    reverse_iterator    operator-(difference_type n) const {
        reverse_iterator tmp(*this);
        tmp.current += n;
        return tmp;
    }
    reverse_iterator& operator+=(difference_type n) {
        this->current -= n;
        return *this;
    }
    reverse_iterator& operator-=(difference_type n) {
        this->current += n;
        return *this;
    }
    reference         operator[](difference_type n) const {
        return *(*this + n);
    }
};

template <class Iterator1, class Iterator2>
bool                          
operator==(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
    return x.base() == y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator<(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
    return x.base() > y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator!=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
    return x.base() != y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator>(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
    return x.base() < y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator>=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
    return x.base() <= y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator<=(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
    return x.base() >= y.base();
}

template <class Iterator1, class Iterator2>
typename ft::reverse_iterator<Iterator1>::difference_type
operator-(const reverse_iterator<Iterator1>& x, const reverse_iterator<Iterator2>& y) {
    return (y.base() - x.base());
}

template <class Iterator>
typename ft::reverse_iterator<Iterator>
operator+(typename reverse_iterator<Iterator>::difference_type n,
          const reverse_iterator<Iterator>& x) {
    return reverse_iterator<Iterator>(x.base() - n);
}

}
#endif