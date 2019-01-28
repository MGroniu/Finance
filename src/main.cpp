#include<Rcpp.h>
#include"EuropeOption.h"
#include<cmath>
#include<iostream>
#include"Random1.h"
#include<vector>

using std::vector;

using namespace Rcpp;



// [[Rcpp::export]]

double getdownandoutput(int nInt = 20,

							  double strike = 100,

                              double spot = 95,

                              double vol = 0.2,

                              double r = 0.06,

                              double expiry = 0.5,

							  double Barrier = 93,

                              int nReps = 800){


    // set the seed
	srand( time(NULL) );

	EuropeOption OptionOne(nInt, strike, spot, vol, r, expiry, Barrier);


	double price =	OptionOne.getdownandoutput(nReps);


	return price;

}
