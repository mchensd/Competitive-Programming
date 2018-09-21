#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define PI 3.14159265358979
#define inf 0x3f3f3f3f

int position[101];
// bool visited[101]; dont need........ lul
int main() {
    freopen("input.txt", "r", stdin);
    // freopen("hoofball.in", "r", stdin);
    // freopen("hoofball.out", "w", stdout);
    int N;
    cin >> N;
    for (int i=0; i<N; i++) {
    	int x;
    	cin >> x;
    	position[i] = x;
    }
    sort(position, position+N);
    for (int i=0; i<N; i++) {
        cout << position[i] << " ";
    }
    cout << endl;
    int ans = 0;
    int lft = 0;
    int rght = N-1;
    while (lft <= rght) {
        // how does this even work
    	ans += 2;
    	int tmpl = lft;
    	while (tmpl == 0 || position[tmpl+1] - position[tmpl] < position[tmpl] - position[tmpl-1]) {
    		tmpl++;
    	}
    	if (tmpl >= rght) {
    		ans--;
    		break;
    	}
    	int tmpr = rght;
    	while (tmpr == N-1 || position[tmpr] - position[tmpr-1] <= position[tmpr+1] - position[tmpr]) {
    		tmpr--;
    	}
    	if (tmpr <= lft) {
    		ans --;
    		break;
    	}
    	lft = tmpl+1;
    	rght = tmpr-1;
    }
    cout << ans << endl;
}
