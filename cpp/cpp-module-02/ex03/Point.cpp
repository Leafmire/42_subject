/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Point.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/24 06:44:08 by gson              #+#    #+#             */
/*   Updated: 2022/07/24 06:54:52 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Point.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Point::Point() : x(0), y(0)
{
}

Point::Point( const float x, const float y) : x(x), y(y)
{
}

Point::Point( const Point & src ) : x(src.getX()), y(src.getY())
{
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Point::~Point()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Point &				Point::operator=( Point const & rhs )
{
	//if ( this != &rhs )
	//{
		//this->_value = rhs.getValue();
	//}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Point const & i )
{
	//o << "Value = " << i.getValue();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

const Fixed & Point::getX() const
{

}
const Fixed & Point::getY() const
{
	
}
/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */