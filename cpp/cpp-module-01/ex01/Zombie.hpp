/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/17 00:09:33 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 19:35:10 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
# define ZOMBIE_HPP

# include <iostream>
# include <string>

class Zombie {
	private:
		std::string name;
	public:
		Zombie(void);
		~Zombie(void);

		Zombie(std::string name);
		void	set_name(std::string name);
		void	announce(void);
};

Zombie* zombieHorde( int N, std::string name );

#endif