#include <vector>
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

/*������������һ�ֶַ���֮˼���������㷨�ϵĵ���Ӧ�á���������������������Ӧ��������ð����������ϵĵݹ���η���

���ݶ�������			
�ȶ��ԣ�false
����ʽ���ڲ�����
ƽ��ʱ�临�Ӷȣ�	O(nlogn)
���ʱ�临�Ӷȣ�    O(nlogn)
�ʱ�临�Ӷȣ�    O(n*n)
�ռ临�Ӷ�:         O(logn)
�㷨��������������һ��Ԫ�أ���Ϊ "��׼"��pivot��;

�����������У�����Ԫ�رȻ�׼ֵС�İڷ��ڻ�׼ǰ�棬����Ԫ�رȻ�׼ֵ��İ��ڻ�׼�ĺ��棨��ͬ�������Ե���һ�ߣ���
����������˳�֮�󣬸û�׼�ʹ������е��м�λ�á������Ϊ������partition��������

�ݹ�أ�recursive����С�ڻ�׼ֵԪ�ص������кʹ��ڻ�׼ֵԪ�ص�����������
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

/*��������ָ���ö��������ݽṹ����Ƶ�һ�������㷨

���ݶ�������
�ȶ��ԣ�false
����ʽ���ڲ�����
ƽ��ʱ�临�Ӷȣ�	O(nlogn)
���ʱ�临�Ӷȣ�    O(nlogn)
�ʱ�临�Ӷȣ�    O(nlogn)
�ռ临�Ӷ�:         O(1)
�㷨������һ���� H[0����n-1]��

�Ѷ��ף����ֵ���Ͷ�β������

�Ѷѵĳߴ���С 1�������� shift_down(0)��Ŀ���ǰ��µ����鶥�����ݵ�������Ӧλ�ã�

�ظ����� 2��ֱ���ѵĳߴ�Ϊ 1��
*/
template<typename T>
void heapSort(T array[], int length);
// ��ȡ�󶥶Ѷ���
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

/*�������򣺺������ڽ����������ֵת��Ϊ���洢�ڶ��⿪�ٵ�����ռ��С�
��Ϊһ������ʱ�临�Ӷȵ����򣬼�������Ҫ����������ݱ�������ȷ����Χ��������
���ݶ�������		����
�ȶ��ԣ�true
����ʽ���ⲿ����
ƽ��ʱ�临�Ӷȣ�	O(n+k)
���ʱ�临�Ӷȣ�    O(n+k)
�ʱ�临�Ӷȣ�    O(n+k)
�ռ临�Ӷ�:         O(k)
�㷨����1���ҳ��������������������С��Ԫ��
��2��ͳ��������ÿ��ֵΪi��Ԫ�س��ֵĴ�������������C�ĵ�i��
��3�������еļ����ۼӣ���C�еĵ�һ��Ԫ�ؿ�ʼ��ÿһ���ǰһ����ӣ�
��4���������Ŀ�����飺��ÿ��Ԫ��i����������ĵ�C(i)�ÿ��һ��Ԫ�ؾͽ�C(i)��ȥ1
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

/*Ͱ���򣺼�������������档�������˺�����ӳ���ϵ����Ч���Ĺؼ����������ӳ�亯����ȷ����

���ݶ�������		����
�ȶ��ԣ�true
����ʽ���ⲿ����
ƽ��ʱ�临�Ӷȣ�	O(n+k)
���ʱ�临�Ӷȣ�    O(n+k)
�ʱ�临�Ӷȣ�    O(n*n)
�ռ临�Ӷ�:         O(n+k)
�㷨��
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
/*����������ԭ���ǽ�������λ���и�ɲ�ͬ�����֣�Ȼ��ÿ��λ���ֱ�Ƚϡ�

���ݶ�������		����
�ȶ��ԣ�true
����ʽ���ⲿ����
ƽ��ʱ�临�Ӷȣ�	O(n*k)
���ʱ�临�Ӷȣ�    O(n*k)
�ʱ�临�Ӷȣ�    O(n*k)
�ռ临�Ӷ�:         O(n+k)
�㷨��
*/
static void radixSort(int array[], int n);
// ���������������λ��
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