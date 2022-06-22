#include<iostream>
#include<cstring>
#include<random>
#include<ctime>
#include"Sort.h"

using namespace std;

int main() {
	KeyType InsSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };//���������ԭ����˳�����仯���ʶ����߸���ͬ������
	KeyType SelectSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType BubbleSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType ShellSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType HeapSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType QKSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 };
	KeyType MergeSort1[11] = { 0,9,5,6,8,10,2,1,4,3,7 }, MergeSort1_1[11];//��������
	KeyType InsSort2[100001], SelectSort2[100001], BubbleSort2[100001], ShellSort2[100001], HeapSort2[100001], QKSort2[100001], MergeSort2[100001];
	KeyType MergeSort2_1[100001];//��������
	uniform_int_distribution<int> u(0, 1000000);
	default_random_engine e(time(0));
	for (int i = 1; i < 100001; i++)
		InsSort2[i] = u(e) % 200000 + 1;
	memcpy(SelectSort2, InsSort2, sizeof(InsSort2));//ͬ�������߸�����
	memcpy(BubbleSort2, InsSort2, sizeof(InsSort2));
	memcpy(ShellSort2, InsSort2, sizeof(InsSort2));
	memcpy(HeapSort2, InsSort2, sizeof(InsSort2));
	memcpy(QKSort2, InsSort2, sizeof(InsSort2));
	memcpy(MergeSort2, InsSort2, sizeof(InsSort2));
	//10������
	cout << "**********10������**********" << endl;
	cout << "----------��������----------" << endl;
	InsSort(InsSort1, 11);
	cout << "--------��ѡ������--------" << endl;
	SelectSort(SelectSort1, 11);
	cout << "----------ð������----------" << endl;
	BubbleSort(BubbleSort1, 11);
	cout << "----------ϣ������----------" << endl;
	ShellSort(ShellSort1, 11);
	cout << "----------������----------" << endl;
	HeapSort(HeapSort1, 11);
	cout << "----------��������----------" << endl;
	Print(QKSort1, 11);
	QKSort(QKSort1, 11, 1, 10);
	cout << "�Ƚϴ���Ϊ:" << compare << " �ƶ�����Ϊ:" << moving << endl;
	compare = 0; moving = 0;
	cout << "----------�鲢����----------" << endl;
	Print(MergeSort1, 11);
	MergeSort(MergeSort1, MergeSort1_1, 1, 10, 11);
	cout << "�Ƚϴ���Ϊ:" << compare << " �ƶ�����Ϊ:" << moving << endl;
	compare = 0; moving = 0;
	cout << endl;
	//100000������
	cout << "**********10�������**********" << endl;
	cout << "----------��������----------" << endl;
	InsSort(InsSort2, 100001);
	BubbleSort(InsSort2, 100001);//�������׼ȷ��
	cout << "--------��ѡ������--------" << endl;
	SelectSort(SelectSort2, 100001);
	BubbleSort(SelectSort2, 100001);//�������׼ȷ��
	cout << "----------ð������----------" << endl;
	BubbleSort(BubbleSort2, 100001);
	BubbleSort(BubbleSort2, 100001);//�������׼ȷ��
	cout << "----------ϣ������----------" << endl;
	ShellSort(ShellSort2, 100001);
	BubbleSort(ShellSort2, 100001);//�������׼ȷ��
	cout << "----------������----------" << endl;
	HeapSort(HeapSort2, 100001);
	BubbleSort(HeapSort2, 100001);//�������׼ȷ��
	cout << "----------��������----------" << endl;
	QKSort(QKSort2, 100001, 1, 100000);
	cout << "�Ƚϴ���Ϊ:" << compare << " �ƶ�����Ϊ:" << moving << endl;
	BubbleSort(QKSort2, 100001);//�������׼ȷ��
	cout << "----------�鲢����----------" << endl;
	MergeSort(MergeSort2, MergeSort2_1, 1, 100000, 100001);
	cout << "�Ƚϴ���Ϊ:" << compare << " �ƶ�����Ϊ:" << moving << endl;
	BubbleSort(MergeSort2, 100001);//�������׼ȷ��
	return 0;
}