/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:04:56 by nbled             #+#    #+#             */
/*   Updated: 2023/09/01 15:41:23 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

void    Harl::debug(void)
{
    std::cout << GRAY << "[ DEBUG ]" << END << std::endl;
    std::cout << "I love to get extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. I just love it!" << std::endl;
}

void    Harl::info(void)
{
    std::cout << GRAY << "[ INFO ]" << END << std::endl;
    std::cout << "I cannot believe adding extra bacon cost more money. You don’t put enough! If you did I would not have to ask for it!" << std::endl;
}

void    Harl::warning(void)
{
    std::cout << GRAY << "[ WARNING ]" << END << std::endl;
    std::cout << "I think I deserve to have some extra bacon for free. I’ve been coming here for years and you just started working here last month." << std::endl;
}

void    Harl::error(void)
{
    std::cout << GRAY << "[ ERROR ]" << END << std::endl;
    std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}

Harl::Harl(void)
{
    this->_keys[0] = "DEBUG";
    this->_keys[1] = "INFO";
    this->_keys[2] = "WARNING";
    this->_keys[3] = "ERROR";

    this->_fcts[0] = &Harl::debug;
    this->_fcts[1] = &Harl::info;
    this->_fcts[2] = &Harl::warning;
    this->_fcts[3] = &Harl::error;
}

void    Harl::complain(std::string level)
{
    for (int i = 0; i < 4; i++)
    {
        if (this->_keys[i] == level)
        {
            (void)(this->*_fcts[i])();
            break ;
        }
    }
}
