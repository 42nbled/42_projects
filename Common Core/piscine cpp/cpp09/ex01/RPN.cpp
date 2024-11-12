/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:00 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:13:39 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN& RPN::operator=(const RPN& other)
{
    _stack = other._stack;
    return *this;
}

void	RPN::calculation(std::string str)
{
	for (size_t i = 0; i < str.size(); i++)
	{
		if (str[i] && ((str[i] == '-' && str[i + 1] && isdigit(str[i + 1])) || isdigit(str[i])))
		{
			if (str[i] && str[i] == '-')
				_stack.push((str[++i] - 48) * -1);
			else
				_stack.push(str[i] - 48);
		}
		else if (str[i] && str[i] == '+')
			addition();
		else if (str[i] && str[i] == '-')
			soustraction();
		else if (str[i] && str[i] == '*')
			multiplication();
		else if (str[i] && str[i] == '/')
			division();
		else if (str[i] && str[i] != ' ')
			throw RPN::bad_argument();
	}
	std::cout << _stack.top() << std::endl;
}

void RPN::addition()
{
	int	i;

	i = _stack.top();
	_stack.pop();
	i += _stack.top();
	_stack.pop();
	_stack.push(i);
}

void RPN::soustraction()
{
	int	i;

	i = _stack.top();
	_stack.pop();
	i = _stack.top() - i;
	_stack.pop();
	_stack.push(i);
}

void RPN::multiplication()
{
	int	i;

	i = _stack.top();
	_stack.pop();
	i *= _stack.top();
	_stack.pop();
	_stack.push(i);
}

void RPN::division()
{
	int	i;

	i = _stack.top();
	_stack.pop();
	if (i == 0)
		throw RPN::division_zero();
	i = _stack.top() / i;
	_stack.pop();
	_stack.push(i);
}
