/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/31 16:32:17 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/05 12:07:27 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <iomanip>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include "../inc/Array.hpp"

template <class T>
void displayClassArray(T &arr) {
	
	std::stringstream s;
	
	s << std::setfill('-') << std::setw(50) << "-" << std::endl;
	s << arr << std::endl;

	std::cout << s.str();
}

#define MAX_VAL 750
#define MAX_VAL2 10.0f

int main(int, char**)
{
    Array<int> numbers(MAX_VAL);
    int* mirror = new int[MAX_VAL];
    
    srand(time(NULL));
    for (int i = 0; i < MAX_VAL; i++) {
        
        const int value = ((rand() % MAX_VAL) + 1);
        numbers[i] = value;
        mirror[i] = value;
    }
    
    {
        Array<int> tmp = numbers;
        Array<int> test(tmp);
    }
    
    for (int i = 0; i < MAX_VAL; i++) {
        
        if (mirror[i] != numbers[i]) {
            
            std::cerr << "didn't save the same value!!" << std::endl;
            return 1;
        }
    }
    
    try {
        numbers[-2] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Trying to access numbers[-2] : " << e.what() << '\n';
    }
    
    try {
        numbers[MAX_VAL] = 0;
    }
    catch(const std::exception& e) {
        std::cerr << "Trying to access numbers[MAX_VAL] : " << e.what() << '\n';
    }
    
    for (int i = 0; i < MAX_VAL; i++) {
        numbers[i] = ((rand() % MAX_VAL) + 1);
    }
    
    delete [] mirror;
    
    Array<float> floats(10);
    for (int i = 0; i < 10; i++) {
        floats[i] = static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) / MAX_VAL2);
    }
    displayClassArray(floats);

    Array<std::string> strings(5);
    strings[0] = "Lorem";
    strings[1] = "ipsum";
    strings[2] = "dolor";
    strings[3] = "sit";
    strings[4] = "amet";
    displayClassArray(strings);

    Array<int> empty;
    Array<int> alloc(42);
    empty = alloc;
    empty[41] = 42;
    displayClassArray(empty);
    
    return 0;
}