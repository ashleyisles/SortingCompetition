#include <iostream>
#include <chrono>
#include <ctime>
#include <iomanip>

using namespace std;

void build_maxheap(int*, int);
void heapsort(int*, int);
void max_heapify(int*, int, int);

int main(int argc, char *argv[])
{

    const int numberOfElements = 7;
    int array[numberOfElements] = {9, 56, 1, 8, 13, 4, 7};

    for(int i = 0; i < numberOfElements; i++)
        cout << array[i] << " ";

    cout << endl;
    chrono::time_point<chrono::system_clock> start, end;

    build_maxheap(array, numberOfElements);

    start = chrono::system_clock::now();
    //cout << "heap sort " << heapsort(array, numberOfElements) << endl;
    heapsort(array, numberOfElements);
    end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "\nfinished computation at " << ctime(&end_time) << "elapsed time: " << fixed << elapsed_seconds.count() << "s\n";

    for(int i = 0; i < numberOfElements; i++)
        cout << array[i] << " ";
}

void max_heapify(int *a, int i, int n)
{
    int j, temp;
    temp = a[i];
    j = 2*i;
    while (j <= n)
    {
        if (j < n && a[j+1] > a[j])
            j = j+1;
        if (temp > a[j])
            break;
        else if (temp <= a[j])
        {
            a[j/2] = a[j];
            j = 2*j;
        }
        cout << j << endl;
    }
    a[j/2] = temp;
    return;
}
void heapsort(int *a, int n)
{
    int i, temp;
    for (i = n - 1; i >= 1; i--)
    {
        temp = a[i];
        a[i] = a[1];
        a[1] = temp;
        max_heapify(a, 1, i-1);
    }
}
void build_maxheap(int *a, int n)
{
    int i;
    for(i = n/2; i >= 1; i--)
    {
        max_heapify(a, i, n);
    }
}

