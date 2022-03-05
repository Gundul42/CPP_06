/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 18:09:01 by graja             #+#    #+#             */
/*   Updated: 2022/03/05 14:50:04 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <stdexcept>
#include <iomanip>

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

	;
	try
	{
		d = std::stod(input);
	}
	catch (std::invalid_argument &ia)
	{
		std::cout << ia.what() << std::endl;
		std::cout << "d set to 0" << std::endl;
		d = 0.0;
	}
	f = static_cast<float>(d);
	std::cout << "String conversion to double = " << std::setprecision(2) << d << std::endl;
	std::cout << "Cast to float = " << f << std::endl;
	return (0);
}
