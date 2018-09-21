#include <bits/stdc++.h>
using namespace std;

bool visited[101][101];
int x, y, k, m;

int main() {
#ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
#else
    freopen("pails.in", "r", stdin);
    freopen("pails.out", "w", stdout);
#endif
    ios::sync_with_stdio(0);
    cin >> x >> y >> k >> m;
    queue<pair<int, int> > cur; // the current depth level
    visited[0][0] = true;
    int ans = m;
    cur.push(make_pair(0, 0));
    for (int i=0; i<=k; ++i) {
    	queue<pair<int, int> > next; // the next depth level;
    	while (!cur.empty()) {
    		pair<int, int> state = cur.front();
    		cur.pop();
    		int A = state.first;
    		int B = state.second;
            ans = min(ans, abs(A+B-m));
    		if (!visited[x][B]) { // fill the first to the top
    			visited[x][B] = true;
    			next.push(make_pair(x, B));
    		}

    		if (!visited[A][y]) { //fill the second to the top
    			visited[A][y]= true;
    			next.push(make_pair(A, y));
    		}

    		if (!visited[0][B]) {// empty the first bucket
    			visited[0][B] = true;
    			next.push(make_pair(0, B));
    		}

    		if (!visited[A][0]) { // empty the second bucket
    			visited[A][0] = true;
    			next.push(make_pair(A, 0));
    		}

    		int nextA = 0;
    		int nextB = B+A;

    		if (nextB > y) {
    			nextA = A - (y-B);
    			nextB = y;
    		}
    		if (!visited[nextA][nextB]) { // pour first into second
    			visited[nextA][nextB] = true;
    			next.push(make_pair(nextA, nextB));
    		}

    		nextA = A+B;
    		nextB = 0;
    		if (nextA > x) {
    			nextA = x;
    			nextB = B - (x-A);
    		}

    		if (!visited[nextA][nextB]) {// pour the second into the first
    			visited[nextA][nextB] = true;
    			next.push(make_pair(nextA, nextB));
    		}
    	}
    	cur = next;
    }
    cout << ans << endl;	
}
