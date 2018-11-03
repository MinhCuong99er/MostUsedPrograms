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
            arr[i][j] = rand()%12;
        }
    }
}
void output (float arr[][MAX], int n)
{
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
string isMatrixTransposition (float arr[][MAX], int n)
{
    int count = 0;
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<n;j++)
        {
            if (arr[i][j]==arr[j][i]) count++;
        }
    }
    if (count==n*n) return "\nMa tran vua nhap giong ma tran chuyen vi.";
    else return "\nMa tran vua nhap ko giong ma tran chuyen vi.";
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
        output(b,n);
    }
    else cout << "\nKhong co ma tran nghich dao\n";
}
int main()
{
    int level;
    cout << "Nhap cap cua ma tran: ";
    srand(time(NULL));
    level = rand()%4 + 1;
    cout << level << endl;
    srand(time(NULL));

    float arr[MAX][MAX];
    input(arr,level);
    cout << "\nMa tran vua nhap:\n";
    output(arr,level);

    float det = determinant(arr,level);
	cout << isMatrixTransposition(arr,level) << "\nDinh thuc cua ma tran la: " << det << "\nMa tran nghich dao:\n";
	inverseMatrix(arr,level);
    return 0;
}
