/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:32:24 by gson              #+#    #+#             */
/*   Updated: 2022/07/24 06:41:54 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : fixed_point(0)
{
	//std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	//std::cout << "Int constructor called" << std::endl;
	this->fixed_point = num << this->fractional_bits;
}

Fixed::Fixed(const float num)
{
	//std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(num * (1 << this->fractional_bits));
}

Fixed::Fixed( const Fixed & src )
{
	//std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	//std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=( Fixed const & rhs )
{
	//std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->fixed_point = rhs.getRawBits();
	}
	return *this;
}

bool Fixed::operator>( Fixed const & rhs )
{
	return (this->toFloat() > rhs.toFloat());
}
bool Fixed::operator<( Fixed const & rhs )
{
	return (this->toFloat() < rhs.toFloat());
}
bool Fixed::operator>=( Fixed const & rhs )
{
	return (this->toFloat() >= rhs.toFloat());
}
bool Fixed::operator<=( Fixed const & rhs )
{
	return (this->toFloat() <= rhs.toFloat());
}
bool Fixed::operator==( Fixed const & rhs )
{
	return (this->toFloat() == rhs.toFloat());
}
bool Fixed::operator!=( Fixed const & rhs )
{
	return (this->toFloat() != rhs.toFloat());
}

float Fixed::operator+( Fixed const & rhs )
{
	return (this->toFloat() + rhs.toFloat());
}
float Fixed::operator-( Fixed const & rhs )
{
	return (this->toFloat() - rhs.toFloat());
}
float Fixed::operator*( Fixed const & rhs )
{
	return (this->toFloat() * rhs.toFloat());
}
float Fixed::operator/( Fixed const & rhs )
{
	return (this->toFloat() / rhs.toFloat());
}

Fixed& Fixed::operator++( void )
{
	this->fixed_point++;
	return (*this);
}
Fixed Fixed::operator++( int )
{
	Fixed fixed(*this);

	this->fixed_point++;
	return (fixed);
}
Fixed& Fixed::operator--( void )
{
	this->fixed_point--;
	return (*this);
}
Fixed Fixed::operator--( int )
{
	Fixed fixed(*this);

	this->fixed_point--;
	return (fixed);
}

std::ostream& operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return (o);
}

Fixed &Fixed::max( Fixed &f1,  Fixed &f2)
{
	if (f1.toFloat() > f2.toFloat())
		return (f1);
	else
		return (f2);
}
Fixed &Fixed::min( Fixed &f1,  Fixed &f2)
{
	if (f1.toFloat() < f2.toFloat())
		return (f1);
	else
		return (f2);	
}
const Fixed &Fixed::max( Fixed const &f1,  Fixed const &f2)
{
	if (f1.toFloat() > f2.toFloat())
		return (f1);
	else
		return (f2);
}
const Fixed &Fixed::min( Fixed const &f1,  Fixed const &f2)
{
	if (f1.toFloat() < f2.toFloat())
		return (f1);
	else
		return (f2);	
}

/*
** --------------------------------- METHODS ----------------------------------
*/

float Fixed::toFloat(void) const
{
	return ((float)this->fixed_point / (float)(1 << this->fractional_bits));
}

int Fixed::toInt(void) const
{
	return (this->fixed_point >> this->fractional_bits);
}

int Fixed::getRawBits(void) const
{
	return (this->fixed_point);
}

void Fixed::setRawBits(int const raw)
{
	this->fixed_point = raw;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */