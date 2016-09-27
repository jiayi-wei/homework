#include "ML.h"

ml_algorithm::ml_algorithm()
{

}

ml_algorithm::~ml_algorithm()
{
	theta.clear();
	data_for_cate.clear();
	data_for_nor.clear();
}

int ml_algorithm::ml_for_nor()
{
	if (data_for_nor.size() == 0)
	{
		std::cout << "The Data of normal distribution is empty" << std::endl;
		return -1;
	}
	double sum_mean = 0;
	double sum_var = 0;
	double num_of_data = data_for_nor.size();
	for (int i = 0; i < data_for_nor.size(); i++)
	{
		sum_mean += data_for_nor[i];
	}
	ml_mean = sum_mean / num_of_data;
	for (int i = 0; i < data_for_nor.size(); i++)
	{
		sum_var += (data_for_nor[i] - ml_mean)*(data_for_nor[i] - ml_mean);
	}
	ml_var = sum_var / num_of_data;
	return 1;
}

int ml_algorithm::ml_for_cate()
{
	if (data_for_cate.size() == 0)
	{
		std::cout << "The data of categorical distribution is empty" << std::endl;
		return -1;
	}
	double element_to_add = 1/double(data_for_cate.size());
	for (int i = 0; i < data_for_cate.size(); i++)
	{
		theta[data_for_cate[i]] += element_to_add;
	}
	return 1;
}