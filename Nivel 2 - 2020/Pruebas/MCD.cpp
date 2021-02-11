#include <bits/stdc++.h>
using namespace std;

int MCD(int a, int b){
	if(b==0) return a;
	MCD(b,a%b);
}

int main(){
	
	cout<< MCD(10,21) << endl;
	
	
	return 0;
}
