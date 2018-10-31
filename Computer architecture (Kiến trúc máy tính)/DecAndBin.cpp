#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

string LongDecToBin (long k) // Chuyển đổi số nguyên dài hệ 10 sang hệ 2
{
    if (k==0) return "0";
    else if (k==2) return "1";
    else
    {
        if (k%2==0) return LongDecToBin(k/2) + "0";
        else return LongDecToBin(k/2) + "1";
    }
}
//string longToString (long k)
//{
//    return to_string(k);
//}
long stringToLong (string a) // Chuyển dổi số thực dạng string sang long
{
    return atoi(a.c_str());
}
long BinToLongDec(long n) // Chuyển đổi số hệ 2 sang hệ 10
{
    long decimalNumber = 0, i = 0, remainder;
    while (n!=0)
    {
        remainder = n%10;
        n /= 10;
        decimalNumber += remainder*pow(2,i);
        ++i;
    }
    return decimalNumber;
}
string DoubleDecToBin(double k)  // Chuyển đổi số thực thuộc [0,1] hệ 10 sang hệ 2
{
    if (k==1.000) return "1";
    else
    {
        if (k>1) return "1" + DoubleDecToBin(k*2);
        else return "0" + DoubleDecToBin(k*2);
    }
}
string numberToBin (double n)  // Chuyển đổi số thực hệ 10 sang hệ 2
{
    long natural = (long) n;
    double real = (natural<n) ? (n - natural) : 0;
    return (real==0) ? LongDecToBin(natural) : (LongDecToBin(natural) + "0." + DoubleDecToBin(real*2));
}
void FloatDecToBin(double n) // Chuyển đổi số thực bất kì hệ 10 sang hệ 2
{
    double i;
    cout<<"doi sang he 2: 0.";
    do
    {
        i=n*2;
        if(i<1)
        {
            cout<<"0";
            n=i;
        }
        if(i>1)
        {
            cout<<"1";
            n=i-1;
        }
    }
    while (i!=1.00);
    cout<<"1\n";
}
double stringToDouble (string a) // Chuyển dổi số thực dạng string sang double
{
    return atof(a.c_str());
}
int main()
{
    double n;
    long k,y;
    cout << "Nhap so thap phan (so thuc) can chuyen doi: ";
    cin >> n;
    //FloatDecToBin(real);
    cout << "So thap phan (so thuc) sau chuyen doi la so nhi phan: " << numberToBin(n);

    cout << "\nNhap so nhi phan can chuyen doi: ";
    cin >> k;
    y = BinToLongDec(k);
    cout << "So nhi phan sau chuyen doi la so thap phan: " << y << endl;
    return 0;
}
