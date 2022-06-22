#pragma once
#ifndef _SORT_H_
#define _SORT_H_

//全局变量
extern unsigned long long int moving;//元素移动次数
extern unsigned long long int compare;//元素比较次数
typedef int KeyType;//关键字类型

void Print(KeyType r[], int n);//输出数组
void InsSort(KeyType r[], int n);//插入排序，0号单元为哨兵
void SelectSort(KeyType r[], int n);//简单选择排序,n-1为数组长度,0号单元不用
void BubbleSort(KeyType r[], int n);//冒泡排序
void ShellSort(KeyType r[], int n);//希尔排序
void sift(KeyType r[], int k, int m);//重建堆
void crt_heap(KeyType r[], int n);//建初堆
void HeapSort(KeyType r[], int n);//堆排序
int QKPass(KeyType r[], int n, int left, int right);//一趟快速排序
void QKSort(KeyType r[], int n, int left, int right);//快速排序
void _Merge(KeyType r[], int low, int mid, int high, KeyType temp[], int n);//归并排序的“治”,r为待排数组，temp为辅助数组
void MergeSort(KeyType r[], KeyType temp[], int low, int high, int n);//归并排序,n-1为数组长度,0号单元不用

#endif//_SORT_H_