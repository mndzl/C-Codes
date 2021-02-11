#include <bits/stdc++.h>
using namespace std;


int get_capic(string);
int main(){
	
	int n;
	cin>>n;
	vector<string>res;
	
	for (int i=0; i<n; i++){
		string nin;
		cin>>nin;
		res.push_back(nin);
		string non;
		cin>>non;
		res.push_back(non);
	}
	
	for (int i=0; i<int(res.size()); i=i+2){
		int nin = get_capic(res[i]);
		int non = get_capic(res[i+1]);
		
		if(nin>non){
			cout<<"RABANON"<<endl;
		}else if(nin<non){
			cout<<"RABANIN"<<endl;
		}else{
			cout<<"DA IGUAL"<<endl;
		}
	}
	

	return 0;
}

int get_capic(string a1){
	string a_rev = a1;
	a_rev.pop_back();
	reverse(a_rev.rbegin(),a_rev.rend());
	
	int cont = 0;
	for (auto a:a_rev){
		cont++;
		a1.push_back(a);
		if(a1 == string(a1.rbegin(),a1.rend())){
			break;
		}
	}
	
	return cont;
}

