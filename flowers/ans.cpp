#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int a[10005];
int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int f, k;
    cin >> f >> k;
    for (int i=0; i<k; ++i) {
    	int L, I;
    	cin >> L >> I;
    	for (int k=L; k<=f; k+=I) {
    		a[k]=1;
    	}
    }
    int s = 0;
    for (int i=1; i<=f; ++i) {
    	s += 1-a[i];
    }
    cout << s << endl;
}
