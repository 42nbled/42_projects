/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MateriaSource.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:11:55 by nbled             #+#    #+#             */
/*   Updated: 2023/11/21 18:07:52 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "iMateriaSource.hpp"

class MateriaSource : public IMateriaSource
{
    public:
        MateriaSource(void);
        MateriaSource(const MateriaSource & copy);
        ~MateriaSource(void);

        MateriaSource&      operator=(const MateriaSource & copy);

        void        setMateria(int i, AMateria *m);
        AMateria*   getMateria(int i) const;
        
        void        learnMateria(AMateria*);
        AMateria*   createMateria(std::string const & type);      
    private:
        AMateria    *_inventory[4];
};

#endif
 