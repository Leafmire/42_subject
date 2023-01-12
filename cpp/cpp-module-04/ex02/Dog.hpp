/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:58:23 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 22:35:07 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Dog : public Animal
{

	public:

		Dog();
		Dog( Brain &brain );
		Dog( Dog const & src );
		~Dog();

		void makeSound() const;
		Brain *getBrain(void) const;

		Dog &		operator=( Dog const & rhs );

	private:

		Brain *brain;

};

#endif /* ************************************************************* DOG_H */