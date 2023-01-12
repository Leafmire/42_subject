/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:58:31 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 21:17:43 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

# include "Animal.hpp"
# include "Brain.hpp"

class Cat : public Animal
{

	public:

		Cat();
		Cat(Brain &brain);
		Cat( Cat const & src );
		~Cat();

		void makeSound() const;

		Cat &		operator=( Cat const & rhs );

	private:

		Brain *brain;

};

#endif /* ************************************************************* CAT_H */