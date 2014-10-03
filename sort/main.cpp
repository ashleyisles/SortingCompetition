#include <algorithm>
#include <fstream>
#include <iostream>
#include <chrono>
#include <ctime>
#include <cstring> 
#include <iomanip>
#include <string>
#include <vector>
#include "sortingcompetition.h"

using namespace std;



//get maximum value in arr[]
/*int getMax(vector<string> arr, int n)
{
    int max = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > max)
            max = arr[i];
    return max;
}

//count sort of arr[]
void countSort(vector<string> arr, int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--)
    {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
//sorts arr[] of size n using Radix Sort
void radixsort(vector<string> arr, int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}*/

int main(int argc, char *argv[])
{
    SortingCompetition* run = new SortingCompetition("mobyDick.txt");
    string outputFile = "dobyMick";

    run->readData();
    run->prepareData();


    chrono::time_point<chrono::system_clock> start, end;
    start = chrono::system_clock::now();
    run->sortData();
    end = chrono::system_clock::now();

    chrono::duration<double> elapsed_seconds = end-start;
    time_t end_time = chrono::system_clock::to_time_t(end);

    cout << "\nfinished computation at " << ctime(&end_time) << "elapsed time: " << fixed << elapsed_seconds.count() << "s\n";
    run->outputData(outputFile);

}

/*PASS BY REFERENCE, PASS BY VALUE
GENERATE DATA SUCH THAT DATA SETS ARE STATISTICALLY AND SIGNIFICANTLY DIFFERENT
DETERMINE WHETHER OR NOT THEY’RE DIFFERENT, WITH P VALUE LESS THAN OR EQUAL TO 0.5. DATA SETS MUST HAVE 20 RUNS EACH. BONUS QUESTION FOR MIDTERM
SHOW THAT RUNTIMES FOR PASS-BY-VALUE AND PASS-BY-REFERENCE ARE ACTUALLY STATISTICALLY DIFFERENT AND NOT JUST BY CHANCE.
INCLUDE CODE*/

