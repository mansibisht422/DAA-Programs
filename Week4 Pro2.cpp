#include <iostream>
#include <cstdlib>
using namespace std;

int comparisons = 0;
int swaps = 0;

// Swap Function
void swapValues(int &a, int &b) {
    int temp = a;
    a = b;
    b = temp;
    swaps++;
}

// Partition Function
int partition(int arr[], int low, int high) {

    // Random Pivot
    int randomIndex = low + rand() % (high - low + 1);

    swapValues(arr[randomIndex], arr[high]);

    int pivot = arr[high];

    int i = low - 1;

    for (int j = low; j < high; j++) {

        comparisons++;

        if (arr[j] < pivot) {
            i++;
            swapValues(arr[i], arr[j]);
        }
    }

    swapValues(arr[i + 1], arr[high]);

    return i + 1;
}

// Quick Sort Function
void quickSort(int arr[], int low, int high) {

    if (low < high) {

        int pivotIndex = partition(arr, low, high);

        quickSort(arr, low, pivotIndex - 1);
        quickSort(arr, pivotIndex + 1, high);
    }
}

int main() {

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        int arr[n];

        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        comparisons = 0;
        swaps = 0;

        quickSort(arr, 0, n - 1);

        // Printing sorted array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
        cout << "comparisons = " << comparisons << endl;
        cout << "swaps = " << swaps << endl;
    }

    return 0;
}