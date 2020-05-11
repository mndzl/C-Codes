#include <bits/stdc++.h>
using namespace std;

int main(){
	
	vector<int> v = {2, 3, 2, 5, 1, 5, 2, 3};
	
	int x = 8;
	int j = 0;
	int n = v.size();
	int sum = 0;
	int resI, resJ;
	
	for(int i=0; i<n; i++){
		printf("El arreglo [%i..%i] da %i como suma\n", i,j,sum);
		while(j<n and sum<x){
			sum += v[j++];
			printf("El arreglo [%i..%i] da %i como suma\n", i,j,sum);
		}
		if(sum == x){
			resI = i;
			resJ = j;
			printf("El subarreglo [%i..%i] da %i", resI, resJ, x);
			return 0;
		}
		sum-= v[i];
	}
	
	cout<<"No se ha encontrado un subarreglo que cumpla las condiciones";
	
	
	return 0;
}
