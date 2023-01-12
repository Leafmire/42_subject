/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:22:54 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 22:25:18 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Brain::Brain()
{
	std::cout << "Brain constructor called" << std::endl;
}

Brain::Brain( const Brain & src )
{
	std::cout << "Brain copy constructor called" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Brain::~Brain()
{
	std::cout << "Brain destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Brain &				Brain::operator=( Brain const & rhs )
{
	for (size_t i = 0; i < 100; i++)
	{
		this->ideas[i] = rhs.ideas[i];
	}
	return (*this);
}

/*
** --------------------------------- METHODS ----------------------------------
*/


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Brain::getIdea() const
{
	return (this->ideas[0]);
}

void Brain::setIdea(std::string idea)
{
	this->ideas[0] = idea;
}

/* ************************************************************************** */