// Áp dụng Công thức nội suy Lagrange và Newton tính gần đúng giá trị đa thức
#include <cmath>
#include <iostream>
using namespace std;

// Công thức nội suy Lagrange
double LagrangeInterpolationFormula (double x[], double y[], int k, double c) 
{
    double p = 0,Lagrange[k];
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

/* Công thức nội suy Newton

    Hàm kiểm tra sai phân tiến hay lùi:
        + Tiến trả về 1.
        + Lùi trả về 0.
        + Còn lại trả về -1.
*/
int invalidProcessOrBackward (double x[])
{
    long i,count=0;
    long n = sizeof(x)/sizeof(double);
    for (i=0;i<n-1;i++)
    {
        if (x[i]<x[i+1]) count++;
    }
    return (count==0) ? 0 : ((count == n-1) ? 1 : -1);
}
double caculateSignal (int i,int j, double x[], double y[]) // Tính tỷ hiệu
{
    if (j==i+1 ) return (y[j]-y[i])/(x[j]-x[i]);
    else
        return (caculateSignal(i+1,j,x,y)/(x[j]-x[i]) - caculateSignal(i,j-1,x,y)/(x[j]-x[i]));
}
double NewtonProgressInterpolationFormula (double x[], double y[],int k, double c) // Nôi suy Newton tiến
{
    int i,j;
    double p = y[0];
    for (i=1;i<k;i++)
    {
        double temp = 1.0;
        for (j=0;j<i;j++) temp *= (c-x[j]);
        p += temp*caculateSignal(0,i,x,y);
    }
    return p;
}
double NewtonBackInterpolationFormula (double x[], double y[],int k, double c) // Nôi suy Newton lùi
{
    int i,j;
    double p = y[k-1];
    for (i=k-2;i>=0;i--)
    {
        double temp = 1.0;
        for (j=k-2;j>=1;j--) temp *= (c-x[j]);
        p += temp*caculateSignal(i-k,i,x,y);
    }
    return p;
}

int main ()
{
    int n,i,j;
    cout << "Nhap so diem moc + 1: ";
    cin >> n;
    double c;
    cout << "Nhap gia tri: ";
    cin >> c;
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
    cout << "\nGia tri gan dung cua da thuc tai x = c la: \n+ Ap dung cong thuc noi suy Lagrange: f(c) ~ "
         << LagrangeInterpolationFormula(x,y,n+1,c)
         << "\n+ Ap dung cong thuc noi suy Newton: f(c) ~ "
    //if (invalidProcessOrBackward(x)==1)
         << NewtonProgressInterpolationFormula(x,y,n+1,c);
    //else if (invalidProcessOrBackward(x)==0)
        //cout << NewtonBackInterpolationFormula(x,y,n+1,c);
    return 0;
}
