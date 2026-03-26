#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &v, vector<int> &temp, int start, int mid, int end)
{
    int i = start;
    int j = mid + 1;
    int k = start;

    while (i <= mid && j <= end)
    {
        if (v[i] > v[j])
        {
            temp[k++] = v[j++];
        }
        else
        {
            temp[k++] = v[i++];
        }
    }

    while (i <= mid)
    {
        temp[k++] = v[i++];
    }

    while (j <= end)
    {
        temp[k++] = v[j++];
    }

    for (int i = start; i <= end; i++)
    {
        v[i] = temp[i];
    }
}

void mergeSort(vector<int> &v, vector<int> &temp, int start, int end)
{
    if (start < end)
    {
        int mid = start + (end - start) / 2;
        mergeSort(v, temp, start, mid);
        mergeSort(v, temp, mid + 1, end);
        merge(v, temp, start, mid, end);
    }
}

void mergeSort(vector<int> &v)
{
    if (v.empty())
        return;

    vector<int> temp(v.size());
    mergeSort(v, temp, 0, v.size() - 1);
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
    dataSet(size, a);

    auto start = chrono::high_resolution_clock::now();
    mergeSort(a);
    auto end = chrono::high_resolution_clock::now();

    auto durationUs = chrono::duration_cast<chrono::microseconds>(end - start);
    double durationMs = durationUs.count() / 1000.0;

    cout << fixed << setprecision(3);
    cout << "Student Name: Md. Ashiquzzaman Khan\n";
    cout << "Student ID: C243005\n";
    cout << "Algorithm Name: Merge Sort\n";
    cout << "Input Size: " << size << "\n";
    cout << "Sorting time: " << durationMs << " ms (" << durationUs.count() << " us)\n";

    return 0;
}