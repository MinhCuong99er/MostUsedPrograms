#include<iostream>
#include<cstdlib>
#include<ctime>
using namespace std;

void arrayIn (int array[], int &size)
{
    srand(time(NULL));
    for (int i=0;i<size;i++) array[i] = rand()%99;
}
void arrayOut (int array[], int size)
{
    for (int i=0;i<size;i++) cout << array[i] << " ";
    cout << "\n";
}
void arrayCopy (int a[], int b[], int size)
{
    for (int i=0;i<size;i++) b[i] = a[i];
}

// Sắp xếp nổi bọt - T = O(n*n)
void BubbleSort (int array[], int size)
{
    cout << "+ Bubble Sort:\t  ";
    int b[size],i,j;
    arrayCopy(array,b,size);
    for (i=0;i<size-1;i++)
    {
        for (j=0;j<size-1;j++)
        {
            if (b[j] > b[j+1]) swap(b[j],b[j+1]);
        }
    }
    arrayOut(b,size);
}
// Sắp xếp lựa chọn - T = O(n*n)
void SelectionSort(int array[], int size)
{
    cout << "+ Selection Sort: ";
    int b[size],i,j,min;
    arrayCopy(array,b,size);
	for (i=0;i<size-1;i++)
	{
		min = i;
		for (j=i+1;j<size;j++)
			if (b[min]>b[j]) min = j;
			swap(b[i], b[min]);
	}
	arrayOut(b,size);
}
// Sắp xếp xen vào - T = O(n*n)
void InsertionSort (int array[], int size)
{
    cout << "+ Insertion Sort: ";
    int b[size],i,j,temp;
    arrayCopy(array,b,size);
    for (i=1;i<size;i++)
    {
        /* Di chuyển các phần tử có giá trị lớn hơn giá trị
       key về sau một vị trí so với vị trí ban đầu
       của nó */
        temp = b[i];
        j = i - 1;
        while (j>=0 && b[j]>temp)
        {
            b[j+1] = b[j];
            j--;
        }
        b[j+1] = temp;
    }
    arrayOut(b,size);
}
// Sắp xếp nhanh - T = O(nlog(n))
void QuickSort(int array[], int left, int right)
{
    int i =  left,j = right;
    int x = array[(left+right)/2];
    do
    {
        while(array[i] < x && i < right) i++;
        while(array[j] > x && j > left) j--;
        if (i <= j)
        {
            swap(array[i], array[j]);
            i++;
            j--;
        }
    }
    while (i <= j);
    if (left < j) QuickSort(array,left,j);
    if (i < right) QuickSort(array,i,right);
}
void QuickSortArray(int array[], int size)
{
    int b[size];
    cout << "+ Quick Sort:\t  ";
    arrayCopy(array,b,size);
    QuickSort(b,0,size-1);
    arrayOut(b,size);
}
// Sắp xếp hòa nhập - T = O(nlog(n))
void Merge(int array[], int left, int mid, int right)
{
	int a[mid-left+1], b[right-mid];
	int i, index_array = left;
	for(i = 0; i < mid-left+1; i++) a[i] = array[index_array++];
	for(i = 0; i < right-mid; i++) b[i] = array[index_array++];
	int index_temp1 = 0,index_temp2 = 0;
	index_array = left;
	while(index_temp1 <= mid-left && index_temp2 < right-mid)
    {
		if (a[index_temp1] < b[index_temp2])
        {
			array[index_array] = a[index_temp1];
			index_temp1++;
		}
		else
        {
			array[index_array] = b[index_temp2];
			index_temp2++;
		}
		index_array++;
	}
	while(index_temp1 <= mid-left)
    {
		array[index_array] = a[index_temp1];
		index_array++;
		index_temp1++;
	}
	while(index_temp2 < right-mid)
    {
		array[index_array] = b[index_temp2];
		index_array++;
		index_temp2++;
	}
}
void MergeSort(int array[],int left, int right)
{
	int mid = (right+left)/2;
	if (left < right)
    {
		MergeSort(array,left,mid);
		MergeSort(array,mid+1,right);
		Merge(array,left,mid,right);
	}
}
void MergeSortArray (int array[],int size)
{
    int b[size];
    cout << "+ Merge Sort:\t  ";
    arrayCopy(array,b,size);
    MergeSort(b,0,size-1);
    arrayOut(b,size);
}
// Sắp xếp sử dụng cây thứ tự bộ phận - T = O(nlog(n))
void Heapify(int array[], int length, int i)
{
	int largest = i;
	int left = 2*i+1;
	int right = 2*i+2;

	if (left < length && array[left] > array[largest]) largest = left;
	if (right < length && array[right] > array[largest]) largest = right;
	if (largest != i)
	{
		swap(array[i], array[largest]);
		Heapify(array,length,largest);
	}
}
void HeapSort (int array[], int size)
{
    cout << "+ Heap Sort:\t  ";
    int b[size],i;
    arrayCopy(array,b,size);
    for (int i = size/2-1; i>=0; i--)
		Heapify(b,size,i);

	for (int i = size-1; i>=0 ; i--)
	{
		swap(b[0],b[i]);
		Heapify(b,i,0);
	}
    arrayOut(b,size);
}
int main()
{
    int size;
    srand(time(NULL));
    size = rand()%10+2;
    cout << "The number of elements of the array is: " << size << endl;
    int array[size];
    arrayIn(array,size);
    cout << "The array which has just been entered is: ";
    arrayOut(array,size);

    cout << "\nThe array after sorting is:\n";
    BubbleSort(array,size);
    SelectionSort(array,size);
    InsertionSort(array,size);
    HeapSort(array,size);
    QuickSortArray(array,size);
    MergeSortArray(array,size);

    return 0;
}
