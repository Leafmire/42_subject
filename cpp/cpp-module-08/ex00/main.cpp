/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 19:15:36 by gson              #+#    #+#             */
/*   Updated: 2022/08/08 19:50:54 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"

int	main(void)
{
	int	array[] = { 1, 2, 3, 4, 5 };
  	std::vector<int> num_vector(array, array + 4);
  	std::list<int>	empty_list;

	try
	{
		std::cout << easyfind(empty_list, 2) << std::endl;
	}
	catch( const std::exception &e )
	{ 
		std::cerr << e.what() << std::endl;
	}

  	try
	{
		std::cout << easyfind(num_vector, 4) << std::endl;
	}
	catch( const std::exception &e )
	{
		std::cerr << e.what() << std::endl;
	}

  	return (0);
}