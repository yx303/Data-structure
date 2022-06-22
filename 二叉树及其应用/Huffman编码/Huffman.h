#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H
#define N 27//Ҷ�ӽ�����ֵ
#define M 2*N-1//���н�����ֵ
#define Maxfre 32768//Ƶ�����ֵ
#include<string>
using std::string;

struct HTNode {
	string data = "";//���ֵ
	int weight=0;//���Ȩֵ
	int parent=0;//˫���±�
	int LChild = 0, RChild = 0;//��,�Һ��ӽ���±�
	string code = "";//���ÿ���ַ��ı���
};
typedef HTNode HuffmanTree[M + 1];//�ṹ���飬0�ŵ�Ԫ����

void select(HuffmanTree& ht, int n, int& s1, int& s2);//ѡ������parentΪ0��weight��С�Ľ�㣬����Ÿ���s1��s2
void CrtHuffmanTree(HuffmanTree& ht, int w[], int n);//�����������ht[M+1]
void Encoding(HuffmanTree& ht, int n);//��Ҷ�ӽ�㵽����������ÿ��Ҷ�ӽ���Ӧ�Ĺ���������
string Decoding(HuffmanTree& ht, int n);//����
void Print();//��ӡ�������ļ�
void TreePrint();//��ӡHuffman��



#endif//HUFFMAN_H