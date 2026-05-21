#include <iostream>
using namespace std;

int comparisons = 0;
int inversions = 0;

// Merge Function
void merge(int arr[], int low, int mid, int high) {

    int n1 = mid - low + 1;
    int n2 = high - mid;

    int left[n1], right[n2];

    for (int i = 0; i < n1; i++)
        left[i] = arr[low + i];

    for (int j = 0; j < n2; j++)
        right[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = low;

    while (i < n1 && j < n2) {

        comparisons++;

        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            inversions += (n1 - i);
            j++;
        }

        k++;
    }

    while (i < n1) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

// Merge Sort Function
void mergeSort(int arr[], int low, int high) {

    if (low < high) {

        int mid = (low + high) / 2;

        mergeSort(arr, low, mid);
        mergeSort(arr, mid + 1, high);

        merge(arr, low, mid, high);
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
        inversions = 0;

        mergeSort(arr, 0, n - 1);

        // Printing sorted array
        for (int i = 0; i < n; i++) {
            cout << arr[i] << " ";
        }

        cout << endl;
        cout << "comparisons = " << comparisons << endl;
        cout << "inversions = " << inversions << endl;
    }

    return 0;
}