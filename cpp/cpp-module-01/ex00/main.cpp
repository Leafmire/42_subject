/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:09:01 by gson              #+#    #+#             */
/*   Updated: 2022/07/17 04:02:50 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int	main(void)
{
	Zombie *zombie1;
	
	zombie1 = newZombie("zombie1");
	randomChump("zombie2");
	zombie1->announce();

	delete zombie1;
	return (0);
}