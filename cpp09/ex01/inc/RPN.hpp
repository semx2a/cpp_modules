/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 13:28:27 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/10 15:00:48 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
# define RPN_HPP

# include <iostream>
# include <string>
# include <stack>
# include <cmath>
# include <climits>
# include <exception>


class RPN : public std::stack<int> {
	
	public:
		RPN();
		RPN(std::string);
		RPN(RPN const&);
		virtual ~RPN();

		RPN&	operator=(RPN const&);

		typedef std::stack<int>::container_type::iterator iterator;
		iterator begin(void);
		iterator end(void);

		typedef std::stack<int>::container_type::const_iterator const_iterator;
		const_iterator begin(void) const;
		const_iterator end(void) const;

	private:

		std::string	_expression;
		
		bool	_isOperator(char);
		bool	_isOperand(char);
		int		_operation(int, int, char);
		int		_expressionEval(void);
		
};

#endif