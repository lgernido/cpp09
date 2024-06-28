/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:31:35 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/28 10:20:11 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

/*****************************************************************************/
/*                                  INCLUDES                                 */
/*****************************************************************************/
#include <string>
#include <iostream>
#include <cctype>
#include <map>
#include <algorithm>
#include <cstdlib>
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

class BitcoinExchange
{
    public :
        BitcoinExchange();
        ~BitcoinExchange();

        BitcoinExchange(BitcoinExchange const &src);
        BitcoinExchange& operator=(const BitcoinExchange&src);

        BitcoinExchange(std::string _inputFile);
        
        void error(std::string message);
        void convertRate(std::string line);
        

    private :

        const std::string _inputFile;
        std::map<std::string, float>_btcMap;

        void readCSV();
        void parseFile();
        void initRates(std::string line);

        int checkDates(std::string date);
        int digitCheck(std::string line);

    
};
/*****************************************************************************/
/*                                  TEMPLATES                                */
/*****************************************************************************/



#endif