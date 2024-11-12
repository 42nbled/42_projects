/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:05:04 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:08:07 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

int main()
{
    std::cout << GRAY << std::endl;
    std::cout << "+------------------------------------------------------+" << std::endl;
    std::cout << "|                   MEMORY LEAK TEST                   |" << std::endl;
    std::cout << "+------------------------------------------------------+" << std::endl;
    std::cout << END << std::endl;
    {
        const Animal* j = new Dog();
        const Animal* i = new Cat();
        delete j;
        delete i;
    }
    std::cout << GRAY << std::endl;
    std::cout << "+------------------------------------------------------+" << std::endl;
    std::cout << "|                   ALLOC LIST TEST                    |" << std::endl;
    std::cout << "+------------------------------------------------------+" << std::endl;
    std::cout << END << std::endl;
    {
        int n = 4;
        Animal *array[n];
        for (int i = 0; i < n / 2; i++)
            array[i] = new Dog();
        for (int i = n / 2; i < n; i++)
            array[i] = new Cat();
        std::cout << std::endl;
        for (int i = 0; i < n; i++)
            delete(array[i]);
    }
    std::cout << GRAY << std::endl;
    std::cout << "+------------------------------------------------------+" << std::endl;
    std::cout << "|                   BRAIN COPY TEST                    |" << std::endl;
    std::cout << "+------------------------------------------------------+" << std::endl;
    std::cout << END << std::endl;
    {
        Dog dog1;
        Brain* brain1 = dog1.get_brain();
        brain1->set_idea("woof", 0);
        Dog dog2 = dog1;
        Brain* brain2 = dog2.get_brain();
        std::cout << std::endl;
        std::cout << GRAY << "\tdog1 idea[0] = " << brain1->get_idea(0) << END << std::endl;
        std::cout << GRAY << "\tdog2 idea[0] = " << brain2->get_idea(0) << END << std::endl;
        brain1->set_idea("woof", 1);
        std::cout << GRAY << "\tdog1 idea[1] = " << brain1->get_idea(1) << END << std::endl;
        std::cout << GRAY << "\tdog2 idea[1] = " << brain2->get_idea(1) << END << std::endl;
        std::cout << std::endl;
    }

    return 0;
}
