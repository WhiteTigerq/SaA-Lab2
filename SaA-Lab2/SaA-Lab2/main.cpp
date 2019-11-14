//
//  main.cpp
//  SaA-Lab2
//
//  Created by Олег Джинганин on 14/11/2019.
//  Copyright © 2019 Олег Джинганин. All rights reserved.
//

#include <iostream>
using namespace std;

template<class type>
void InsertSort(type* a,long n)
{
    for(long i=1;i<n;i++)
    {
        type x=a[i];
        long j=i-1;
        for(;j>=0 && a[j]>x;j--)
            a[j+1]=a[j];
        a[j+1]=x;
    }
}

int main(int argc, const char * argv[])
{
    std::cout << "Hello, World!\n";
    return 0;
}
