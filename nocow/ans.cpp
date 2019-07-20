#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

#define mp make_pair
#define pb push_back

int adjCnt[35];
string adjList[35][105];
string noCow[105][35];
int mult[35];
bool inList(string adj, int ind) {
	for (int i=0; i<adjCnt[ind]; ++i){ 
		if (adjList[ind][i] == adj) {
			return true;
		}
	}
	return false;
}

int stringToNum(string s, int ind) {
	for (int i=0; i<adjCnt[ind]; ++i) {
		if (adjList[ind][i] == s) {
			return 
		}
	}
}

int adjListtoInt(int ind) {

}

int main() {
    #if defined(SUBLIME_RUN) || defined(USE_INPUT_FILE)
    freopen("input.txt", "r", stdin);
    #endif
    ios::sync_with_stdio(0);
    int N, K;
    cin >> N >> K;
    int numAdjs=0;
    for (int i=0; i<N; ++i) {
    	string a;
    	cin >> a >> a >> a >> a;
    	cin >> a;
    	int ind = 0;
    	while (a!="cow.") {
    		noCow[i][ind] = a;
    		if (!inList(a, ind)){
    			adjList[ind][adjCnt[ind]++] = a;
    		}
    		ind++;
    		cin >> a;
    	}
    	numAdjs = ind;
    }
    int curMult = 1;
    for (int i=numAdjs-1; i>=0; --i) {
    	mult[i] = curMult;
    	curMult *= adjCnt[i];
    	sort(adjList[i], adjList[i] + adjCnt[i]);
    }



}	
