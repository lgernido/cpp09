/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 11:34:04 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/28 10:37:24 by lgernido         ###   ########.fr       */
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
            convertRate(line);
    }  
	inputFile.close();
	return ;
}

int BitcoinExchange::digitCheck(std::string line)
{
    for (size_t i = 0; i < line.size(); ++i)
    {
        if (!isdigit(line[i]))
        {
            return (1);
        }
    }
    return (0);
}

int BitcoinExchange::checkDates(std::string date)
{
    if (date.size() < 14 || date[4] != '-' || date[7] != '-')
    {
        std::cout << ORANGE BOLD << "Error: bad input => " << date << RESET << std::endl;
        return (1);
    }
    else
    {
        std::string year, month, day, btcNB;
        std::istringstream element(date);

        getline(element, year, '-');
        if (year.size() != 4 || digitCheck(year))
        {
            std::cout << ORANGE BOLD "Error: bad year input =>" << year << RESET << std::endl;
            return (1);
        }
        getline(element, month, '-');
        if(month.size() != 2 || (atoi(month.c_str())) < 1 || (atoi(month.c_str())) > 12 || digitCheck(month))
        {
            std::cout << ORANGE BOLD "Error: bad month input => " << month << RESET << std::endl;
            return (1);
        }
        getline(element, day, '|');
        if(day.size() != 3 || (atoi(day.c_str())) < 1 || (atoi(day.c_str())) > 31 || !isdigit(day[1]) || !isdigit(day[0]))
        {
            std::cout << ORANGE BOLD "Error: bad day input => " << day << RESET << std::endl;
            return (1);
        }
        getline(element, btcNB);
        if (atof(btcNB.c_str()) > 1000)
        {
            std::cout << ORANGE BOLD << "Error: too large number" RESET << std::endl;
            return (1);
        }
        else if (atof(btcNB.c_str()) < 0)
        {
            std::cout << ORANGE BOLD << "Error: not a positive number" RESET << std::endl;
            return(1);
        }
        if (!(atoi(year.c_str()) % 4 == 0 && atoi(year.c_str()) % 100 != 0) || atoi(year.c_str()) % 400 == 0)
        {
            if (atoi(month.c_str()) == 02 && atoi(day.c_str()) > 28)
            {
                std::cout << ORANGE BOLD << "Error: not a leap year" RESET << std::endl;
                return (1);
            }
        }
    }
    return 0; 
}

/*Finding correct rate to the date in database file*/

void BitcoinExchange::convertRate(std::string line)
{
    std::istringstream data(line);
    std::string date;
    std::string btcSTR;
    float btcNB;
    getline(data, date, '|');
    getline(data, btcSTR);

    btcNB = atof(btcSTR.c_str());
    
    std::map<std::string, float>::iterator rateIt = _btcMap.lower_bound(date);

    if (rateIt == _btcMap.end() || rateIt->first != date)
    {
        if (rateIt != _btcMap.begin())
        {
            rateIt--;
            float rate = rateIt->second;
            std::cout << date << " => " << btcNB << " = " << btcNB * rate << std::endl;
        }
        else
            std::cout << "ERROR" << std::endl;
    }
    else
    {
        float rate = rateIt->second; 
        std::cout << date << " => " << btcNB << " = " << btcNB * rate << std::endl;
    }
}

/*Utils*/

void BitcoinExchange::error(std::string message)
{
    std::cout << RED BOLD "Error: "<< message << RESET << std::endl;
    exit(1);
}