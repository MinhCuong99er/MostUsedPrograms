#include <cmath>
#include <iostream>
using namespace std;

int invalidProcessOrBackward (float x[])
{
    long i,count=0;
    long n = sizeof(x)/sizeof(float);
    for (i=0;i<n-1;i++)
    {
        if (x[i]<x[i+1]) count++;
    }
    return (count==0) ? 0 : ((count == n-1) ? 1 : -1);
}
double caculateSignal (int i,int j, double x[], double y[]) // Tính tủ hiệu
{
    if (j==i+1) return (y[j]-y[i])/(x[j]-x[i]);
    else
        return (caculateSignal(i+1,j,x,y)/(x[j]-x[i]) - caculateSignal(i,j-1,x,y)/(x[j]-x[i]));
}


int main ()
{
    int n,i,j,first,last;
    cout << "Nhap so diem moc + 1: ";
    cin >> n;
    double c;
    double x[n+1],y[n+1];
    cout << endl;
    for (i=0;i<n+1;i++)
    {
        cout << "Nhap gia tri x: x(" << i <<") = ";
        cin >> x[i];
    }
    for (i=0;i<n+1;i++)
    {
        cout << "Nhap gia tri y = f(x): f[x(" << i<<")] = ";
        cin >> y[i];
    }
    cout << "Nhap vi tri luc dau: ";
    cin >> first;
    cout << "Nhap vi tri luc sau: ";
    cin >> last;
    cout << "Gia tri cua ty hieu tu vi tri i toi vi tri j la: "
         << caculateSignal(first,last,x,y);
    return 0;
}
