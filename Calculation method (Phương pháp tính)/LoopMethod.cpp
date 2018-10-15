/*LoopMethod.cpp
  The approximation of the equation
  Xấp xỉ nghiệm của pt f(x) = 0 */
#include <stdlib.h>
#include <cmath>
#include <ctime>
#include <iostream>
using namespace std;

double caculacateF_x (double x) // Khai báo hàm f(x)
{
    return  pow(1+4*x,0.25) ;
}
double random(double a, double b) // Hàm Random số thực từ a đến b
{
   return a + (b - a)*rand()/RAND_MAX;
}
void loopMethod (double a, double b, double c) // phương pháp lặp
{
    srand(time(NULL));
    double x = random(a,b),y;
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

    cout << "\nAp dung phuong phap lap:\n";
    loopMethod(first,last,accuracy);
    return 0;
}
