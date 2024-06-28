/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:52:11 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/28 10:38:44 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"


int main(int argc, char **argv) 
{
    Merge merge;
    if (merge.parseInput(argc, argv) == 0) 
    {
        merge.displayList();
        // merge.displayVector();
        merge.sortList();
        merge.sortVector();
    } 
    return 0;
}