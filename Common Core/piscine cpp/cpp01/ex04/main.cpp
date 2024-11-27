/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:03:23 by nbled             #+#    #+#             */
/*   Updated: 2023/09/02 15:56:12 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <fstream>
#include <string>

std::string ft_replace(const std::string& line, const std::string& s1, const std::string& s2)
{
    std::string result;
    size_t pos = 0;
    size_t found = line.find(s1);

    while (found != std::string::npos)
    {
        result += line.substr(pos, found - pos) + s2;
        pos = found + s1.length();
        found = line.find(s1, pos);
    }
    result += line.substr(pos);
    
    return result;
}

int main(int argc, char** argv)
{
    if (argc != 4)
        return 1;
    std::string file = argv[1];
    std::string s1 = argv[2];
    std::string s2 = argv[3];
    std::ifstream File1(file.c_str());
    if (!File1.is_open())
        return 1;
    std::string File2name = file + ".replace";
    std::ofstream File2(File2name.c_str());
    if (!File2.is_open())
    {
        File1.close();
        return 1;
    }
    std::string line;
    while (std::getline(File1, line))
    {
        std::string replacedLine = ft_replace(line, s1, s2);
        File2 << replacedLine << std::endl;
    }
    File1.close();
    File2.close();
    
    return 0;
}
