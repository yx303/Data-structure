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
	cout << "************���˵�***************" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	do {
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), FOREGROUND_GREEN);
		cout << "1-��ʼ��Huffman��" << endl;
		cout << "2-����" << endl;
		cout << "3-����" << endl;
		cout << "4-��ӡ����" << endl;
		cout << "5-��ӡHuffman��" << endl;
		cout << "101-�˳�" << endl;
		cout << "Enter choice:";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cin >> choice;
		switch(choice) {
		case 1://��ʼ��Huffman��
			cout << "�������ַ�������";
			cin >> n;
			CrtHuffmanTree(ht, r, n);
			cout << "Huffman���ѽ���!" << endl;
			cout << "�ѽ�Huffman��д��HuffmanTree.txt�ļ��У���Ҫ�鿴��ѡ��5��ѡ��!" << endl;
			cout << endl;
			break;
		case 2://����
		{
			cout << "������Ҫ������ַ���:";
			string str = "\n";
			getline(cin, str);
			getline(cin, temp);
			Encoding(ht, n);
			for (int i = 0; i < (int)temp.size(); i++) {//�ҵ����ַ���Ӧ�ı���
				string str(1, temp[i]);
				for (int j = 1; j <= n; j++)
					if (str == ht[j].data) code += ht[j].code;
			}
			ofstream outfile;
			outfile.open("CodedFile.txt", ios::out);
			if (!outfile) cout << "�ļ���ʧ��!" << endl;
			outfile << code << endl;
			outfile.close();
			cout << "������ɣ�" << endl;
			cout << "�ѽ����봮д��CodedFile.txt�ļ��У���Ҫ�鿴��ѡ��4��ѡ��!" << endl;
			cout << endl;
		}
				break;
		case 3://����
			decode = Decoding(ht, n); 
			cout << "����Ϊ:" << decode << endl;
			cout << endl;
			break;
		case 4://��ӡ����
			cout << "���봮Ϊ:" << endl;;
			Print();
			cout << endl;
			break;
		case 5://��ӡHuffman��
			cout << "Huffman��Ϊ��" << endl;
			TreePrint();
			//cout << endl;
			break;
		}
	} while (choice != 101);
	return 0;
}