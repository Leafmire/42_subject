/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 20:22:52 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 22:12:46 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
# define BRAIN_HPP

# include <iostream>
# include <string>

class Brain
{

	public:

		Brain();
		Brain( Brain const & src );
		~Brain();

		std::string getIdea() const;
		void setIdea(std::string idea);

		Brain &		operator=( Brain const & rhs );

	private:

		std::string ideas[100];

};

#endif /* *********************************************************** BRAIN_H */