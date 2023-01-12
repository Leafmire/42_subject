/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:15:39 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 18:40:28 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Convert.hpp"
#include <cstdlib>

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Convert::Convert()
{
	this->c = 0;
	this->i = 0;
	this->f = 0;
	this->d = 0;
}

Convert::Convert( const Convert & src )
{
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Convert::~Convert()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Convert &				Convert::operator=( Convert const & rhs )
{
	if ( this != &rhs )
	{
		this->c = rhs.c;
		this->i = rhs.i;
		this->f = rhs.f;
		this->d = rhs.d;
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/


void Convert::convertType(char* arg)
{
	std::string str(arg);

	if (str.length() == 1 && strtol(arg, NULL, 10) == 0 && str != "0")
	{
		char arg_char = arg[0];
		this->i = static_cast<int>(arg_char);
		this->c = static_cast<char>(i);
		this->f = static_cast<float>(i);
		this->d = static_cast<double>(i);
	}
	else
	{
		this->d = strtod(arg, NULL);
		this->c = static_cast<char>(d);
		this->i = static_cast<int>(d);
		this->f = static_cast<float>(d);
	}
}

bool Convert::myIsinf( float val )
{
    if ((*(int32_t *)(&val) & 0x7f800000) == 0x7f800000)
        return (true);
    if ((*(int32_t *)(&val) & 0xff800000) == 0xff800000)
        return (true);
    return (false);
}

bool Convert::myIsinf( double val )
{
    if ((*(int64_t *)(&val) & 0x7ff0000000000000) == 0x7ff0000000000000)
        return (true);
    if ((*(int64_t *)(&val) & 0xfff0000000000000) == 0xfff0000000000000)
        return (true);
    return (false);
}

bool Convert::checkDisplay() const
{
	if (this->i < 32 || this->i > 127)
		return (false);
	return (true);
}

bool Convert::checkIsNan() const
{
	if (this->d != this->d)
		return (true);
	return (false);
}

bool Convert::checkIsInf()
{
	if (myIsinf(this->d) && myIsinf(this->f))
		return (true);
	return (false);
}

bool Convert::checkIsInt() const
{
	if (std::floor(this->d) == this->d)
		return (true);
	return (false);
}

void Convert::printChar()
{
	if (this->checkIsNan() == true || this->checkIsInf() == true)
	{
		std::cout << "char: " << "impossible" << std::endl;
	}
	else
	{
		if (this->checkDisplay() == false)
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << this->getChar() << "'" << std::endl;
	}
}

void Convert::printInt()
{
	if (this->checkIsNan() == true || this->checkIsInf() == true || !(this->d >= INT_MIN && this->d <= INT_MAX))
	{
		std::cout << "int: " << "impossible" << std::endl;
	}
	else
	{
		std::cout << "int: " << this->getInt() << std::endl;
	}
}

void Convert::printFloat()
{
	if (this->checkIsNan() == true)
	{
		std::cout << "float: " << "nan" << "f" << std::endl;
	}
	else if (this->checkIsInf())
	{
		if (this->f < 0)
		{
			std::cout << "float: " << "-inf" << "f" << std::endl;
		}
		else
		{
			std::cout << "float: " << "+inf" << "f" << std::endl;
		}
	
	}
	else
	{
		if (this->checkIsInt() == true)
		{
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << "float: " << this->getFloat() << "f" << std::endl;
			std::cout.unsetf(std::ios::fixed);
		}
		else
		{
			std::cout << "float: " << this->getFloat() << "f" << std::endl;
		}
	}
}

void Convert::printDouble()
{
	if (this->checkIsNan() == true)
	{
		std::cout << "double: " << "nan" << std::endl;
	}
	else if (this->checkIsInf())
	{
		if (this->d < 0)
		{
			std::cout << "double: " << "-inf" << std::endl;
		}
		else
		{
			std::cout << "double: " << "+inf" << std::endl;
		}
	
	}
	else
	{
		if (this->checkIsInt() == true)
		{
			std::cout << std::fixed;
			std::cout.precision(1);
			std::cout << "double: " << this->getDouble() << std::endl;
			std::cout.unsetf(std::ios::fixed);
		}
		else
		{
			std::cout << "double: " << this->getDouble() << std::endl;
		}
	}
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

char Convert::getChar(void) const
{
	return (this->c);
}

int Convert::getInt(void) const
{
	return (this->i);
}

float Convert::getFloat(void) const
{
	return (this->f);
}

double Convert::getDouble(void) const
{
	return (this->d);
}


/* ************************************************************************** */