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
	
	for(int j=k; j<v.size(); j++){
		sum += v[j] - v[j-k];
		max_sum = max(sum,max_sum);
	}

	
	cout<<max_sum;

	return 0;
}
