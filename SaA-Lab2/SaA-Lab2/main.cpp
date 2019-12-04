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

int InsertSort(int* arr,int n){
    unsigned count = 0;
    for (int i = 1; i < n; i++)
    {
    if (arr[i] >= arr[i - 1])
    count++;
    for (int j = i; j > 0 && arr[j - 1] > arr[j]; j--, count++)
    SwapElement(arr, j);
    }
    return count;
}

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

unsigned BubbleSortv1(int* arr, short n)
{
    unsigned count = 0;
    bool check;
    for (int i = 0; i < n - 1; i++)
    {
        check = false;
        for (int j = (n - 1); j > i; j--)
        {
            count++;
            if (arr[j - 1] > arr[j])
            {
                SwapElement(arr, j);
                check = true;
            }
        }
        if (check == false)
            break;
    }
    return count;
}

unsigned BubbleSortv2(int* arr, short n)
{
    unsigned count = 0;
    int last_swaped_el_num;
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = (n - 1); j > i; j--)
        {
            count++;
            if (arr[j - 1] > arr[j])
            {
                SwapElement(arr, j);
                last_swaped_el_num = j - 1;
            }
            else last_swaped_el_num = j;
        }
        i = last_swaped_el_num;
    }
    return count;
}

int siftDown(int *numbers, int root, int bottom)
{
    int count = 0;
  int maxChild;
  int done = 0;
  while ((root * 2 <= bottom) && (!done))
  {
    if (root * 2 == bottom)
      maxChild = root * 2;
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
      count++;
    if (numbers[root] < numbers[maxChild])
    {
      int temp = numbers[root];
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else
      done = 1;
  }
    return count;
}
int heapSort(int *numbers, int array_size)
{
    int count = 0;
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    count += siftDown(numbers, i, array_size - 1);
  for (int i = array_size - 1; i >= 1; i--, count++)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    count += siftDown(numbers, 0, i - 1);
  }
    return count;
}

int QuicksortHoar(int *mas, int first, int last) // Хоара
{
    int mid, count;
    int counts = 0;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f]<mid){
            f++;
            counts++;
        }
        while (mas[l]>mid){
            counts++;
            l--;
        }
        if (f <= l) //перестановка элементов
        {
            counts++;
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f<l);
    counts++;
    if (first<l) QuicksortHoar(mas, first, l);
    counts++;
    if (f<last) QuicksortHoar(mas, f, last);
    return counts;
}

int SortBySelection(int* arr, short n)
{
    int count = 0;
    int value, key;
    for (int i = 0; i < n - 1; i++)
    {
        value = arr[i];
        key = i;
        for (int j = i + 1; j < n; j++)
        {
            count++;
            if (arr[j] < arr[key])
                key = j;
        }
        count++;
        if (key != i)
        {
            arr[i] = arr[key];
            arr[key] = value;
        }
    }
    return count;
}

unsigned ShellSort(int* arr, short n)
{
    unsigned count = 0;
    int step = n / 2;
    while (step > 0)
    {
        for (int i = 0; i < (n - step); i++)
        {
            if (arr[i] < arr[i + step])
                count++;
            for (int j = i; j >= 0 && arr[j] > arr[j + step]; j--, count++)
            {
                int temp = arr[j];
                arr[j] = arr[j + step];
                arr[j + step] = temp;
            }
        }
        step /= 2;
    }
    return count;
}

void GetArray(int* arr, const short sz)
{
    for (int i = 0; i < sz; i++)
    {
        arr[i] = rand();
    }
}

void GetDisArray(const int* arr1, int* arr2, const short sz)
{
    for (int i = 0; i < sz; i++) arr2[i] = arr1[i];
}

void GetOrderArray(const int* arr1, int* arr2, const short sz)
{
    for (int i = 0; i < sz; i++)
    {
        arr2[i] = arr1[i];
    }
    for (int i = 1; i < sz; i++)
    {
        for (int j = i; j > 0 && arr2[j - 1] > arr2[j]; j--)
            SwapElement(arr2, j);
    }
}

void GetReorderArray(const int* arr1, int* arr2, short sz)
{
    int temp;
    for (int i = 0; i < sz; i++)
    {
        arr2[i] = arr1[i];
    }
    for (int i = 0; i < sz - 1; i++)
    {
        for (int j = i + 1; j < sz; j++)
        {
            if (arr2[i] < arr2[j])
            {
                temp = arr2[i];
                arr2[i] = arr2[j];
                arr2[j] = temp;
            }
        }
    }
}

void GetInfo(const int* arr, short sz)
{
    cout << endl;
    for (int i = 0; i < sz; i++)
    {
        cout << arr[i] << "-";
    }
    cout << endl;
}

int main(int argc, const char * argv[])
{
    setlocale(0, "");
    while (cin.get() != 'q') {
        cout << "\nВведите размер массива --> ";
        int size;
        cin >> size;
        srand(50);
        int* default_arr = new int[size];
        GetArray(default_arr, size);
        cin.clear();
        cout << "Анализ сортировки вставками" << endl;
        int *ordered_arr = new int[size];
        int *reordered_arr = new int[size];
        int *disordered_arr = new int[size];
        GetDisArray(default_arr, disordered_arr, size);
        GetOrderArray(disordered_arr, ordered_arr, size);
        GetReorderArray(ordered_arr, reordered_arr, size);
        cout << "Упорядоченный массив размера " << size << ":\n";
        cout << "Сортировка вставками: " << InsertSort(ordered_arr, size);
        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
        cout << "Сортировка вставками: " << InsertSort(reordered_arr, size);
        cout << "\nНеупорядоченный массив размера " << size << ":\n";
        cout << "Сортировка вставками: " << InsertSort(disordered_arr, size);
        GetInfo (disordered_arr, size);
        cout << endl;
        GetInfo (ordered_arr, size);
        cout << endl;
        GetInfo (reordered_arr, size);
        cout << endl;
        delete[] ordered_arr;
        delete[] reordered_arr;
        delete[] disordered_arr;
//        cout << "Анализ сортировки пузырьком" << endl;
//        int *ordered_arr = new int[size];
//        int *reordered_arr = new int[size];
//        int *disordered_arr = new int[size];
//        GetDisArray(default_arr, disordered_arr, size);
//        GetOrderArray(disordered_arr, ordered_arr, size);
//        GetReorderArray(ordered_arr, reordered_arr, size);
//        cout << "Упорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSort(ordered_arr, size);
//        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSort(reordered_arr, size);
//        cout << "\nНеупорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSort(disordered_arr, size);
//        GetInfo (disordered_arr, size);
//        cout << endl;
//        GetInfo (ordered_arr, size);
//        cout << endl;
//        GetInfo (reordered_arr, size);
//        cout << endl;
//        delete[] ordered_arr;
//        delete[] reordered_arr;
//        delete[] disordered_arr;
//        cout << "Анализ сортировки пузырьком улучшенной версии 1" << endl;
//        int *ordered_arr = new int[size];
//        int *reordered_arr = new int[size];
//        int *disordered_arr = new int[size];
//        GetDisArray(default_arr, disordered_arr, size);
//        GetOrderArray(disordered_arr, ordered_arr, size);
//        GetReorderArray(ordered_arr, reordered_arr, size);
//        cout << "Упорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSortv1(ordered_arr, size);
//        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSortv1(reordered_arr, size);
//        cout << "\nНеупорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSortv1(disordered_arr, size);
//        GetInfo (disordered_arr, size);
//        cout << endl;
//        GetInfo (ordered_arr, size);
//        cout << endl;
//        GetInfo (reordered_arr, size);
//        cout << endl;
//        delete[] ordered_arr;
//        delete[] reordered_arr;
//        delete[] disordered_arr;
//        cout << "Анализ сортировки пузырьком улучшенной версии 2" << endl;
//        int *ordered_arr = new int[size];
//        int *reordered_arr = new int[size];
//        int *disordered_arr = new int[size];
//        GetDisArray(default_arr, disordered_arr, size);
//        GetOrderArray(disordered_arr, ordered_arr, size);
//        GetReorderArray(ordered_arr, reordered_arr, size);
//        cout << "Упорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSortv2(ordered_arr, size);
//        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSortv2(reordered_arr, size);
//        cout << "\nНеупорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка пузырьком: " << BubbleSortv2(disordered_arr, size);
//        GetInfo (disordered_arr, size);
//        cout << endl;
//        GetInfo (ordered_arr, size);
//        cout << endl;
//        GetInfo (reordered_arr, size);
//        cout << endl;
//        delete[] ordered_arr;
//        delete[] reordered_arr;
//        delete[] disordered_arr;
//        cout << "Анализ сортировки Хоара" << endl;
//        int *ordered_arr = new int[size];
//        int *reordered_arr = new int[size];
//        int *disordered_arr = new int[size];
//        GetDisArray(default_arr, disordered_arr, size);
//        GetOrderArray(disordered_arr, ordered_arr, size);
//        GetReorderArray(ordered_arr, reordered_arr, size);
//        cout << "Упорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка Хоара: " << QuicksortHoar(ordered_arr, 0, size-1);
//        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
//        cout << "Сортировка Хоара: " << QuicksortHoar(reordered_arr, 0, size-1);
//        cout << "\nНеупорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка Хоара: " << QuicksortHoar(disordered_arr, 0, size-1);
//        GetInfo (disordered_arr, size);
//        cout << endl;
//        GetInfo (ordered_arr, size);
//        cout << endl;
//        GetInfo (reordered_arr, size);
//        cout << endl;
//        delete[] ordered_arr;
//        delete[] reordered_arr;
//        delete[] disordered_arr;
//        cout << "Анализ сортировки выбором" << endl;
//        int *ordered_arr = new int[size];
//        int *reordered_arr = new int[size];
//        int *disordered_arr = new int[size];
//        GetDisArray(default_arr, disordered_arr, size);
//        GetOrderArray(disordered_arr, ordered_arr, size);
//        GetReorderArray(ordered_arr, reordered_arr, size);
//        cout << "Упорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка выбором: " << SortBySelection(ordered_arr, size);
//        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
//        cout << "Сортировка выбором: " << SortBySelection(reordered_arr, size);
//        cout << "\nНеупорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка выбором: " << SortBySelection(disordered_arr, size);
//        GetInfo (disordered_arr, size);
//        cout << endl;
//        GetInfo (ordered_arr, size);
//        cout << endl;
//        GetInfo (reordered_arr, size);
//        cout << endl;
//        delete[] ordered_arr;
//        delete[] reordered_arr;
//        delete[] disordered_arr;
//        cout << "Анализ сортировки Шелла" << endl;
//        int *ordered_arr = new int[size];
//        int *reordered_arr = new int[size];
//        int *disordered_arr = new int[size];
//        GetDisArray(default_arr, disordered_arr, size);
//        GetOrderArray(disordered_arr, ordered_arr, size);
//        GetReorderArray(ordered_arr, reordered_arr, size);
//        cout << "Упорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка Шелла: " << ShellSort(ordered_arr, size);
//        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
//        cout << "Сортировка Шелла: " << ShellSort(reordered_arr, size);
//        cout << "\nНеупорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка Шелаа: " << ShellSort(disordered_arr, size);
//        GetInfo (disordered_arr, size);
//        cout << endl;
//        GetInfo (ordered_arr, size);
//        cout << endl;
//        GetInfo (reordered_arr, size);
//        cout << endl;
//        delete[] ordered_arr;
//        delete[] reordered_arr;
//        delete[] disordered_arr;
//        cout << "Анализ сортировки пирамидой" << endl;
//        int *ordered_arr = new int[size];
//        int *reordered_arr = new int[size];
//        int *disordered_arr = new int[size];
//        GetDisArray(default_arr, disordered_arr, size);
//        GetOrderArray(disordered_arr, ordered_arr, size);
//        GetReorderArray(ordered_arr, reordered_arr, size);
//        cout << "Упорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка пирамидой: " << heapSort(ordered_arr, size);
//        cout << "\nУпорядоченный в обратном порядке массив размера " << size << ":\n";
//        cout << "Сортировка пирамидой: " << heapSort(reordered_arr, size);
//        cout << "\nНеупорядоченный массив размера " << size << ":\n";
//        cout << "Сортировка пирамидой: " << heapSort(disordered_arr, size);
//        GetInfo (disordered_arr, size);
//        cout << endl;
//        GetInfo (ordered_arr, size);
//        cout << endl;
//        GetInfo (reordered_arr, size);
//        cout << endl;
//        delete[] ordered_arr;
//        delete[] reordered_arr;
//        delete[] disordered_arr;
        cout << "Введите любой символ чтобы проанализировать другой массив (q - выход) --> ";
        cin.get();
    }
    return 0;
}
