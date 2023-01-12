/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/26 00:31:11 by gson              #+#    #+#             */
/*   Updated: 2022/07/26 00:38:43 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap spike("spike");
	ClapTrap mace(spike);
	mace.setName("mace");

	spike.setAttackDamage(9);
	spike.attack("mace");
	mace.takeDamage(spike.getAttackDamage());
	std::cout << "spike's energy point : "<< spike.getEnergyPoint() << std::endl;
	std::cout << "mace's hit point     : "<< mace.getHitPoint() << std::endl;
	mace.beRepaired(1);
	std::cout << "mace's hit point     : "<< mace.getHitPoint() << std::endl;
	mace.takeDamage(2);
	std::cout << "mace's hit point     : "<< mace.getHitPoint() << std::endl;
	mace.beRepaired(1);
	return (0);
}