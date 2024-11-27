/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   megaphone.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/30 15:47:02 by nbled             #+#    #+#             */
/*   Updated: 2023/08/30 15:49:49 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(int argc, char **argv)
{
    if (argc > 1)
    {
       for (int i = 1; argv[i]; i++)
            for (int j = 0; argv[i][j]; j++)
                argv[i][j] = std::toupper(argv[i][j]);
        for (int i = 1; argv[i]; i++)  
            std::cout << argv[i];
    }
    else
        std::cout << "* LOUD AND UNBEARABLE FEEDBACK NOISE *";
    std::cout << std::endl;
    return (0);
}
