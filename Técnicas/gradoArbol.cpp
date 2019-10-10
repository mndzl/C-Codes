#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main(){
	vector<vector<int>>adj;
	adj.resize(12);
	adj[1]={2,3,4};
	adj[2]={5,6};
	adj[3]={7};
	adj[4]={8};
	adj[6]={9};
	adj[9]={11};
	adj[8]={10};
	
	queue<int>q;
	q.push(1);
	int levels=0;
	vector<int>visited;
	int finalLevel=0;
	
	while(visited.size()<11){
	int childs=1;
		int actual = q.front();

		q.pop();
		visited.push_back(actual);
		levels++;
		childs--;

		if(adj[actual].size()>0){
			for(int i=0; i<adj[actual].size(); i++){
				q.push(adj[actual][i]);
				childs++;
				levels++;
			}
		}
		else{
			if(childs==0){
				finalLevel=max(levels,finalLevel);
			}
			levels=0;
		}
	}
	
	return 0;
}
