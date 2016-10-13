#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

struct Huffman
{
	double weight;
	Huffman* Rchild = NULL;
	Huffman* Lchild = NULL;
	char* code;
	Huffman(double n) : weight(n){}
};

struct Huffcode
{
	double weight;
	string code = "";
};

bool compare_for_read(Huffcode A, Huffcode B)
{
	return A.weight < B.weight;
}

void GetCode(Huffman* node, string s, vector<Huffcode> &result)
{
	string s_;
	if (abs(node->weight - 1.0) > 1e-3)
	{
		s_ = s + node->code;
	}
	if (node->Lchild == NULL)
	{
		Huffcode codetemp;
		codetemp.code = s_;
		codetemp.weight = node->weight;
		result.push_back(codetemp);
	}
	else
	{
		GetCode(node->Lchild, s_, result);
		GetCode(node->Rchild, s_, result);
	}
}

bool compare_for_create(Huffman* A, Huffman* B)
{
	return A->weight < B->weight;
}

Huffman* CreateHuff(vector<double> possi)
{
	bool flag = false;

	vector<Huffman*> Huff;
	for (int i = 0; i < possi.size(); i++)
	{
		Huffman* temp_huff=(Huffman*)malloc(sizeof(Huffman));
		temp_huff->weight = possi[i];
		temp_huff->code = (char*)malloc(strlen("1") + 1);
		temp_huff->Lchild = NULL;
		temp_huff->Rchild = NULL;
		Huff.push_back(temp_huff);
	}

	for (int i = 0; i < Huff.size(); i++)
	{
		sort(Huff.begin(), Huff.end(), compare_for_create);
		
		if (!flag)
		{
			flag = true;
			strcpy(Huff[i]->code, "0");
		}
		else
		{
			flag = false;
			strcpy(Huff[i]->code, "1");
			Huffman* temp_ = (Huffman*)malloc(sizeof(Huffman)); 			
			temp_->Lchild = Huff[i];
			temp_->Rchild = Huff[i - 1];
			temp_->weight = Huff[i]->weight + Huff[i - 1]->weight;
			temp_->code = (char*)malloc(strlen("1") + 1);
			Huff.push_back(temp_);
		}
	}
	return Huff[Huff.size() - 1];
}

void main()
{
	vector<double> possi = { 0.2, 0.3, 0.1, 0.4 };
	Huffman* root = CreateHuff(possi);
	vector<Huffcode> result;

	GetCode(root, root->code, result);
	sort(result.begin(), result.end(), compare_for_read);
	for (int i = 0; i < result.size(); i++)
		cout << result[i].weight << "  " << result[i].code << endl;
	system("pause");
}