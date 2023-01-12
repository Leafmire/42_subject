/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:35:06 by gson              #+#    #+#             */
/*   Updated: 2022/07/29 21:08:01 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

Form::Form() : name("Any"), is_signed(false), grade_to_sign(150), grade_to_execute(150)
{
	std::cout << "Form default constructor called" << std::endl;
}

Form::Form(std::string const name, const int grade_to_sign, const int grade_to_execute) : name(name), is_signed(false), grade_to_sign(grade_to_sign), grade_to_execute(grade_to_execute)
{
	std::cout << "Form default constructor called" << std::endl;
	if (grade_to_sign > 150 || grade_to_execute > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade_to_sign < 1 || grade_to_execute < 1)
	{
		throw GradeTooHighException();
	}
}

Form::Form( const Form & src ) : name(src.name), is_signed(src.is_signed), grade_to_sign(src.grade_to_sign), grade_to_execute(src.grade_to_execute)
{	
	std::cout << "Form copy constructor called" << std::endl;
	if (grade_to_sign > 150 || grade_to_execute > 150)
	{
		throw GradeTooLowException();
	}
	else if (grade_to_sign < 1 || grade_to_execute < 1)
	{
		throw GradeTooHighException();
	}
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

Form::~Form()
{
	std::cout << "Form destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

Form &Form::operator=( Form const & rhs )
{
	if ( this != &rhs )
	{
		std::cout << "you can't assign this form to another form." << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, Form const & i )
{
	o << "Form name: " << i.getName() << " / is Signed: " << (i.getIsSigned() == 0 ? "No" : "Yes") << " / gradeToSign: " << i.getGradeToSign() << " / gradeToExecute: " << i.getGradeToExecute();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void Form::beSigned(const Bureaucrat &b)
{
	int b_grade;

	b_grade = b.getGrade();
	if (this->grade_to_sign < b_grade)
		throw GradeTooLowException();
	this->is_signed = true;
}


const char * Form::GradeTooLowException::what() const throw()
{
	return "Grade is too Low.";
}

const char * Form::GradeTooHighException::what() const throw()
{
	return "Grade is too High.";
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string Form::getName() const
{
	return (this->name);
}

int Form::getGradeToSign() const
{
	return (this->grade_to_sign);
}

int Form::getGradeToExecute() const
{
	return (this->grade_to_execute);
}

bool Form::getIsSigned() const
{
	return (this->is_signed);
}

/* ************************************************************************** */