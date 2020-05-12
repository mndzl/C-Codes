#include <bits/stdc++.h>
using namespace std;

int main(){
	
	int nums[] = {-2, -3, 4, -1, -2, 1, 5, -3};
	int n = 8;
	
	
	int max_so_far = -99999999;
	int max_ending_here = 0;
	int start = 0, s = 0, end = 0;
	for(int i=0; i<n; i++){
		max_ending_here += nums[i];
		
		if(max_so_far<max_ending_here){
			max_so_far = max_ending_here;
			start = s;
			end = i+1;
		}
		
		if (max_ending_here<0){
			max_ending_here = 0;
			s = i + 2;
		}

	}
	
	printf("Max subarray sum = %i ([%i..%i])", max_so_far, start, end);
	
	return 0;
}
