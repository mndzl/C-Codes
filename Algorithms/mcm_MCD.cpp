#include <bits/stdc++.h>
using namespace std;

int findmcd(int a,int b);

int main(){
	int a,b,c;cin>>a>>b>>c;
	cout<<findmcd(findmcd(a,b),c);
	
	
	return 0;
}
int findmcd(int a,int b){
	if(b==0)return a;
	return findmcd(b,a%b);
}
