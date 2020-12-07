#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void printArray(int a[], int size) {
	for (int i = 0; i < size; i++) {
		printf("%d ", a[i]);
	}

	printf("\n");
}

void merge(int *a, int low, int mid, int high)
{
	//临时创建额外空间存放比较后的数组元素，并初始化
	int *tmp = (int *)malloc(sizeof(a));
	memset(tmp, -1, sizeof(a) / sizeof(int));

	int index = low;
	int i = low, j = mid + 1;
	//注意:当划分的区间足够小时,low==mid,mid+1==high
	while (i <= mid && j <= high) {
		if (a[i] <= a[j])
			tmp[index++] = a[i++];
		else
			tmp[index++] = a[j++];
	}
	//将左边元素填充到tmp中
	while (i <= mid)
		tmp[index++] = a[i++];
	//将右边元素填充的tmp中
	while (j <= high)
		tmp[index++] = a[j++];
	//将tmp中的数据拷贝到原数组对应的序列区间
	//注意:end2-begin1+1
	memcpy(a + low, tmp + low, sizeof(int)*(high - low + 1));
}

//归并排序(合并排序)
//前提：合并两个有序数组
//1.先把整个待排序区间平均分成两份
//2.分别对左右两个小区间按照分治算法处理，知道小区间内元素个数<=1
//3.合并左右两个有序区间
void mergeSortInternal(int *a, int low, int high)
{
	if (low >= high)
		return;
	int mid = (low + high) / 2;
	//[low,mid)
	//[mid,high)
	mergeSortInternal(a, low, mid);
	mergeSortInternal(a, mid + 1, high);

	//合并两个有序数组
	merge(a, low, mid, high);
}


int main()
{
	int a[] = { 9, 3, 5, 4, 9, 2, 7, 9, 3, 6, 8, 8 };
	int size = sizeof(a) / sizeof(int);
	int left = 0;
	int right = size - 1;
	printArray(a, size);

	mergeSortInternal(a, left, right);
	printArray(a, size);

	system("pause");
	return 0;
}