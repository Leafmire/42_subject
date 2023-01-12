/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 01:54:20 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 02:04:15 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ScavTrap::ScavTrap()
{
	ClapTrap::setHitPoint(100);
	ClapTrap::setEnergyPoint(50);
	ClapTrap::setAttackDamage(20);
	std::cout << "ScavTrap [ NAME: guardian / HP: 100 / ENERGY: 50 / DAMAGE: 20 ] created!" << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name)
{
	ClapTrap::setHitPoint(100);
	ClapTrap::setEnergyPoint(50);
	ClapTrap::setAttackDamage(20);
	std::cout << "ScavTrap [ NAME: " << name << " / HP: 100 / ENERGY: 50 / DAMAGE: 20 ] created!" << std::endl;
}

ScavTrap::ScavTrap( const ScavTrap & src ) : ClapTrap( src )
{
	std::cout << "ScavTrap [ NAME: " << src.getName() << " ] copied!" << std::endl;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ScavTrap::~ScavTrap()
{
	std::cout << "ScavTrap [ NAME: " << this->getName() << " ] disappeared..." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ScavTrap &				ScavTrap::operator=( ScavTrap const & rhs )
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

void ScavTrap::attack(const std::string& target)
{
	if (this->getHitPoint() <= 0 || this->getEnergyPoint() <= 0)
	{
		blockBehavior(this->getName());
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " attacks " << target << " , causing " << this->getAttackDamage() << " points of damage!" << std::endl;
	this->setEnergyPoint(this->getEnergyPoint() - 1);
}

void ScavTrap::guardGate()
{
	if (this->getHitPoint() <= 0 || this->getEnergyPoint() <= 0)
	{
		blockBehavior(this->getName());
		return ;
	}
	std::cout << "ScavTrap " << this->getName() << " is now in Gate keeper mode." << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


/* ************************************************************************** */