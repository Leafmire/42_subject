/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gson <gson@student.42seoul.kr>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 21:34:37 by gson              #+#    #+#             */
/*   Updated: 2022/07/19 03:05:51 by gson             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstring>
#include <fstream>

int check_args(int argc)
{
  if (argc != 4)
  {
    std::cout << "Error: argument" << "\n";
    return (1);
  }
  return (0);
}

int check_ifs(std::ifstream &ifs)
{
  if (ifs.fail())
  {
    std::cout << "Error: Cannot open file" << "\n";
    return (1);
  }
  return (0);
}

int check_ofs(std::ofstream &ofs, std::ifstream &ifs)
{
  if (ofs.fail())
  {
    std::cout << "Error: Cannot create file" << "\n";
    ifs.close();
    return (1);
  }
  return (0);
}

int main(int argc, char **argv)
{
  if (check_args(argc) == 1)
    return (1);

  std::string file = argv[1];
  std::ifstream ifs;
  ifs.open(file.c_str());

  if (check_ifs(ifs) == 1)
    return (1);

  std::ofstream ofs;
  std::string out = file + ".replace";
  ofs.open(out.c_str());

  if (check_ofs(ofs, ifs) == 1)
    return (1);

  std::string line;
  size_t  idx;
  while (std::getline(ifs, line))
  {
    idx = line.find(argv[2]);
    if (idx == std::string::npos)
      ofs << line;
    else
    {
      ofs << line.substr(0, idx) << argv[3];
      line = line.substr(idx + std::strlen(argv[2]));
      idx = line.find(argv[2]);
      while (idx != std::string::npos)
      {
        ofs << line.substr(0, idx) << argv[3];
        line = line.substr(idx + std::strlen(argv[2]));
        idx = line.find(argv[2]);
      }
      ofs << line;
    }
    ofs << "\n";
  }

  ifs.close();
  ofs.close();
  return (0);
}