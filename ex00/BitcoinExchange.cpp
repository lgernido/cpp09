/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:34:04 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/21 15:12:25 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

/*****************************************************************************/
/*                      CONSTRUCTORS & DESTRUCTOR                            */
/*****************************************************************************/

BitcoinExchange::BitcoinExchange(){}

BitcoinExchange::BitcoinExchange(BitcoinExchange const &src)
{
    *this = src;
    return;
}

BitcoinExchange::BitcoinExchange(std::string _inputFile) : _inputFile(_inputFile)
{
    /*Lire et parser le fichier*/
}

BitcoinExchange::~BitcoinExchange(){}

/*****************************************************************************/
/*                           ASSIGNEMENT OPERATOR                            */
/*****************************************************************************/

BitcoinExchange& BitcoinExchange::operator=(const BitcoinExchange& src)
{
    (void)src;
    return (*this);
}

/*****************************************************************************/
/*                            PUBLIC METHODS                                 */
/*****************************************************************************/

void BitcoinExchange::readCSV()
{
    std::ifstream database("data.csv");
    std::string line:

    if(database.fail())
        error("Opening the database file.");
    getline(database.line);
    while(!database.eof)
    {
        getline(database.line);
        initRates(line);
    }
    database.close()
}

void BitcoinExchange::initRates(std::string line)
{
    std::stringstream data(line);
    std::string date, rate;

    getline(data, date, ",");
    getline(data, rate);

    _btcMap[date] = atof(rate.c_str());
}

void BitcoinExchange::parseFile()
{
    std::ifstream	inputFile(_inputFile.c_str());
	std::string		line;

	if (inputFile.fail())
		error("Opening the input file.");
	getline(inputFile, line);
	if (line.compare("date | value") != 0)
		error("Invalid input format.");
	while (getline(inputFile, line))
		// compareDates(line);
	inputFile.close();
	return ;
}

void BitcoinExchange::error(std::string message)
{
    std::cout << RED BOLD "Error: "<< message << RESET << std::endl;
    exit(1);
}

int BitcoinExchange::checkDates(std::string date)
{
    if (date.size() != 10 || date[4] != '-' || date[7] != '-')
        error("Bad date format in the input file. Correct format should be YYYY-MM-DD.");
    std::string year, month, day;
    float quantity;
    std::stringstream element;
    
}