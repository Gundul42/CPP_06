/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: graja <graja@student.42wolfsburg.de>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/06 13:56:11 by graja             #+#    #+#             */
/*   Updated: 2022/03/07 15:45:32 by graja            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Base.hpp"
#include <iostream>
#include <stdexcept>

static
Base	*generate(void)
{
	int	random;

	random = rand() % 3;
	if (!random)
	{
		std::cout << "Type A generated " << std::endl;
		return (new A);
	}
	else if (random == 1)
	{
		std::cout << "Type B generated " << std::endl;
		return (new B);
	}
	else
	{
		std::cout << "Type C generated " << std::endl;
		return (new C);
	}
}

static
void	identify(Base *ptr)
{
	std::cout << "Ptr is of type ";
	if (dynamic_cast<A *>(ptr))
	{
		std::cout << "A" << std::endl;
		return ;
	}
	if (dynamic_cast<B *>(ptr))
	{
		std::cout << "B" << std::endl;
		return ;
	}
	if (dynamic_cast<C *>(ptr))
	{
		std::cout << "C" << std::endl;
		return ;
	}
}

static
void	identify(Base & ref)
{
	try
	{
		dynamic_cast<A &>(ref);
		std::cout << "Reference is of type A" << std::endl;
		return ;
	}
	catch (std::bad_cast)
	{}
	try
	{
		dynamic_cast<B &>(ref);
		std::cout << "Reference is of type B" << std::endl;
		return ;
	}
	catch (std::bad_cast)
	{}
	try
	{
		dynamic_cast<C &>(ref);
		std::cout << "Reference is of type C" << std::endl;
		return ;
	}
	catch (std::bad_cast)
	{}
}

int main(void)
{
	Base	*rnd = NULL;
	int	i = 0;

	srand(time(NULL));
	while (i < 10)
	{
		rnd = generate();
		identify(rnd);
		identify(*rnd);
		std::cout << "---" << std::endl;
		delete rnd;
		i++;
	}
	return (0);
}
