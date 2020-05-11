#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<int>v = {7, 10, 4, 1, 9, 5, 9, 6};
	
	int x = 12;
	int j = v.size()-1, i=0;
	int resA=-1, resB=-1;
	
	while(i<4 and j>4){
		int sum = v[i]+v[j];
		printf("Sumando V[%i] y V[%i] obtenemos %i\n", i, j, sum);
		
		if (sum<x) i++;
		
		else if(sum>x) j--;
		
		else{
			resA = i;
			resB = j;
			break;
		}
		
	}
	
	if(resA != -1)	printf("Sumando V[%i] y V[%i] obtenemos %i", resA, resB, x);
	
	else cout<<"No se ha encontrado un par que sume "<<x<<endl;
	
	
	return 0;
}
