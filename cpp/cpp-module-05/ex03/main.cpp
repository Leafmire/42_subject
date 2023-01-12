/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:34:49 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 19:02:01 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	Bureaucrat alice("Alice", 1);
	Bureaucrat bruce("Bruce", 150);
	Intern new_intern;
    Form* rrf;
	try
	{
		rrf = new_intern.makeForm("presidential pardon", "Bender");
		std::cout << *rrf << std::endl;
		alice.signForm(*rrf);
		std::cout << *rrf << std::endl;
		alice.executeForm(*rrf);
		delete rrf;
	}
	catch(std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}