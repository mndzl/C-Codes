#include <bits/stdc++.h>
using namespace std;

int main(){
	int n;cin>>n;
	int a;cin>>a;
	int b;cin>>b;
	
	set<int>div;
	
	for (int i=2; i<n; i++){
		if (a%i==0 or b%i==0){
			div.insert(i);
			cout<<i<<" ";
		}
	}
	int cont = 0;
	for (auto i:div){
		cont+=i;
	}
	
	cout<<cont;

}
