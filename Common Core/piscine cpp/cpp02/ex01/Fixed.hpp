/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/03 22:57:51 by nbled             #+#    #+#             */
/*   Updated: 2023/09/03 23:28:03 by nbled            ###   ########.fr       */
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
        Fixed(int i);
        Fixed(const float i);
        ~Fixed();

        void operator=(const Fixed & copy);

        int getRawBits(void)const;
        void setRawBits(int const raw);
        float toFloat( void ) const;
        int toInt( void ) const;

    private:
        int                 n;
        static const int    bits = 8;
};

std::ostream& operator<<(std::ostream & stream, const Fixed & fixed);

#endif
