/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:11:55 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:13:38 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <map>

class BitcoinExchange
{
    public:
        BitcoinExchange();
		BitcoinExchange(std::string input);
        BitcoinExchange(const BitcoinExchange& other);
        ~BitcoinExchange();

        BitcoinExchange& operator=(const BitcoinExchange& other);

		int			get_data(void);
		int			btc(char **argv);
		int			is_valid(std::string str);
		void		find_value(std::string date, float n);
		std::string	date_decrease(std::string date);

	private :
		std::string						_input;
		std::map<std::string, float>	_data;

};


#endif
