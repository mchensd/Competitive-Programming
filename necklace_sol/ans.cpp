/*
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;
#define in cin
#define out cout

int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("necklace.in", "r", stdin);
    freopen("necklace.out", "w", stdout);
#endif"necklace.out");

    string text, pattern;
    in >> text >> pattern;

    int n = text.size();
    int m = pattern.size();

    for (int i = 0; i < n; ++i) {
        text[i] -= 'a';
    }
    
    for (int i = 0; i < m; ++i) {
        pattern[i] -= 'a';
    }

    vector<vector<int> > next(m, vector<int>(26, 0));

    for (int i = 1; i < m; ++i) {
        int prev = next[i - 1][pattern[i - 1]];
        next[i - 1][pattern[i - 1]] = i;
        for (int j = 0; j < 26; ++j) {
            next[i][j] = next[prev][j];
        }
    }
    next[m - 1][pattern[m - 1]] = m;

    vector<int> max_taken(m, -n - 1);
    max_taken[0] = 0;
    for (int i = 0; i < n; ++i) {
        vector<int> next_taken = max_taken;
        for (int j = 0; j < m; ++j) {
            int cur = next[j][text[i]];
            if (cur < m) {
                next_taken[cur] = max(next_taken[cur], max_taken[j] + 1);
            }
        }
        max_taken = next_taken;
    }

    int result = 0;
    for (int i = 0; i < m; ++i) {
        result = max(result, max_taken[i]);
    }

    out << n - result << endl;

    in.close();
    out.close();
}