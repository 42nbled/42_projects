/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:59:15 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 20:31:49 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

int main()
{
    std::string str = "HI THIS IS BRAIN";
    std::string *stringPTR = &str;
    std::string &stringREF = str;

    std::cout << "Adresse de la string en mémoire: " GRAY << &str << END << std::endl;
    std::cout << "Adresse stockée dans stringPTR: " GRAY << stringPTR << END << std::endl;
    std::cout << "Adresse stockée dans stringREF: " GRAY << &stringREF << END << std::endl << std::endl;

    std::cout << "Valeur de la string: " GRAY << str << END << std::endl;
    std::cout << "Valeur pointée par stringPTR: " GRAY << *stringPTR << END << std::endl;
    std::cout << "Valeur pointée par stringREF: " GRAY << stringREF << END << std::endl;

    return 0;
}
