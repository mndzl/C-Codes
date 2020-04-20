#include <bits/stdc++.h>
#include <cstring>
#include <cstddef>
using namespace std;

void toBinary(){
	int x; cout<<"Decimal number to be converted: "; cin>>x;
	
	string res = "";
	for (int i=30; i>=0; i--){
		if ((x & (1<<i)) != 0){
			res+='1';
		}else{
			res+='0';
		}
	} 	
	
	cout << res << "\n";
}

void toDecimal(){
	string n; cout<<"Binary number to be converted: "; cin>>n;
	int sum = 0;
	
	for (int i=n.length()-1; i>=0; i--){
		if (n[i]=='1'){
			sum += pow(2,n.length()-1-i);
		}
	}
	
	cout << sum;
}

int main(){
	
	toBinary();
	toDecimal();

	
	return 0;
}
