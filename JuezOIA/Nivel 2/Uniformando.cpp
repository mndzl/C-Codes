#include <bits/stdc++.h>
using namespace std;


queue<pair<int,int>>q;
bool toTransform;
int adj[6][6]={{0,0,1,1,0,0},
			   {0,1,0,1,0,1},
			   {1,1,0,1,1,0},
			   {1,1,0,1,1,0},
			   {0,1,1,0,0,1},
			   {1,1,0,0,1,1}};
pair<int,int>actual;
bool huboCambio;

void reiniciar();
void ver(int x,int y,vector<vector<bool>>&visited);
int main(){
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	
	bool fin=false;
	int mov=0;
	
	cout<<"PROGRESO: \n";
	for(int i=0; i<6; i++){
		for(int j=0; j<6;j++){
			cout<<adj[i][j]<<" ";
		}
		cout<<"\n";
	}
	
	
	while(!fin){
		q.push({0,0});
		vector<vector<bool>>visited(6,vector<bool>(6));
		visited[0][0]=true;

		adj[0][0]=!adj[0][0];
		
		while(!q.empty()){
			actual = q.front();
			q.pop();
			//Abajo
			if(actual.first+1<=5)ver(actual.first+1,actual.second,visited);
			//Derecha
			if(actual.second+1<=5)ver(actual.first,actual.second+1,visited);
			//Arriba
			if(actual.first-1>=0)ver(actual.first-1,actual.second,visited);
			//Izquierda
			if(actual.second-1>=0)ver(actual.first,actual.second-1,visited);
			
		}
		mov++;
		cout<<"PROGRESO: \n";
		for(int i=0; i<6; i++){
			for(int j=0; j<6;j++){
				cout<<adj[i][j]<<" ";
			}
			cout<<"\n";
		}
		
		int suma = 0;
		for(int i=0; i<6; i++){
			for(int j=0; j<6; j++){
				suma = suma + adj[i][j];
			}
		}
		if(suma == 0 or suma == 6*6){
			cout<<mov;
			return 0;
		}
		
	}
	
	cout<<mov;
	
	return 0;
}
void ver(int x,int y,vector<vector<bool>>&visited){
	if(adj[x][y]!=adj[actual.first][actual.second] and visited[x][y]==false){
		q.push({x,y});
		visited[x][y]=true;
		adj[x][y]=!adj[x][y];
	}
}
