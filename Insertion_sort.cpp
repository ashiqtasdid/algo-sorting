#include <bits/stdc++.h>
using namespace std;

void insertionSort(vector<int> &a)
{
    for (int j = 1; j < a.size(); j++)
    {
        int key = a[j];
        int i = j - 1;
        while (i >= 0 && a[i] > key)
        {
            a[i + 1] = a[i];
            --i;
        }

        a[i + 1] = key;
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
    insertionSort(a);
    auto end = chrono::high_resolution_clock::now();

    auto durationUs = chrono::duration_cast<chrono::microseconds>(end - start);
    double durationMs = durationUs.count() / 1000.0;
    cout << fixed << setprecision(3);
    cout << "Student Name: Md. Ashiquzzaman Khan" << endl;
    cout << "Student ID: C243005" << endl;
    cout << "Algorithm Name: Insertion Sort" << endl;
    cout << "Input Size: " << size << endl;
    cout << "Sorting time: " << durationMs << " ms (" << durationUs.count() << " us)" << endl;
    return 0;
}