/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:08:51 by gson              #+#    #+#             */
/*   Updated: 2022/07/18 21:57:14 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WEAPON_HPP
# define WEAPON_HPP

# include <iostream>
# include <string>

class Weapon {
	private:
		std::string type;
	public:
		Weapon(void);
		~Weapon(void);

		Weapon(std::string type);
		void	setType(std::string type);
		const std::string&	getType(void);
};

#endif