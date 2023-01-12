/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by gson              #+#    #+#             */
/*   Updated: 2022/07/30 19:18:06 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"

class PresidentialPardonForm : public Form
{

	public:

		PresidentialPardonForm();
		PresidentialPardonForm( std::string const &target );
		PresidentialPardonForm( PresidentialPardonForm const & src );
		~PresidentialPardonForm();

		void execute(Bureaucrat const & executor) const;

		std::string getTarget() const;
		PresidentialPardonForm &		operator=( PresidentialPardonForm const & rhs );

	private:

		std::string target;

};

std::ostream &			operator<<( std::ostream & o, PresidentialPardonForm const & i );

#endif /* ******************************************* PRESIDENTIALPARDONFORM_H */