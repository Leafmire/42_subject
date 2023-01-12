/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:35:06 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 18:52:00 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Bureaucrat::Bureaucrat() : name("Any"), grade(150)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string const name, int grade) : name(name), grade(grade)
{
	std::cout << "Bureaucrat default constructor called" << std::endl;
	if (this->grade > 150)
	{
		this->grade = 150;
		throw GradeTooLowException();
	}
	else if (this->grade < 1)
	{
		this->grade = 150;
		throw GradeTooHighException();
	}
}

Bureaucrat::Bureaucrat( const Bureaucrat & src ) : name(src.name), grade(src.grade)
{
	std::cout << "Bureaucrat copy constructor called" << std::endl;
	if (this->grade > 150)
	{
		this->grade = 150;
		throw GradeTooLowException();
	}
	else if (this->grade < 1)
	{
		this->grade = 150;
		throw GradeTooHighException();
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Bureaucrat::~Bureaucrat()
{
	std::cout << "Bureaucrat destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Bureaucrat &Bureaucrat::operator=( Bureaucrat const & rhs )
{
	std::cout << "you assign grade without name" << std::endl;
	if ( this != &rhs )
	{
		this->grade = rhs.getGrade();
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i )
{
	o << i.getName() << ", bureaucrat grade " << i.getGrade();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Bureaucrat::increaseGrade()
{
	if (this->grade == 1)
		throw GradeTooHighException();
	else
		this->grade--;
}

void Bureaucrat::decreaseGrade()
{
	if (this->grade == 150)
		throw GradeTooLowException();
	else
		this->grade++;
}

void Bureaucrat::signForm(Form &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << this->name << " signed " << form.getName() << " form." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn’t sign " << form.getName() << " form, because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(Form const & form)
{
	try
	{
		form.execute(*this);
		std::cout << this->name << " executed " << form.getName() << " form." << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->name << " couldn’t executed " << form.getName() << " form, because " << e.what() << std::endl;
	}	
}

const char * Bureaucrat::GradeTooLowException::what() const throw() 
{
	return "Grade is too Low.";
}

const char * Bureaucrat::GradeTooHighException::what() const throw() 
{
	return "Grade is too High.";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Bureaucrat::getName() const
{
	return (this->name);
}

int Bureaucrat::getGrade() const
{
	return (this->grade);
}


/* ************************************************************************** */