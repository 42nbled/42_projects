/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 17:57:46 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:02:20 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"
#include <iostream>

int main()
{
    const Animal* meta = new Animal();
    const Animal* d = new Dog();
    const Animal* c = new Cat();
    const WrongAnimal* Wrongmeta = new WrongAnimal();
    const WrongAnimal* WrongC = new WrongCat();
    std::cout << std::endl;

    std::cout << meta->getType() << " " << std::endl;
    std::cout << d->getType() << " " << std::endl;
    std::cout << c->getType() << " " << std::endl;
    std::cout << Wrongmeta->getType() << " " << std::endl;
    std::cout << WrongC->getType() << " " << std::endl;
    std::cout << std::endl;

    meta->makeSound();
    d->makeSound();
    c->makeSound();
    Wrongmeta->makeSound();
    WrongC->makeSound();
    std::cout << std::endl;

    delete(meta);
    delete(d);
    delete(c);
    delete(Wrongmeta);
    delete(WrongC);

    return 0;
}
