#pragma once
#ifndef _SORT_H_
#define _SORT_H_

//ȫ�ֱ���
extern unsigned long long int moving;//Ԫ���ƶ�����
extern unsigned long long int compare;//Ԫ�رȽϴ���
typedef int KeyType;//�ؼ�������

void Print(KeyType r[], int n);//�������
void InsSort(KeyType r[], int n);//��������0�ŵ�ԪΪ�ڱ�
void SelectSort(KeyType r[], int n);//��ѡ������,n-1Ϊ���鳤��,0�ŵ�Ԫ����
void BubbleSort(KeyType r[], int n);//ð������
void ShellSort(KeyType r[], int n);//ϣ������
void sift(KeyType r[], int k, int m);//�ؽ���
void crt_heap(KeyType r[], int n);//������
void HeapSort(KeyType r[], int n);//������
int QKPass(KeyType r[], int n, int left, int right);//һ�˿�������
void QKSort(KeyType r[], int n, int left, int right);//��������
void _Merge(KeyType r[], int low, int mid, int high, KeyType temp[], int n);//�鲢����ġ��Ρ�,rΪ�������飬tempΪ��������
void MergeSort(KeyType r[], KeyType temp[], int low, int high, int n);//�鲢����,n-1Ϊ���鳤��,0�ŵ�Ԫ����

#endif//_SORT_H_