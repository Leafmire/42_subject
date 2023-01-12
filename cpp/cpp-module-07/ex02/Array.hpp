/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 20:21:28 by gson              #+#    #+#             */
/*   Updated: 2022/08/07 18:57:04 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{
	public:
		Array();
		Array( Array const & src );
		Array( unsigned int n );
		~Array();

		T &operator[]( int idx ) const;

		Array &operator=( Array const & rhs );

		unsigned int size() const;

		class OutOfArrayRangeException;
	private:
		unsigned int array_len;
		T* array;
};

template <typename T>
Array<T>::Array()
{
	this->array = NULL;
	this->array_len = 0;
}

template <typename T>
Array<T>::Array( unsigned int n )
{
	this->array = new T[n];
	this->array_len = n;
}

template <typename T>
Array<T>::Array(Array<T> const &src)
{
	this->array = NULL;
	this->array_len = 0;
	*this = src;
}

template <typename T>
Array<T>::~Array()
{
	if (this->array)
		delete [] this->array;
}

template <typename T>
Array<T> & Array<T>::operator=( Array<T> const & rhs )
{
	if (this != &rhs)
	{	
		if (this->array)
			delete [] this->array;
		this->array = new T[rhs.array_len];
		this->array_len = rhs.array_len;
		for (unsigned int i = 0; i < this->array_len; i++)
		{
			this->array[i] = rhs.array[i];
		}
	}
	return (*this);
}

template <typename T>
T & Array<T>::operator[]( int idx ) const
{
	if (idx < 0 || idx >= (int)this->array_len)
		throw OutOfArrayRangeException();
	else
		return (this->array[idx]);
}

template <typename T>
unsigned int Array<T>::size() const
{
	return (this->array_len);
}

template <typename T>
class Array<T>::OutOfArrayRangeException : public std::exception{
	public :
		const char *what() const throw() {
			return "Index out of range.";
		}
};

template< typename T >
std::ostream &	operator << ( std::ostream & o, Array<T> const & array )
{
	o << "{ ";
	if (array.size()) 
	{
		for (unsigned int i = 0; i < array.size() - 1; i++)
		{
			o << array[i] << ", " << array[i];
		}
	}
	o << " }";

	return o;
}

#endif
