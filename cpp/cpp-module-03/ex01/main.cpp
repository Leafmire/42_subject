/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:31:11 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 16:33:03 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap spike("spike");
	ClapTrap *mace = new ScavTrap("mace");

	spike.attack("mace");
	mace->takeDamage(spike.getAttackDamage());
	mace->attack("spike");
	spike.takeDamage(mace->getAttackDamage());
	std::cout << "spike's energy point : "<< spike.getEnergyPoint() << std::endl;
	std::cout << "mace's hit point     : "<< mace->getHitPoint() << std::endl;
	mace->beRepaired(1);
	std::cout << "mace's hit point     : "<< mace->getHitPoint() << std::endl;
	mace->takeDamage(81);
	std::cout << "mace's hit point     : "<< mace->getHitPoint() << std::endl;
	mace->beRepaired(1);
	spike.guardGate();
	mace->guardGate();

	delete mace;
	return (0);
}