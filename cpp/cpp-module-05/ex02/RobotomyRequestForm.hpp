/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 18:18:43 by gson              #+#    #+#             */
/*   Updated: 2022/07/30 19:18:06 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include <string>
# include "Form.hpp"
# include <ctime>
# include <cstdlib>

class RobotomyRequestForm : public Form
{

	public:

		RobotomyRequestForm();
		RobotomyRequestForm( std::string const &target );
		RobotomyRequestForm( RobotomyRequestForm const & src );
		~RobotomyRequestForm();

		void execute(Bureaucrat const & executor) const;

		std::string getTarget() const;
		RobotomyRequestForm &		operator=( RobotomyRequestForm const & rhs );

	private:

		std::string target;

};

std::ostream &			operator<<( std::ostream & o, RobotomyRequestForm const & i );

#endif /* ******************************************* ROBOTOMYREQUESTFORM_H */