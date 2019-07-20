#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N;
    cin >> N;

    stack<int> dirty, washed, dried;

    for (int i=5; i>=1; --i){ 
    	dirty.push(i);
    }

    int c, d;
    while (cin >> c) {
    	cin >> d;
    	if (c == 1) {
    		while (d--) {
    			washed.push(dirty.top());
    			dirty.pop();
    		}
    	}
    	else {
    		while (d--) {
    			dried.push(washed.top());
    			washed.pop();
    		}
    	}
    }
    while (dried.size()) {
    	cout << dried.top() << endl;
    	dried.pop();
    }
}
