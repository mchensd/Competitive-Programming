#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
#define PI 3.14159265358979
#define inf 0x3f3f3f3f

typedef pair<int, int> PII;
int position[101];
int rightmost[102];
bool visited[102];
int main() {
    // freopen("input.txt", "r", stdin);
    freopen("hoofball.in", "r", stdin);
    freopen("hoofball.out", "w", stdout);
    ios::sync_with_stdio(0);
	int N;
	cin >> N;
	for (int i=0; i<N; i++) {
		int x;
		cin >> x;
		position[i] = x;
	}    
	sort(position, position+N);
	for (int i=0; i<N; i++) {
		memset(visited, false, sizeof(visited));
		int cur_pos = i;
		while (!visited[cur_pos]) {
			visited[cur_pos] = true;
			if (cur_pos == 0) {
				cur_pos++;
			}
			else if (cur_pos == N-1) {
				cur_pos--;
			}
			else {
				if (position[cur_pos] - position[cur_pos-1] <= position[cur_pos+1] - position[cur_pos]) {
					cur_pos--;
				}
				else {
					cur_pos++;
				}
			}	
		}
		int lft = -1, rght = -1;
		for (int i=0; i<=N; i++) {
			if (visited[i]) {
				if (lft == -1) {
					lft = i;
				}
			}
			else {
				if (lft > -1 && rght == -1) {
					rght = i-1;
				}
			}
		}
		rightmost[lft] = max(rightmost[lft], rght);
	}
	// for (int i=0; i<N; i++) {
	// 	cout << position[i] << " ";
	// }
	//jrwoijr3oijrio2rjojij3irijoi2j3irojo2jri23orjo2i3jroi23jro2i3jro2irjoij
	// cout << endl;
	// cout << rightmost[0] << endl;
	int ans = 1;
	int next_update = rightmost[0]+1;
	int running_max = rightmost[0];
	for (int i=1; i<N; i++){
		running_max = max(running_max, rightmost[i]);
		if (i == next_update) {
			ans++;
			next_update = running_max+1;
		}
	}
	cout << ans << endl;
}
/*
5
1 3 5 7 9
*/
