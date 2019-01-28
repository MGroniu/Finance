#include<cmath>
#include<iostream>
#include "EuropeOption.h"
#include"Random1.h"


//definition of constructor
EuropeOption::EuropeOption(
    double Barrier_,
	int nInt_,
	double strike_,
	double spot_,
	double vol_,
	double r_,
	double expiry_){
	    Barrier = Barrier_;
		nInt = nInt_;
		strike = strike_;
		spot = spot_;
		vol = vol_;
		r = r_;
		expiry = expiry_;
		generatePath();
}

//method definition
void EuropeOption::generatePath(){
	double thisDrift = (r * expiry - 0.5 * vol * vol * expiry) / double(nInt);
	double cumShocks = 0;
	thisPath.clear();

	for(int i = 0; i < nInt; i++){
		cumShocks += (thisDrift + vol * sqrt(expiry / double(nInt)) * GetOneGaussianByBoxMuller());
		thisPath.push_back(spot * exp(cumShocks));
	}
}

double EuropeOption::getdownandoutput(int nReps){

	double rollingSum = 0.0;
	double thisMin = 0.0;

	for(int i = 0; i < nReps; i++){
		generatePath();
		thisMin = std::min_element(thisPath.begin(), thisPath.end());
		if(thisMin>Barrier){
            rollingSum += (thisPath.back() < strike) ? (strike - thisPath.back()) : 0;
		}
	}

	return exp(-r * expiry) * rollingSum / double(nReps);

}
