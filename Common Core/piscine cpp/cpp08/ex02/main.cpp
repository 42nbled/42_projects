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

#include "MutantStack.hpp"
#include <list>

int main()
{
	std::cout << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << "|               SUBJECT STACK TEST               |" << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << std::endl;
	{
		MutantStack<int> mstack;
		mstack.push(5);
		mstack.push(17);
		std::cout << mstack.top() << std::endl;
		mstack.pop();
		std::cout << mstack.size() << std::endl;
		mstack.push(3);
		mstack.push(5);
		mstack.push(737);
		mstack.push(0);
		MutantStack<int>::iterator it = mstack.begin();
		MutantStack<int>::iterator ite = mstack.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::stack<int> s(mstack);
	}
	std::cout << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << "|               SUBJECT LIST TEST                |" << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << std::endl;
	{
		std::list<int> list;
		list.push_back(5);
		list.push_back(17);
		std::cout << list.back() << std::endl;
		list.pop_back();
		std::cout << list.size() << std::endl;
		list.push_back(3);
		list.push_back(5);
		list.push_back(737);
		list.push_back(0);
		std::list<int>::iterator it = list.begin();
		std::list<int>::iterator ite = list.end();
		++it;
		--it;
		while (it != ite)
		{
			std::cout << *it << std::endl;
			++it;
		}
		std::list<int> s(list);
	}
	std::cout << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << "|                   BONUS TEST                   |" << std::endl;
	std::cout << "+------------------------------------------------+" << std::endl;
	std::cout << std::endl;
	{
		MutantStack<float> fstack;
		fstack.push(1.0);
		fstack.push(1.2);
		fstack.push(1.4);
		fstack.push(1.6);
		fstack.push(1.8);

		std::cout << "from begin to end : ";
		MutantStack<float>::iterator it = fstack.begin();
		MutantStack<float>::iterator it2 = fstack.end();
		while (it != it2)
		{
			std::cout << "[" << *it << "] ";
			it++;
		}
		std::cout << std::endl;

		std::cout << "from end to begin : ";
		it2 = fstack.begin();
		while (it != it2)
		{
			it--;
			std::cout << "[" << *it << "] ";
		}
		std::cout << std::endl;
	}
	return (0);
}
