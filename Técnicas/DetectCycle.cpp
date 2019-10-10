#include <bits/stdc++.h>
using namespace std;

int main(){
	vector<vector<int>>adjList={{1,2,3},
		                         {2,0,4},
		                         {4,0,1,3},
		                         {0,2},
		                         {2,1}};
	
	
	stack<int>q;
	vector<bool>visited(5);
	visited[0] = true;
	vector<int>vecinosCero;
	for(auto i:adjList[0]){
		q.push(i);
		vecinosCero.push_back(i);
	}
	while(!q.empty()){
		int actual = q.top();
		q.pop();
		visited[actual]=true;
		for(auto v:adjList[actual]){
			if(!visited[v]){
					if(find(vecinosCero.begin(),vecinosCero.end(),v)!=vecinosCero.end()){
						cout<<"Ciclico";return 0; 
					}
					q.push(v);
			}
		}
	}
	cout<<"No ciclico";
	return 0;
}
