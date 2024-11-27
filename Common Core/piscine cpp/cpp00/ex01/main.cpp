/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:47:45 by nbled             #+#    #+#             */
/*   Updated: 2023/08/30 15:52:26 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <limits>

#define GREEN_ARROW	"\033[1m\033[32m❱ \033[0m"

int main()
{
    PhoneBook phonebook;
    std::string str;
    int index;

    index = 0;
    str = "start";
    while (str != "EXIT")
    {
        std::cout << GREEN_ARROW;
        std::getline(std::cin, str);
        if (std::cin.eof())
			return 0;
        if (str == "ADD")
        {
            phonebook.addContact(index);
            index++;
            if (index == 8)
                index = 0;
        }
        else if (str == "SEARCH")
            phonebook.searchContacts();
    }
    return 0;
}
