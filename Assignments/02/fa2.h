//Jimmy Von Holle
//CS 372
//Assignment 2
//fa2.h
//

#ifndef FA2_H_INCLUDED
#define FA2_H_INCLUDED
#include <iostream>
#include <cstddef>
using std::size_t;
#include <random>
using std::normal_distribution;
#include <vector>
using std::vector;
#include <functional>
using std::function;
#include <future>
using std::async;
using std::future;


//Function normRand
//takes an int
//returns a vector of doubles
//doubles are from a  normal distribution with
//				mu = 100.0 and sigma = 15.0
//same sequence is always returned
inline vector<double> normRand(size_t n)
{
	vector<double> seqVec;
    std::random_device d;
    std::mt19937 rando(d());
    auto sigdist = normal_distribution<> (1.0, .5);
    double sigma = sigdist(rando);
	std::mt19937 ranGen(1);
	auto nDistro = normal_distribution<> (100.0, sigma);
	for(size_t i =0; i< n; ++i)
		seqVec.push_back(nDistro(ranGen));

	return seqVec;
}

//Function asyncSquares
//takes an int
//returns a vector of ints size n
//int i in the vector has value i*i (i^2)
//		eg 0,1,4,9,16,25...
//uses async calculations to compute squares
inline vector<int> asyncSquares(size_t n)
{
	vector<future<int>> squareFut;
	vector<int> rSquares;
	
	for(int i =0; i< n; ++i)
		squareFut.push_back (async(std::launch::async,[](int m){return m*m;},i));

	for(auto &e : squareFut)
		rSquares.push_back(e.get());

	return rSquares;
}

//Function repeatFunction
//takes a function and an int
//returns a function that acts like the given function called n times on itself
//i have no idea what's going on
function<int(int)> repeatFunction(function<int(int)> f, int n)
{
	//auto rF = f(f);
//	return rF;
}

#endif
