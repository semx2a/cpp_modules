/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:31:45 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/11 18:45:22 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
# define PMERGEME_HPP

# include <iostream>
# include <string>
# include <sstream>
# include <vector>
# include <list>
# include <bits/stdc++.h> //for binary search
# include <algorithm>
# include <iterator>
# include <stdexcept>

# include <cmath>
# include <ctime>

# include "display.hpp"

typedef enum e_container {
	
	VECTOR,
	LIST
} t_container;

typedef std::vector<int>	t_vecI;
typedef std::list<int> 		t_listI;

class PmergeMe { 
	
	public:
		
		PmergeMe(void);
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &pmergeMe);
		~PmergeMe(void);
	
		PmergeMe	&operator=(PmergeMe const &pmergeMe);

		t_vecI			getVec(void) const;
		t_listI			getList(void) const;
		int				getSize(t_container type) const;

		void			setVec(t_vecI vec);
		void			setList(t_listI list);
		void			setSize(int size, t_container type);

		void			sort();
		void			checkArgs(int ac, char **av) const;
		void			isSorted(t_container type) const;
		std::string 	print(t_vecI const) const;
		std::string 	print(t_listI const) const;
		std::string 	display(void) const;

		
	private:
	
		t_vecI				_vec;
		t_listI				_list;
		int					_size[2];
		std::stringstream	_buf;

		std::clock_t	_start[2];
		std::clock_t	_stop[2];
		
		bool    		_isPositiveNumeric (std::string const& s) const;
		std::string		_getTimeMicro(t_container type) const;
		void 			_fordJohnsonSort(t_vecI &X);
		void			_fordJohnsonSort(t_listI &X);
		void 			_sortHalf(t_vecI &S, t_vecI &remaining, const t_vecI &X);
		void			_sortHalf(t_listI &S, t_listI &remaining, const t_listI &X);
};

std::ostream	&operator<<(std::ostream &o, PmergeMe const &pmergeMe);


#endif