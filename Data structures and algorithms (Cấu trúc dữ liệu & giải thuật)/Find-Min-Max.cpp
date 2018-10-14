#include<iostream>
#include <cmath>
using namespace std;
void findMinMax (float arr[], int n)
{
    float max,min;
    min = arr[0];
    max = arr[0];
    for (int i=0;i<n;i++)
    {
        min = (min + arr[i])/2 - abs(min - arr[i])/2;
        max = (max + arr[i])/2 + abs(max - arr[i])/2;
    }
    cout << min << " " << max;
}
int main ()
{
    int n;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    float arr[n];
    for (int i=0;i<n;i++)
    {
        cout << "Nhap phan tu thu " << i+1 << ": ";
        cin >> arr[i];
    }
    cout << "Phan tu nho nhat va lon nhat cua mang: ";
    findMinMax(arr,n);
}
