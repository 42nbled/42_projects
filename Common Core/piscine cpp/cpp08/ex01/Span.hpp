/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:28 by nbled             #+#    #+#             */
/*   Updated: 2023/10/26 01:46:27 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <iostream>
#include <ctime>

class Span
{
    public:
        Span();
        Span(unsigned int n);
        Span(const Span& other);
        ~Span();

        Span& operator=(const Span& other);

        void			addNumber(int i);
		void			addRangeNumber(unsigned int n);
		void			print_vec(void);
        unsigned int	shortestSpan(void);
        unsigned int	longestSpan(void);

        class class_full : public std::exception
		{
            public:
                const char	*what() const throw()
                {
                    return ("Error: class full\n");
                }
        };

		class not_enough : public std::exception
		{
			public:
				const char	*what() const throw()
				{
					return ("Error: not enough variable\n");
				}
		};

    private:
        std::vector<int>	_vector;
		unsigned int		_n;
};

#endif
