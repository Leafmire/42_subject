/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:50:13 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 22:26:07 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(void)
{

}

HumanB::~HumanB(void)
{
	
}

HumanB::HumanB(std::string name) : name(name), weapon(NULL)
{
	
}

void HumanB::setWeapon(Weapon &weapon)
{
	this->weapon = &weapon;
}

void HumanB::attack(void)
{
	std::cout << name << " attacks with his " << weapon->getType() << "\n";
}