/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/01 18:30:07 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/05 17:11:40 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
# define SPAN_HPP

#include <iostream>
#include <exception>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdlib>

class Span {
	
	public:
		Span(void);
		Span(unsigned int);
		Span(Span const&);
		~Span(void);

		Span&	operator=(Span const&);

		void						setSpan(std::vector<int>);
		void						setMaxElements(unsigned int);
		std::vector<int> const & 	getSpan(void) const;
		unsigned int				getMaxElements(void) const;

		void			addNumber(int); 
		void			addNumber(std::vector<int>::iterator, std::vector<int>::iterator);
		unsigned int 	shortestSpan(void);
		unsigned int 	longestSpan(void);
		
	
	private:

		std::vector<int>	_span;
		unsigned int		_maxElements;
};

std::ostream &operator<<(std::ostream &o, Span const &s);

#endif