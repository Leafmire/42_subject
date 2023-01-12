/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:21:07 by gson              #+#    #+#             */
/*   Updated: 2022/07/30 19:21:08 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

RobotomyRequestForm::RobotomyRequestForm() : Form("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequest default constructor called" << std::endl;
	this->target = "no_target";
}

RobotomyRequestForm::RobotomyRequestForm( std::string const &target ) : Form("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequest default constructor called" << std::endl;
	this->target = target;
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm & src ) : Form("RobotomyRequest", 72, 45)
{
	std::cout << "RobotomyRequest copy constructor called" << std::endl;
	this->target = src.getTarget();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

RobotomyRequestForm::~RobotomyRequestForm()
{
	std::cout << "RobotomyRequestForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

RobotomyRequestForm &				RobotomyRequestForm::operator=( RobotomyRequestForm const & rhs )
{
	if ( this != &rhs )
	{
		std::cout << "you can't assign this form to another form." << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i )
{
	o << "RobotomyRequestForm target: " << i.getTarget() << " / is Signed: " << (i.getIsSigned() == 0 ? "No" : "Yes") << " / gradeToSign: " << i.getGradeToSign() << " / gradeToExecute: " << i.getGradeToExecute();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void RobotomyRequestForm::execute(Bureaucrat const & executor) const
{
	int executor_grade;

	executor_grade = executor.getGrade();
	if (this->getGradeToExecute() < executor_grade)
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw IsSignedFalse();

	srand(time(0));
	std::cout << "/* bzzzzzzzzzz... The high-pitched sound is heard from somewhere. */" << std::endl;
	if (rand() % 10 >= 5)
	{
		std::cout << this->target << " has been robotomized successfully!" << std::endl;
	}
	else
	{
		std::cout << this->target << " failed to robotomize..." << std::endl;
	}
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string RobotomyRequestForm::getTarget() const
{
	return (this->target);
}

/* ************************************************************************** */