/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:50:15 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 22:23:22 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMAN_B_HPP
# define HUMAN_B_HPP

# include "Weapon.hpp"

class HumanB {
	private:
		std::string name;
		Weapon *weapon;
	public:
		HumanB(void);
		~HumanB(void);

		HumanB(std::string name);
		void	setWeapon(Weapon &wepon);
		void	attack(void);
};

#endif