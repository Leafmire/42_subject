/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:26:37 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 22:25:34 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_A_HPP
# define HUMAN_A_HPP

# include "Weapon.hpp"

class HumanA {
	private:
		std::string name;
		Weapon &weapon;
	public:
		HumanA(void);
		~HumanA(void);

		HumanA(std::string name, Weapon &weapon);
		void	setWeapon(Weapon &weapon);
		void	attack(void);
};

#endif