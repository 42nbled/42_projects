/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:12:00 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:13:39 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"
#include <cstdlib>
#include <fstream>

BitcoinExchange::BitcoinExchange() {}
BitcoinExchange::BitcoinExchange(std::string input) {_input = input;}
BitcoinExchange::BitcoinExchange(const BitcoinExchange& other) {*this = other;}
BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& other)
{
    _input = other._input;
    return *this;
}

int	 BitcoinExchange::get_data()
{
	std::ifstream 	fd;
	std::string 	str;
	std::string 	date;
	float 			value;

	fd.open("data.csv");
	if (!fd.is_open())
	{
		std::cout << "Failed to open the file: data.csv" << std::endl;
		return 1;
	}
	std::getline(fd, str);
	while (std::getline(fd, str))
	{
		size_t pos = str.find(',');
		date = str.substr(0, pos);
		value = static_cast<float>(std::atof(str.substr(pos + 1).c_str()));
		_data.insert(std::make_pair(date, value));
	}
	return 0;
}

int	BitcoinExchange::btc(char **argv)
{
	const char* 	fd = argv[1];
	std::ifstream 	file(fd);
	std::string 	str;
	std::string 	date;
	float 			value;

	if (!file.is_open())
	{
		std::cout << "Failed to open the file: " << fd << std::endl;
		return 1;
	}
	std::getline(file, str);
	while (std::getline(file, str))
	{
		if (str.size() > 14 && is_valid(str))
		{
			size_t pos = str.find(' ');
			date = str.substr(0, pos);
			value = static_cast<float>(std::atof(str.substr(pos + 3).c_str()));
			if (value > 0 && value < 1001)
				find_value(date, value);
			else if (value > 1000)
				std::cout << "Error: too large a number." << std::endl;
		}
		else if (str.size() > 13 && str[13] == '-')
			std::cout << "Error: not a positive number" << std::endl;
		else if (str.size() > 1)
			std::cout << "Error: bad inputs => " << str << std::endl;
	}
	file.close();
	return 0;
}

int	BitcoinExchange::is_valid(std::string str)
{
	if (isdigit(str[0]) && isdigit(str[1]) && isdigit(str[2]) && isdigit(str[3]) && str[4] == '-'
		&& isdigit(str[5]) && isdigit(str[6]) && str[7] == '-' && isdigit(str[8]) && isdigit(str[9]))
	{
		for (int i = 13; str[i] && str[i + 1]; i++)
			if (!isdigit(str[i]) && str[i] != '.')
				return 0;
		return 1;
	}
	return 0;
}

void		BitcoinExchange::find_value(std::string date, float n)
{
	std::string								previous_date = date;
	std::map<std::string, float>::iterator	it = _data.find(date);
	while(it == _data.end() && date[0] == '2')
	{
		date = date_decrease(date);
		it = _data.find(date);
	}
	if (it != _data.end())
		std::cout << previous_date << " => " << n << " = " << it->second * n << std::endl;
	else if (date[0] != '2')
		std::cout << "Error: no data =>" << previous_date << std::endl;
}

std::string BitcoinExchange::date_decrease(std::string date)
{
	if (date[9] > '0')
		date[9]--;
	else if (date[9] == '0')
	{
		date[9] = '9';
		date[8]--;
	}
	if (date[8] == '0' && date[9] == '0')
	{
		date[9] = '1';
		date[8] = '3';
		if (date[6] > '0')
			date[6]--;
		else if (date[6] == '0')
		{
			date[6] = '6';
			date[5]--;
		}
		if (date[5] == '0' && date[6] == '0')
		{
			if (date[3] > '0')
				date[3]--;
			else if (date[3] == '0')
			{
				date[3] = '9';
				if (date[2] > '0')
					date[2]--;
				else if (date[2] == '0')
				{
					date[2] = '9';
					if (date[1] > '0')
						date[1]--;
					else if (date[1] == '0')
					{
						date[1] = '9';
						date[0]--;
					}
				}
			}
			date[6] = '2';
			date[5] = '1';
		}
	}
	return date;
}
