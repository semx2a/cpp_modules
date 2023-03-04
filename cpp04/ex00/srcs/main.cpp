/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 18:48:21 by seozcan           #+#    #+#             */
/*   Updated: 2023/03/04 20:45:38 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include "../inc/Animal.hpp"
#include "../inc/Cat.hpp"
#include "../inc/Dog.hpp"
#include "../inc/WrongAnimal.hpp"
#include "../inc/WrongCat.hpp"

int	main()
{
	const Animal* 		meta 	= new Animal();
	const Animal* 		i 		= new Cat();
	const Animal* 		j 		= new Dog();
	const WrongAnimal*	k 		= new WrongAnimal();
	const WrongAnimal*	l 		= new WrongCat();

	std::cout << meta->getType() << std::endl;	
	std::cout << i->getType() << std::endl;
	std::cout << j->getType() << std::endl;
	std::cout << k->getType() << std::endl;
	std::cout << l->getType() << std::endl;
	
	std::cout << std::endl;
	meta->makeSound();
	i->makeSound(); //will output the cat sound!
	j->makeSound();
	k->makeSound();
	l->makeSound();

	delete meta;
	delete i;
	delete j;
	delete k;
	delete l;
	
	return 0;
}