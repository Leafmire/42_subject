/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:32:24 by gson              #+#    #+#             */
/*   Updated: 2022/07/28 16:17:24 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

const int Fixed::fractional_bits = 8;

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Fixed::Fixed() : fixed_point(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int num)
{
	std::cout << "Int constructor called" << std::endl;
	this->fixed_point = num << this->fractional_bits;
}

Fixed::Fixed(const float num)
{
	std::cout << "Float constructor called" << std::endl;
	this->fixed_point = roundf(num * (1 << this->fractional_bits));
}

Fixed::Fixed( const Fixed & src )
{
	std::cout << "Copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Fixed& Fixed::operator=( Fixed const & rhs )
{
	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
	{
		this->fixed_point = rhs.getRawBits();
	}
	return *this;
}

std::ostream& operator<<( std::ostream & o, Fixed const & i )
{
	o << i.toFloat();
	return (o);
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