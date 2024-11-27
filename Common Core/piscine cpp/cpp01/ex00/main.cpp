/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:56:23 by nbled             #+#    #+#             */
/*   Updated: 2023/09/02 14:50:56 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main()
{
    Zombie* yes = newZombie("yes");
    yes->announce();
    Zombie maybe;
    maybe.announce();
    randomChump("no");
    delete yes;
    return 0;
}
