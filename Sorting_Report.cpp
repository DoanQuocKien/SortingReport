#include <bits/stdc++.h>
#include <chrono>

using namespace std;

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int rnd(int a, int b)
{
    //cerr << a <<' '<< b <<'\n';
    return a + rng() % (b - a + 1);
}
void merge(double arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Create temp arrays
    double* leftArr = new double[n1];
    double* rightArr = new double[n2];

    // Copy data to temp arrays
    for (int i = 0; i < n1; i++)
        leftArr[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        rightArr[i] = arr[mid + 1 + i];

    // Merge temp arrays back into original array
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (leftArr[i] <= rightArr[j]) {
            arr[k] = leftArr[i];
            i++;
        } else {
            arr[k] = rightArr[j];
            j++;
        }
        k++;
    }

    // Copy remaining elements of leftArr, if any
    while (i < n1) {
        arr[k] = leftArr[i];
        i++;
        k++;
    }

    // Copy remaining elements of rightArr, if any
    while (j < n2) {
        arr[k] = rightArr[j];
        j++;
        k++;
    }
    delete[] leftArr;
    delete[] rightArr;
}

// Merge Sort function
void mergeSort(double arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid);       // Sort first half
        mergeSort(arr, mid + 1, right);  // Sort second half

        merge(arr, left, mid, right);    // Merge sorted halves
    }
}
// Partition function using a random element as pivot
int partition(double arr[], int low, int high) {
    int pos = rnd(low, high); // Find a random index
    swap(arr[pos], arr[high]); // Move pivot to the end

    double pivot = arr[high]; // Use the new last element as pivot
    int i = low - 1; // Pointer for smaller elements

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) { // If current element is smaller than pivot
            i++;
            swap(arr[i], arr[j]);
        }
    }
    swap(arr[i + 1], arr[high]); // Place pivot in correct position
    return i + 1; // Return pivot index
}

// QuickSort function
void quickSort(double arr[], int low, int high) {
    if (low < high) {
        int pivotIndex = partition(arr, low, high); // Partition the array

        quickSort(arr, low, pivotIndex - 1);  // Sort left subarray
        quickSort(arr, pivotIndex + 1, high); // Sort right subarray
    }
}
void heapify(double arr[], int n, int i) {
    int largest = i;         // Assume root is largest
    int left = (i << 1) + 1;    // Left child index
    int right = (i << 1) + 2;   // Right child index

    // Check if left child exists and is greater than root
    if (left < n && arr[left] > arr[largest])
        largest = left;

    // Check if right child exists and is greater than the largest so far
    if (right < n && arr[right] > arr[largest])
        largest = right;

    // If largest is not root, swap and continue heapifying
    if (largest != i) {
        swap(arr[i], arr[largest]);
        heapify(arr, n, largest);
    }
}

// HeapSort function
void heapSort(double arr[], int n) {
    // Build max heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    // Extract elements from heap one by one
    for (int i = n - 1; i > 0; i--) {
        swap(arr[0], arr[i]);   // Move current root to end
        heapify(arr, i, 0);      // Heapify reduced heap
    }
}
const int n = 1e6;
double a[10][n];
int main()
{
    srand(time(NULL));
    freopen("testcase.txt", "r", stdin);
    freopen("raw_report.txt", "w", stdout);
    for(int j = 0; j < 10; ++j) cerr << a[0][j] << ' ';
    for(int i = 0; i < 10; ++i)
    {
        for(int j = 0; j < n; ++j)
            cin >> a[i][j];
    }
    cout << "MergeSort" << ' ';
    double cur_sum = 0;
    for(int i = 0; i < 10; ++i)
    {
        auto start = chrono::high_resolution_clock::now();
        mergeSort(a[i], 0, n - 1);
        auto end = chrono::high_resolution_clock::now();  // End timer
        std::chrono::duration<double> elapsed = end - start;
        cout << elapsed.count() << " ";
        cur_sum += elapsed.count();
    }
    cout << cur_sum / 10 << '\n';
    cur_sum = 0;
    cout << "QuickSort" << ' ';
    for(int i = 0; i < 10; ++i)
    {
        auto start = chrono::high_resolution_clock::now();
        quickSort(a[i], 0, n - 1);
        auto end = chrono::high_resolution_clock::now();  // End timer
        std::chrono::duration<double> elapsed = end - start;
        cout << elapsed.count() << " ";
        cur_sum += elapsed.count();
    }
    cout << cur_sum / 10 << '\n';
    cur_sum = 0;
    cout << "HeapSort" << ' ';
    for(int i = 0; i < 10; ++i)
    {
        auto start = chrono::high_resolution_clock::now();
        heapSort(a[i], n);
        auto end = chrono::high_resolution_clock::now();  // End timer
        std::chrono::duration<double> elapsed = end - start;
        cout << elapsed.count() << " ";
        cur_sum += elapsed.count();
    }
    cout << cur_sum / 10 << '\n';
    cur_sum = 0;
    cout << "std::sort(C++)" << ' ';
    for(int i = 0; i < 10; ++i)
    {
        auto start = chrono::high_resolution_clock::now();
        sort(a[i], a[i] + n);
        auto end = chrono::high_resolution_clock::now();  // End timer
        std::chrono::duration<double> elapsed = end - start;
        cout << elapsed.count() << " ";
        cur_sum += elapsed.count();
    }
    cout << cur_sum / 10 << '\n';
    return 0;
}