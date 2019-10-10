#include <bits/stdc++.h>
using namespace std;

vector<int>factDe(25,-1);
unsigned long long factorial(int a){
	if(factDe[a]!=-1)return factDe[a];
	else if(a==0 or a==1){
		factDe[a]=1;
		return 1;
	}
	else{
		factDe[a] = a*factorial(a-1);
		return factDe[a];
	}
}

int main(){
	
	vector<int>toFactor;
	for(int i=0; i<50; i++){
		int a;cin>>a;
		toFactor.push_back(a);
	}
	cout<<endl;
	for(int i=0; i<50; i++){
		cout<<factorial(toFactor[i])<<endl;
	}
	
	
	return 0;
}
