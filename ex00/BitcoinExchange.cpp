/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:34:04 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/22 14:34:13 by lgernido         ###   ########.fr       */
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
    readCSV();
    parseFile();
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

/*Checking the database file and initializing the corresponging map container*/

void BitcoinExchange::readCSV()
{
    std::ifstream database("data.csv");
    std::string line;

    if(database.fail())
        error("Opening the database file.");
    getline(database, line);
    while(!database.eof())
    {
        getline(database, line);
        initRates(line);
    }
    database.close();
}

void BitcoinExchange::initRates(std::string line)
{
    std::istringstream data(line);
    std::string date, rate;

    getline(data, date, ',');
    getline(data, rate);

    _btcMap[date] = atof(rate.c_str());
}


/*Parsing the input file*/

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
    {
		if (checkDates(line) == 0)
            initInput(line);     
    }
    
	inputFile.close();
	return ;
}

int BitcoinExchange::checkDates(std::string date)
{
    if (date.size() < 14 || date[4] != '-' || date[7] != '-')
        std::cout << ORANGE BOLD << "Error: bad input => " << date << RESET << std::endl;
    else
    {
        std::string year, month, day, btcNB;
        std::istringstream element(date);

        getline(element, year, '-');
        if (year.size() != 4)
        {
            std::cout << ORANGE BOLD "Error: bad year input =>" << year << RESET << std::endl;
            return (1);
        }
        getline(element, month, '-');
        if(month.size() != 2 || static_cast<int>(atoi(month.c_str())) < 1 || static_cast<int>(atoi(month.c_str())) > 12)
        {
            std::cout << ORANGE BOLD "Error: bad month input => " << month << RESET << std::endl;
            return (1);
        }
        getline(element, day, '|');
        if(day.size() != 3 || static_cast<int>(atoi(day.c_str())) < 1 || static_cast<int>(atoi(day.c_str())) > 31)
        {
            std::cout << ORANGE BOLD "Error: bad day input => " << day << RESET << std::endl;
            return (1);
        }
        getline(element, btcNB);
        if (atof(btcNB.c_str()) > INT_MAX || atof(btcNB.c_str()) < INT_MIN)
        {
            std::cout << ORANGE BOLD << "Error: too large number" RESET << std::endl;
            return (1);
        }
    }
    return 0; 
}

void BitcoinExchange::initInput(std::string line)
{
    std::istringstream data(line);
    std::string date, rate;

    getline(data, date, '|');
    getline(data, rate);

    _inputMap[date] = atof(rate.c_str());
}

/*Finding correct rate to the date in database file*/



/*Utils*/

void BitcoinExchange::error(std::string message)
{
    std::cout << RED BOLD "Error: "<< message << RESET << std::endl;
    exit(1);
}