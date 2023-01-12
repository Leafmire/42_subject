/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:35:10 by gson              #+#    #+#             */
/*   Updated: 2022/08/04 20:41:36 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include <iostream>
# include <string>

class Bureaucrat
{

	public:

		Bureaucrat();
		Bureaucrat(std::string const & name, int grade);
		Bureaucrat( Bureaucrat const & src );
		~Bureaucrat();

		std::string getName() const;
		int getGrade() const;

		void increaseGrade();
		void decreaseGrade();

		class GradeTooLowException;
		class GradeTooHighException;

		Bureaucrat 		&operator=( Bureaucrat const & rhs );
	private:

		std::string const name;
		int grade;

};

std::ostream &			operator<<( std::ostream & o, Bureaucrat const & i );


class Bureaucrat::GradeTooLowException : public std::exception{
	public :
		const char *what() const throw();
};

class Bureaucrat::GradeTooHighException : public std::exception{
	public :
		const char *what() const throw();
};

#endif /* ****************************************************** BUREAUCRAT_H */