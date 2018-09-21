#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define mp make_pair
#define pb push_back




int board[9][9];

int main() {
    #ifdef USE_INPUT_FILE
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int t; cin >> t;
    while (t--) {
    	int si=0, sj=0;

    	for (int i=0; i<8; ++i)for(int j=0; j<8; ++j) board[i][j]=1;
    	for (int i=0; i<8; ++i ){
    		string s; cin >> s;
    		for (int j=0; j<8; ++j) {
    			if (s[j] == 'k') {
    				board[i][j] = 2;
    			}
    			else if (s[j] == 'P') {
    				if (i == 1 && board[0][j] == 0) {
    					board[i][j] = 0;
    				}
    				else {
    					sj = j;
    				}
    			}
    			else {
    				board[i][j] = 0;
    			}
    		}
    	}
    	
    	// check knight
    	int chj[] = {-2, -1,1,2};
    	int chi[] = {1,2,2,1};
    	bool done = false;
    	for (int k=0;k<4;++k) {
    		int dx = chj[k], dy=chi[k];
    		if (min(dx, dy) >= 0 && max(dx, dy) < 8) {
    			if (board[dx][dy] == 2) {
    				cout << 1 << endl;
    				done=true;
    			}
    		}
    	}
    	if (done) continue;
    	for (int j=0; j<8; ++j) {
    		if (board[0][j] == 2) {
    			cout << 2 << endl;
    			done = true;
    		}
    	}
    	if (done)continue;
    	for (int i=0; i<8; ++i) {
    		if (board[i][sj] == 2) {
    			cout << 2 << endl; done=true;
    		}
    	}
    	if (done) continue;
    	for (int i=si+1, j=sj-1; i<8&&j>=0; ++i, --j) {
    		if (board[i][j] == 2) {
    			done = true;
    			break;
    		}
    	}
    	for (int i=si+1, j=sj+1; i<8&&j<8;++i,++j) {
    		if (board[i][j]==2){
    			done = true;
    			break;
    		}
    	}
    	if (done) {
    		cout << 2 << endl;
    	}
    	else {
    		cout << 0 << endl;
    	}
    }






}
