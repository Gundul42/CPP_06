/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:56:11 by graja             #+#    #+#             */
/*   Updated: 2022/03/06 15:11:11 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serials.hpp"

static
uintptr_t	*serialize(t_data *data)
{
	std::cout << std::endl << "now serializing" << std::endl << std::endl;
	return (reinterpret_cast<uintptr_t *>(data));
}

static
t_data		*deserialize(uintptr_t *data)
{
	std::cout << std::endl << "now deserializing" << std::endl << std::endl;
	return (reinterpret_cast<t_data *>(data));
}

static
void		printit(t_data	*data)
{
	std::cout << "------------------------------------------------" << std::endl;
	std::cout << data->name << " " << data->fname << std::endl;
	std::cout << data->street << " " << data->number << std::endl;
	std::cout << data->postcode << " " << data->city << std::endl;
	std::cout << "************************************************" << std::endl;
}

int main(void)
{
	t_data			*test = new t_data;
	uintptr_t	*hold;

	test->name = "Hubert";
	test->fname = "Mueller";
	test->street = "Hammelgasse";
	test->number = 123;
	test->postcode = 19228;
	test->city = "Bommelhausen";
	printit(test);
	hold = serialize(test);
	std::cout << "data pointer:" << test << std::endl;
	std::cout << "serial pointer:" << hold << std::endl;
	test = deserialize(hold);
	std::cout << "serial pointer:" << hold << std::endl;
	std::cout << "data pointer:" << test << std::endl;
	printit(test);
	delete test;
}
