#include<iostream>
#include<algorithm>
#include<vector>
#include<string>

using namespace std;

struct Huffnode
{
	double weight;
	string code = "";
	int Lnode = -1;
	int Rnode = -1;
};

struct Huff
{
	double weight;
	string code="";
};

bool compare(Huffnode A, Huffnode B)
{
	return A.weight < B.weight;
}

void returncode(int address, vector<Huffnode> nodes, string str, vector<Huff>& Huff_output)
{
	nodes[address].code.insert(0, str);
	if (nodes[address].Lnode == -1)
	{
		Huff temp;
		temp.code = nodes[address].code;
		temp.weight = nodes[address].weight;
		Huff_output.push_back(temp);
	}
	else
	{
		returncode(nodes[address].Lnode, nodes, nodes[address].code, Huff_output);
		returncode(nodes[address].Rnode, nodes, nodes[address].code, Huff_output);
	}
}

vector<Huff> Huffman(vector<double> nums)
{
	vector<Huffnode> nodes;
	vector<Huff> Huff_output;

	double sum = 0;
	for (int i = 0; i < nums.size(); i++)
			sum += nums[i];
	if (abs(sum - 1.0) > 1e-5)
	{
		cout << "输入数据有误" << endl;
		return Huff_output;
	}

	for (int i = 0; i < nums.size(); i++)
	{
		Huffnode temp;
		temp.weight = nums[i];
		nodes.push_back(temp);
	}
	
	int flag = 0;
	int count = 0;

	while (fabs(nodes[count].weight - 1.0) > 1e-9)
	{
		sort(nodes.begin(), nodes.end(), compare);
		if (flag == 0)
		{
			nodes[count].code = '0';
			flag = 1; 
			sum += nodes[count].weight;
		}
		else
		{
			nodes[count].code = '1';
			flag = 0;
			Huffnode newnode;
			newnode.weight = nodes[count].weight + nodes[count - 1].weight;
			newnode.Lnode = count-1;
			newnode.Rnode = count;
			nodes.push_back(newnode);
			sum += nodes[count].weight;
		}
		count++;
	}
	returncode(nodes.size()-1, nodes, nodes[count].code, Huff_output);
	return Huff_output;
}

void main()
{
	vector<double> nums = { 0.1, 0.2, 0.3, 0.4 };
	vector<Huff> output = Huffman(nums);
	for (int i = 0; i < output.size(); i++)
		cout << output[i].weight << "  " << output[i].code << endl;
	system("pause");
}