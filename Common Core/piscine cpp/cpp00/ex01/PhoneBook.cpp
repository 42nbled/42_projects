/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:48:19 by nbled             #+#    #+#             */
/*   Updated: 2023/08/30 16:05:59 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <iostream>
#include <string>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

void PhoneBook::addContact(int index)
{
    contact[index].inputContactInfo();
}

void PhoneBook::searchContacts()
{
    std::string index;

    std::cout << std::endl;
    std::cout << GRAY "+----------+----------+----------+----------+" END << std::endl;
    std::cout << GRAY "|" END;
    std::cout << "     INDEX" GRAY "|" END;
    std::cout << "FIRST_NAME" GRAY "|" END;
    std::cout << " LAST NAME" GRAY "|" END;
    std::cout << "  NICKNAME" GRAY "|" END << std::endl;
    std::cout << GRAY "+----------+----------+----------+----------+" END << std::endl;
    for (int i = 0; i < 8; i++)
        contact[i].displayContactInfo(i);
    std::cout << GRAY "+----------+----------+----------+----------+" END << std::endl << std::endl;
    while (true)
    {
        std::cout << "Select index: ";
        std::getline(std::cin, index);
        if (std::cin.eof())
			return ;
        if (index.size() == 1 && index[0] >= '0' && index[0] < '8')
        {
            contact[index[0] - 48].displayIndexInfo();
            break;
        }
        else
        {
            std::cout << "Invalid index. Please select a valid index." << std::endl;
        }
    }
}
