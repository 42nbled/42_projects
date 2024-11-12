/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 02:19:10 by nbled             #+#    #+#             */
/*   Updated: 2023/10/20 09:37:03 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"
#include <iostream>
#include <stdint.h>

int    main()
{
	Data* data = new Data;
	data->str = "test";
	std::cout << "Data addr: " << &data << std::endl;
	std::cout << "Data str: " << data->str << std::endl;
	std::cout << std::endl;

	uintptr_t serialized = Serializer::serialize(data);
	std::cout << "serialized addr: " << &serialized << std::endl;
	std::cout << "serialized value: " << serialized << std::endl;
	std::cout << std::endl;

	Data *cpy = Serializer::deserialize(serialized);
	std::cout << "Deserialized data addr: " << cpy << std::endl;
	std::cout << "Deserialized data value: " << cpy->str << std::endl;
	std::cout << std::endl;

	delete data;
	return 0;
}
