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
    int help;
    help = arr[i - 1];
    arr[i - 1] = arr[i];
    arr[i] = help;
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

template<class type>
void BubbleSort(type* a, long n) // пузырек
{
    for(long i=0;i<n-1;i++)
        for(long j=n-1;j>i;j--)
            if(a[j-1]>a[j]) Swap(a[j],a[j-1]);
}

template<class type>
void Swap(type& x,type& y) // вспомогательная функция
{
    type temp=x;
    x=y;
    y=temp;
}

// Функция "просеивания" через кучу - формирование кучи
void siftDown(int *numbers, int root, int bottom)
{
  int maxChild; // индекс максимального потомка
  int done = 0; // флаг того, что куча сформирована
  // Пока не дошли до последнего ряда
  while ((root * 2 <= bottom) && (!done))
  {
    if (root * 2 == bottom)    // если мы в последнем ряду,
      maxChild = root * 2;    // запоминаем левый потомок
    // иначе запоминаем больший потомок из двух
    else if (numbers[root * 2] > numbers[root * 2 + 1])
      maxChild = root * 2;
    else
      maxChild = root * 2 + 1;
    // если элемент вершины меньше максимального потомка
    if (numbers[root] < numbers[maxChild])
    {
      int temp = numbers[root]; // меняем их местами
      numbers[root] = numbers[maxChild];
      numbers[maxChild] = temp;
      root = maxChild;
    }
    else // иначе
      done = 1; // пирамида сформирована
  }
}
// Функция сортировки на куче
void heapSort(int *numbers, int array_size)
{
  // Формируем нижний ряд пирамиды
  for (int i = (array_size / 2) - 1; i >= 0; i--)
    siftDown(numbers, i, array_size - 1);
  // Просеиваем через пирамиду остальные элементы
  for (int i = array_size - 1; i >= 1; i--)
  {
    int temp = numbers[0];
    numbers[0] = numbers[i];
    numbers[i] = temp;
    siftDown(numbers, 0, i - 1);
  }
}

void QuicksortHoar(int *mas, int first, int last) // Хоара
{
    int mid, count;
    int f = first, l = last;
    mid = mas[(f + l) / 2]; //вычисление опорного элемента
    do
    {
        while (mas[f]<mid) f++;
        while (mas[l]>mid) l--;
        if (f <= l) //перестановка элементов
        {
            count = mas[f];
            mas[f] = mas[l];
            mas[l] = count;
            f++;
            l--;
        }
    } while (f<l);
    if (first<l) QuicksortHoar(mas, first, l);
    if (f<last) QuicksortHoar(mas, f, last);
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
        cout << "Анализ сортировки вставками\n";
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
        cout << "Введите любой символ чтобы проанализировать другой массив (q - выход) --> ";
        cin.get();
    }
    return 0;
}
