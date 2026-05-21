#include <iostream>
#include <cmath>
using namespace std;

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

        int key;
        cin >> key;

        int step = sqrt(n);
        int prev = 0;

        int comparisons = 0;
        bool found = false;

        // Finding block
        while (arr[min(step, n) - 1] < key) {
            comparisons++;

            prev = step;
            step += sqrt(n);

            if (prev >= n) {
                break;
            }
        }

        // Linear Search inside block
        for (int i = prev; i < min(step, n); i++) {
            comparisons++;

            if (arr[i] == key) {
                found = true;
                break;
            }
        }

        if (found) {
            cout << "Present " << comparisons << endl;
        }
        else {
            cout << "Not Present " << comparisons << endl;
        }
    }

    return 0;
}