//  *
// ***
//*****
//
//  *
// * *
//*****
//
//     *
//    * *
//   *   *
//  *     *
// *       *
//***********

#include <iostream>
#include <stdio.h>
using namespace std;

void printBottom(long length, long pos)
{
    long i;
    for (i=0;i<pos;i++) cout << " ";
    for (i=0;i<2*length-1;i++) cout << "*";
    cout << endl;
}

void printEmptyBottom(long length, long pos)
{
    long i;
    for (i=0;i<pos;i++) cout << " ";
    for (i=0;i<2*length-1;i++)
    {
        if (i==0 || i==2*length-2) cout << "*";
        else cout << " ";
    }
    cout << endl;
}
void printTriangle(long n, long bottomLength)
{
    if (n == 0) return;
    else
    {
        printTriangle(n-1, bottomLength);
        printEmptyBottom(n, bottomLength-n);
    }
}
void printEmptyTriangle(long n)
{
    if (n == 0)return;
    printTriangle(n-1, n);
    printBottom(n, 0);
}

int main()
{
    long n;
    cin >> n;
    printEmptyTriangle(n);
    return 0;
}


//printEmptyBottom(1, 4)
//    *
//printEmptyBottom(2, 3)
//   * *
//printEmptyBottom(3, 2)
//  *   *
//printEmptyBottom(4, 1)
// *     *



