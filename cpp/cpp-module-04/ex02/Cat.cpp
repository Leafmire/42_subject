/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:58:28 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 22:06:31 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Cat::Cat()
{
	std::cout << "Cat class created." << std::endl;
	this->brain = new Brain;
	this->type = "Cat";
}

Cat::Cat(Brain &brain)
{
	std::cout << "Cat class created." << std::endl;
	this->type = "Cat";
	*this->brain = brain;
}

Cat::Cat( const Cat & src ) : Animal( src )
{
	std::cout << "Cat class copied." << std::endl;
	this->brain = new Brain(*(src.brain));
	this->type = "Cat";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Cat::~Cat()
{
	std::cout << "Cat class deleted." << std::endl;
	delete this->brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Cat &				Cat::operator=( Cat const & rhs )
{
	if ( this != &rhs )
	{
		this->type = rhs.getType();
		this->brain = new Brain(*(rhs.brain));
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void Cat::makeSound() const
{
	std::cout << "* Mew Mew *" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */