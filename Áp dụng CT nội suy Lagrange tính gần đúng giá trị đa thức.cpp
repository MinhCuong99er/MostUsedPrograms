#include <cmath>
#include <iostream>
using namespace std;

float caculacation (float x[], float y[], int k, float c)
{
    float p = 0,Lagrange[k];
    int i,j;
    for (i=0;i<k;i++)
    {
        // Tinh gia tri cua da thuc Lagrange co ban thu i
        Lagrange[i] = 1;
        for (j=0;j<k;j++)
        {
            if (i!=j) Lagrange[i] *= (c-x[j])/(x[i]-x[j]);
        }
        // Cong y[i]*Lagrange[i] vao ket qua
        p += y[i]*Lagrange[i];
    }
    return p;
}
int main ()
{
    int n,i,j;
    float c;
    cout << "Nhap so diem moc + 1: ";
    cin >> n;
    cout << "Nhap gia tri: ";
    cin >> c;
    float x[n+1],y[n+1];
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
    cout << "\nGia tri gan dung cua da thuc tai x = c la: " << caculacation(x,y,n+1,c);
    return 0;
}
