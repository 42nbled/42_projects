/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:32 by nbled             #+#    #+#             */
/*   Updated: 2023/10/18 15:13:22 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"
#include <stdlib.h>
#include <ctype.h>
#include <limits.h>


void	ScalarConverter::convert(std::string str)
{
	if (!str.compare("+inff") || !str.compare("inff") || !str.compare("-inff")
		|| !str.compare("+inf") || !str.compare("inf") || !str.compare("-inf"))
		print_inf(str);
	else if (!str.compare("nanf") || !str.compare("nan"))
		print_nan();
	else
	{
		int type = get_type(str);
		char	_c;
		int		_i;
		float	_f;
		double	_d;

		if (type == 1)
			_c = static_cast<char>(str[0]);
		else if (type == 2)
			_i = atoi(str.c_str());
		else if (type == 3)
			_f = atof(str.c_str());
		else if (type == 4)
			_d = static_cast<double>(atof(str.c_str()));

		if (type == 1)
			print_char(_c);
		else if (type == 2)
			print_int(_i);
		else if (type == 3)
			print_float(_f);
		else if (type == 4)
			print_double(_d);
		else
			std::cout << "Error : impossible conversion" << std::endl;
	}
}

int		ScalarConverter::get_type(std::string str)
{
	if (is_int(str))
		return 2;
	if (is_float(str))
		return 3;
	if (is_double(str))
		return 4;
	if (is_char(str))
		return 1;
	return 0;
}

int		ScalarConverter::is_char(std::string str)
{
	if (str.size() == 1)
		return 1;
	return 0;
}

int		ScalarConverter::is_int(std::string str)
{
	int	i = 0;

	if (atol(str.c_str()) > INT_MAX || atol(str.c_str()) < INT_MIN)
        return 0;
	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (!isdigit(str[i]))
            return 0;
		i++;
	}
	return 1;
}

int		ScalarConverter::is_float(std::string str)
{
	int	i 		= 0;
	int	count	= 0;

	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == ',')
            count++;
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != ',')
		{
			if (str[i] == 'f' && !str[++i] && count == 1)
				return 1;
            return 0;
		}
		i++;
	}
	return 0;
}

int		ScalarConverter::is_double(std::string str)
{
	int	i 		= 0;
	int	count	= 0;

	if (str[i] && (str[i] == '+' || str[i] == '-'))
		i++;
	while (str[i])
	{
		if (str[i] == '.' || str[i] == ',')
            count++;
		if (!isdigit(str[i]) && str[i] != '.' && str[i] != ',')
            return 0;
		i++;
	}
	if (count == 1)
		return 1;
	return 0;
}

void	ScalarConverter::print_char(char _c)
{
	std::cout << "char : " << _c << std::endl;
	std::cout << "int: " << static_cast<int>(_c) << std::endl;
    std::cout << "float: " << static_cast<float>(_c) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(_c) << std::endl;
}

void	ScalarConverter::print_int(int _i)
{
	if (_i > 127 || _i < 0)
		std::cout << "char: impossible" << std::endl;
	else if (_i < 32 || (_i == 127))
		std::cout << "char: Non displayable" << std::endl;
	else
    	std::cout << "char: '" << static_cast<char>(_i) << "'" << std::endl;

	std::cout << "int: " << _i << std::endl;
	std::cout << "float: " << static_cast<float>(_i) << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(_i) << std::endl;
}

void	ScalarConverter::print_float(float _f)
{
		if (static_cast<int>(_f) > 127 || static_cast<int>(_f) < 0)
		std::cout << "char: impossible" << std::endl;
	else if (static_cast<int>(_f) < 32 || (static_cast<int>(_f) == 127))
		std::cout << "char: Non displayable" << std::endl;
	else
    	std::cout << "char: '" << static_cast<char>(_f) << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(_f) << std::endl;
	std::cout << "float: " << _f << "f" << std::endl;
    std::cout << "double: " << static_cast<double>(_f)  << std::endl;
}

void	ScalarConverter::print_double(double _d)
{
	if (static_cast<int>(_d) > 127 || static_cast<int>(_d) < 0)
		std::cout << "char: impossible" << std::endl;
	else if (static_cast<int>(_d) < 32 || (static_cast<int>(_d) == 127))
		std::cout << "char: Non displayable" << std::endl;
	else
    	std::cout << "char: '" << static_cast<char>(_d) << "'" << std::endl;

	std::cout << "int: " << static_cast<int>(_d) << std::endl;
	std::cout << "float: " << static_cast<float>(_d) << "f" << std::endl;
    std::cout << "double: " << _d << std::endl;
}

void	ScalarConverter::print_inf(std::string str)
{
	std::cout << "char: impossible " << std::endl;
	std::cout << "int: impossible" << std::endl;
	if (str[0] == '-')
	{
		std::cout << "float: -inff" << std::endl;
		std::cout << "double: -inf" << std::endl;
	}
	else
	{
		std::cout << "float: +inff" << std::endl;
		std::cout << "double: +inf" << std::endl;
	}
}

void	ScalarConverter::print_nan()
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: nanf" << std::endl;
	std::cout << "double: nan" << std::endl;
}
