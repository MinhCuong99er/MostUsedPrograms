// Xấp xỉ nghiệm của pt f(x) = 0 bằng pp chia đôi
#include<iostream>
#include<cmath>
using namespace std;

float findFx (float x)
{
    return pow(x,6) + pow(x,5) + 3*x - 1;
}
void xapxinghiem (float a, float b, float c)
{
    float p,k;
    k = abs(a-b);
    int count=0;
    while (abs(findFx(p)) > c)  /* |a - b| > c và f(p) != 0 */
    {
        p = (a+b)*0.5;
        if (findFx(p)*findFx(a)<0) b = p;
        else a = p;
        count++;
    }
    cout << "Nghiem xap xi cua pt la: " << p 
         << "\nSo lan lap la: " << count
         << "\nSai so la: " << k/(pow(2,count));
}
int main ()
{
    float a,b,c;
    cout << "Nhap khoang gia tri mien xac dinh: ";
    cin >> a >> b;
    cout << "Nhap do chinh xac: ";
    cin >> c;
    xapxinghiem(a,b,c);
    return 0;
}
