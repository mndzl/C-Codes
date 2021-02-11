#include <bits/stdc++.h>

using namespace std;

int analizar(vector<vector<int>> &muestras) {
	int max_v = 0;
	
	for(int i=0; i<muestras.size(); i++){
		for(int j=0; j<muestras[i].size(); j++){
			int dif = muestras[i][j] - i;
			max_v = max(dif, max_v);
		}
	}

	return max_v;
}

