#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &a, int low, int high)
{
    int p = a[low];
    int i = low - 1;
    int j = high + 1;

    while (true)
    {
        do
        {
            i++;
        } while (a[i] < p);

        do
        {
            j--;
        } while (a[j] > p);

        if (i >= j)
            return j;

        swap(a[i], a[j]);
    }
}

void quickSort(vector<int> &a, int low, int high)
{
    if (low < high)
    {
        int p = partition(a, low, high);
        quickSort(a, low, p);
        quickSort(a, p + 1, high);
    }
}

void dataSet(int n, vector<int> &a)
{
    for (int i = 0; i < n; i++)
        a.push_back(i + 1);

    for (int i = n - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        swap(a[i], a[j]);
    }
}

int main()
{
    srand(time(0));
    long long size = 1e5;

    vector<int> a;
    dataSet((int)size, a);
    auto start = chrono::high_resolution_clock::now();

    quickSort(a, 0, a.size() - 1);
    auto end = chrono::high_resolution_clock::now();

    auto durationUs = chrono::duration_cast<chrono::microseconds>(end - start);
    double durationMs = durationUs.count() / 1000.0;
    cout << fixed << setprecision(3);
    cout << "Student Name: Md. Ashiquzzaman Khan" << endl;
    cout << "Student ID: C243005" << endl;
    cout << "Algorithm Name: Quick Sort" << endl;
    cout << "Input Size: " << size << endl;
    cout << "Execution time: " << durationMs << " ms (" << durationUs.count() << " us)" << endl;

    return 0;
}