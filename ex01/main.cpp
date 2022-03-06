/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:09:01 by graja             #+#    #+#             */
/*   Updated: 2022/03/06 12:25:33 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <climits>
#include <cfloat>

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Input ERROR: wrong number of parameters" << std::endl;
		return (1);
	}
	std::string	input = argv[1];
	int			i;
	char			c;
	float			f;
	double			d;

	try
	{
		d = std::stod(input);
	}
	catch (std::invalid_argument &ia)
	{
		if (input.length() == 1)
		{
			std::cout << "Input is of type char, casting to double" << std::endl;
			d = static_cast<double>(input.front());
		}
		else
		{
			std::cout << "No Conversion possible !" << std::endl;
			return (1);
		}
	}
	std::cout << std::fixed << std::setprecision(15); 
	std::cout << "String conversion to double = " << d << std::endl;
	std::cout << std::setprecision(7); 
	f = static_cast<float>(d);
	std::cout << "Cast to float = " << f << std::endl;
	if (f && (f > INT_MAX || f < INT_MIN))
	{
		std::cout << "value is beyond Int_Min/Max converting to smaller value";
		std::cout << " is not possible without data loss" << std::endl;
		return (0);
	}
	try
	{
		i = std::stoi(input, 0, 0);
	}
	catch (std::invalid_argument &ia)
	{
		if (input.length() != 1)
		{
			std::cout << "Cast to int : not possible" << std::endl;
			std::cout << "Cast to char : not possible" << std::endl;
			return (0);
		}
	}
	i = static_cast<int>(d);
	std::cout << "Cast to int = " << i << std::endl;
	if (i && (i > CHAR_MAX || i < CHAR_MIN))
	{
		std::cout << "value is beyond Char_Min/Max converting to smaller value";
		std::cout << " is not possible without data loss" << std::endl;
		return (0);
	}
	c = static_cast<char>(i);
	if (isprint(c))
		std::cout << "Cast to char = " << c << std::endl;
	else
		std::cout << "Cast to char = is not printable" << std::endl;
	return (0);
}
