#include <iostream>
#include <stdlib.h>
#include <ctime>
#include <iomanip>
using namespace std;
const int MAX = 10;

void input(float arr[][MAX], int &n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            arr[i][j] = rand()%9;
            //cin >> arr[i][j];
        }
    }
}
void output (float arr[][MAX], int n)
{
    //cout << "\nMa tran:\n";
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (arr[i][j] == (long) arr[i][j])
            {
                if (arr[i][j]<10 && arr[i][j]>=0) cout << "  " << arr[i][j] << " ";
                else if (arr[i][j]<=-10 ) cout << arr[i][j] << " ";
                else cout << " " << arr[i][j] << " ";
            }
            else
            {
                if (arr[i][j]<10 && arr[i][j]>=0)
                    cout << "  " << fixed << setprecision (5) << arr[i][j] << " ";
                else if (arr[i][j]<=-10 )
                    cout << fixed << setprecision (5) << arr[i][j] << " ";
                else cout << " " << fixed << setprecision (5) << arr[i][j] << " ";
            }
//            if (arr[i][j]<10 && arr[i][j] == (long) arr[i][j]) cout << "0" << arr[i][j] << " ";
//            else if (arr[i][j]>=0 && arr[i][j] != (long) arr[i][j]) cout << " " << arr[i][j] << " ";
//            else cout << arr[i][j] << " ";
            //cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}
void copyArray (float a[][MAX],float b[][MAX], int n)
{
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            b[i][j] = a[i][j];
        }
    }
}
bool theSameMatrix (float a[][MAX],float b[][MAX], int n)
{
    int count=0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (a[i][j] == b[i][j]) count++;
        }
    }
    return (count==n*n);
}
void sumOrSub(float a[][MAX],float b[][MAX], int n, char c)
{
    float t[MAX][MAX];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            switch (c)
            {
                case '+':
                    t[i][j] = a[i][j]+b[i][j];
                    break;
                case '-':
                    t[i][j] = a[i][j]-b[i][j];
                    break;
            }
        }
    }
    cout << "Phep cong hoac tru 2 ma tran:\n";
    output(t,n);
}
float determinant (float arr[][MAX],int n)
{
    float a[MAX][MAX];
    copyArray(arr,a,n);
    if (n==1) return a[0][0];
    else if (n==2) return (a[0][0]*a[1][1] - a[0][1]*a[1][0]);
    else
    {
        int i,j,k,count=0,kt;
        float b[100],h,det=1.0,c[100];
        for(i=0;i<n-1;i++)
        {
            if(a[i][i]==0)
            {
            kt=0;
            for(j=0;j<n;j++)
                if(a[i][j]!=0)
                {
                    for(k=0;k<n;k++)
                    {
                        // Doi cot j voi cot i
                        swap(a[k][i],a[k][j]);
                    }
                    count++;// dem so lan doi cot
                    kt++;// Kiem tra xem co so 0 o dong i cot j
                    break;
                }
            }
            if(kt==0) return 0;
            b[i]=a[i][i];
            for(j=0;j<n;j++) a[i][j]=a[i][j]/b[i];//tao so 1 o dong i,cot i
            for(j=i+1;j<n;j++)
            {
                h=a[j][i];
                for(k=0;k<n;k++)
                    a[j][k]=a[j][k]-h*a[i][k]; //lay dong thu j-h*dong i
            }
        }
        b[n-1]=a[n-1][n-1];
        for(i=0;i<n;i++) det*=b[i];// Nhan cac so da lay ra ngoai dinh thuc
        return (count%2==0) ? det : -det;
    }
}
bool HaveInverseMatrix (float arr[][MAX], int n)
{
    float a[MAX][MAX];
    copyArray(arr,a,n);
    return (determinant(a,n)!=0);
}
void inverseMatrix(float arr[][MAX], int n)
{
    int i,j,k;
    float a[MAX][MAX],b[MAX][MAX],temp;
    copyArray(arr,a,n);
    if (determinant(a,n)!=0)
    {
        for (i = 0; i < n; i++)
        {
            // Tạo ra b là ma trận đơn vị đó
            for (j = 0; j < n; j++)
            {
                b[i][j] = (i==j) ? 1 : 0;
            }
        }
        for (i = 0; i < n; i++) // Xử lý từ hàng đầu đến hàng cuối
        {
            if (a[i][i] == 0) // Nếu gặp phần tử trên đường chéo chính bằng 0 thì đổi hàng
            {
                k = i+1;
                while (k < n && a[k][i] == 0) k++;
                for (j = 0; j < n; j++) // Đổi hàng đó của a đó, cả với ma trận b nữa
                {
                    swap(a[i][j],a[k][j]);
                    swap(b[i][j],b[k][j]);
                }
            }
            temp = a[i][i];
            for (j = i; j < n; j++) a[i][j] /= temp;
            for (j = 0; j < n; j++) b[i][j] /= temp;
            for (j = i+1; j < n; j++)
            {
                temp = -a[j][i];
                for (k = i; k < n; k++) a[j][k] += temp*a[i][k];
                for (k = 0; k < n; k++) b[j][k] += temp*b[i][k];
            }
        }
        // Kết thúc quá trình Gauss
        for (i = n-1; i > 0; i--) // Bắt đầu quá trình Jordan
            for (j = i-1; j >=0; j--)
            {
                temp = -a[j][i];
                for (k = n-1; k >= i; k--)  a[j][k] += temp*a[i][k];
                for (k = 0; k < n; k++) b[j][k] += temp*b[i][k];
            }
        cout << "Ma tran nghich dao: \n";
        output(b,n);
    }
    else cout << "\nKhong co ma tran nghich dao\n";
}
void multiphyMatrix(float a[][MAX],float b[][MAX], int n)
{
    float t[MAX][MAX];
    int i,j,k;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n;j++)
        {
            t[i][j]=0;
            for(k=0;k<n;k++) t[i][j] += a[i][k] * b[k][j];
        }
    }
    output(t,n);
}
char randomCharacter ()
{
    srand(time(NULL));
    int num = rand()%3;
    if (num==0) return '+';
    else if (num==1) return '-';
    else if (num==2) return '*';
    else if (num==3) return '/';
}
void divisionMatrix(float a[][MAX],float b[][MAX], int n)
{
    float t[MAX][MAX],c[MAX][MAX];
    copyArray(b,t,n);
    int i,j,k,temp;
    if (determinant(t,n)!=0)
    {
        for (i = 0; i < n; i++)
        {
            // Tạo ra c là ma trận đơn vị đó
            for (j = 0; j < n; j++)
            {
                c[i][j] = (i==j) ? 1 : 0;
            }
        }
        for (i = 0; i < n; i++) // Xử lý từ hàng đầu đến hàng cuối
        {
            if (t[i][i] == 0) // Nếu gặp phần tử trên đường chéo chính bằng 0 thì đổi hàng
            {
                k = i+1;
                while (k < n && t[k][i] == 0) k++;
                for (j = 0; j < n; j++) // Đổi hàng đó của a đó, cả với ma trận b nữa
                {
                    swap(t[i][j],t[k][j]);
                    swap(c[i][j],c[k][j]);
                }
            }
            temp = t[i][i];
            for (j = i; j < n; j++) t[i][j] /= temp;
            for (j = 0; j < n; j++) c[i][j] /= temp;
            for (j = i+1; j < n; j++)
            {
                temp = -a[j][i];
                for (k = i; k < n; k++) t[j][k] += temp*a[i][k];
                for (k = 0; k < n; k++) c[j][k] += temp*c[i][k];
            }
        }
        // Kết thúc quá trình Gauss
        for (i = n-1; i > 0; i--) // Bắt đầu quá trình Jordan
            for (j = i-1; j >=0; j--)
            {
                temp = -t[j][i];
                for (k = n-1; k >= i; k--)  t[j][k] += temp*a[i][k];
                for (k = 0; k < n; k++) c[j][k] += temp*b[i][k];
            }
        multiphyMatrix(a,c,n);
    }
    else cout << "\nKhong the thuc hien phep chia 2 ma tran\n";
}
void operations (float a[][MAX],float b[][MAX], int n, char c)
{
    switch (c)
    {
        case '+': case '-':
            sumOrSub(a,b,n,c);
            break;
        case '*':
            cout << "Phep nhan 2 ma tran:\n";
            multiphyMatrix(a,b,n);
            break;
        case '/':
            cout << "Phep chia 2 ma tran:\n";
            divisionMatrix(a,b,n);
            break;
        default: return;
    }
}
int main()
{
    int level;
    cout << "Nhap cap cua ma tran: ";
    srand(time(NULL));
    level = rand()%4 + 1;
    cout << level << endl;

    srand(time(NULL));
    float a[MAX][MAX],b[MAX][MAX];
    input(a,level);
    cout << "\nMa tran vua nhap:\nMa tran A:\n";
    output(a,level);
    input(b,level);
    cout << "Ma tran B:\n";
    output(b,level);

    cout << "\nNhap phep toan can thuc hien: ";

    char c = randomCharacter ();
    cout << c << endl;
    operations(a,b,level,c);
    return 0;
}
