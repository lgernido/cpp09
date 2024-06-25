/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:52:11 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/25 15:08:15 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

int main(int argc, char **argv)
{
    if (parseInput(argv) == 1)
    {
        std::cout << RED BOLD "Incorrect input" RESET << std::endl;
        return (1);
    }
    else
    {
        Merge sorting;
        sorting.sortDeque()
    }
}