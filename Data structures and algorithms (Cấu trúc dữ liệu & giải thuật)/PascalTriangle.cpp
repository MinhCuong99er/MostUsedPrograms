#include<iostream>
using namespace std;
int main ()
{
    int n,i,j;
    cin >> n;
    int a[n][n];
    for (i=0;i<n;i++)
    {
        for (j=0;j<=i;j++)
        {
            a[i][j] = (j==0 || i==j) ? 1 : (a[i-1][j-1] + a[i-1][j]);
            if (a[i][j]<10 && j!=0) cout << " "<< a[i][j] << " ";
            else cout << a[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
