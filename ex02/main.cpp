/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luciegernidos <luciegernidos@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:52:11 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/27 18:22:23 by luciegernid      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"


int main(int argc, char **argv) 
{
    Merge merge;
    /*Parsing et innitialisation des deux containeur*/
    if (merge.parseInput(argc, argv) == 0) {
        merge.displayList();
        merge.displayVector();
    }
    merge.sortList();
    merge.sortVector();
    
    return 0;
}