#include<vector>
#include<string>
#include<iostream>
#include<algorithm>

using namespace std;

struct Huffman
{
	float weight;
	Huffman* Rchild = NULL;
	Huffman* Lchild = NULL;
	string code = "";
};

struct Huffcode
{
	float weight;
	string code = "";
};

void GetCode(Huffman* node, string s, vector<Huffcode> &result)
{
	node->code.insert(0, s);
	if (node->Lchild == NULL)
	{
		Huffcode codetemp;
		codetemp.code = node->code;
		codetemp.code = node->weight;
		result.push_back(codetemp);
	}
	else
	{
		GetCode(node->Lchild, node->code, result);
		GetCode(node->Rchild, node->code, result);
	}
}

Huffman* CreateHuff(vector<float> possi)
{

}

bool compare(Huffcode A, Huffcode B)
{
	return A.weight > B.weight;
}

void main()
{
	vector<float> possi = { 0.2, 0.3, 0.1, 0.4 };
	Huffman* root = CreateHuff(possi);
	vector<Huffcode> result;
	GetCode(root, root->code, result);
	sort(result.begin(), result.end(), compare);
	for (int i = 0; i < result.size(); i++)
		cout << result[i].weight << "  " << result[i].code << endl;
	system("pause");
}