/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:34:49 by gson              #+#    #+#             */
/*   Updated: 2022/07/30 01:52:32 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	Bureaucrat Alice("Alice", 1);
	Bureaucrat Bruce("Bruce", 2);

	std::cout << "----------------------" << std::endl;
	
	try
	{
		Bureaucrat Chen("Chen", 160);
		std::cout << Chen << std::endl;
	}
	catch (std::exception & e)
	{
		std::cerr << e.what() << " Grade will be setted up default value." << std::endl;
	}

	std::cout << "----------------------" << std::endl;

	try
	{
		Alice.increaseGrade();
		Bruce.decreaseGrade();
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "----------------------" << std::endl;

	Bruce.decreaseGrade();
	std::cout << Alice << std::endl;
	std::cout << Bruce << std::endl;

	return (0);
}