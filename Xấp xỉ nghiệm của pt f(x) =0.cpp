#include<iostream>
#include<cmath>
using namespace std;

float findFx (float x)
{
    return pow(x,6) + pow(x,5) + 3*x - 1;
}
void xapxinghiem (float a, float b, float c)
{
    float p;
    int count=0;
    while (b-a>=c)
    {
        p = (a+b)*0.5;
        if (findFx(p)*findFx(a)<0) b = p;
        else a = p;
        count++;
    }
    cout << "Nghiem xap xi cua pt la: " << p << endl;
    cout << "So lan lap: " << count << endl;
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

