/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:28 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 15:13:25 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    public:
        static void	convert(std::string str);
		static int	get_type(std::string str);

		static int is_char(std::string str);
		static int is_int(std::string str);
		static int is_float(std::string str);
		static int is_double(std::string str);

		static void	print_char(char _c);
		static void	print_int(int _i);
		static void	print_float(float _f);
		static void	print_double(double _d);
		static void	print_inf(std::string str);
		static void	print_nan(void);
};

#endif
