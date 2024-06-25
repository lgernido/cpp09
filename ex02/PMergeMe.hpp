/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:51:32 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/25 15:08:35 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

/*****************************************************************************/
/*                                  INCLUDES                                 */
/*****************************************************************************/
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <list>
#include <deque>
#include <string>
#include <fstream>
#include <sstream>
#include <limits.h>

/*****************************************************************************/
/*                                  COLORS                                   */
/*****************************************************************************/

#define RED		"\033[0;31m"
#define GREEN	"\033[0;32m"
#define YELLOW	"\033[0;33m"
#define ORANGE "\033[38;5;208m"
#define BLUE	"\033[0;34m"
#define MAGENTA	"\033[0;35m"
#define CYAN	"\033[0;36m"
#define WHITE	"\033[0;37m"
#define BOLD       "\033[1m"
#define UNDERLINE  "\033[4m"
#define ITALIC     "\033[3m"
#define RESET      "\033[0m"


/*****************************************************************************/
/*                                  CLASS                                    */
/*****************************************************************************/

class Merge
{
    public :
        Merge();
        ~Merge();

        Merge(Merge const &src);
        Merge& operator=(const Merge& src);

        int parseInput(char **argv);

        void sortList();
        std::deque<int> sortDeque(std::deque<int>& dq);

    private :

        std::list<unsigned int>list;
        std::deque<unsigned int>deque;
}

/*****************************************************************************/
/*                                  TEMPLATES                                */
/*****************************************************************************/


#endif