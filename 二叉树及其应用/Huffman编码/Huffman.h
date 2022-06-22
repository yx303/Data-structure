#pragma once
#ifndef HUFFMAN_H
#define HUFFMAN_H
#define N 27//叶子结点最大值
#define M 2*N-1//所有结点最大值
#define Maxfre 32768//频度最大值
#include<string>
using std::string;

struct HTNode {
	string data = "";//结点值
	int weight=0;//结点权值
	int parent=0;//双亲下标
	int LChild = 0, RChild = 0;//左,右孩子结点下标
	string code = "";//存放每个字符的编码
};
typedef HTNode HuffmanTree[M + 1];//结构数组，0号单元不用

void select(HuffmanTree& ht, int n, int& s1, int& s2);//选择两个parent为0且weight最小的结点，其序号赋给s1、s2
void CrtHuffmanTree(HuffmanTree& ht, int w[], int n);//构造哈夫曼树ht[M+1]
void Encoding(HuffmanTree& ht, int n);//从叶子结点到根，逆向求每个叶子结点对应的哈夫曼编码
string Decoding(HuffmanTree& ht, int n);//解码
void Print();//打印编码后的文件
void TreePrint();//打印Huffman树



#endif//HUFFMAN_H