/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/28 17:35:10 by gson              #+#    #+#             */
/*   Updated: 2022/07/29 21:08:12 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include <iostream>
# include <string>
# include "Bureaucrat.hpp"

class Form
{

	public:

		Form();
		Form(std::string const name, const int grade_to_sign, const int grade_to_execute);
		Form( Form const & src );
		~Form();

		std::string getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		void beSigned(const class Bureaucrat &b);

		class GradeTooLowException;
		class GradeTooHighException;

		Form 		&operator=( Form const & rhs );
	private:

		std::string const name;
		bool is_signed;
		const int grade_to_sign;
		const int grade_to_execute;

};

std::ostream &			operator<<( std::ostream & o, Form const & i );


class Form::GradeTooLowException : public std::exception{
	public :
		const char *what() const throw();
};

class Form::GradeTooHighException : public std::exception{
	public :
		const char *what() const throw();
};

#endif /* ****************************************************** FORM_H */