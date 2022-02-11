#include <vector>
#include <iostream>
using namespace std;

/*ð���������ظ����߷ù�Ҫ��������У�һ�αȽ�����Ԫ�أ�������ǵ�˳�����Ͱ����ǽ���������
���ݶ�������
�ȶ��ԣ�true
����ʽ���ڲ�����
ƽ��ʱ�临�Ӷȣ�    O(n*n)
���ʱ�临�Ӷȣ�    O(n*n)
�ʱ�临�Ӷȣ�    O(n*n)
�ռ临�Ӷ�:         O(1)
�㷨���Ƚ����ڵ�Ԫ�ء������һ���ȵڶ����󣬾ͽ�������������

��ÿһ������Ԫ����ͬ���Ĺ������ӿ�ʼ��һ�Ե���β�����һ�ԡ��ⲽ���������Ԫ�ػ�����������

������е�Ԫ���ظ����ϵĲ��裬�������һ����

����ÿ�ζ�Խ��Խ�ٵ�Ԫ���ظ�����Ĳ��裬ֱ��û���κ�һ��������Ҫ�Ƚϡ�
*/
template<typename T>
void bubbleSort(T array[],int len) {
	for (int  i = 0; i < len-1; i++)
	{
		for (int j = 0; j < len-1; j++)
		{
			if (array[j] > array[j + 1]) {
				int temp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = temp;
			}
		}
	}
}

/*ѡ������
���ݶ�������    ����
�ȶ��ԣ�true     false
����ʽ���ڲ�����
ƽ��ʱ�临�Ӷȣ�    O(n*n)
���ʱ�临�Ӷȣ�    O(n*n)
�ʱ�临�Ӷȣ�    O(n*n)
�ռ临�Ӷ�:         O(1)
�㷨��������δ�����������ҵ���С����Ԫ�أ���ŵ��������е���ʼλ�á�

�ٴ�ʣ��δ����Ԫ���м���Ѱ����С����Ԫ�أ�Ȼ��ŵ����������е�ĩβ��

�ظ��ڶ�����ֱ������Ԫ�ؾ�������ϡ�
*/
template<typename T>
void selectionSort(T array[], int len) {
	for (int i = 0; i < len-1; i++)
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (array[min] > array[j]) {
				min = j;
			}
		}
		int temp = array[i];
		array[i] = array[min];
		array[min] = temp;
	}
}

/*�����������Ĺ���ԭ����ͨ�������������У�����δ�������ݣ��������������дӺ���ǰɨ�裬�ҵ���Ӧλ�ò����롣
���ݶ�������    ����
�ȶ��ԣ�true
����ʽ���ڲ�����
ƽ��ʱ�临�Ӷȣ�    O(n*n)
���ʱ�临�Ӷȣ�    O(n)
�ʱ�临�Ӷȣ�    O(n*n)
�ռ临�Ӷ�:         O(1)
�㷨������һ���������е�һ��Ԫ�ؿ���һ���������У��ѵڶ���Ԫ�ص����һ��Ԫ�ص�����δ�������С�

��ͷ��β����ɨ��δ�������У���ɨ�赽��ÿ��Ԫ�ز����������е��ʵ�λ�á�

������������Ԫ�������������е�ĳ��Ԫ����ȣ��򽫴�����Ԫ�ز��뵽���Ԫ�صĺ��档��
*/
template<typename T>
void insertSort(T array[], int len) {
	for (int i = 1; i < len; i++)
	{
		int waitNum = array[i];
		int j = i;
		for ( ; j > 0 && waitNum < array[j - 1]; j--)
		{
				array[j] = array[j-1];
		}
		array[j] = waitNum;
	}
}

/*ϣ�������Ƚ�����������ļ�¼���зָ��Ϊ���������зֱ����ֱ�Ӳ�������
�����������еļ�¼"��������"ʱ���ٶ�ȫ���¼��������ֱ�Ӳ�������

���ݶ���
�ȶ��ԣ�false
����ʽ���ڲ�����
ƽ��ʱ�临�Ӷȣ�	O(nlog2n)
���ʱ�临�Ӷȣ�    O(n)
�ʱ�临�Ӷȣ�    O(nlog2n)
�ռ临�Ӷ�:         O(1)
�㷨��ѡ��һ���������� t1��t2��������tk������ ti > tj, tk = 1��

���������и��� k�������н��� k ������

ÿ�����򣬸��ݶ�Ӧ������ ti�����������зָ�����ɳ���Ϊ m �������У�

�ֱ�Ը��ӱ����ֱ�Ӳ������򡣽���������Ϊ 1 ʱ������������Ϊһ����������

���ȼ�Ϊ�������еĳ��ȡ�
*/
template<typename T>
void shellSort(T array[], int len) {
	int d = 1;
	while ( d < len/3 ) {
		d = 3 * d + 1;
	}
	while (d > 0)
	{
		for (int  i = d; i < len; i++)
		{
			for (int j = i; j >= d && array[j] < array[j - d]; j -= d)
			{
				int temp = array[j];
				array[j] = array[j - d];
				array[j - d] = temp;
			}
		}
		d /= 3;
	}
}

/*�鲢�����ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨�����㷨�ǲ��÷��η���Divide and Conquer����һ���ǳ����͵�Ӧ�á�

���ݶ�������			����
�ȶ��ԣ�true
����ʽ���ⲿ����
ƽ��ʱ�临�Ӷȣ�	O(nlogn)
���ʱ�临�Ӷȣ�    O(nlogn)
�ʱ�临�Ӷȣ�    O(nlogn)
�ռ临�Ӷ�:         O(n)
�㷨������ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ�������У�

�趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ�ã�

�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ�ã�

�ظ����� 3 ֱ��ĳһָ��ﵽ����β��

����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β��
*/
template<typename T>
void mergeSort(T array[], int len) {
	T* a = array;
	T* b = new T[len];
	for (int i = 1; i < len; i += i)							// ÿ�αȽϵĲ���������
	{
		for (int start = 0; start < len; start += i + i )		// ÿ����֮����бȽ�
		{
			int low = start;
			int mid = (start + i) < len ? (start + i) : len;
			int high = (start + i + i) < len ? (start + i + i) : len;
			int k = low;
			int start1 = low;									// ��һ������Ŀ�ʼ������
			int end1 = mid;										// ��һ������Ľ�����������
			int start2 = mid;
			int end2 = high;
			while (start1 < end1 && start2 < end2)
			{
				b[k++] = a[start1] > a[start2] ? a[start2++] : a[start1++];
			}
			while (start1 < end1) {
				b[k++] = a[start1++];
			}
			while (start2<end2)
			{
				b[k++] = a[start2++];
			}
		}
		T* temp = a;
		a = b;
		b = temp;
	}
	if (a != array) {
		for (int i = 0; i < len; i++)
		{
			b[i] = a[i];
		}
		b = a;
	}
	delete[] b;
}

/*���������ǽ����ڹ鲢�����ϵ�һ����Ч�������㷨�����㷨�ǲ��÷��η���Divide and Conquer����һ���ǳ����͵�Ӧ�á�

���ݶ�������			
�ȶ��ԣ�true
����ʽ���ⲿ����
ƽ��ʱ�临�Ӷȣ�	O(nlogn)
���ʱ�临�Ӷȣ�    O(nlogn)
�ʱ�临�Ӷȣ�    O(n*n)
�ռ临�Ӷ�:         O(logn)
�㷨������ռ䣬ʹ���СΪ�����Ѿ���������֮�ͣ��ÿռ�������źϲ�������У�

�趨����ָ�룬���λ�÷ֱ�Ϊ�����Ѿ��������е���ʼλ�ã�

�Ƚ�����ָ����ָ���Ԫ�أ�ѡ�����С��Ԫ�ط��뵽�ϲ��ռ䣬���ƶ�ָ�뵽��һλ�ã�

�ظ����� 3 ֱ��ĳһָ��ﵽ����β��

����һ����ʣ�µ�����Ԫ��ֱ�Ӹ��Ƶ��ϲ�����β��
*/
template<typename T>
void quickSort(T array[], int length) {
	if (length <= 0) {
		return;
	}
	vector<vector<int>> range(length, vector<int>(2));
	//int range[length][2] = { 0 };
	int p = 0;
	range[p][0] = 0;
	range[p][1] = length - 1;
	p++;
	while (p) {
		int r[2] = { 0 };
		p--;
		r[0] = range[p][0];
		r[1] = range[p][1];
		if (r[0] >= r[1]) {
			continue;
		}
		T mid = array[r[0]];
		int left = r[0] + 1;
		int right = r[1];
		while (left < right) {
			while (array[left] < mid && left < right) {
				left++;
			}
			while (array[right] >= mid && left < right) {
				right--;
			}
			T temp = array[left];
			array[left] = array[right];
			array[right] = temp;
		}
		if (array[left]>=mid)
		{
			left--;
		}
		array[r[0]] = array[left];
		array[left] = mid;

		range[p][0] = r[0];
		range[p][1] = left - 1;
		p++;
		range[p][0] = left + 1;
		range[p][1] = r[1];
		p++;
	}
}