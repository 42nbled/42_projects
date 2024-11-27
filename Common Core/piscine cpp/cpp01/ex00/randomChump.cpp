/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   randomChump.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:57:14 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 15:20:55 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"
#include <cstdlib>
#include <ctime>

void randomChump(const std::string& name)
{
    Zombie zombie(name);
    zombie.announce();
}
