#include<iostream>
#include "Huffman.h"
#include<string>
#include<fstream>
using namespace std;


void select(HuffmanTree& ht, int n, int& s1, int& s2)
{
	int m1, m2;//存放最小和次小的权值
	m1 = m2 = Maxfre;//令其为最大
	for (int i = 1; i <= n; i++) {
		if (ht[i].weight < m1 && ht[i].parent == 0) {
			m2 = m1;
			m1 = ht[i].weight;
			s2 = s1;
			s1 = i;
		}
		else if (ht[i].weight < m2 && ht[i].parent == 0) {
			m2 = ht[i].weight;
			s2 = i;
		}
	}
}

void CrtHuffmanTree(HuffmanTree& ht, int w[], int n)
{//构造哈夫曼树
	ifstream ifile;
	ifile.open("字频表.txt", ios::in);
		if (!ifile) cout << "文件打开失败!" << endl;
	int i=1, s1, s2, m = 2 * n - 1;
	while (!ifile.eof()) {
		ifile >> w[i];
		i++;
	}
	ifile.close();
	ht[1].data = " ";
	ht[1].weight = w[1];
	for (i = 2; i <= n; i++) {
		ht[i].data = char('A' + i - 2);
		ht[i].weight = w[i];
		ht[i].LChild = 0;
		ht[i].parent = 0;
		ht[i].RChild = 0;
	}
	for (i = n + 1; i <= m; i++) ht[i] = { "-",0,0,0,0,"" };
	for(i = n + 1; i <= m; i++) {
		select(ht, i - 1, s1, s2);
		ht[i].weight = ht[s1].weight + ht[s2].weight;
		ht[s1].parent = i;
		ht[s2].parent = i;
		ht[i].LChild = s1;
		ht[i].RChild = s2;
	}
	ofstream ofile;
	ofile.open("HuffmanTree.txt", ios::out);
	if (!ofile) cout << "文件打开失败!" << endl;
	ofile << "结点i" << "	" << "字符" << "	" << "权值" << "	" << "双亲" << "	" << "左孩子" << "	" << "右孩子" << endl;
	for (i = 1; i <= m; i++) {
		ofile << i << "	" << ht[i].data << "	" << ht[i].weight << "	" << ht[i].parent << "	" << ht[i].LChild << "	" << ht[i].RChild << endl;
	}
}

void Encoding(HuffmanTree& ht, int n)
{//哈夫曼编码
	int c, p;
	string code;
	for (int i = 1; i <= n; i++) {
		code = "";
		c = i;
		p = ht[i].parent;
		while (p != 0) {
			if (ht[p].LChild == c) code += '0';
			else code += '1';
			c = p;
			p = ht[p].parent;
		}
		for (int j = (int)code.size() - 1; j >= 0; j--) {
			ht[i].code += code[j];
		}
	}
}

string Decoding(HuffmanTree& ht, int n)
{//哈夫曼解码
	cout << "请输入编码串（以#结尾）：";
	string s, temp = "";//存放解码串
	cin >> s;
	int i = 2 * n - 1;
	int j = 0;
	while (s[j] != '#') {
		if (s[j] == '0') i = ht[i].LChild;
		else i = ht[i].RChild;
		if (ht[i].LChild == 0 && ht[i].RChild == 0) {//ht[i]是叶结点
			temp += ht[i].data;
			i = 2 * n - 1;//回到根节点
		}
		j++;
	}
	return temp;
}

void Print()
{//打印编码后的文件
	ifstream infile;
	infile.open("CodedFile.txt", ios::in);
	if (!infile) cout << "文件打开失败!" << endl;
	int i = 0;
	string s;
	while (!infile.eof()) {
		infile >> s;	
	}
	while (s[i] == '0' || s[i] == '1' ){
		cout << s[i];
		if (i % 50 == 49) cout << endl;
		i++;
	}
	infile.close();
}

void TreePrint()
{//打印Huffman树
	string temp;
	ifstream infile;
	infile.open("HuffmanTree.txt", ios::in);
	if (!infile) cout << "文件打开失败!" << endl;
	while (!infile.eof()) {
		getline(infile, temp);
		cout << temp << endl;
	}
	infile.close();
}
