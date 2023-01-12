/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:31:16 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 16:34:10 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ClapTrap::ClapTrap() : name("guardian"), hit_p(10), energy_p(10), attack_d(0)
{
	std::cout << "ClapTrap [ NAME: guardian / HP: 10 / ENERGY: 10 / DAMAGE: 0 ] created!" << std::endl;
}

ClapTrap::ClapTrap(std::string name) : name(name), hit_p(10), energy_p(10), attack_d(0)
{
	std::cout << "ClapTrap [ NAME: " << name << " / HP: 10 / ENERGY: 10 / DAMAGE: 0 ] created!" << std::endl;
}

ClapTrap::ClapTrap( const ClapTrap & src )
{
	std::cout << "ClapTrap [ NAME: " << src.getName() << " ] copied!" << std::endl;
	*this = src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ClapTrap::~ClapTrap()
{
	std::cout << "ClapTrap [ NAME: " << this->name << " ] disappeared..." << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ClapTrap &				ClapTrap::operator=( ClapTrap const & rhs )
{
	if ( this != &rhs )
	{
		this->name = rhs.getName();
		this->hit_p = rhs.getHitPoint();
		this->energy_p = rhs.getEnergyPoint();
		this->attack_d = rhs.getAttackDamage();
	}
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ClapTrap::setName(std::string name)
{
	this->name = name;
}
void ClapTrap::setHitPoint(int hit_p)
{
	this->hit_p = hit_p;
}
void ClapTrap::setEnergyPoint(int energy_p)
{
	this->energy_p = energy_p;
}
void ClapTrap::setAttackDamage(int attack_d)
{
	this->attack_d = attack_d;
}

void ClapTrap::attack(const std::string& target)
{
	if (hit_p <= 0 || energy_p <= 0)
	{
		blockBehavior(this->name);
		return ;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << " , causing " << this->attack_d << " points of damage!" << std::endl;
	this->energy_p -= 1;
}
void ClapTrap::takeDamage(unsigned int amount)
{
	if (hit_p <= 0 || energy_p <= 0)
	{
		blockBehavior(this->name);
		return ;
	}
	std::cout << "ClapTrap " << this->name << " is damaged " << amount << " points of HP!" << std::endl;
	this->hit_p -= amount;
}
void ClapTrap::beRepaired(unsigned int amount)
{
	if (hit_p <= 0 || energy_p <= 0)
	{
		blockBehavior(this->name);
		return ;
	}
	std::cout << "ClapTrap " << this->name << " repaired " << amount << " points of HP!" << std::endl;
	this->hit_p += amount;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/


std::string ClapTrap::getName() const
{
	return (this->name);
}
int ClapTrap::getHitPoint() const
{
	return (this->hit_p);
}
int ClapTrap::getEnergyPoint() const
{
	return (this->energy_p);
}
int ClapTrap::getAttackDamage() const
{
	return (this->attack_d);
}

/*
** --------------------------------- OTHERS ----------------------------------
*/

void ClapTrap::blockBehavior(std::string name)
{
	std::cout << "ClapTrap " << name << " can't move " << std::endl;
}

void ClapTrap::guardGate()
{
}

/* ************************************************************************** */