/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/14 03:57:28 by gson              #+#    #+#             */
/*   Updated: 2023/01/04 16:10:13 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_HPP
#define MAP_HPP

#include <memory>
#include <stdexcept>
#include <sys/_types/_size_t.h>
#include <iostream>
#include "map_iterator.hpp"
#include "tree.hpp"
#include "iterator.hpp"
#include "util.hpp"


namespace ft {

template<
    class Key,
    class T,
    class Compare = ft::less<Key>,
    class Allocator = std::allocator<ft::pair<const Key, T> >
> class map {
public:
    typedef Key                                                 key_type;
    typedef T                                                   mapped_type;
    typedef ft::pair<const key_type, mapped_type>               value_type;
    typedef Compare                                             key_compare;
    typedef Allocator                                           allocator_type;
    typedef typename allocator_type::reference                  reference;
    typedef typename allocator_type::const_reference            const_reference;
    typedef typename allocator_type::pointer                    pointer;
    typedef typename allocator_type::const_pointer              const_pointer;
    typedef typename allocator_type::size_type                  size_type;
    typedef typename allocator_type::difference_type            difference_type;

    typedef typename ft::RBTree<value_type, Compare>::iterator                    iterator;
    typedef typename ft::RBTree<value_type, Compare>::const_iterator              const_iterator;
    typedef ft::map_reverse_iterator<iterator>                               reverse_iterator;
    typedef ft::map_reverse_iterator<const_iterator>                         const_reverse_iterator;

    class value_compare
    {
        friend class map;
        protected:
            key_compare comp;
            value_compare(key_compare c) : comp(c) {};
        public:
            bool operator()(const value_type& x, const value_type& y) const {
                return comp(x.first, y.first);
            };
    };

    private:
        RBTree<value_type, Compare>	    tree;
		allocator_type	        _alloc;
        key_compare             _comp;

    public:
    explicit map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : tree(), _alloc(alloc), _comp(comp) {
    };

    template <class InputIterator>
    map (InputIterator first, InputIterator last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()) : tree(), _alloc(alloc), _comp(comp) {
            this->insert(first, last);
    };
    map (const map& x) : tree(), _alloc(x._alloc), _comp(x._comp) {
        this->insert(x.begin(), x.end());
    };

    map& operator= (const map& x) {
        if (this == &x) {
            return *this;
        }
        this->clear();
        this->insert(x.begin(), x.end());

        return *this;
    };

    ~map() {
        this->clear();
    };
    
    /*
    ** iterators
    */

    iterator       begin() {
        NODE<value_type>* p = tree.root;
        if (p == 0) {
            return iterator(tree.nil, tree.nil);
        }
        while (p->l_child != tree.nil) {
            p = p->l_child;
        }
        return iterator(p, tree.nil);
    }

    iterator       end() {
        return iterator(tree.nil, tree.nil);
    }

    const_iterator       begin() const{
        NODE<value_type>* p = tree.root;
        if (p == 0) {
            return const_iterator(tree.nil, tree.nil);
        }
        while (p->l_child != tree.nil) {
            p = p->l_child;
        }
        return const_iterator(p, tree.nil);
    }

    const_iterator       end() const{
        return const_iterator(tree.nil, tree.nil);
    }

    reverse_iterator       rbegin() {
        return reverse_iterator(this->end());
    }
    const_reverse_iterator rbegin() const {
        return const_reverse_iterator(this->end());
    };
    reverse_iterator       rend() {
        return reverse_iterator(this->begin());
    };
    const_reverse_iterator rend() const {
        return const_reverse_iterator(this->begin());
    };

    /*
    ** capacity
    */
    bool      empty()    const {
        return (tree.get_node_num() == 0 ? true : false);
    };

    size_type size()     const {
        return tree.get_node_num();
    };
    size_type max_size() const {
        return tree.max_size();
    };


    /*
    ** element access
    */
    mapped_type& operator[](const key_type& k) {
        iterator m = this->find(k);

        if (m == this->end())
            this->insert(ft::make_pair(k, mapped_type()));
        m = this->find(k);
        return (*m).second;
    };

    /*
    ** modifiers
    */
    pair<iterator, bool> insert(const value_type& val) {
        return tree.insert_node(val);
    };
    iterator             insert (iterator position, const value_type& val) {
        (void) position;
        return tree.insert_node(val).first;
    }

    template <class InputIterator>
	void insert (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
		difference_type n = ft::distance(first, last);
		while (n) {
			this->insert(*first);
			--n;
            ++first;
		}
	}

    void      erase (iterator position) {
        this->erase((*position).first);
    };

    size_type erase (const key_type& k) {
        if (this->find(k) == this->end()) {
            return 0;
        }
        tree.delete_node(ft::make_pair(k, mapped_type()));
        return 1;
    };
    void      erase (iterator first, iterator last) {
        while (first != last) {
            this->erase((*first++).first);
        }
    };

    void clear() {
        tree.clear_tree(tree.root);
    };

    void swap (map& x) {
        tree.swap(x.tree);
    };

    /*
    ** observers
    */
    allocator_type get_allocator() const {
        return _alloc;
    };
    key_compare    key_comp()      const {
        return key_compare();
    };
    value_compare  value_comp()    const {
        return value_compare(key_compare());
    };

    /*
    ** map operations
    */
    iterator       find (const key_type& k) {
        return iterator(tree.serach_tree(ft::make_pair(k, mapped_type())), tree.nil);
    };
    const_iterator find (const key_type& k) const {
        return const_iterator(tree.serach_tree(ft::make_pair(k, mapped_type())), tree.nil);
    };
    
    size_type count (const key_type& k) const {
        if (this->find(k) == this->end())
            return 0;
        return 1;
    };

    iterator       lower_bound (const key_type& k) {
        iterator first = this->begin();
        iterator last  = this->end();

        while (first != last) {
            if (!_comp((*first).first, k)) {
                break ;
            }
            ++first;
        }
        return first;
    };
    const_iterator lower_bound (const key_type& k) const {
        const_iterator first = this->begin();
        const_iterator last  = this->end();

        while (first != last) {
            if (!_comp((*first).first, k)) {
                break ;
            }
            ++first;
        }
        return first; 
    };

    iterator       upper_bound (const key_type& k) {
        iterator first = this->begin();
        iterator last  = this->end();

        while (first != last) {
            if (_comp(k, (*first).first)) {
                break ;
            }
            ++first;
        }
        return first;
    };
    const_iterator upper_bound (const key_type& k) const {
        const_iterator first = this->begin();
        const_iterator last  = this->end();

        while (first != last) {
            if (_comp(k, (*first).first)) {
                break ;
            }
            ++first;
        }
        return first; 
    };

    pair<const_iterator,const_iterator> equal_range (const key_type& k) const {
        return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
    };
    pair<iterator,iterator>             equal_range (const key_type& k) {
        return ft::make_pair(this->lower_bound(k), this->upper_bound(k));
    };
};

template <class Key, class T, class Compare, class Allocator>
bool
operator==(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y) {
	if (x.size() == y.size() && ft::equal(x.begin(), x.end(), y.begin()))
		return true;
	return false;
};

template <class Key, class T, class Compare, class Allocator>
bool
operator< (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y) {
    if (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end()))
		return true;
	return false;
};

template <class Key, class T, class Compare, class Allocator>
bool
operator<=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y) {
    if (ft::lexicographical_compare(x.begin(), x.end(), y.begin(), y.end())
		|| x == y)
		return true;
	return false;
};

template <class Key, class T, class Compare, class Allocator>
bool
operator!=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y) {
	return !(x == y);
}

template <class Key, class T, class Compare, class Allocator>
bool
operator> (const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y) {
    return !(x <= y);
};

template <class Key, class T, class Compare, class Allocator>
bool
operator>=(const map<Key, T, Compare, Allocator>& x,
           const map<Key, T, Compare, Allocator>& y) {
    return !(x < y);
};

template <class Key, class T, class Compare, class Allocator>
void
swap(map<Key, T, Compare, Allocator>& x, map<Key, T, Compare, Allocator>& y){
    x.swap(y);
}

}
#endif