/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 15:04:49 by nbled             #+#    #+#             */
/*   Updated: 2023/09/02 15:09:58 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

class Harl
{
    public:
        Harl(void);
        void    complain(std::string level);

    private:
        std::string _keys[4];
        void        (Harl::*_fcts[4])(void);


        void    debug(void);
        void    info(void);
        void    warning(void);
        void    error(void);
};
