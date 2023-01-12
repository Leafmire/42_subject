/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 02:17:19 by gson              #+#    #+#             */
/*   Updated: 2022/08/04 16:32:55 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

# include <iostream>
# include <string>

class Animal
{

	public:

		Animal();
		Animal( Animal const & src );
		virtual ~Animal();

		std::string getType() const ;
		void setType(std::string type);
		virtual void makeSound() const;

		Animal &		operator=( Animal const & rhs );

	protected:

		std::string type;

};

#endif /* ********************************************************** ANIMAL_H */