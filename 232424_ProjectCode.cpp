#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q; // Read the length of the string and number of queries
    string S;
    cin >> S; // Read the string

    // Create a 2D array for cumulative counts of letters
    vector<vector<int>> count(26, vector<int>(n + 1, 0));

    // Fill the cumulative counts
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            count[j][i + 1] = count[j][i]; // Carry forward previous counts
        }
        count[S[i] - 'a'][i + 1]++; // Increment the count for the current character
    }

    // Store queries in a vector
    vector<pair<int, int>> queries(q);
    for (int i = 0; i < q; ++i) {
        cin >> queries[i].first >> queries[i].second; // Read each query
    }

    // Process each query
    for (int i = 0; i < q; ++i) {
        int L = queries[i].first - 1; // Convert to 0-based index
        int R = queries[i].second - 1; // Convert to 0-based index

        int maxCount = 0;
        char resultChar = 'a';

        // Check each character from 'a' to 'z'
        for (int j = 0; j < 26; ++j) {
            int charCount = count[j][R + 1] - count[j][L]; // Count in range [L, R]
            // Update if this character count is greater or if it's a tie and lexicographically smaller
            if (charCount > maxCount || (charCount == maxCount && char(j + 'a') < resultChar)) {
                maxCount = charCount;
                resultChar = char(j + 'a');
            }
        }

        // Output the result for the query
        cout << resultChar << " " << maxCount << endl;
    }

    return 0;
}