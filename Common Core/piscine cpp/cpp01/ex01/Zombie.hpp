/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 14:58:14 by nbled             #+#    #+#             */
/*   Updated: 2023/08/31 16:21:31 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <string>

class Zombie 
{
    public:
        Zombie();
        Zombie(const std::string& newName);
        ~Zombie();
        
        void announce() const;
        void setName(const std::string& newName);

    private:
        std::string name;
};

Zombie* zombieHorde(int N, const std::string& name);

#endif
