/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:05:34 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:08:01 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include "Animal.hpp"
#include "Brain.hpp"
#include <iostream>

class Dog : public Animal
{
    public:
        Dog();
        Dog(const Dog& other);
        ~Dog();

        Dog& operator=(const Dog& other);

        Brain* get_brain()const;

    private:
        Brain* brain;
};

#endif
