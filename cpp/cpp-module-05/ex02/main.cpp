/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:34:49 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 19:04:35 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat alice("Alice", 1);
	Bureaucrat bruce("Bruce", 150);
	Bureaucrat crea("crea", 136);
	try
	{
		ShrubberyCreationForm home("home");
		std::cout << home << std::endl;
		bruce.signForm(home);
		crea.executeForm(home);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "----------------------" << std::endl;

	try
	{
		RobotomyRequestForm ky("ky");
		std::cout << ky << std::endl;
		alice.signForm(ky);
		alice.executeForm(ky);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << "----------------------" << std::endl;

	try
	{
		PresidentialPardonForm ford("ford");
		std::cout << ford << std::endl;
		alice.signForm(ford);
		alice.executeForm(ford);
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}