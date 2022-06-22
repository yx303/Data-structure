#include<iostream>
#include<fstream>
#include<conio.h>
#include "Windows.h"
#include "Huffman.h"
using namespace std;

int main() {
	int n, choice, r[28];
	HuffmanTree ht;
	string s, temp, code = "", decode;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_RED);
	cout << "************主菜单***************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	do {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "1-初始化Huffman树" << endl;
		cout << "2-编码" << endl;
		cout << "3-译码" << endl;
		cout << "4-打印编码" << endl;
		cout << "5-打印Huffman树" << endl;
		cout << "101-退出" << endl;
		cout << "Enter choice:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> choice;
		switch(choice) {
		case 1://初始化Huffman树
			cout << "请输入字符集数：";
			cin >> n;
			CrtHuffmanTree(ht, r, n);
			cout << "Huffman树已建成!" << endl;
			cout << "已将Huffman树写入HuffmanTree.txt文件中，如要查看请选择“5”选项!" << endl;
			cout << endl;
			break;
		case 2://编码
		{
			cout << "请输入要编码的字符串:";
			string str = "\n";
			getline(cin, str);
			getline(cin, temp);
			Encoding(ht, n);
			for (int i = 0; i < (int)temp.size(); i++) {//找到该字符对应的编码
				string str(1, temp[i]);
				for (int j = 1; j <= n; j++)
					if (str == ht[j].data) code += ht[j].code;
			}
			ofstream outfile;
			outfile.open("CodedFile.txt", ios::out);
			if (!outfile) cout << "文件打开失败!" << endl;
			outfile << code << endl;
			outfile.close();
			cout << "编码完成！" << endl;
			cout << "已将编码串写入CodedFile.txt文件中，如要查看请选择“4”选项!" << endl;
			cout << endl;
		}
				break;
		case 3://译码
			decode = Decoding(ht, n); 
			cout << "译码为:" << decode << endl;
			cout << endl;
			break;
		case 4://打印编码
			cout << "编码串为:" << endl;;
			Print();
			cout << endl;
			break;
		case 5://打印Huffman树
			cout << "Huffman树为：" << endl;
			TreePrint();
			//cout << endl;
			break;
		}
	} while (choice != 101);
	return 0;
}