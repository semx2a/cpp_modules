/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:48:21 by seozcan           #+#    #+#             */
/*   Updated: 2024/02/08 16:43:04 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/AAnimal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"

#define RESET	"\033[m"
#define BHIGREEN	"\033[1;92m"
#define BHIORANGE	"\033[1;93m"
#define BHIPURPLE	"\033[1;95m"

int	main()
{
	const AAnimal* i	= new Cat();
	const AAnimal* j	= new Dog();

	std::cout << std::endl << BHIGREEN <<"Make sound tests:" << RESET << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();

	std::cout << std::endl;
	delete i;
	delete j;
	
	std::cout << std::endl << BHIORANGE << "Animal array containing dogs and cats:" << RESET << std::endl;
	//Animal array test
	const AAnimal* meta[20];
	
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

	//Deep copy test
	std::cout << std::endl << BHIPURPLE << "Deep copy tests" << RESET << std::endl;
	Dog basic;
	{
		Dog tmp = basic;
	}

	std::cout << std::endl;
	Cat puss;
	{
		Cat tmp1 = puss;
	}

	//AAnimal instanciation
	//const AAnimal* notGoingToWork = new AAnimal();
	
	return 0;
}