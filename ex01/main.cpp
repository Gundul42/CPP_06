/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:56:11 by graja             #+#    #+#             */
/*   Updated: 2022/03/07 11:26:34 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "serials.hpp"

static
uintptr_t	serialize(t_data *data)
{
	std::cout << std::endl << "now serializing" << std::endl << std::endl;
	return (reinterpret_cast<uintptr_t >(data));
}

static
t_data		*deserialize(uintptr_t raw)
{
	std::cout << std::endl << "now deserializing" << std::endl << std::endl;
	return (reinterpret_cast<t_data *>(raw));
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
	t_data			*reint = NULL;
	uintptr_t	raw;

	test->name = "Hubert";
	test->fname = "Mueller";
	test->street = "Hammelgasse";
	test->number = 123;
	test->postcode = 19228;
	test->city = "Bommelhausen";
	printit(test);
	raw = serialize(test);
	std::cout << "Pointer Adress: " << test << std::endl;
	std::cout << "raw serialized: " << raw << std::endl;
	reint = deserialize(raw);
	std::cout << "New deserialized pointer Adress: " << reint << std::endl;
	std::cout << "Old original pointer Adress    : " << test << std::endl;
	std::cout << "Printout from new pointer:" << std::endl << std::endl;
	printit(reint);

	delete test;
}
