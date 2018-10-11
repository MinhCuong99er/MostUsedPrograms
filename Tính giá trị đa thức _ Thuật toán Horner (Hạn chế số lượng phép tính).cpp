#include <cmath>
#include <iostream>
using namespace std;

float caculacation (float arr[], int k, int c)
{
    float p = arr[k-1];
    for (int i=k-2;i>=0;i--)
    {
        p = p*c + arr[i];
    }
    return p;
}
int main ()
{
    int n,i,c;
    cout << "Nhap bac cao nhat cua da thuc: ";
    cin >> n;
    cout << "Nhap gia tri: ";
    cin >> c;
    float arr[n+1];
    cout << endl;
    for (i=0;i<n+1;i++)
    {
        cout << "Nhap cac he so cua da thuc: arr[" << i <<"] = ";
        cin >> arr[i];
    }
//    float p = arr[n];
//    for (i=n-1;i>=0;i--)
//    {
//        p = p*c + arr[i];
//    }
    cout << "\nDa thuc p(x) = ";
    for (i=n;i>=0;i--)
    {
        if (arr[i]!=0)
        {
            if (i==0) cout << arr[i];
            else if (i==1 && arr[i]==1) cout << "x + ";
            else if (i==1 && arr[i]!=1) cout << arr[i] << "x + ";
            else if (arr[i]==1 && i!=1) cout << "x^" << i << " + ";
            else cout << arr[i] << "x^" << i << " + ";
        }
    }
    cout << "\nGia tri cua da thuc tai x = p la: " << caculacation(arr,n+1,c) << " ";
    return 0;
}
