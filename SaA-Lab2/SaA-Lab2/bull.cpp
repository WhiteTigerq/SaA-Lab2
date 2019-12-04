//
//  main.cpp
//  SaA-Lab2
//
//  Created by Олег Джинганин on 14/11/2019.
//  Copyright © 2019 Олег Джинганин. All rights reserved.
//

#include <iostream>
#include <random>
using namespace std;

int BubbleSort(int* a, int n) // пузырек
{
    unsigned count = 0;
    for(int i=0;i<n-1;i++)
    {
        for(int j=n-1;j>i;j--)
        {
            count++;
            if (a[j-1] > a[j])
                SwapElement(a,j);
        }
    }
    return count;
}
