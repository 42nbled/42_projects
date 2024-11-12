/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:11:32 by nbled             #+#    #+#             */
/*   Updated: 2023/11/22 13:34:25 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "Cure.hpp"
#include "Ice.hpp"
#include "Character.hpp"
#include "MateriaSource.hpp"
#include <iostream>

#define GRAY "\x1b[37;1m"
#define END "\033[0m"

int main()
{
    std::cout << GRAY << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "|                   CURE TEST                     |" << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << END << std::endl;
    {
        const AMateria* test = new Cure();
        const AMateria* clone = test->clone();
        std::cout << test->getType() << std::endl;
        std::cout << clone->getType() << std::endl;
        delete test;
        delete clone;
    }
    std::cout << GRAY << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "|                   ICE TEST                      |" << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << END << std::endl;
    {
        const AMateria* test = new Ice();
        const AMateria* clone = test->clone();
        std::cout << test->getType() << std::endl;
        std::cout << clone->getType() << std::endl;
        delete test;
        delete clone;
    }
    std::cout << GRAY << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "|                  CHARACTER TEST                 |" << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << END << std::endl;
    {
        ICharacter* bob = new Character("bob");
        AMateria* cure = new Cure();
        AMateria* ice = new Ice();
        
        bob->equip(cure);
        bob->equip(ice);

        std::cout <<  std::endl;
        bob->use(0, *bob);
        bob->use(1, *bob);
        bob->use(2, *bob);
        bob->use(3, *bob);
        bob->use(4, *bob);
        std::cout <<  std::endl;
        
        bob->unequip(0);
        bob->unequip(1);

        delete cure;
        delete ice;
        delete bob;
    }
    std::cout << GRAY << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << "|                   SUBJECT TEST                  |" << std::endl;
    std::cout << "+-------------------------------------------------+" << std::endl;
    std::cout << END << std::endl;
    {
        IMateriaSource* src = new MateriaSource();
        src->learnMateria(new Ice());
        src->learnMateria(new Cure());
        ICharacter* me = new Character("me");
        AMateria* tmp;
        tmp = src->createMateria("ice");
        me->equip(tmp);
        tmp = src->createMateria("cure");
        me->equip(tmp);
        ICharacter* bob = new Character("bob");
        me->use(0, *bob);
        me->use(1, *bob);
        delete bob;
        delete me;
        delete src;
    }

    return 0;
}
