#ifndef POINT_H
#define POINT_H


#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include <cassert>
#include <algorithm>
#include <math.h>
#include <numeric>
#include <fstream>
#include <iterator>

template <std::size_t dim> struct point { double coords[dim]; };
template <std::size_t dim> using points = std::vector<point<dim>>;
typedef std::unordered_multimap<std::string, std::string> dictionary;

/*-------------------------------------   1.1   -------------------------------------*/
template <std::size_t dim> point<dim> createRandom();

template <std::size_t dim>
std::ostream& operator<<(std::ostream& out, const point<dim>& p);

/*-------------------------------------   1.3   -------------------------------------*/
template <std::size_t dim>
double dist(const point<dim>& p1, const point<dim>& p2);

template <std::size_t dim>
const point<dim>& closest(const points<dim>& pts, const point<dim>& p);

/*-------------------------------------   1.4   -------------------------------------*/
template <std::size_t dim>
point<dim> operator+(const point<dim>& p1, const point<dim>& p2);

template<std::size_t dim>
point<dim> barycenter(const points<dim>& pts);

/*-------------------------------------   2.1   -------------------------------------*/
std::string normalize(std::string const & str);

bool isAnagram(std::string const & str1, std::string const & str2);

/*-------------------------------------   2.2   -------------------------------------*/
std::vector<std::string> load();

/*-------------------------------------   2.3   -------------------------------------*/
dictionary convert(std::vector<std::string> const & words);

/*-------------------------------------   2.4   -------------------------------------*/
std::vector<std::string> anagrams(dictionary const &, std::string const &);


#include "point.hxx"

#endif //POINT_H
