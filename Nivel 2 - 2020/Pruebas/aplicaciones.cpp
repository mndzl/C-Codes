#include <bits/stdc++.h>
using namespace std;


int main(){
	int c,a;
	cin>>c>>a;
	
	vector<int>apps;
	for (int i=0; i<c; i++){
		int app;
		cin>>app;
		apps.push_back(app);
	}

	int mb = apps[0];
	int min_cont = 999999;
	int cont = 1;
	int i = 0;
	int j = 0;
	while(j<int(apps.size())){
		if (mb<a){
			mb += apps[++j];
			cont++;
		}
		else{
			min_cont = min(min_cont,cont);
			mb -= apps[i];
			i++;
			cont--;
		}
			
	}

	cout<<min_cont<<endl;
	

	return 0;
}
