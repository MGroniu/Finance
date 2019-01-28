#include<vector>


class EuropeOption{
public:

	//constructor
	EuropeOption(
    double Barrier_,
		int nInt_,
		double strike_,
		double spot_,
		double vol_,
		double r_,
		double expiry_
		);

	//destructor
	~EuropeOption(){};

	//methods
	void generatePath();
	double getdownandoutput(int nReps);



	//members
	std::vector<double> thisPath;
	double Barrier;
	int nInt;
	double strike;
	double spot;
	double vol;
	double r;
	double expiry;

};
