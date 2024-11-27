/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:58:02 by nbled             #+#    #+#             */
/*   Updated: 2023/09/01 15:24:45 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    int size;

    size = 5;
    Zombie* horde = zombieHorde(size, "Peon");
    if (horde == NULL)
        return 1;
    for (int i = 0; i < size; ++i)
        horde[i].announce();
    delete[] horde;

    return 0;
}
