/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:48:21 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/05 01:19:47 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"


int	main()
{
	const Animal* i	= new Cat();
	const Animal* j	= new Dog();

	
	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	
	std::cout << std::endl;
	i->makeSound(); //will output the cat sound!
	j->makeSound();

	std::cout << std::endl;
	delete i;
	delete j;
	
	std::cout << std::endl;


	//Animal array test
	const Animal* meta[20];
	
	std::cout << std::endl;
	for (int i = 0; i < 20; i++) {
		
		if (i < 10)
			meta[i] = new Cat();
		else
			meta[i] = new Dog();
	}

	std::cout << std::endl;
	for (int i = 0; i < 20; i++) {
		
		delete meta[i];
	}
	
	return 0;
}