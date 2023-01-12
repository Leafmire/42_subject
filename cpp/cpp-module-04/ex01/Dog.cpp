/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:58:26 by gson              #+#    #+#             */
/*   Updated: 2022/08/04 16:27:31 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Dog::Dog()
{
	std::cout << "Dog class created." << std::endl;
	this->brain = new Brain();
	this->type = "Dog";
}

Dog::Dog(Brain &brain)
{
	std::cout << "Dog class created." << std::endl;
	this->type = "Dog";
	this->brain = new Brain(brain);
}

Dog::Dog( const Dog & src ) : Animal( src )
{
	std::cout << "Dog class copied." << std::endl;
	this->brain = new Brain(*(src.brain));
	this->type = "Dog";
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Dog::~Dog()
{
	std::cout << "Dog class deleted." << std::endl;
	delete this->brain;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Dog &				Dog::operator=( Dog const & rhs )
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

void Dog::makeSound() const
{
	std::cout << "* Bow-Wow *" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return (this->brain);
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */