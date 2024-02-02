/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:28:11 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 15:22:08 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/RPN.hpp"

RPN::RPN() : std::stack<int>() {}

RPN::RPN (std::string expression) : _expression(expression) {
	
	try { 
		std::cout << this->_expressionEval() << std::endl;
	}
	catch (std::runtime_error &e) {
		std::cout << e.what() << std::endl;
	}
	catch (std::exception &e) {
		std::cout << e.what() << std::endl;
	}
	
}

RPN::RPN(RPN const &rhs) : std::stack<int>(rhs) {
	
	*this = rhs;
}

RPN::~RPN(void) {}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: OPERATORS::

RPN &	RPN::operator=(RPN const &rhs) {
	
	if (this != &rhs)
		this->c = rhs.c;
	return (*this);
}

//:::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: ITERATORS::

RPN::iterator RPN::begin(void) {
	
	return std::stack<int>::c.begin();
}

RPN::iterator RPN::end(void) {
	
	return std::stack<int>::c.end();
}


RPN::const_iterator	RPN::begin(void) const {
	
	return std::stack<int>::c.begin();
}

RPN::const_iterator RPN::end(void) const {
	
	return std::stack<int>::c.end();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::

bool RPN::_isOperator(char ch){
	
	return (ch == '+'|| ch == '-'|| ch == '*'|| ch == '/');
}

bool RPN::_isOperand(char ch){
	
	return (ch >= '0' && ch <= '9');
}

int RPN::_operation(int a, int b, char op){
	
	//Perform operation
	switch (op) {
		
		case '+':
			return b + a;
		case '-':
			return b - a;
		case '*':
			return b * a;
		case '/': {
			
			if (b == 0)
				throw std::runtime_error("Error: Division by zero.");
			return b / a;
		}
		default:
			throw std::runtime_error("Error: Unknown operator.");
	}
	
	return (0);
}

int RPN::_expressionEval(void) {
   
	int a, b;
	
	for(std::string::iterator it = this->_expression.begin(); it != this->_expression.end(); it++) {
		
		//read elements and perform expression evaluation
		if (this->_isOperator(*it) == true) {
			
			if (this->size() < 2)
				throw std::runtime_error("Error: Not enough operands.");
			a = this->top();
			this->pop();
			b = this->top();
			this->pop();
			this->push(this->_operation(a, b, *it));
		}
		
		else if (this->_isOperand(*it) == true)
			this->push(*it - '0');

		else if (*it != ' ')
			throw std::runtime_error("Error: Unknown character.");
	}
	
	return this->top();
}
