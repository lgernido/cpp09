/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:44:24 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/25 09:10:45 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RNP_HPP
#define RNP_HPP

/*****************************************************************************/
/*                                  INCLUDES                                 */
/*****************************************************************************/
#include <string>
#include <iostream>
#include <cctype>
#include <algorithm>
#include <cstdlib>
#include <stack>
#include <ctime>
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

class RPN 
{
    public :
        RPN();
        ~RPN();

        RPN(RPN const &src);
        RPN& operator=(const RPN& src);

        RPN(std::stack<double> numbers);

        void compute(std::string calculus);

    private :
        std::stack<double>numbers;
};

/*****************************************************************************/
/*                                  TEMPLATES                                */
/*****************************************************************************/


#endif