/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:11:55 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:13:38 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <stack>

class RPN
{
    public:
        RPN() {};
        RPN(const RPN& other) {*this = other;};
        ~RPN() {};

        RPN& operator=(const RPN& other);

		void	calculation(std::string str);
		void	addition(void);
		void	soustraction(void);
		void	multiplication(void);
		void	division(void);

		class division_zero : std::exception
        {
            public:
                const char  *what(void) const throw()
                {
                    return ("Error: Division by zero");
                }
        };
		class bad_argument : std::exception
        {
            public:
                const char  *what(void) const throw()
                {
                    return ("Error: Bad argument");
                }
        };

	private :
		std::stack<int>	_stack;
};


#endif
