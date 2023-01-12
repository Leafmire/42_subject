/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by gson              #+#    #+#             */
/*   Updated: 2022/07/30 21:19:35 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include <fstream>

class ShrubberyCreationForm : public Form
{

	public:

		ShrubberyCreationForm();
		ShrubberyCreationForm( std::string const &target );
		ShrubberyCreationForm( ShrubberyCreationForm const & src );
		~ShrubberyCreationForm();

		void execute(Bureaucrat const & executor) const;

		std::string getTarget() const;
		ShrubberyCreationForm &		operator=( ShrubberyCreationForm const & rhs );

	private:

		std::string target;

};

std::ostream &			operator<<( std::ostream & o, ShrubberyCreationForm const & i );

#endif /* ******************************************* SHRUBBERYCREATIONFORM_H */