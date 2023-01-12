/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:21:07 by gson              #+#    #+#             */
/*   Updated: 2022/07/30 19:21:08 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

PresidentialPardonForm::PresidentialPardonForm() : Form("PresidentialPardon", 25, 5)
{
	std::cout << "PresidentialPardon default constructor called" << std::endl;
	this->target = "no_target";
}

PresidentialPardonForm::PresidentialPardonForm( std::string const &target ) : Form("PresidentialPardon", 25, 5)
{
	std::cout << "PresidentialPardon default constructor called" << std::endl;
	this->target = target;
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm & src ) : Form("PresidentialPardon", 25, 5)
{
	std::cout << "PresidentialPardon copy constructor called" << std::endl;
	this->target = src.getTarget();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

PresidentialPardonForm::~PresidentialPardonForm()
{
	std::cout << "PresidentialPardonForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

PresidentialPardonForm &				PresidentialPardonForm::operator=( PresidentialPardonForm const & rhs )
{
	if ( this != &rhs )
	{
		std::cout << "you can't assign this form to another form." << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i )
{
	o << "PresidentialPardonForm target: " << i.getTarget() << " / is Signed: " << (i.getIsSigned() == 0 ? "No" : "Yes") << " / gradeToSign: " << i.getGradeToSign() << " / gradeToExecute: " << i.getGradeToExecute();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void PresidentialPardonForm::execute(Bureaucrat const & executor) const
{
	int executor_grade;

	executor_grade = executor.getGrade();
	if (this->getGradeToExecute() < executor_grade)
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw IsSignedFalse();

	std::cout << this->target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string PresidentialPardonForm::getTarget() const
{
	return (this->target);
}

/* ************************************************************************** */