#include <iostream>
#include <algorithm>
#include <iomanip>
#include <fstream>
using namespace std;
double addition (double *p, int n)
{
    double sum=0;
    for (int i=0;i<n;i++)
    {
        if (i%2==0) sum += *(p+i);
    }
    return sum;
}
void toFile (double *p, int n)
{
    ofstream  Data;
    Data.open("data.txt",ios::out);
    Data << n << "\n";
    for (int i=0;i<n;i++) Data << fixed << setprecision(2) << *(p+i) << " ";
    Data << "\nend";
    Data.close();
}
bool is3ConsecutiveNumbers (double *p, int n)
{
    for (int i=0;i<n-2;i++)
    {
        if (*(p+i+2) - *(p+i+1) == 1 && *(p+i+1) -*(p+i) == 1) return true;
    }
    return false;
}

void delete5 (double *p, int n)
{
    sort(p,p+n);
    int i=n-1;
    while (*(p+i) != 5)
    {
        i--;
        n--;
    }
    cout << "\nMang sau khi xoa: ";
    for (i=0;i<n;i++) cout << *(p+i) << " ";
}
int main ()
{
    int n,i;
    cout << "Nhap so phan tu cua mang: ";
    cin >> n;
    double arr[n], *p;
    for (i=0;i<n;i++)
    {
        cout << "Nhap phan thu " << i+1 << ": ";
        cin >> arr[i];
    }
    p = arr;
    cout << "\nMang truoc khi sap xep: ";
    for (i=0;i<n;i++) cout << *(p+i) << " ";
    toFile(p,n);
    cout << "\nMang sau khi sap xep: ";
    sort(p,p+n);
    for (i=0;i<n;i++) cout << *(p+i) << " ";
    cout <<  endl << "\nTong cac phan tu co chi so chan trong mang: " << addition(p,n) << endl;
    cout << "Phan tu lon nhat trong mang: " << *(p+n-1) << " va phan tu lon nhi tong mang: " << *(p+n-2);

    if (is3ConsecutiveNumbers(p,n)) cout << "\nMang chua 3 so duong lien tiep\n";
    else cout << "\nMang ko chua 3 so duong lien tiep\n";
    delete5(p,n);
    return 0;
}

