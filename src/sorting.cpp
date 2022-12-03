#include "header.h"
/*Сравниваются пять алгоритмов сортировки:
  - сортировка выбором
  - шейкер сортировка
  - сортировка вставками
  - пузырьковая сортировка
  - сортировка методом Шелла */
#include<iostream>
#include<cstdlib>
#include <locale>

#include <ctime>
using namespace std;

template<class Item>
void exch(Item& A, Item& B)
{
    Item t = A;
    A = B;
    B = t;
}
//----------------------------------------------------------
template<class Item>
void compexch(Item& A, Item& B)
{
    if (B < A) exch(A, B);
}
//-------------------------------------------------------
//Сортировка выбором
template<class Item>
int selection(Item a[], int l, int r)
{
    int startTime = 0;
    int endTime = 0;

    startTime = clock();
    for (int i = l; i < r; i++)
    {
        int min = i;
        for (int j = i + 1; j <= r; j++)
            if (a[j] < a[min])
                min = j;
        exch(a[i], a[min]);
    }
    endTime = clock();

    return (endTime - startTime);
}
//----------------------------------------------------------
//Шейкер сортировка
template<class Item>
int shaker(Item a[], int l, int r)
{
    int startTime = 0;
    int endTime = 0;

    int left = l, right = r;

    startTime = clock();

    while (left < right)
    {
        for (int i = left; i < right; i++)
            compexch(a[i], a[i + 1]);

        right--;
        for (int i = right; i > left; i--)
            compexch(a[i - 1], a[i]);

        left++;
    }
    endTime = clock();

    return (endTime - startTime);
}
//-------------------------------------------------
//Сортировка вставками
template<class Item>
int insertion(Item a[], int l, int r)
{
    int startTime = 0;
    int endTime = 0;

    int i;
    startTime = clock();
    for (i = r; i < l; i--)
        compexch(a[i - 1], a[i]);

    for (i = l + 2; i <= r; i++)
    {
        int j = i;
        Item v = a[i];
        while (v < a[j - 1])
        {
            a[j] = a[j - 1];  j--;
        }
        a[j] = v;
    }
    endTime = clock();

    return (endTime - startTime);
}
//-----------------------------------------------------------
//Пузырьковая сортировка
template<class Item>
int bubble(Item a[], int l, int r)
{
    int startTime = 0;
    int endTime = 0;
    startTime = clock();

    for (int i = l; i < r; i++)
        for (int j = r; j > i; j--)
            compexch(a[j - 1], a[j]);

    endTime = clock();

    return (endTime - startTime);
}
//------------------------------------------------------------------
//сортировка методом Шелла
template<class Item>
int shellsort(Item a[], int l, int r)
{
    int h;
    int startTime = 0;
    int endTime = 0;
    startTime = clock();

    for (h = 1; h <= (r - 1) / 9; h = 3 * h + 1);
    for (; h > 0; h /= 3)
        for (int i = l + h; i <= r; i++)
        {
            int j = i;
            Item v = a[i];
            while (j >= l + h && v < a[j - h])
            {
                a[j] = a[j - h];
                j -= h;
            }
            a[j] = v;
        }
    endTime = clock();

    return (endTime - startTime);
}
//------------------------------------------------------------------
//Заполнение массива
template<class Item>
void randmass(Item* a, int N)
{
    for (int i = 0; i < N; i++)
        a[i] = 1000 * (1.0 * rand() / RAND_MAX);
}
//Показать массив
template<class Item>
void showmass(Item* a, int N)
{
    for (int i = 0; i < N; i++)
        cout << a[i] << "  ";
}
//---------------------------------------------------------------
int func2()
{
    const int N = 10000;
    int* a = new int[N];

    cout << "Сортировка методом выбора: " << selection(a, 0, N - 1) << endl;
    setlocale(LC_ALL, "rus");
    cout << "Результаты тестов: " << endl;
    randmass(a, N);
    cout << "Сортировка методом выбора: " << selection(a, 0, N - 1) << endl;

    randmass(a, N);
    cout << "Шейкер сортировка:         " << shaker(a, 0, N - 1) << endl;

    randmass(a, N);
    cout << "Сортировка вставками:      " << insertion(a, 0, N - 1) << endl;

    randmass(a, N);
    cout << "Пузырьковая сортировка:    " << bubble(a, 0, N - 1) << endl;

    randmass(a, N);
    cout << "Сортировка методом Шелла:  " << shellsort(a, 0, N - 1) << endl;
    return 0;
}

	
