#include <vector>
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

/*快速排序：又是一种分而治之思想在排序算法上的典型应用。本质上来看，快速排序应该算是在冒泡排序基础上的递归分治法。

数据对象：数组			
稳定性：false
排序方式：内部排序
平均时间复杂度：	O(nlogn)
最好时间复杂度：    O(nlogn)
最坏时间复杂度：    O(n*n)
空间复杂度:         O(logn)
算法：从数列中挑出一个元素，称为 "基准"（pivot）;

重新排序数列，所有元素比基准值小的摆放在基准前面，所有元素比基准值大的摆在基准的后面（相同的数可以到任一边）。
在这个分区退出之后，该基准就处于数列的中间位置。这个称为分区（partition）操作；

递归地（recursive）把小于基准值元素的子数列和大于基准值元素的子数列排序；
*/
template<typename T>
void quickSort(T array[], int length) {
	if (length <= 0) {
		return;
	}
	vector<vector<int>> range(length, vector<int>(2));
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

/*堆排序：是指利用堆这种数据结构所设计的一种排序算法

数据对象：数组
稳定性：false
排序方式：内部排序
平均时间复杂度：	O(nlogn)
最好时间复杂度：    O(nlogn)
最坏时间复杂度：    O(nlogn)
空间复杂度:         O(1)
算法：创建一个堆 H[0……n-1]；

把堆首（最大值）和堆尾互换；

把堆的尺寸缩小 1，并调用 shift_down(0)，目的是把新的数组顶端数据调整到相应位置；

重复步骤 2，直到堆的尺寸为 1。
*/
template<typename T>
void heapSort(T array[], int length);
// 获取大顶堆堆首
template<typename T>
void maxHeapify(T array[], int start, int end) {
	int parent = start;
	int son = start * 2 + 1;
	while (son <= end) {
		if (son + 1 <= end && array[son] < array[son + 1]) {
			son++;
		}
		if (array[parent]>array[son])
		{
			return;
		}
		else
		{
			int temp = array[parent];
			array[parent] = array[son];
			array[son] = temp;
			parent = son;
			son = parent * 2 + 1;
		}
	}
}
template<typename T>
void heapSort(T array[], int length) {
	for (int i = length / 2 - 1; i >= 0; i--)
	{
		maxHeapify(array, i, length - 1);
	}
	for (int i = length - 1; i > 0; i--)
	{
		int temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		maxHeapify(array, 0, i - 1);
	}
}

/*计数排序：核心在于将输入的数据值转化为键存储在额外开辟的数组空间中。
作为一种线性时间复杂度的排序，计数排序要求输入的数据必须是有确定范围的整数。
数据对象：数组		链表
稳定性：true
排序方式：外部排序
平均时间复杂度：	O(n+k)
最好时间复杂度：    O(n+k)
最坏时间复杂度：    O(n+k)
空间复杂度:         O(k)
算法：（1）找出待排序的数组中最大和最小的元素
（2）统计数组中每个值为i的元素出现的次数，存入数组C的第i项
（3）对所有的计数累加（从C中的第一个元素开始，每一项和前一项相加）
（4）反向填充目标数组：将每个元素i放在新数组的第C(i)项，每放一个元素就将C(i)减去1
*/
//template<typename T>
static void countSort(int array[], int length) {
	int count[100] = {0};
	for (int i = 0; i < length; i++) {
		count[array[i]]++;
	}
	int n = 0;
	for (int i = 0; i < 100; i++)
	{
		for (int j = 0; j < count[i]; j++) {
			array[n] = i;
			n++;
		}
	}
}

/*桶排序：计数排序的升级版。它利用了函数的映射关系，高效与否的关键就在于这个映射函数的确定。

数据对象：数组		链表
稳定性：true
排序方式：外部排序
平均时间复杂度：	O(n+k)
最好时间复杂度：    O(n+k)
最坏时间复杂度：    O(n*n)
空间复杂度:         O(n+k)
算法：
*/
static void buchetSort(int array[], int n);
struct ListNode {
	explicit ListNode(int i = 0) :mData(i), mNext(NULL) {}
	ListNode* mNext;
	int mData;
};
static ListNode* insert(ListNode* head,int val){
	ListNode dummyNode;
	ListNode *newNode = new ListNode(val);
	ListNode *pre,*curr;
	dummyNode.mNext = head;
	pre = &dummyNode;
	curr = head;
	while(NULL != curr && curr->mData<=val){
		pre = curr;
		curr = curr->mNext;
	}
	newNode->mNext = curr;
	pre->mNext = newNode;
	return dummyNode.mNext; 
}
static ListNode* Merge(ListNode* head1,ListNode* head2){
	ListNode dummyNode;
	ListNode *dummy = &dummyNode;
	while(NULL != head1 && NULL != head2){
		if(head1->mData <= head2->mData){
			dummy->mNext = head1;
			head1 = head1->mNext;
		}else{
			dummy->mNext = head2;
			head2 = head2->mNext;
		}
		dummy = dummy->mNext;
	}
	if(NULL != head1)dummy->mNext = head1;
	if(NULL != head2)dummy->mNext = head2;
	return dummyNode.mNext;
}
static void buchetSort(int array[], int n){
	const int BUCKET_NUM = 10;
	vector<ListNode*> buckets(BUCKET_NUM,(ListNode*)(0));
	for (int i = 0; i < n; i++) {
		int index = array[i] / BUCKET_NUM;
		ListNode* head = buckets.at(index);
		buckets.at(index) = insert(head, array[i]);
	}
	ListNode *head = buckets.at(0);
	for (int i = 1; i < BUCKET_NUM; ++i) {
		head = Merge(head, buckets.at(i));
	}
	for (int  i = 0; i < n ; ++i)
	{
		array[i] = head->mData;
		head = head->mNext;
	}
}
/*基数排序：其原理是将整数按位数切割成不同的数字，然后按每个位数分别比较。

数据对象：数组		链表
稳定性：true
排序方式：外部排序
平均时间复杂度：	O(n*k)
最好时间复杂度：    O(n*k)
最坏时间复杂度：    O(n*k)
空间复杂度:         O(n+k)
算法：
*/
static void radixSort(int array[], int n);
// 求数组中最大数的位数
static int maxbit(int array[], int n) {
	int max = array[0];
	for (int i = 1; i < n; i++)
	{
		if (max < array[i]) {
			max = array[i];
		}
	}
	int bit = 1;
	int p = 10;
	while (max>p)
	{
		max = max / p;
		bit++;
	}
	return bit;
}
static void radixSort(int array[], int n) {
	int bit = maxbit(array, n);
	int* tmp = new int[n];
	int* count = new int[10];
	int i, j, k;
	int radix = 1;
	for (i = 0; i < bit; i++)
	{
		for(j =0;j<10;j++)
		{
			count[j] = 0;
		}
		for (j = 0; j < n; j++)
		{
			k = (array[j] / radix )% 10;
			count[k]++;
		}
		for (j = 1; j < 10; j++)
		{
			count[j] += count[j - 1];
		}
		for (j = n - 1; j >= 0; j--) {
			k = (array[j] / radix) % 10;
			tmp[count[k] - 1] = array[j];
			count[k]--;
		}
		for (j = 0; j < n; j++)
		{
			array[j] = tmp[j];
		}
		radix *= 10;
	}
	delete []tmp;
	delete[]count;
}