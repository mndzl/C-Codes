#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v = {2, 3, 2, 5, 1, 5, 2, 3};
	
	int max_sum = 0;
	int sum = 0;
	
	int k = 3;
	
	for(int i=0; i<k; i++){
		sum += v[i];
	}
	
	
	int resI = -1;
	int resJ = -1;
	
	for(int j=k; j<v.size(); j++){
		sum += v[j] - v[j-k];
		if(max_sum<sum){
			max_sum = sum;
			resI = j-k+1;
			resJ = j;
		}
		max_sum = max(sum,max_sum);
	}

	printf("Suma maxima (%i) en la posición [%i..%i]", max_sum, resI, resJ);

	return 0;
}
