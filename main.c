#include <stdio.h>
#include <math.h>

// https://leetcode-cn.com/problems/smallest-k-lcci/
// smallest-k 数组中前k的最小的数

int* smallest_k(int* arr, int count, int k);
int* smallest_k_impl(int* arr, int start, int end, int k);
int partition(int* arr, int start, int end);


int* smallest_k(int* arr,int count,int k){
	if(k>=count){
		return arr;
	}
	smallest_k_impl(arr,0,count-1,k-1);
	return arr;
}

int* smallest_k_impl(int* arr,int start,int end,int k){

	// 执行与快速排序一样的划分方法
	// 将区间划分为左中右三部分 left mid right
	int left = start;
	int right = end;
	int mid = partition(arr, left, right);
	while (mid != k) {
		if (mid < k) {
			left = mid+1;
			mid = partition(arr, left, right);
		}
		else if (mid > k) {
			right = mid-1;
			mid = partition(arr, left, right);
		}
	}
	return arr;
}

// 从小到大执行一次划分,返回mid的索引
int partition(int* arr,int start,int end){
	if(start==end){
		return start;
	}
	int pivot = arr[start];
	int left = start;
	int right = end;

	while (left!=right)
	{
		while (left!=right)
		{
			if(arr[right]<pivot){
				arr[left] = arr[right];
				break;
			}
			right--;
		}
		while (left!=right)
		{
			if(arr[left]>pivot){
				arr[right] = arr[left];
				break;
			}
			left++;
		}
	}
	arr[left] = pivot;
	return left;
}




void main() {

	int arr[] = {9,5,7,4,6,8,3,1,2,0};
	int k = 4;
	//int arr[] = { 7,6,5 };
	//int k = 1;
	int* result = smallest_k(arr,sizeof(arr)/sizeof(int),k);
	for (size_t i = 0; i < k; i++)
	{
		printf("%d,",*(result+i));
	}

	printf("\nhello\n");
}