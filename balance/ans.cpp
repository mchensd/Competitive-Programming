#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

bool visited[10000];
int main() {
#if defined(USE_INPUT_FILE) || defined(SUBLIME_RUN)
	freopen("input.txt", "r", stdin);   
#endif
    ios::sync_with_stdio(0);
    int N;
    cin >> N;
    int ans = 0;
    while (!visited[N]) {
    	++ans;
    	visited[N] = true;
	    N = (N/10) % 100;
	    N*=N;
    }
    
    cout << ans << endl;
}
