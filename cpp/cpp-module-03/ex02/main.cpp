/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:31:11 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 17:51:41 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	ScavTrap spike("spike");
	FragTrap mace("mace");

	spike.attack("mace");
	mace.takeDamage(spike.getAttackDamage());
	std::cout << "spike's energy point : "<< spike.getEnergyPoint() << std::endl;
	std::cout << "mace's hit point     : "<< mace.getHitPoint() << std::endl;
	mace.beRepaired(1);
	std::cout << "mace's hit point     : "<< mace.getHitPoint() << std::endl;
	mace.takeDamage(80);
	std::cout << "mace's hit point     : "<< mace.getHitPoint() << std::endl;
	mace.beRepaired(1);
	spike.guardGate();
	mace.highFivesGuys();
	return (0);
}