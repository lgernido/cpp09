/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PMergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 10:51:59 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/25 15:06:30 by lgernido         ###   ########.fr       */
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
    this->deque = src.deque;
    this->list = src.list;
    return (*this);
}

/*****************************************************************************/
/*                            PUBLIC METHODS                                 */
/*****************************************************************************/

void Merge::sortList()
{
    
}

void Merge::sortDeque()
{
    
}

std::deque<int> merge(const std::deque<int>& left, const std::deque<int>& right) {
    std::deque<int> result;
    std::deque<int>::const_iterator it_left = left.begin();
    std::deque<int>::const_iterator it_right = right.begin();

    while (it_left != left.end() && it_right != right.end()) 
    {
        if (*it_left <= *it_right) 
        {
            result.push_back(*it_left);
            ++it_left;
        } 
        else 
        {
            result.push_back(*it_right);
            ++it_right;
        }
    }

    while (it_left != left.end()) 
    {
        result.push_back(*it_left);
        ++it_left;
    }

    while (it_right != right.end()) 
    {
        result.push_back(*it_right);
        ++it_right;
    }

    return result;
}

std::deque<int> Merge::sortDeque(std::deque<int>& dq) 
{
    if (dq.size() <= 1) 
    {
        return dq;
    }

    std::deque<int>::iterator middle = dq.begin() + dq.size() / 2;

    std::deque<int> left(dq.begin(), middle);
    std::deque<int> right(middle, dq.end());

    left = mergeInsertionSort(left);
    right = mergeInsertionSort(right);

    return merge(left, right);
}

int Merge::parseInput(char **argv)
{
    for (int i = 0; i < argv.size(); i++)
    {
        if (!isdigit(argv[i]))
            return (1);
    }
    return (0);
}