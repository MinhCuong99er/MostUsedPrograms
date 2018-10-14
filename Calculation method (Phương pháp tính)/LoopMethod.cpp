//The approximation of the equation
// Xấp xỉ nghiệm của pt f(x) = 0

#include <cmath>
#include <iostream>
using namespace std;

double caculacateF_x (double x) // Khai báo hàm f(x)
{
    return x*cos(x) - 2*x*x + 3*x -1 ;
}
void loopMethod (double a, double b, double c) // phương pháp lặp
{
    double x = min(a,b),y;
    int count=0;
    while (abs(x-y) > c)
    {
        y = x;
        x = caculacateF_x(x);
        count++;
    }
    cout << "Nghiem xap xi cua pt la: " << x
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
    cout << "Ap dung phuong phap lap:\n";
    loopMethod(first,last,accuracy);
    return 0;
}
