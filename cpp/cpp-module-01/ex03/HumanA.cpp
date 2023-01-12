/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:29:42 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 22:25:43 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanA.hpp"

HumanA::~HumanA(void)
{
	
}

HumanA::HumanA(std::string name, Weapon &weapon) : name(name), weapon(weapon)
{
	
}

void HumanA::setWeapon(Weapon &weapon)
{
	this->weapon = weapon;
}

void HumanA::attack(void)
{
	std::cout << this->name << " attacks with his " << this->weapon.getType() << "\n";
}