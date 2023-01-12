/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:43:05 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 18:57:10 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Intern::Intern()
{
}

Intern::Intern( const Intern & src )
{
	(void)src;
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Intern::~Intern()
{
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Intern &				Intern::operator=( Intern const & rhs )
{
	(void)rhs;
	return *this;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

Form * Intern::makeForm(std::string const & name, std::string const & target)
{
	std::string form_names[3];
	form_names[0] = "shrubbery creation";
	form_names[1] = "robotomy request";
	form_names[2] = "presidential pardon";

	Form * (*form_create_func[3])(std::string const & target);
	form_create_func[0] = &makeShrubberyCreationForm;
	form_create_func[1] = &makeRobotomyRequestForm;
	form_create_func[2] = &makePresidentialPardonForm;

	for (int i = 0; i < 3; i++)
	{
		if (name == form_names[i])
		{
			std::cout << "Intern creates " << form_names[i] << " form" << std::endl;
			return (form_create_func[i])(target);
		}
	}
	throw FormNameNotExist();
}

const char * Intern::FormNameNotExist::what() const throw()
{
	return "This form name does not exist.";
}


/*
** --------------------------------- ACCESSOR ---------------------------------
*/

Form * makeShrubberyCreationForm( std::string const & target )
{
	return (new ShrubberyCreationForm(target));
}

Form * makeRobotomyRequestForm( std::string const & target )
{
	return (new RobotomyRequestForm(target));
}

Form * makePresidentialPardonForm( std::string const & target )
{
	return (new PresidentialPardonForm(target));
}

/* ************************************************************************** */