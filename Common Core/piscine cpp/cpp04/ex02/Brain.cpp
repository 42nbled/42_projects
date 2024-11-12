/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:48 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:13:48 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain()
{
    std::cout << "-Brain is in-" << std::endl;
}

Brain::Brain(const Brain& other)
{
    std::cout << "-Brain copy is in-" << std::endl;
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
}

Brain::~Brain()
{
    std::cout << "-Brain is out-" << std::endl;
}

Brain& Brain::operator=(const Brain& other)
{
    for (int i = 0; i < 100; ++i)
        this->ideas[i] = other.ideas[i];
    return *this;
}

std::string Brain::get_idea(int n)const
{
    return(ideas[n]);
}

void    Brain::set_idea(std::string idea, int n)
{
    ideas[n] = idea;
}
