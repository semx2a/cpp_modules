/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/05 17:35:38 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/06 13:49:33 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <string>
#include <list>

#include "../inc/MutantStack.hpp"

template<typename T>
void displayHeader(std::string msg, T const &type) {
	
	if (type)
		std::cout << msg << type << std::endl;
	else 
		std::cout << msg << std::endl;
	std::cout << "================" << std::endl;
}

template<typename T>
void displaySubheader(std::string msg, T const &type) {
	
	if (type)
		std::cout << msg << type << std::endl;
	else 
		std::cout << msg << std::endl;
	std::cout << "----------------" << std::endl;
}

int main()
{

	displayHeader("mstack tests: ", NULL);
	MutantStack<int> mstack;
	
	displaySubheader("performing push: 17", NULL);
	mstack.push(17);
	displaySubheader("performing push: 5", NULL);
	mstack.push(5);
	
	displaySubheader("top of the stack: ", mstack.top());

	displaySubheader("performing pop ", NULL);
	mstack.pop();
	
	displaySubheader("size of the stack: ", mstack.size());
	
	displaySubheader("performing push: 3", NULL);
	mstack.push(3);
	displaySubheader("performing push: 5", NULL);
	mstack.push(5);
	displaySubheader("performing push: 737", NULL);
	mstack.push(737);
	displaySubheader("performing push: 0", NULL);
	mstack.push(0);

	
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	
	displaySubheader("size of the stack mstack: ", mstack.size());
	
	displaySubheader("content of the stack mstack: ", NULL);
	size_t i = 0;
	while (it != ite) {
		std::cout << "mstack[" << i << "] = " << *it << std::endl;
		i++;
		it++;
	}

	std::cout << std::endl;

	displayHeader("lstack tests: ", NULL);
	std::list<int> lstack;
	
	displaySubheader("performing push back: 17", NULL);
	lstack.push_back(17);
	displaySubheader("performing push back: 5", NULL);
	lstack.push_back(5);
	
	displaySubheader("top of the stack: ", lstack.back());

	displaySubheader("performing pop back", NULL);
	lstack.pop_back();
	
	displaySubheader("size of the stack: ", mstack.size());
	
	displaySubheader("performing push back: 3", NULL);
	lstack.push_back(3);
	displaySubheader("performing push back: 5", NULL);
	lstack.push_back(5);
	displaySubheader("performing push back: 737", NULL);
	lstack.push_back(737);
	displaySubheader("performing push back: 0", NULL);
	lstack.push_back(0);

	
	std::list<int>::iterator itl = lstack.begin();
	std::list<int>::iterator itel = lstack.end();
	++itl;
	--itl;
	
	displaySubheader("size of the stack lstack: ", mstack.size());
	
	displaySubheader("content of the stack lstack: ", NULL);
	size_t j = 0;
	while (itl != itel) {
		std::cout << "mstack[" << j << "] = " << *itl << std::endl;
		j++;
		itl++;
	}

	return 0;
}