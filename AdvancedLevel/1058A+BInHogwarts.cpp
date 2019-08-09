#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<stdio.h>
using namespace std;

struct CNode
{
    long Galleon;
    int Sickle, Knut;
};

int main()
{
    CNode A, B, C;
    scanf("%ld.%d.%d", &A.Galleon, &A.Sickle, &A.Knut);
    scanf("%ld.%d.%d", &B.Galleon, &B.Sickle, &B.Knut);
    C.Knut = A.Knut + B.Knut;
    C.Sickle = A.Sickle + B.Sickle + C.Knut / 29;
    C.Galleon = A.Galleon + B.Galleon + C.Sickle / 17;
    C.Knut %= 29;
    C.Sickle %= 17;
    cout << C.Galleon << "." << C.Sickle << "." << C.Knut;
    return 0;
}