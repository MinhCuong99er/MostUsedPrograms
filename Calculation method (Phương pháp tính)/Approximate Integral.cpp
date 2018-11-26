#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
const double pi = 16 * atan(0.2) - 4*atan(1.0/239);
const double euler = 2.71828182845904523536;

double caculacateF_x (double x) // Khai bao ham f(x)
{
    return x*x ;
}

double TrapezoidalMethod (double first, double last, double arr[], int size, double h) // Pp hinh thang
{
	double sum=0.0;
	for (int i=1;i<=size-1;i++) {
		sum += caculacateF_x(arr[i]);
	}
	return 0.5*h*(caculacateF_x(first) + 2*sum + caculacateF_x(last));
}
double SimpsonMethod (double first, double last, double arr[], int size, double h) // Pp Simpson
{
	double even = 0.0,odd = 0.0;
	for (int i=1;i<=size-1;i++) {
		if (i%2!=0) odd += caculacateF_x(arr[i]);
		else even += caculacateF_x(arr[i]);
	}
	return (h/3.0)*(caculacateF_x(first) + 2*even + 4*odd + caculacateF_x(last));
}
int main ()
{
	double first,last;
	cout << "Enter the first value: ";
   	cin >> first;
    cout << "Enter the last value: ";
    cin >> last;
    int size,i,j;
    cout << "Enter the amount to divide: ";
    cin >> size;

    double h = (last-first)/size,arr[size];
    for (int i=0;i<size;i++) {
		arr[i] = first + i*h;
	}

    cout << "\nThe integral of a to b of f(x) is:\n+ Use Trapezoidal Method: "
		 << TrapezoidalMethod(first,last,arr,size,h)
		 << "\n+ Use Simpson Method: " << SimpsonMethod(first,last,arr,size,h);
    return 0;
}

