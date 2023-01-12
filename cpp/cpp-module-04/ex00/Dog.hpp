/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:58:23 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 19:58:24 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"

class Dog : public Animal
{

	public:

		Dog();
		Dog( Dog const & src );
		~Dog();

		void makeSound() const;

		Dog &		operator=( Dog const & rhs );

	private:

};

#endif /* ************************************************************* DOG_H */