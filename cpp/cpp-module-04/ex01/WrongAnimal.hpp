/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/27 19:58:21 by gson              #+#    #+#             */
/*   Updated: 2022/07/27 20:20:50 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

# include <iostream>
# include <string>

class WrongAnimal
{

	public:

		WrongAnimal();
		WrongAnimal( WrongAnimal const & src );
		virtual ~WrongAnimal();

		std::string getType() const ;
		void makeSound() const;

		WrongAnimal &		operator=( WrongAnimal const & rhs );

	protected:

		std::string type;

};

#endif /* ***************************************************** WRONGANIMAL_H */