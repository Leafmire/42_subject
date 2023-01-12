/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_iterator.hpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/15 19:05:05 by gson              #+#    #+#             */
/*   Updated: 2023/01/03 18:36:38 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_ITERATOR_HPP
#define MAP_ITERATOR_HPP

#include "tree_node.hpp"
#include "util.hpp"

namespace ft {

template<class _Iter, class T, class Compare>
class MapIterator {
    public:
        typedef _Iter                                                          iterator_type;
        typedef T                                                              node_content_type;
        typedef T*                                                             node_content_pointer;
        typedef T&                                                             node_content_reference;
        typedef typename ft::bidirectional_iterator_tag                        iterator_category;
        typedef typename ft::iterator_traits<_Iter *>::value_type              value_type;
        typedef typename ft::iterator_traits<_Iter *>::difference_type         difference_type;
        typedef typename ft::iterator_traits<_Iter *>::pointer                 pointer;
        typedef typename ft::iterator_traits<_Iter *>::reference               reference;

        MapIterator(const Compare& comp = Compare()) : _node(), _nil(), _comp(comp) {}
        MapIterator(_Iter* node_p, _Iter* nil, const Compare& comp = Compare()) : _node(node_p), _nil(nil), _comp(comp) {}
        MapIterator(const MapIterator &x) : _node(x._node), _nil(x._nil), _comp() {}
        virtual ~MapIterator() {};

        MapIterator& operator=(const MapIterator &rhs) {
            if (*this == rhs) {
                return (*this);
            }
            this->_node = rhs._node;
            this->_nil = rhs._nil;
            this->_comp = rhs._comp;
            return *this;
        }

        // 전위 증감연산자
        MapIterator& operator++() {
            pointer cur = _node;
            if (_node == _nil) {
                cur = cur->r_child;
                while (cur->l_child != _nil) {
                    cur = cur->l_child;
                }
                _node = cur;
                return *this;
            }
            if (_node->r_child == _nil) {
                cur = _node->parent;
                while (cur != _nil && _comp(cur->data.first, _node->data.first)) {
                    cur = cur->parent;
                }
                _node = cur;
            }
            else {
                cur = _node->r_child;
                while (cur->l_child != _nil) {
                        cur = cur->l_child;
                }
                _node = cur;
            }
            return *this;
        };
        MapIterator& operator--() {
            pointer cur = _node;
            if (_node == _nil) {
                cur = cur->r_child;
                while (cur->r_child != _nil) {
                    cur = cur->r_child;
                }
                _node = cur;
                return *this;
            }
            if (_node->l_child == _nil) {
                cur = _node->parent;
                while (cur != _nil && !_comp(cur->data.first, _node->data.first)) {
                    cur = cur->parent;
                }
                _node = cur;
            }
            else {
                cur = _node->l_child;
                while (cur->r_child != _nil) {
                    cur = cur->r_child;
                }
                _node = cur;
            }
            return *this;
        };

        //후위 증감연산자
        MapIterator operator++(int) {
            MapIterator ret(*this);
            operator++();
            return ret;
        };
        MapIterator operator--(int) {
            MapIterator ret(*this);
            operator--();
            return ret;
        };

        bool operator==(MapIterator rhs) const {
            return (_node == rhs._node);
        };
        bool operator!=(MapIterator rhs) const {
            return !(*this == rhs);
        };

        node_content_type& operator*() const {
            return _node->data;
        };
        node_content_type*   operator->() const {
            return &(_node->data);
        }

    public:
        pointer _node;
        pointer _nil;
        Compare _comp;
};

template<class _Iter, class T, class Compare>
class MapConstIterator {
    public:
        typedef _Iter                                                          iterator_type;
        typedef T                                                              node_content_type;
        typedef const T*                                                       node_content_pointer;
        typedef const T&                                                       node_content_reference;
        typedef typename ft::bidirectional_iterator_tag                        iterator_category;
        typedef _Iter                                                          value_type;
        typedef typename ft::iterator_traits<_Iter *>::difference_type         difference_type;
        typedef const _Iter*                                                   pointer;
        typedef const _Iter&                                                   reference;

        MapConstIterator(const Compare& comp = Compare()) : _node(), _nil(), _comp(comp) {}
        MapConstIterator(_Iter* node_p, _Iter* nil, const Compare& comp = Compare()) : _node(node_p), _nil(nil), _comp(comp) {}
        MapConstIterator(const MapConstIterator &x) : _node(x._node), _nil(x._nil), _comp() {}
        MapConstIterator(const MapIterator<_Iter, T, Compare> &x) : _node(x._node), _nil(x._nil), _comp() {}
        virtual ~MapConstIterator() {};

        MapConstIterator& operator=(const MapConstIterator &rhs) {
            if (*this == rhs) {
                return (*this);
            }
            this->_node = rhs._node;
            this->_nil = rhs._nil;
            this->_comp = rhs._comp;
            return *this;
        }

        // 전위 증감연산자
        MapConstIterator& operator++() {
            pointer cur = _node;
            if (_node == _nil) {
                cur = cur->r_child;
                while (cur->l_child != _nil) {
                    cur = cur->l_child;
                }
                _node = cur;
                return *this;
            }
            if (_node->r_child == _nil) {
                cur = _node->parent;
                while (cur != _nil && _comp(cur->data.first, _node->data.first)) {
                    cur = cur->parent;
                }
                _node = cur;
            }
            else {
                cur = _node->r_child;
                while (cur->l_child != _nil) {
                        cur = cur->l_child;
                }
                _node = cur;
            }
            return *this;
        };
        MapConstIterator& operator--() {
            pointer cur = _node;
            if (_node == _nil) {
                cur = cur->r_child;
                while (cur->r_child != _nil) {
                    cur = cur->r_child;
                }
                _node = cur;
                return *this;
            }
            if (_node->l_child == _nil) {
                cur = _node->parent;
                while (cur != _nil && !_comp(cur->data.first, _node->data.first)) {
                    cur = cur->parent;
                }
                _node = cur;
            }
            else {
                cur = _node->l_child;
                while (cur->r_child != _nil) {
                    cur = cur->r_child;
                }
                
                _node = cur;
            }
            return *this;
        };

        //후위 증감연산자
        MapConstIterator operator++(int) {
            MapConstIterator ret(*this);
            operator++();
            return ret;
        };
        MapConstIterator operator--(int) {
            MapConstIterator ret(*this);
            operator--();
            return ret;
        };

        bool operator==(MapConstIterator rhs) const {
            return (_node == rhs._node);
        };
        bool operator!=(MapConstIterator rhs) const {
            return !(*this == rhs);
        };

        const node_content_type& operator*() const {
            return _node->data;
        };
        const node_content_type*   operator->() const {
            return &(_node->data);
        }

    public:
        pointer _node;
        pointer _nil;
        Compare _comp;
};

/*
** reverse iterator
*/
template <class _Iter>
class map_reverse_iterator
{
protected:
    _Iter current;
public:
    typedef _Iter                                            iterator_type;
    typedef typename iterator_traits<_Iter>::difference_type difference_type;
    typedef _Iter&                                           reference;
    typedef _Iter*                                           pointer;
    typedef typename _Iter::node_content_type                node_content_type;
    typedef typename _Iter::node_content_pointer             node_content_pointer;
    typedef typename _Iter::node_content_reference           node_content_reference;

    map_reverse_iterator() : current() {}
    explicit map_reverse_iterator(_Iter x) : current(x) {}
    template <class U> map_reverse_iterator(const map_reverse_iterator<U>& u) : current(u.base()) {}
    map_reverse_iterator& operator=(const map_reverse_iterator& u) {
        current = u.base();
        return *this;
    }
    _Iter    base() const {
        return current;
    }
    node_content_reference operator*() const {
        _Iter tmp = current;
        return *(--tmp);
    }
    node_content_pointer   operator->() const {
        return &(operator*());
    }

    map_reverse_iterator& operator++() {
       --current;
       return *this;
    }
    map_reverse_iterator  operator++(int) {
        map_reverse_iterator tmp(*this);
        --current;
        return tmp;      
    }
    map_reverse_iterator& operator--() {
       ++current;
       return *this;
    }
    map_reverse_iterator  operator--(int) {
        map_reverse_iterator tmp(*this);
        ++current;
        return tmp;   
    }
};

template <class Iterator1, class Iterator2>
bool                          
operator==(const map_reverse_iterator<Iterator1>& x, const map_reverse_iterator<Iterator2>& y) {
    return x.base() == y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator<(const map_reverse_iterator<Iterator1>& x, const map_reverse_iterator<Iterator2>& y) {
    return x.base() > y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator!=(const map_reverse_iterator<Iterator1>& x, const map_reverse_iterator<Iterator2>& y) {
    return x.base() != y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator>(const map_reverse_iterator<Iterator1>& x, const map_reverse_iterator<Iterator2>& y) {
    return x.base() < y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator>=(const map_reverse_iterator<Iterator1>& x, const map_reverse_iterator<Iterator2>& y) {
    return x.base() <= y.base();
}

template <class Iterator1, class Iterator2>
bool                          
operator<=(const map_reverse_iterator<Iterator1>& x, const map_reverse_iterator<Iterator2>& y) {
    return x.base() >= y.base();
}

}



#endif