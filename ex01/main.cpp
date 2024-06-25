/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:44:05 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/25 09:10:20 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        std::cout << RED BOLD "Invalid syntax : ./RPN calculus" RESET << std::endl;
        return (1);
    }
    else
    {
        std::string input = argv[1];
        RPN decoding;
        decoding.compute(input);
        return (0);
    }
}