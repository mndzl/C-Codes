#include <bits/stdc++.h>
using namespace std;

int main(){
	
	vector<int>v = {2,2,2,2,2};
	
	int max_length = 0;
	int resI = -1, resJ= -1;
	
	int j = 0;
	int i = 0;
	while(j<v.size()){
		j++;
		if(max_length<j-i){
			max_length = j-i;
			resI = i;
			resJ = j-1;
		}
		if(j<v.size() and v[j-1]>=v[j])
			i = j;
	}

	
	printf("Max length is %i in [%i..%i]", max_length, resI, resJ);
	
	return 0;
}
