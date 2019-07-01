#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int>>grafo;
	grafo.resize(10);
	for(int i=0; i<10; i++){
		grafo[i].resize(10);
	}
	grafo[0][1]=1;
	grafo[0][2]=1;
	grafo[0][3]=1;
	grafo[3][9]=1;
	grafo[3][4]=1;
	grafo[4][8]=1;
	grafo[2][7]=1;
	grafo[1][6]=1;
	grafo[1][5]=1;
	
	stack<int>s;
	s.push(0);	
	bool visitados[10];
	
	
	while(!s.empty()){
		int actual = s.top();
		s.pop();
		visitados[actual]=true;
		for(int i=0; i<10; i++){
			if(actual==i)continue;
			if(grafo[actual][i]==1 and !visitados[i]){
				s.push(i);
			}
		}
	cout<<actual<<" ";	
	}
	
	return 0;
}
