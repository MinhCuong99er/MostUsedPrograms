//The approximation of the equation
// Xấp xỉ nghiệm của pt f(x) = 0

#include <cmath>
#include <iostream>
using namespace std;

double caculacateF_x (double x) // Khai báo hàm f(x)
{
    return x*cos(x) - 2*x*x + 3*x -1 ;
}
void theBisectionMethod(double a, double b, double c) // Phương pháp chia đôi
{
    double p,k;
    k = abs(a-b);
    int count=0;
    while (abs(caculacateF_x(p)) > c)  /* |a - b| > c và f(p) != 0 */
    {
        p = (a+b)*0.5;
        if (caculacateF_x(p)*caculacateF_x(a)<0) b = p;
        else a = p;
        count++;
    }
    cout << "Khoang phan ly nghiem: [" << a << " , " << b << "]"
         << "\nNghiem xap xi cua pt la: " << p
         << "\nSo lan lap la: " << count
         << "\nSai so la: " << k/(pow(2,count)) << "\n\n";
}
double theBowingMethod (double a, double b, double c) // Phương pháp dây cung
{
    int count=0;
    double p = a - ((b-a)*caculacateF_x(a)/(caculacateF_x(b) - caculacateF_x(a)));
    if (caculacateF_x(p)*caculacateF_x(a) < 0)
    {
        while (abs(caculacateF_x(p)) > c)
        {
            b = p;
            p = a - (b-a)*caculacateF_x(a)/(caculacateF_x(b) - caculacateF_x(a));
            count++; 
        }
    }
    else
    {
        while (abs(caculacateF_x(p)) > c)
        {
            a = p;
            p = a - (b-a)*caculacateF_x(a)/(caculacateF_x(b) - caculacateF_x(a));
            count++;
        }
    }
    cout << "Khoang phan ly nghiem: [" << a << " , " << b << "]"
         << "\nNghiem xap xi cua pt la: " << p
         << "\nSo lan lap la: " << count << "\n\n";
}

int main ()
{
    double accuracy,first,last;
    cout << "Nhap khoang phan ly nghiem [a, b] = ";
    cin >> first >> last;
    cout << "Nhap sai so / do chinh xac: ";
    cin >> accuracy;

    cout << endl;
    cout << "Ap dung phuong phap chia doi:\n";
    theBisectionMethod(first,last,accuracy);
    cout << "Ap dung phuong phap day cung:\n";
    theBowingMethod(first,last,accuracy);
    return 0;
}
