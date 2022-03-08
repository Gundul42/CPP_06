/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:09:01 by graja             #+#    #+#             */
/*   Updated: 2022/03/08 11:46:44 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>
#include <climits>

static
double	ft_makedoub(std::string input)
{
	double			d;

	try
	{
		d = std::stod(input);
	}
	catch (std::invalid_argument &ia)
	{
		if (input.length() == 1)
			d = static_cast<double>(input.front());
		else
		{
			std::cout << "No Conversion possible !" << std::endl;
			exit (1);
		}
	}
	catch (std::out_of_range &ooa)
	{
		std::cout << "Input is out of range of a double" << std::endl;
		exit (1);
	}
	return (d);
}

static
bool	ft_makeInt(float f, std::string input)
{
	if (f && (f > INT_MAX || f < INT_MIN))
	{
		std::cout << "char   : not possible" << std::endl;
		std::cout << "int    : not possible" << std::endl;
		return (false);
	}
	try
	{
		std::stoi(input, 0, 0);
	}
	catch (std::invalid_argument &ia)
	{
		if (input.length() != 1)
		{
			std::cout << "char   : not possible" << std::endl;
			std::cout << "int    : not possible" << std::endl;
			return (false);
		}
	}
	return (true);
}

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

	std::cout << std::fixed << std::setprecision(1);
	d = ft_makedoub(input);
	f = static_cast<float>(d);
	if (ft_makeInt(f, input))
	{
		c = static_cast<char>(d);
		i = static_cast<int>(d);
		if (i && (i > CHAR_MAX || i < CHAR_MIN))
			std::cout << "char   : not possible" << std::endl;
		else if (isprint(c))
			std::cout << "char   : " << c << std::endl;
		else if (!isprint(c))
			std::cout << "char   : is not printable" << std::endl;
		std::cout << "int    : " << i << std::endl;
	}
	std::cout << "float  : " << f << "f" << std::endl;
	//std::cout << "float  : " << std::stof(input) << std::endl;
	std::cout << "double : " << d << std::endl;
	return (0);
}
