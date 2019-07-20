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

    int T, N;
    cin >> T >> N;
    int posN, negN;
    int posLoc[50001], negLoc[50001];
    for (int i=0; i<N; ++i) {
    	int x; cin >>x;
    	if (x >= 0) {
    		posLoc[posN++] = x;
    	}
    	else {
    		negLoc[negN++] = x;
    	}
    }

    int negInd=0, posInd=0;

    int curTime = 0;
    int counter = -1;
    int curLoc = 0;
    while (curTime < T) {
    	cout << curTime << ' ' << curLoc << endl;
    	counter++;
    	if (posInd == posN && negInd == negN) {
    		break;
    	}
    	if (posInd == posN) {
    		curTime += abs(curLoc-negLoc[negInd]);
    		curLoc = negLoc[negInd++];
    	}
    	else if (negInd == negN) {
    		curTime += abs(curLoc-posLoc[posInd]);
    		curLoc = posLoc[posInd++];
    	}

    	else if (posLoc[posInd] < abs(negLoc[negInd])) {
    		curTime += abs(curLoc-posLoc[posInd]);
    		curLoc = posLoc[posInd++];
    	}
    	else {
    		curTime += abs(curLoc-negLoc[negInd]);
    		curLoc = negLoc[negInd++];
    	}

    }
    cout << counter << endl;
}
