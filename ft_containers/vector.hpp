/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:21:52 by gson              #+#    #+#             */
/*   Updated: 2023/01/03 20:43:15 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
#define VECTOR_HPP

#include "iterator.hpp"
#include <memory>
#include <stdexcept>
#include <sys/_types/_size_t.h>
#include <iostream>

namespace ft {

	template < class T, class Allocator = std::allocator<T> >
	class vector
	{
		public :
			typedef T													value_type;
			typedef Allocator											allocator_type;
			typedef typename allocator_type::reference					reference;
			typedef typename allocator_type::const_reference			const_reference;
			typedef typename allocator_type::pointer					pointer;
			typedef typename allocator_type::const_pointer				const_pointer;

			typedef size_t												size_type;
			typedef typename allocator_type::difference_type			difference_type;

			typedef ft::RandomAccessIterator<T>							iterator;
			typedef ft::RandomAccessIterator<const T>					const_iterator;
			typedef ft::reverse_iterator<iterator>						reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>				const_reverse_iterator;

			/*
			**	explicit 키워드는 자신이 원하지 않은 형변환이 일어나지 않도록 제한하는 키워드이다.
			*/
			explicit vector(const allocator_type& alloc = allocator_type()) : data(0), _size(0), _capacity(0), _alloc(alloc) {};
			explicit vector(size_type n, const value_type& val = value_type(), \
				const allocator_type& alloc = allocator_type()) : data(0), _size(n), _capacity(0), _alloc(alloc) {
					_capacity = _size;
					data = _alloc.allocate(_capacity);
					for (size_t i = 0; i < _size; i++)
					{
						_alloc.construct(data + i, val);
					}
				};

			template <class InputIterator>
			vector (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last, \
				const allocator_type& alloc = allocator_type()) : data(0), _size(0), _capacity(0), _alloc(alloc) {
					_capacity = ft::distance(first, last);
					_size = _capacity;
					data = _alloc.allocate(_capacity);
					this->assign(first, last);
			};

			vector(const vector &x) : data(0), _size(0), _capacity(0), _alloc(x._alloc) {
				*this = x;
			};

			vector& operator=(const vector &x) {
				if (this == &x) {
					return *this;
				}
				this->clear();
				_alloc.deallocate(data, _capacity);
				this->_size = 0;
				this->_capacity = x._capacity;
				this->data = _alloc.allocate(_capacity);
				this->assign(x.begin(), x.end());
				return *this;
			};

			reference at (size_type n) {
				if (_size == 0 || n > _size - 1) {
					throw std::out_of_range("out of range");
				}
				return data[n];
			}

			const_reference at (size_type n) const {
				if (_size == 0 || n > _size - 1) {
					throw std::out_of_range("out of range");
				}
				return data[n];
			}

			reference back() {
				return data[_size - 1];
			}
			
			const_reference back() const {
				return data[_size - 1];
			}

			reference front() {
				return data[0];
			}

			const_reference front() const {
				return data[0];
			}

			/* Iterator */
			iterator	begin() {
				return iterator(data);
			};
			iterator	end() {
				return iterator(data + _size);
			};

			const_iterator	begin() const {
				return const_iterator(data);
			};
			const_iterator	end() const {
				return const_iterator(data + _size);
			};

			reverse_iterator	rbegin() {
				return reverse_iterator(data + _size);
			};
			reverse_iterator	rend() {
				return reverse_iterator(data);
			};

			const_reverse_iterator	rbegin() const {
				return const_reverse_iterator(data + _size);
			};
			const_reverse_iterator	rend() const {
				return const_reverse_iterator(data);
			};

			/* erase & insert */
			iterator erase (iterator position) {
				return erase(position, position + 1);
			}

			iterator erase (iterator first, iterator last) {
				iterator tmp(first);
				while (last != this->end()) {
					*first = *last;
					++first;
					++last;
				}
				difference_type _distance = ft::distance(first, last);
				while (_distance) {
					_alloc.destroy(&data[_size - 1]);
					--_size;
					--_distance;
				}
				return tmp;
			}

			iterator insert (iterator position, const value_type& val) {
				size_type i = ft::distance(begin(), position);
				insert(position, 1, val);
				return (iterator(data + i));
			}
			
			void insert (iterator position, size_type n, const value_type& val) {
				vector v(position, end());
				_size -= ft::distance(position, end());
				while (n) {
					this->push_back(val);
					--n;
				}
				iterator tmp_it = v.begin();
				while (tmp_it != v.end()) {
					this->push_back(*tmp_it);
					++tmp_it;
				}
			}
			
			template <class InputIterator>
			void insert (iterator position, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				vector v(position, end());
				_size -= ft::distance(position, end());
				while (first != last) {
					this->push_back(*first);
					++first;
				}
				iterator tmp_it = v.begin();
				while (tmp_it != v.end()) {
					this->push_back(*tmp_it);
					++tmp_it;
				}
			}

			/* Access */

			reference operator[] (size_type n) {
				return data[n];
			}

			const_reference operator[] (size_type n) const {
				return data[n];
			}

			size_type max_size() const {
				return _alloc.max_size();
			}

			allocator_type get_allocator() const {
				return _alloc;
			}

			size_type capacity() const {
				return _capacity;
			}

			size_type size() const {
				return _size;
			}

			void resize (size_type n, value_type val = value_type()) {
				if (n == _size) {
					return ;
				}
				else if (n < _size) {
					while (_size != n) {
						pop_back();
					}
				}
				else if (n > _size) {
					while (_size != n) {
						push_back(val);
					}
				}
			}

			void swap(vector& other) {
				vector tmp;
				tmp.copy_keep_ite_validity(other);
				other.copy_keep_ite_validity(*this);
				this->copy_keep_ite_validity(tmp);
			}

			bool empty() const {
				if (_size == 0)
					return true;
				else
				 	return false;
			}

			~vector() {
				for (size_t i = 0; i < _size; i++) {
					_alloc.destroy(data + i);
				}				
				_alloc.deallocate(data, _capacity);
			};

			template <class InputIterator>
			void assign (typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type first, InputIterator last) {
				this->clear();
				while (first != last) {
					push_back(*first);
					++first;
				}
			};
			
			void assign (size_type n, const value_type& val) {
				this->clear();
				while (n) {
					push_back(val);
					--n;
				}
			};

			void	clear() {
				while (_size)
					pop_back();
			}

			void	pop_back() {
				--_size;
				_alloc.destroy(data + _size);
			}

			void	reserve(size_type n) {
				if (n > _capacity) {
					if (n < _capacity * 2)
						n = _capacity * 2;
					pointer tmp = _alloc.allocate(n);
					for (size_t i = 0; i < _size; i++) {
						_alloc.construct(tmp + i, data[i]);
					}
					for (size_t i = 0; i < _size; i++) {
						_alloc.destroy(data + i);
					}				
					_alloc.deallocate(data, _capacity);
					data = tmp;
					_capacity = n;
				}
			}

			void	push_back(const value_type& val) {
				if (_size == _capacity) {
					if (_size == 0) {
						reserve(1);
					}
					else {
						reserve(_capacity * 2);
					}
				}
				_alloc.construct(data + _size, val);
				++_size;
			}

		private:
			pointer			data;
			size_t			_size;
			size_t			_capacity;
			allocator_type	_alloc;
		private:
				void copy_keep_ite_validity(vector& other) {
				this->data = other.data;
				this->_alloc = other._alloc;
				this->_size = other._size;
				this->_capacity = other._capacity;
				other.data = 0;
				other._size = 0;
				other._capacity = 0;
			}
	};

template <class T, class Alloc>
bool operator== (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin()))
		return true;
	return false;
}

template <class T, class Alloc>
bool operator!= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs == rhs);
}

template <class T, class Alloc>
bool operator<  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end()))
		return true;
	return false;
}

template <class T, class Alloc>
bool operator<= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	if (ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end())
		|| lhs == rhs)
		return true;
	return false;
}

template <class T, class Alloc>
bool operator>  (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs <= rhs);
}

template <class T, class Alloc>
bool operator>= (const vector<T,Alloc>& lhs, const vector<T,Alloc>& rhs) {
	return !(lhs < rhs);
}

template <class T, class Alloc>
void swap (vector<T,Alloc>& x, vector<T,Alloc>& y) {
	x.swap(y);
}

}


#endif