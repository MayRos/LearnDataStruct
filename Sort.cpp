#include <vector>
#include <iostream>
using namespace std;

/*冒泡排序：它重复地走访过要排序的数列，一次比较两个元素，如果他们的顺序错误就把他们交换过来。
数据对象：数组
稳定性：true
排序方式：内部排序
平均时间复杂度：    O(n*n)
最好时间复杂度：    O(n*n)
最坏时间复杂度：    O(n*n)
空间复杂度:         O(1)
算法：比较相邻的元素。如果第一个比第二个大，就交换他们两个。

对每一对相邻元素作同样的工作，从开始第一对到结尾的最后一对。这步做完后，最后的元素会是最大的数。

针对所有的元素重复以上的步骤，除了最后一个。

持续每次对越来越少的元素重复上面的步骤，直到没有任何一对数字需要比较。
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

/*选择排序：
数据对象：数组    链表
稳定性：true     false
排序方式：内部排序
平均时间复杂度：    O(n*n)
最好时间复杂度：    O(n*n)
最坏时间复杂度：    O(n*n)
空间复杂度:         O(1)
算法：首先在未排序序列中找到最小（大）元素，存放到排序序列的起始位置。

再从剩余未排序元素中继续寻找最小（大）元素，然后放到已排序序列的末尾。

重复第二步，直到所有元素均排序完毕。
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

/*插入排序：它的工作原理是通过构建有序序列，对于未排序数据，在已排序序列中从后向前扫描，找到相应位置并插入。
数据对象：数组    链表
稳定性：true
排序方式：内部排序
平均时间复杂度：    O(n*n)
最好时间复杂度：    O(n)
最坏时间复杂度：    O(n*n)
空间复杂度:         O(1)
算法：将第一待排序序列第一个元素看做一个有序序列，把第二个元素到最后一个元素当成是未排序序列。

从头到尾依次扫描未排序序列，将扫描到的每个元素插入有序序列的适当位置。

（如果待插入的元素与有序序列中的某个元素相等，则将待插入元素插入到相等元素的后面。）
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

/*希尔排序：先将整个待排序的记录序列分割成为若干子序列分别进行直接插入排序，
待整个序列中的记录"基本有序"时，再对全体记录进行依次直接插入排序。

数据对象：
稳定性：false
排序方式：内部排序
平均时间复杂度：	O(nlog2n)
最好时间复杂度：    O(n)
最坏时间复杂度：    O(nlog2n)
空间复杂度:         O(1)
算法：选择一个增量序列 t1，t2，……，tk，其中 ti > tj, tk = 1；

按增量序列个数 k，对序列进行 k 趟排序；

每趟排序，根据对应的增量 ti，将待排序列分割成若干长度为 m 的子序列，

分别对各子表进行直接插入排序。仅增量因子为 1 时，整个序列作为一个表来处理，

表长度即为整个序列的长度。
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

/*归并排序：是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。

数据对象：数组			链表
稳定性：true
排序方式：外部排序
平均时间复杂度：	O(nlogn)
最好时间复杂度：    O(nlogn)
最坏时间复杂度：    O(nlogn)
空间复杂度:         O(n)
算法：申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；

设定两个指针，最初位置分别为两个已经排序序列的起始位置；

比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；

重复步骤 3 直到某一指针达到序列尾；

将另一序列剩下的所有元素直接复制到合并序列尾。
*/
template<typename T>
void mergeSort(T array[], int len) {
	T* a = array;
	T* b = new T[len];
	for (int i = 1; i < len; i += i)							// 每次比较的步长逐步增大
	{
		for (int start = 0; start < len; start += i + i )		// 每两组之间进行比较
		{
			int low = start;
			int mid = (start + i) < len ? (start + i) : len;
			int high = (start + i + i) < len ? (start + i + i) : len;
			int k = low;
			int start1 = low;									// 第一个数组的开始（含）
			int end1 = mid;										// 第一个数组的结束（不含）
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

/*快速排序：是建立在归并操作上的一种有效的排序算法。该算法是采用分治法（Divide and Conquer）的一个非常典型的应用。

数据对象：数组			
稳定性：true
排序方式：外部排序
平均时间复杂度：	O(nlogn)
最好时间复杂度：    O(nlogn)
最坏时间复杂度：    O(n*n)
空间复杂度:         O(logn)
算法：申请空间，使其大小为两个已经排序序列之和，该空间用来存放合并后的序列；

设定两个指针，最初位置分别为两个已经排序序列的起始位置；

比较两个指针所指向的元素，选择相对小的元素放入到合并空间，并移动指针到下一位置；

重复步骤 3 直到某一指针达到序列尾；

将另一序列剩下的所有元素直接复制到合并序列尾。
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