#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v = {2, 3, 2, 5, 1, 5, 2, 3};
	
	int x = 8;
	int sum = 0;
	int j = 0;
	int n = v.size();
	int resI, resJ;
	
	for(int i=0; i<n; i++){
		printf("Subarreglo {%i..%i}, sum = %i\n", i, j, sum);
		while(sum<x && j<n){
			printf("Subarreglo {%i..%i}, sum = %i\n", i, j, sum);
			sum += v[j];
			j++;
		}
		if(sum==x){
			resI = i;
			resJ = j;
			break;
		}
		sum -= v[i];
	}
	
	printf("El subarreglo de suma %i es [%i..%i]", x, resI, resJ-1);
	
	
	
	
	return 0;
}
