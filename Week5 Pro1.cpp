#include <iostream>
using namespace std;

int main() {

    int T;
    cin >> T;

    while (T--) {

        int n;
        cin >> n;

        char arr[n];

        // Frequency array for alphabets
        int freq[26] = {0};

        for (int i = 0; i < n; i++) {
            cin >> arr[i];

            // Counting frequency
            freq[arr[i] - 'a']++;
        }

        int maxFreq = 0;
        char answer;

        // Finding maximum occurring alphabet
        for (int i = 0; i < 26; i++) {

            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                answer = char(i + 'a');
            }
        }

        if (maxFreq <= 1) {
            cout << "No Duplicates Present" << endl;
        }
        else {
            cout << answer << " - " << maxFreq << endl;
        }
    }

    return 0;
}