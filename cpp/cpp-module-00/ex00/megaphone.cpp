/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:07:44 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 16:47:28 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    size_t i;
    size_t j;

    if (argc == 1)
    {
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *" << "\n";
    }
    else
    {
        i = 1;
        while (argv[i] != NULL)
        {
            std::string  str(argv[i]);
            j = 0;
            while (j < str.length())
            {
                std::cout << (char)std::toupper(str[j]);
                j++;
            }
            i++;
        }
        std::cout << "\n";
    }
    return (0);
}