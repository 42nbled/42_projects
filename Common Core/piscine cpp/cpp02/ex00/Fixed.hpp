/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:57:03 by nbled             #+#    #+#             */
/*   Updated: 2023/09/03 23:31:42 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
    public:
        Fixed();
        Fixed(const Fixed & cpy);
        ~Fixed();

        void operator=(const Fixed & copy);

        int getRawBits(void)const;
        void setRawBits(int const raw);

    private:
        int                 n;
        static const int    bits = 8;
};

#endif
