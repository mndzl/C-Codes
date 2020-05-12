#include <bits/stdc++.h>
using namespace std;

int main(){
	int N,D,F;
	cin>>N>>D>>F;
	
	bitset<1000000>dias;
	for(int i=0; i<N; i++){
		int d; cin>>d;
		dias.set(d-1);
	}
	
	int i = 0;
	int faltas = 0;
	int res = -1;
	faltas = !dias[i];
	
	for(int j=1; j<=D; j++){
		faltas += !dias[j];
		res = max(res, j-i);
		if(faltas>F){
			faltas -= !dias[i];
			i++;
		}
	}
	
	cout<<res;
	
	return 0;
}
