#include<iostream>
#include<string>
#include<string.h>
#include<algorithm>
#include<cmath>

using namespace std;
string DecToBin (long k)
{
    if (k==0) return "0";
    else if (k==2) return "1";
    else
    {
        if (k%2==0) return DecToBin(k/2) + "0";
        else return DecToBin(k/2) + "1";
    }
}
//string longToString (long k)
//{
//    return to_string(k);
//}
long stringToLong (string a)
{
    return atoi(a.c_str());
}
long reversing (long k)
{
    long sum=0;
    while(k>0)
    {
        sum = sum*10 + k%10;
        k/=10;
    }
    return sum;
}
long BinToDec(long n)
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
int main ()
{
    long n,k,x,y;
    cout << "Nhap so thap phan can chuyen doi: ";
    cin >> n;
    string str = DecToBin(n);
    x = stringToLong(str);
    cout << "So thap phan sau chuyen doi la so nhi phan: " << x << endl;

    cout << "Nhap so nhi phan can chuyen doi: ";
    cin >> k;
    y = BinToDec(k);
    cout << "So nhi phan sau chuyen doi la so thap phan: " << y << endl;

    return 0;
}
