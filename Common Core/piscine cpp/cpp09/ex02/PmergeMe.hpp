/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/07 18:11:55 by nbled             #+#    #+#             */
/*   Updated: 2023/09/07 18:13:38 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <deque>
#include <ctime>

class PmergeMe
{
    public:
        PmergeMe() {};
        PmergeMe(const PmergeMe& other) {*this = other;};
        ~PmergeMe() {};

        PmergeMe& operator=(const PmergeMe& other);

		// +-------------------------------------------------+
		// |                    VECTOR                       |
		// +-------------------------------------------------+

		void	vector_init(int argc, char **argv);
		int		vector_is_sort(void);
		void	vector_sort(void);
		void	vector_swap(int a, int b);
		void	vector_swap_b(int a, int b);
		void	vector_print(void);

		// +-------------------------------------------------+
		// |                    DEQUE                        |
		// +-------------------------------------------------+

		void	deque_init(int argc, char **argv);
		int		deque_is_sort(void);
		void	deque_sort(void);
		void	deque_swap(int a, int b);
		void	deque_swap_b(int a, int b);
		void	deque_print(void);

		// +-------------------------------------------------+
		// |                  JACOBSTHAL                     |
		// +-------------------------------------------------+

		int		get_jacobsthal(int n);
		void	gen_v_jacobsthal(int lenght);
		void	gen_d_jacobsthal(int lenght);

		class bad_argument : std::exception
        {
            public:
                const char  *what(void) const throw()
                {
                    return ("Error: Bad argument");
                }
        };

	private :
		std::vector<int>	_vector;
		std::vector<int>	_vector_a;
		std::vector<int>	_vector_b;
		std::vector<int>	_v_jacobsthal;

		std::deque<int>	_deque;
		std::deque<int>	_deque_a;
		std::deque<int>	_deque_b;
		std::deque<int>	_d_jacobsthal;
};


#endif
