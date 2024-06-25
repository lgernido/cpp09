/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lgernido <lgernido@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 15:44:16 by lgernido          #+#    #+#             */
/*   Updated: 2024/06/25 09:18:41 by lgernido         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

/*****************************************************************************/
/*                      CONSTRUCTORS & DESTRUCTOR                            */
/*****************************************************************************/

RPN::RPN(){};

RPN::~RPN(){};

RPN::RPN(RPN const &src)
{
    *this = src;
    return ;
}

RPN::RPN(std::stack<double>numbers) :  numbers(numbers){};

/*****************************************************************************/
/*                           ASSIGNEMENT OPERATOR                            */
/*****************************************************************************/

RPN& RPN::operator=(const RPN& src)
{
    this->numbers = src.numbers;
    return *this;
}

/*****************************************************************************/
/*                            PUBLIC METHODS                                 */
/*****************************************************************************/

void RPN::compute(std::string calculus)
{
    for (size_t i = 0; i < calculus.size(); i++)
    {
        char element = calculus[i];
        if (element == ' ')
            continue;
        else if (isdigit(element))
        {
            int nb = element - '0';
            numbers.push(nb);
        }
        else if (element == '+' && numbers.size() >= 2)
        {
            double first = numbers.top();
            numbers.pop();
            double second = numbers.top();
            numbers.pop();
            numbers.push(first + second);
        }
        else if (element == '-' && numbers.size()>= 2)
        {
            double first = numbers.top();
            numbers.pop();
            double second = numbers.top();
            numbers.pop();
            numbers.push(second - first);
        }
        else if (element == '*' && numbers.size() >= 2)
        {
            double first = numbers.top();
            numbers.pop();
            double second = numbers.top();
            numbers.pop();
            numbers.push(first * second);
        }
        else if (element == '/' && numbers.size() >= 2)
        {
            double first = numbers.top();
            numbers.pop();
            double second = numbers.top();
            numbers.pop();
            numbers.push(second / first);
        }
        else
        {
            std::cout << RED BOLD "Invalid input" RESET << std::endl;
            return;
        }
    }
    if (numbers.size() == 1)
    {
        double result = numbers.top();
        numbers.empty();
        std::cout << GREEN BOLD "Result : " << result << std::endl;
        return ;
    }
    else
    {
        std::cout << RED BOLD "Invalid input" RESET << std::endl;
        return ;
    }
}