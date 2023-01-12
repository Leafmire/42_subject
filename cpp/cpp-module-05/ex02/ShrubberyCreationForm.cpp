/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 19:21:07 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 19:01:30 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

/*
** ------------------------------- CONSTRUCTOR --------------------------------
*/

ShrubberyCreationForm::ShrubberyCreationForm() : Form("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreation default constructor called" << std::endl;
	this->target = "no_target";
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string const &target ) : Form("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreation default constructor called" << std::endl;
	this->target = target;
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm & src ) : Form("ShrubberyCreation", 145, 137)
{
	std::cout << "ShrubberyCreation copy constructor called" << std::endl;
	this->target = src.getTarget();
}


/*
** -------------------------------- DESTRUCTOR --------------------------------
*/

ShrubberyCreationForm::~ShrubberyCreationForm()
{
	std::cout << "ShrubberyCreationForm destructor called" << std::endl;
}


/*
** --------------------------------- OVERLOAD ---------------------------------
*/

ShrubberyCreationForm &				ShrubberyCreationForm::operator=( ShrubberyCreationForm const & rhs )
{
	if ( this != &rhs )
	{
		std::cout << "you can't assign this form to another form." << std::endl;
	}
	return *this;
}

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i )
{
	o << "ShrubberyCreationForm target: " << i.getTarget() << " / is Signed: " << (i.getIsSigned() == 0 ? "No" : "Yes") << " / gradeToSign: " << i.getGradeToSign() << " / gradeToExecute: " << i.getGradeToExecute();
	return o;
}


/*
** --------------------------------- METHODS ----------------------------------
*/

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const
{
	int executor_grade;

	executor_grade = executor.getGrade();
	if (this->getGradeToExecute() < executor_grade)
		throw GradeTooLowException();
	if (this->getIsSigned() == false)
		throw IsSignedFalse();
	
	std::ofstream ofs;
	std::string out = this->getTarget() + "_shrubbery";
	ofs.open(out.c_str());
	std::string tree =  "         . . .\n"
            			"       .        .  .     ..    .\n"
            			"    .                 .         .  .\n"
            			"                    .\n"
            			"                   .                ..\n"
            			"   .          .            .              .\n"
            			"   .            '.,        .               .\n"
            			"   .              'b      *\n"
            			"    .              '$    #.                ..\n"
            			"   .    .           $:   #:               .\n"
            			" ..      .  ..      *#  @):        .   . .\n"
            			"              .     :@,@):   ,.**:'   .\n"
            			"  .      .,         :@@*: ..**'      .   .\n"
            			"           '#o.    .:(@'.@*''  .\n"
            			"   .  .       'bq,..:,@@*'   ,*      .  .\n"
            			"              ,p$q8,:@)'  .p*'      .\n"
            			"       .     '  . '@@Pp@@*'    .  .\n"
            			"        .  . ..    Y7'.'     .  .\n"
            			"                  :@):.\n"
            			"                 .:@:'.\n"
            			"               .::(@:.           -ASCII tree-";
	ofs << tree;
	ofs.close();
}

/*
** --------------------------------- ACCESSOR ---------------------------------
*/

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->target);
}

/* ************************************************************************** */