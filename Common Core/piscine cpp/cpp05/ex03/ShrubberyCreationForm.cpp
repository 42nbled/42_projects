/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nbled <nbled@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:25:32 by nbled             #+#    #+#             */
/*   Updated: 2023/10/20 09:27:54 by nbled            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm()
    : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "-ShrubberyCreationForm default constructor called-" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target)
    : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
    std::cout << "-ShrubberyCreationForm constructor called-" << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm& other)
    : AForm("ShrubberyCreationForm", 145, 137), target(other.target)
{
    std::cout << "-ShrubberyCreationForm copy constructor called-" << std::endl;
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
    std::cout << "-ShrubberyCreationForm destructor called-" << std::endl;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& other)
{
    target = other.target;
    return *this;
}

void    ShrubberyCreationForm::action(void)const
{
    std::string folderPath = "";
    std::string fileName = "my_file.txt";
    std::string filePath = folderPath + fileName;
    std::ofstream outFile(filePath.c_str());
    if (outFile.is_open())
    {
        outFile << "                                                     .          \n";
        outFile << "                                          .         ;           \n";
        outFile << "             .              .              ;%     ;;            \n";
        outFile << "               ,           ,                :;%  %;             \n";
        outFile << "                :         ;                   :;%;'     .,      \n";
        outFile << "       ,.        %;     %;            ;        %;'    ,;        \n";
        outFile << "         ;       ;%;  %%;        ,     %;    ;%;    ,%'         \n";
        outFile << "          %;       %;%;      ,  ;       %;  ;%;   ,%;'          \n";
        outFile << "           ;%;      %;        ;%;        % ;%;  ,%;'            \n";
        outFile << "            `%;.     ;%;     %;'         `;%%;.%;'              \n";
        outFile << "             `:;%.    ;%%. %@;        %; ;@%;%'                 \n";
        outFile << "                `:%;.  :;bd%;          %;@%;'                   \n";
        outFile << "                  `@%:.  :;%.         ;@@%;'                    \n";
        outFile << "                    `@%.  `;@%.      ;@@%;                      \n";
        outFile << "                      `@%%. `@%%    ;@@%;                       \n";
        outFile << "                        ;@%. :@%%  %@@%;                        \n";
        outFile << "                          %@bd%%%bd%%:;                         \n";
        outFile << "                            #@%%%%%:;;                          \n";
        outFile << "                            %@@%%%::;                           \n";
        outFile << "                            %@@@%(o);  . '                      \n";
        outFile << "                            %@@@o%;:(.,'                        \n";
        outFile << "                        `.. %@@@o%::;                           \n";
        outFile << "                           `)@@@o%::;                           \n";
        outFile << "                            %@@(o)::;                           \n";
        outFile << "                           .%@@@@%::;                           \n";
        outFile << "                           ;%@@@@%::;.                          \n";
        outFile << "                          ;%@@@@%%:;;;.                         \n";
        outFile << "                      ...;%@@@@@%%:;;;;,..                      \n";
        outFile.close();
    }
    else
        std::cerr << "Failed to open the file for writing." << std::endl;
}
