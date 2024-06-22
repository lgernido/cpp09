/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:34:16 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/22 12:55:59 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"


int main(int argc, char **argv)
{
    if (argc != 2)
        std::cout << "Error: could not open file" << std::endl;
    else
    {
        std::string input_file = argv[1];
        BitcoinExchange btc(input_file);
    }
}