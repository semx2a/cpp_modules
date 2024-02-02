/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: seozcan <seozcan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/10 16:31:47 by seozcan           #+#    #+#             */
/*   Updated: 2023/09/11 18:47:17 by seozcan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/PmergeMe.hpp"

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: CONSTRUCTORS::

PmergeMe::PmergeMe(void) : _vec(), _list(), _size(), _buf() {}

PmergeMe::PmergeMe(PmergeMe const &pmergeMe) {
	
	*this = pmergeMe;
}

PmergeMe::PmergeMe(int ac, char **av) {

	this->checkArgs(ac, av);
	
	std::transform(av + 1, av + ac, std::back_inserter(this->_vec), std::atoi);
	std::transform(av + 1, av + ac, std::back_inserter(this->_list), std::atoi);

	this->_buf << GREEN << "Before std::vector:\t" << print(this->_vec) << NO_COLOR << std::endl;
	this->_buf << PURPLE << "Before std::list:\t" << print(this->_list) << NO_COLOR << std::endl;

	this->setSize(this->_vec.size(), VECTOR);
	this->setSize(this->_list.size(), LIST);	
}

PmergeMe::~PmergeMe(void) {}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: OPERATORS::

PmergeMe	&PmergeMe::operator=(PmergeMe const &rhs) {

	if (this != &rhs) {
		
		this->setVec(rhs.getVec());
		this->setList(rhs.getList());
	}
	return *this;
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: SETTERS::

t_vecI				PmergeMe::getVec(void) const { return this->_vec; }
t_listI				PmergeMe::getList(void) const { return this->_list; }
int					PmergeMe::getSize(t_container type) const { return this->_size[type]; }

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: MUTATORS::

void	PmergeMe::setVec(t_vecI vec) { this->_vec = vec; }
void	PmergeMe::setList(t_listI list) { this->_list = list; }
void	PmergeMe::setSize(int size, t_container type) { this->_size[type] = size; }

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: UTILS::

bool    PmergeMe::_isPositiveNumeric(std::string const& s) const {

    return (s.find_first_not_of ("0123456789") == std::string::npos);
}

void    PmergeMe::checkArgs(int ac, char **av) const{

    for (int i = 1; i < ac; ++i)
    {
        if (!this->_isPositiveNumeric(av[i]))
            throw std::runtime_error("Invalid input. Only positive integers are allowed.");
        if (std::atoll (av[i]) == 0 || std::atoll (av[i]) > std::numeric_limits <int>::max ())
            throw std::runtime_error("Invalid input. Only positive integers are allowed.");
    }
}

void	PmergeMe::sort(void) {
	
	this->_start[VECTOR] = std::clock();
	this->_fordJohnsonSort(this->_vec);
	this->_stop[VECTOR] = std::clock();
	
	this->_start[LIST] = std::clock();
	this->_fordJohnsonSort(this->_list);
	this->_stop[LIST] = std::clock();
}

void	PmergeMe::isSorted(t_container type) const {

	if (type == VECTOR) {
		for (std::vector<int>::const_iterator it = this->_vec.begin(); it != this->_vec.end(); it++) {
			if (it + 1 != this->_vec.end() && *it > *(it + 1)) {
				throw std::runtime_error("Vector is not sorted");
			}
		}
	}
	
	else if (type == LIST) {
    	std::list<int>::const_iterator it = this->_list.begin();
    	std::list<int>::const_iterator next_it = it;
    	++next_it;
	
    	for (;next_it != this->_list.end(); ++next_it) {
    	    if (*it > *next_it) {
				throw std::runtime_error("List is not sorted");
			}
    	    ++it;
    	}
	}
}

std::string	PmergeMe::_getTimeMicro(t_container type) const {

	std::stringstream s;
	s << std::setprecision(10) << (((double)(this->_stop[type] - this->_start[type]) / CLOCKS_PER_SEC) / (1e-6)) << " us";

	return s.str();
}

std::string	PmergeMe::print(t_vecI const vec) const {
	
	std::stringstream s;
	
	for (t_vecI::const_iterator it = vec.begin(); it != vec.end(); ++it) {
		s << *it << " ";
	}
	return s.str();
}

std::string	PmergeMe::print(t_listI const list) const {
	
	std::stringstream s;
	
	for (t_listI::const_iterator it = list.begin(); it != list.end(); ++it) {
		s << *it << " ";
	}
	return s.str();
}


std::string	PmergeMe::display(void) const {
	
	std::stringstream s;
	
	s << this->_buf.str();
	s << GREEN << "After std::vector:\t" << print(this->getVec()) << NO_COLOR << std::endl;
	s << PURPLE << "After std::list:\t" << print(this->getList()) << NO_COLOR << std::endl;
	s << GREEN << "Time to process a range of " << this->getSize(VECTOR) << " elements with std::vector: " << this->_getTimeMicro(VECTOR) << NO_COLOR << std::endl;
	s << PURPLE << "Time to process a range of " << this->getSize(LIST) << " elements with std::list: " << this->_getTimeMicro(LIST) << NO_COLOR << std::endl;

	return s.str();
}

// ::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::::: METHODS::

void PmergeMe::_sortHalf(t_vecI &S, t_vecI &remaining, const t_vecI &X) {

	for (size_t i = 0; i < X.size(); i += 2) {

		if (i == X.size() - 1) {
			remaining.push_back(X[i]);
			break;
		}
		if (X[i] < X[i + 1]) {
			S.push_back(X[i + 1]);
			remaining.push_back(X[i]);
		}
		else {
			S.push_back(X[i]);
			remaining.push_back(X[i + 1]);
		}
	}
	std::sort(S.begin(), S.end());
}


void PmergeMe::_sortHalf(t_listI &S, t_listI &remaining, const t_listI &X) {
	
    for (t_listI::const_iterator it = X.begin(); it != X.end(); std::advance(it , 2) ) {
        
		if (std::distance(it, X.end()) == 1) {
			remaining.push_back(*it);
			break;
		}
		t_listI::const_iterator next_it = it;
        ++next_it;
    
        int next = *next_it;
        if (*it < next) {
            S.push_back(next);
            remaining.push_back(*it);
        }
        else {
            S.push_back(*it);
            remaining.push_back(next);
        }
    }
    S.sort();
}

// Ford-Johnson sort algorithm
void PmergeMe::_fordJohnsonSort(t_vecI &X) {
	
	size_t n = X.size();
	
	if (n <= 1) {
		return;
	}

	t_vecI S;
	t_vecI remaining;
	this->_sortHalf(S, remaining, X);

	// Insert the smallest element from remaining into S
	int					min_remaining = *std::min_element(remaining.begin(), remaining.end());
	t_vecI::iterator	pos = std::lower_bound(S.begin(), S.end(), min_remaining);
	S.insert(pos, min_remaining);

	// Remove smallest element from remaining
	remaining.erase(std::remove(remaining.begin(), remaining.end(), min_remaining), remaining.end());

	// Insert remaining elements into S based on the computed positions
	for (t_vecI::iterator it = remaining.begin(); it != remaining.end(); ++it) {
		pos = std::lower_bound(S.begin(), S.end(), *it);
		S.insert(pos, *it);
	}

	// Copy the sorted elements back to X
	std::copy(S.begin(), S.end(), X.begin());
}

void PmergeMe::_fordJohnsonSort(t_listI &X) {
	
	size_t n = X.size();
	
	if (n <= 1) {
		return;
	}

	t_listI S;
	t_listI remaining;
	this->_sortHalf(S, remaining, X);

	// Insert the smallest element from remaining into S
	int					min_remaining = *std::min_element(remaining.begin(), remaining.end());
	t_listI::iterator	pos = std::lower_bound(S.begin(), S.end(), min_remaining);
	S.insert(pos, min_remaining);

	// Remove smallest element from remaining
	remaining.erase(std::remove(remaining.begin(), remaining.end(), min_remaining), remaining.end());

	// Insert remaining elements into S based on the computed positions
	for (t_listI::iterator it = remaining.begin(); it != remaining.end(); ++it) {
		pos = std::lower_bound(S.begin(), S.end(), *it);
		S.insert(pos, *it);
	}

	// Copy the sorted elements back to X
	std::copy(S.begin(), S.end(), X.begin());
}

// :::::::::::::::::::::::::::::::::::::::::::::::::::::::: OEPRATOR OVERALOAD::

std::ostream    &operator<<(std::ostream &o, PmergeMe const &PMM) {

	o << PMM.display();
	return o;
}