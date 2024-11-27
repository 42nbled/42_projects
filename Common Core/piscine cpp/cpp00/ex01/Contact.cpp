/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:48:01 by nbled             #+#    #+#             */
/*   Updated: 2023/11/15 11:33:50 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include <iostream>
#include <iomanip>
#include <cstdlib> 

# define GRAY "\x1b[37;1m"
#define END "\033[0m"

void Contact::inputContactInfo()
{
    std::string temp;

    std::cout << std::endl;
    do {
        std::cout << "    first name : " GRAY;
        if (!getline(std::cin, temp))
            exit(1);
    } while (temp.empty());
    first_name = temp;

    do {
        std::cout << END"     last name : " GRAY;
        if (!getline(std::cin, temp))
            exit(1);
    } while (temp.empty());
    last_name = temp; 

    do {
        std::cout << END"      nickname : " GRAY;
        if (!getline(std::cin, temp))
            exit(1);
    } while (temp.empty());
    nickname = temp;

    do {
        std::cout << END"  phone number : " GRAY;
        if (!getline(std::cin, temp))
            exit(1);
    } while (temp.empty());
    phone_number = temp;

    do {
        std::cout << END"darkest secret : " GRAY;
        if (!getline(std::cin, temp))
            exit(1);
    } while (temp.empty());
    darkest_secret = temp;
    std::cout << std::endl;
    std::cout << END;
}

void Contact::displayContactInfo(int index)
{
    std::cout << GRAY "|" END;
    std::cout << "         " << index;
    std::cout << GRAY "|" END;
    std::cout << std::setw(10) << ((first_name.size() > 10) ? std::string(first_name, 0, 9) + "." : first_name);
    std::cout << GRAY "|" END;
    std::cout << std::setw(10) << ((last_name.size() > 10) ? std::string(last_name, 0, 9) + "." : last_name);
    std::cout << GRAY "|" END;
    std::cout << std::setw(10) << ((nickname.size() > 10) ? std::string(nickname, 0, 9) + "." : nickname);
    std::cout << GRAY "|" END << std::endl;
}

void Contact::displayIndexInfo()
{
    std::cout << std::endl;
    if (!first_name.empty())
        std::cout << "    first name : " GRAY << first_name << END << std::endl;
    if (!last_name.empty())
        std::cout << "     last name : " GRAY << last_name << END << std::endl;
    if (!nickname.empty())
        std::cout << "      nickname : " GRAY << nickname << END << std::endl;
    if (!phone_number.empty())
        std::cout << "  phone number : " GRAY << phone_number << END << std::endl;
    if (!darkest_secret.empty())
        std::cout << "darkest secret : " GRAY << darkest_secret << END << std::endl;
    std::cout << std::endl;
}
