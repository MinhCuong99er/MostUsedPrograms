//The approximation of the equation
// Xấp xỉ nghiệm của pt f(x) = 0
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

double caculacateF_x (double x) // Khai báo hàm f(x)
{
    return x*x*x*x + 2*x*x*x + 8*x*x + 4*x - 5 ;
}
double caculacateF_dx (double x) // Khai báo hàm f'(x)
{
    return 4*x*x*x + 6*x*x + 16*x + 4;
}
double caculacateF_d2x (double x) // Khai báo hàm f''(x)
{
    return 12*x*x + 12*x + 16;
}
double random(double a, double b)
{
    double x  = a + (b - a)*rand()/RAND_MAX;
    return (caculacateF_x(x)*caculacateF_d2x(x) > 0) ? x : random(a,b);
}
void tangentMethod(double a, double b, double c) // phương pháp Newton (Phương pháp tiếp tuyến)
{
    srand(time(NULL));
    double y;
    double x = random(a,b);
    int count=0;
    while (abs(x-y) > c)
    {
        y = x;
        x = y - caculacateF_x(y)/caculacateF_dx(y);
        count++;
    }
    cout << "Nghiem xap xi cua pt la: " << x
         << "\nSo lan lap la: " << count
         << "\nSai so la: " << abs(x-y) << "\n\n";
}
int main ()
{
    double accuracy,first,last;
    cout << "Nhap khoang phan ly nghiem [a, b] = ";
    cin >> first >> last;
    cout << "Nhap sai so / do chinh xac: ";
    cin >> accuracy;

    cout << endl;
    cout << "Ap dung phuong phap lap:\n";
    tangentMethod(first,last,accuracy);
    return 0;
}
