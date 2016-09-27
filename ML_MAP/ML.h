#include<iostream>
#include<vector>

class ml_algorithm
{
public:
	ml_algorithm();
	~ml_algorithm();
public:
	int ml_for_nor();
	int ml_for_cate();
private:
	double ml_mean;
	double ml_var;
	std::vector<double> theta;
	std::vector<double> data_for_nor;
	std::vector<double> data_for_cate;
};

