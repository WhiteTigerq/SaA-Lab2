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

void SwapElement(int* arr, int i)
{
    int buff;
    buff = arr[i - 1];
    arr[i - 1] = arr[i];
    arr[i] = buff;
}
