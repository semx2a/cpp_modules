/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:48:21 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/04 23:34:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"


int	main()
{
	const Animal* 		meta 	= new Animal();
	const Animal* 		i 		= new Cat();
	const Animal* 		j 		= new Dog();

	std::cout << meta->getType() << std::endl;	
	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << k->getType() << std::endl;
	std::cout << l->getType() << std::endl;
	
	std::cout << std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();


	delete meta;
	delete i;
	delete j;

	return 0;
}