#include <bits/stdc++.h>
using namespace std;

int main(){
	int arr[] = {2,4,6,1,2,4,5,7};
	int x = 9;
	
	int sum = 0;
	int j = 0;
	
	for(int i=0; i<8; i++){
		while(j<8 and sum<x){
			sum += arr[j++];
			printf("Arreglo actual: [%i..%i] con suma %i \n", i, j-1, sum);
		}
		if(sum == x){
			printf("El subarreglo [%i..%i] suma %i", i, j-1, x);
			return 0;
		}
		
		sum -= arr[i]; 
		
	}
	
	cout<<"No se ha encontrado un arreglo que de como resultado "<<x<<endl;


	return 0;
}
