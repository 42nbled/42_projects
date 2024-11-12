/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:00 by nbled             #+#    #+#             */
/*   Updated: 2023/11/23 14:07:39 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "MateriaSource.hpp"

MateriaSource::MateriaSource()
{
    for (int i = 0; i < 4; i++)
        this->setMateria(i, NULL);
}

MateriaSource::MateriaSource(const MateriaSource& other)
{
    *this = other;
}

MateriaSource::~MateriaSource()
{
    for (int i = 0; i < 4; i++)
    {
        delete _inventory[i];
    }
}

MateriaSource& MateriaSource::operator=(const MateriaSource& other)
{
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

void        MateriaSource::setMateria(int i, AMateria *m)
{
    if (i >= 0 && i <= 3)
        _inventory[i] = m;
}

AMateria*   MateriaSource::getMateria(int i) const
{
    if (i < 0 || i > 3)
        return (NULL);
    return (_inventory[i]);
}

// ---------------------------------------------------------
//                      FUNCTION
// ---------------------------------------------------------

void        MateriaSource::learnMateria(AMateria* m)
{
    for (int i = 0; i < 4; i++)
        if (getMateria(i) == NULL)
        {
            _inventory[i] = m;
            return ;
        }
}
AMateria*   MateriaSource::createMateria(std::string const & type)
{
    for (int i = 0; i < 4; i++)
    {
        AMateria *m = this->getMateria(i);
        if (m != NULL && m->getType() == type)
            return (m->clone());
    }
    return (NULL);
}
