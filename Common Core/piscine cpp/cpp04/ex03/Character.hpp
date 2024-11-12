/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:11:55 by nbled             #+#    #+#             */
/*   Updated: 2023/11/20 16:34:16 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"

class Character : public ICharacter
{
    public:
        Character(void);
        Character(std::string name);
        Character(const Character & copy);
        ~Character(void);

        Character&          operator=(const Character & copy);

        void                setName(std::string name);
        std::string const & getName() const;
        void                setMateria(int i, AMateria *m);
        AMateria*           getMateria(int i) const;

        void                equip(AMateria *m);
        void                unequip(int i);
        void                use(int i, ICharacter& target);
        
    private:
        std::string    _name;
        AMateria    *_inventory[4];
};

#endif
 