# Sorting Algorithms Assignment (C++)

This repository contains three standalone C++ implementations of classic sorting algorithms:

- Insertion Sort
- Merge Sort
- Quick Sort

Each program:

- Generates a random dataset of unique integers.
- Sorts the dataset using one algorithm.
- Measures execution time using `std::chrono`.
- Prints student metadata and timing results.

## Files

- `Insertion_sort.cpp`: Insertion sort on `vector<int>`.
- `merge_sort.cpp`: Merge sort (divide and conquer).
- `quick_sort.cpp`: Quick sort using Hoare partition scheme.

## Dataset and Benchmark Setup

All three programs use the same general setup in `main()`:

- Input size: `1e4` (10,000 elements)
- Values: random integers in the range `[1, 1000000]`
- Uniqueness: enforced with `unordered_set<int>` before insertion
- Random seed: `srand(time(0))`

## Time Complexity Summary

- Insertion Sort:
	- Best: `O(n)`
	- Average: `O(n^2)`
	- Worst: `O(n^2)`
- Merge Sort:
	- Best/Average/Worst: `O(n log n)`
- Quick Sort (Hoare partition, first element pivot in this code):
	- Best/Average: `O(n log n)`
	- Worst: `O(n^2)`

## Build and Run (Windows, g++)

Open a terminal in this folder and run:

```powershell
g++ Insertion_sort.cpp -o insertion_sort
.\insertion_sort

g++ merge_sort.cpp -o merge_sort
.\merge_sort

g++ quick_sort.cpp -o quick_sort
.\quick_sort
```

## Python Plotting Scripts (Complexity + Runtime)

Two helper scripts are included:

- `plot_from_cpp.py`: compiles and runs your C++ files, then parses printed times (recommended for your assignment report).
- `plot_sort_analysis.py`: benchmarks Python re-implementations of the algorithms.

### Install dependency

```powershell
pip install matplotlib
```

### Run using C++ executables (recommended)

```powershell
python plot_from_cpp.py
```

Default outputs for `plot_from_cpp.py`:

- `plots_cpp/cpp_runs.csv`
- `plots_cpp/cpp_summary.csv`
- `plots_cpp/cpp_time_comparison.png`
- `plots_cpp/cpp_complexity_curves.png`

Optional arguments:

```powershell
python plot_from_cpp.py --runs 7 --compiler g++ --out-dir plots_cpp
```

- `--runs`: number of runs per algorithm
- `--compiler`: compiler command (for example `g++`)
- `--out-dir`: destination folder for CSV and plot images

### Run Python-only benchmark (optional)

```powershell
python plot_sort_analysis.py
```

Default outputs for `plot_sort_analysis.py`:

- `plots/benchmark_results.csv`
- `plots/empirical_times.png`
- `plots/complexity_curves.png`

## Example Output Format

Each executable prints lines similar to:

```text
Student Name: Md. Ashiquzzaman Khan
Student ID: C243005
Algorithm Name: Quick Sort
Input Size: 10000
Execution time: 1.234 ms (1234 us)
```

(`Insertion_sort.cpp` and `merge_sort.cpp` print `Sorting time` instead of `Execution time`.)

## Notes

- `#include <bits/stdc++.h>` is used, which is supported by GCC/MinGW.
- Timing results vary per run due to randomized input and system load.
- The three programs are independent (no shared headers/source files).
