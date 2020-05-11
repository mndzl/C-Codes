#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v = {7, 10, 4, 1, 9, 5, 9, 6};
	
	int x = 12;
	int n = v.size();
	int j = n-1;
	int resA=-1, resB=-1;
	
	vector<pair<int,int>>vp;
	for(int i=0; i<n; i++){
		vp.push_back({v[i], i});
	} 
	
	sort(vp.begin(), vp.end());
	
	for(int i=0; i<n; i++){
		while(j>i && vp[i].first+vp[j].first>x) j--;
		if(j>1 && vp[i].first+vp[j].first==x){
			resA = i;
			resB = j;
			break;
		}
	}
	
	
	if(resA != -1)	printf("Sumando V[%i] y V[%i] obtenemos %i", vp[resA].second, vp[resB].second, x);
	
	else cout<<"No se ha encontrado un par que sume "<<x<<endl;
	
	
	return 0;
}
