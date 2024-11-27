/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:58:48 by nbled             #+#    #+#             */
/*   Updated: 2023/09/01 15:23:57 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

Zombie* zombieHorde(int N, const std::string& name)
{
    if (N <= 0)
        return (NULL);
    Zombie* horde = new Zombie[N];
    if (horde == NULL)
        return (NULL);
    for (int i = 0; i < N; ++i)
        horde[i].setName(name);
    return horde;
}