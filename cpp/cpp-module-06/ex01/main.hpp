/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/06 18:42:10 by gson              #+#    #+#             */
/*   Updated: 2022/08/06 18:58:37 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_HPP
# define MAIN_HPP

# include <iostream>
# include <stdint.h>

struct Data
{
	char c;
	int i;
	float f;
	double d;
};

uintptr_t serialize(Data* ptr);
Data* deserialize(uintptr_t raw);

#endif