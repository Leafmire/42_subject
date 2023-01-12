/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:09:01 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 19:38:54 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombies;
	int size;

	size = 5;
	zombies = zombieHorde(size, "zombie");
	for (int i = 0; i < size; i++)
	{
		zombies[i].announce();
	}
	delete[] zombies;
	return (0);
}