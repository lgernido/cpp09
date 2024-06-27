/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:51:59 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/27 15:41:04 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PMergeMe.hpp"

/*****************************************************************************/
/*                      CONSTRUCTORS & DESTRUCTOR                            */
/*****************************************************************************/

Merge::Merge(){};

Merge::~Merge(){};

Merge::Merge(Merge const &src)
{
    *this = src;
}

/*****************************************************************************/
/*                           ASSIGNEMENT OPERATOR                            */
/*****************************************************************************/

Merge& Merge::operator=(const Merge& src)
{
    this->vector = src.vector;
    this->list = src.list;
    return (*this);
}

/*****************************************************************************/
/*                            PUBLIC METHODS                                 */
/*****************************************************************************/

void Merge::swap(unsigned int& a, unsigned int& b) 
{
    unsigned int tmp = a;
    a = b;
    b = tmp;
}

int Merge::parseInput(int argc, char **argv) 
{
    for (int i = 1; i < argc; ++i) 
    {
        for (char* p = argv[i]; *p != '\0'; ++p) 
        {
            if (!std::isdigit(*p)) 
            {
                std::cerr << RED BOLD "Invalid input: " << argv[i] << " is not a digit." RESET << std::endl;
                return -1;
            }
        }

        int value = std::atoi(argv[i]);
        if (value < 0) 
        {
            std::cerr << RED BOLD "Invalid input: " << argv[i] << " is not a valid unsigned integer." RESET << std::endl;
            return -1;  
        }
        list.push_back(static_cast<unsigned int>(value));
        vector.push_back(static_cast<unsigned int>(value));
    }
    return 0;  
}

void Merge::displayList() 
{
    std::cout << "Before: ";
    for (std::list<unsigned int>::const_iterator it = list.begin(); it != list.end(); ++it) 
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void Merge::displayVector() 
{
    std::cout << "Before (vector): ";
    for (std::vector<unsigned int>::const_iterator it = vector.begin(); it!=vector.end(); ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

void Merge::sortList() 
{
    int pairNumber = list.size() / 2;
    std::cout << "Number of pairs: " << pairNumber << std::endl;

    std::list<unsigned int>::const_iterator it = list.begin();
    std::list< std::pair<unsigned int, unsigned int> > pairs;


    while (it != list.end()) 
    {
        unsigned int first = *it;
        ++it;
        if (it != list.end()) 
        {
            unsigned int second = *it;
            pairs.push_back(std::make_pair(first, second));
            std::cout << "(" << first << ", " << second << ")" << std::endl;
            ++it;
        }
        else 
        {
            unsigned int second = 0;
            pairs.push_back(std::make_pair(first, second));
            std::cout << "(" << first << ", NULL)" << std::endl;
        }
    }
    std::list<std::pair<unsigned int, unsigned int> >::iterator pairIt;
    for (pairIt = pairs.begin(); pairIt != pairs.end(); ++pairIt) 
    {
        if (pairIt->first > pairIt->second) 
        {
            std::swap(pairIt->first, pairIt->second);
        }
    }
    list.clear();
    recursiveInit(pairs);
    displayList();
}

void Merge::sortVector() 
{
    int pairNumber = vector.size() / 2;
    std::cout << "Number of pairs: " << pairNumber << std::endl;

    std::vector<unsigned int>::const_iterator it = vector.begin();
    std::vector< std::pair<unsigned int, unsigned int> > pairs;
    
    while(it != vector.end())
    {
        unsigned int first = *it;
        ++it;
        if (it != vector.end())
        {
            unsigned int second = *it;
            pairs.push_back(std::make_pair(first, second));
            std::cout << "(" << first << ", " << second << ")" << std::endl;
            ++it;
        }
        else
        {
            unsigned int second = 0;
            pairs.push_back(std::make_pair(first, second));
            std::cout << "(" <<  first << ", NULL)" << std::endl; 
        }
    }
    for (size_t i = 0; i < pairs.size(); ++i) 
    {
        if (pairs[i].first > pairs[i].second) 
        {
            std::swap(pairs[i].first, pairs[i].second);
        }
    }
    vector.clear();
    recursiveInit(pairs);
    displayVector();
}

void Merge::recursiveInit(std::vector<std::pair<unsigned int, unsigned int> >& pair) 
{
    if (pair.empty()) 
    {
        return;
    }

    unsigned int valueToInsert = pair[0].second;
    bool inserted = false;

    for (size_t j = 0; j < vector.size(); ++j) 
    {
        if (vector[j] < valueToInsert && (j + 1 >= vector.size() || vector[j + 1] > valueToInsert)) 
        {
            vector.insert(vector.begin() + j + 1, valueToInsert);
            inserted = true;
            break;
        }
        else if (vector[j] > valueToInsert)
        {
            vector.insert(vector.begin(), valueToInsert);
            inserted = true;
            break;
        }
    }

    if (!inserted) 
    {
        vector.push_back(valueToInsert);
    }

    pair.erase(pair.begin());
    recursiveInit(pair); 
}

void Merge::recursiveInit(std::list<std::pair<unsigned int, unsigned int> >&pair)
{
   if (pair.empty())
   {
        return;
   }
    unsigned int valueToInsert = pair.front().second;
    bool inserted = false;

    for (std::list<unsigned int>::iterator it = list.begin(); it != list.end(); ++it) 
    {
        if (*it > valueToInsert) 
        {
            list.insert(it, valueToInsert);
            inserted = true;
            break;
        }
    }
    if (!inserted) 
    {
        list.push_back(valueToInsert);
    }

    pair.pop_front();
    recursiveInit(pair);
}

void Merge::vectorBS(std::vector<std::pair<unsigned int, unsigned int> > &pair)
{
    unsigned int valueToInsert = pair[0].first;
    bool inserted = false;
    int start = vector.begin();
    int end = vector.end();
    size_t size = vector.size() - 1;
    
    while (!inserted && start <= end)
    {
        size_t vectorHalf = vector.size() / 2;
        if (valueToInsert == vector[vectorHalf])
        {
            inserted = true;
        }
        else if (valueToInsert > vector[vectorHalf])
        {
            start = vectorHalf + 1;
        }
        else
        {
            end = vectorHalf - 1;
        } 
    }
    if (inserted == true)
    {
        vector.insert
    }
}