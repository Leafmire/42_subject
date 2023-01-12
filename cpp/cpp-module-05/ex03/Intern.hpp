/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 21:43:07 by gson              #+#    #+#             */
/*   Updated: 2022/08/02 18:55:45 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class Intern
{

	public:

		Intern();
		Intern( Intern const & src );
		~Intern();

		Form * makeForm(std::string const & name, std::string const & targe);

		Intern &		operator=( Intern const & rhs );

		class FormNameNotExist;
	private:

};

class Intern::FormNameNotExist : public std::exception
{
	public :
		const char *what() const throw();
};

Form * makeShrubberyCreationForm( std::string const & target );
Form * makeRobotomyRequestForm( std::string const & target );
Form * makePresidentialPardonForm( std::string const & target );

#endif /* ********************************************************** INTERN_H */