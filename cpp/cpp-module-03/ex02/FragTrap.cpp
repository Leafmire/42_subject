/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:54:20 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 02:05:46 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

FragTrap::FragTrap()
{
	ClapTrap::setHitPoint(100);
	ClapTrap::setEnergyPoint(100);
	ClapTrap::setAttackDamage(30);
	std::cout << "FragTrap [ NAME: guardian | HP: 100 | ENERGY: 100 | DAMAGE: 30 ] created!" << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name)
{
	ClapTrap::setHitPoint(100);
	ClapTrap::setEnergyPoint(100);
	ClapTrap::setAttackDamage(30);
	std::cout << "FragTrap [ NAME: " << name << " | HP: 100 | ENERGY: 100 | DAMAGE: 30 ] created!" << std::endl;
}

FragTrap::FragTrap( const FragTrap & src ) : ClapTrap( src )
{
	std::cout << "FragTrap [ NAME: " << src.getName() << " ] copied!" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

FragTrap::~FragTrap()
{
	std::cout << "FragTrap [ NAME: " << this->getName() << " ] is broken..." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

FragTrap &				FragTrap::operator=( FragTrap const & rhs )
{
	if ( this != &rhs )
	{
		ClapTrap::operator=(rhs);
	}
	return *this;
}

/*
** --------------------------------- METHODS ----------------------------------
*/

void FragTrap::highFivesGuys( void )
{
	if (this->getHitPoint() <= 0 || this->getEnergyPoint() <= 0)
	{
		blockBehavior(this->getName());
		return ;
	}
	std::cout << "FragTrap " << this->getName() << " is high fived." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */