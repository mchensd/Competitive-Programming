#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
#ifdef SUBLIME_RUN
    freopen("E.txt", "r", stdin);
#elif defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
#endif
    ios::sync_with_stdio(0);
    int K, N;
    cin >> K >> N;
    vector<string> words(N);
    for (int i=0; i<N; ++i) {
        cin >> words[i];
    }
    int ub = (int)1e7+5;
    int lb = 1;
    int flines = 0;
    while (lb < ub) {
        int xs = (lb+ub)/2;
        bool ok = true;
        if (xs == 11) {
            cout << 'a';
        }
        int len = 0;
        int lines = 1;
        for (int i=0; i<N; ++i) {
            if (words[i].size() > xs) {
                ok = false;
                break;
            }
            if (len == 0) {
                len = words[i].size();
            }
            else {
                if (len + 1 + words[i].size() > xs) {
                    ++lines;
                    len = words[i].size();
                }
                else {
                    len += 1 + words[i].size();
                }
                
            }
        }
        if (lines > K) ok = false;
        if (ok) {
            flines = lines;
            ub = xs;
        }
        else {
            lb = xs+1;
        }
    }
    cout << lb << ' ' << flines << '\n';
    int len = 0;
    int lines = 1;
    int xs = lb;
    for (int i=0; i<N; ++i) {
        if (len == 0) {
            len = words[i].size();
            cout << words[i];
        }
        else {
            if (len + 1 + words[i].size() > xs) {
                ++lines;
                len = words[i].size();
                cout << '\n' << words[i];
            }
            else {
                len += 1 + words[i].size();
                cout << ' ' << words[i];
            }
            
        }
    }
    cout << '\n';
}

