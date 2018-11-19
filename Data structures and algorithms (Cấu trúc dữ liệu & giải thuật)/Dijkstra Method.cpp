#include <stdio.h>
#include <conio.h>
#include <iostream>
#include <fstream>
#define max 10
#define MAXINT 33000
using namespace std;
void ReadFile (int array[][max], int &vertice, int &first, int &last)
{
    fstream file;
    file.open("DijkstraInput.inp", ios::in);
    file >> vertice >> first >> last;
    cout << "Ma Tran Lien Ket Tuong Ung.\n" << first << " " << last << endl;
    for(int i=0; i<vertice ; i++)
    {
        for(int j=0; j<vertice ; j++)
        {
            file >> array[i][j];
            cout << array[i][j] << " ";
        }
        cout << endl;
    }
    file.close();
    first--;
    last--;
}
void Dijkstra (int array[][max], int vertice, int first, int last)
{
    char DanhDau[max];
    int Nhan[max], Truoc[max], XP, min,i,j;
    for(i=0; i<vertice; i++)
    {
        Nhan[i] = MAXINT;
        DanhDau[i] = 0;
        Truoc[i] = first;
    }
    Nhan[first] = 0;
    DanhDau[first] = 1;
    XP = first;
    while(XP != last)
    {
        for(j=0; j<vertice; j++)
            if(array[XP][j]>0 && Nhan[j]>array[XP][j]+Nhan[XP] && DanhDau[j]==0)
            {
                Nhan[j] = array[XP][j]+Nhan[XP];
                Truoc[j] = XP;
            }
        min = MAXINT;
        for(j = 0; j<vertice; j++)
            if(min>Nhan[j]&& DanhDau[j]==0)
            {
                min = Nhan[j];
                XP = j;
            }
        DanhDau[XP] = 1;
    }
    cout << "Duong Di Ngan Nhat La: " << Nhan[last] <<endl;
    cout << last+1 << " <- " << Truoc[last]+1;
    i = Truoc[last];
    while(i!=first)
    {
        i = Truoc[i];
        cout << " <- " << i+1;
    }
}

int main()
{
    int array[max][max],vertice,first,last;
    ReadFile(array,vertice,first,last);
    Dijkstra(array,vertice,first,last);
    return 0;
}
