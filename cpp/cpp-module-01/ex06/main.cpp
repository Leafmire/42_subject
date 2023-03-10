/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 03:12:14 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 19:22:59 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int main(int argc, char **argv)
{
	Harl k;

	if (argc < 2)
	{
		std::cout << "Error: argument" << "\n";
		return (1);
	}
	k.complain(argv[1]);
	return (0);
}