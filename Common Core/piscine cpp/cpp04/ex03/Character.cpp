/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:00 by nbled             #+#    #+#             */
/*   Updated: 2023/11/23 16:13:41 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"

Character::Character()
{
    for (int i = 0; i < 4; i++)
        this->setMateria(i, NULL);
}

Character::Character(std::string name)
{
    _name = name;
    for (int i = 0; i < 4; i++)
        this->setMateria(i, NULL);
}

Character::Character(const Character& other)
{
    *this = other;
}

Character::~Character()
{
    for (int i = 0; i < 4; i++)
    {
        delete _inventory[i];
    }
}

Character& Character::operator=(const Character& other)
{
    _name = other._name;
    for (int i = 0; i < 4; i++)
    {
        AMateria *m = other.getMateria(i);
        _inventory[i] = (m->clone());
    }
    return *this;
}

// ---------------------------------------------------------
//                   SETTER / GETTER
// ---------------------------------------------------------

void Character::setName(std::string name)
{
    _name = name;
}

std::string const & Character::getName() const
{
    return(_name);
}

void Character::setMateria(int i, AMateria *m)
{
    if (i >= 0 && i <= 3)
        _inventory[i] = m;
}

AMateria* Character::getMateria(int i) const
{
    if (i < 0 || i > 3)
        return (NULL);
    return (_inventory[i]);
}

// ---------------------------------------------------------
//                      FUNCTION
// ---------------------------------------------------------

void Character::equip(AMateria *m)
{
    for (int i = 0; i < 4; i++)
        if (getMateria(i) == NULL)
        {
            _inventory[i] = m;
            return ;
        }
}

void Character::unequip(int i)
{
    setMateria(i, NULL);
}

void Character::use(int i, ICharacter& target)
{
    if (i >= 0 && i <= 3)
        if (getMateria(i))
            getMateria(i)->use(target);
}
