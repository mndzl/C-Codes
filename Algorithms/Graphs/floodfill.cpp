#include <bits/stdc++.h>
using namespace std;

void floodfill(vector<vector<bool>>&mapa, pair<int,int>pos,int color,vector<vector<bool>>visited){
	int x = pos.first, y = pos.second;
	if(x<0 || x>=4 || y<0 || y>=4 || visited[x][y] || mapa[x][y]!=color) return;

	visited[x][y]=true;
	mapa[x][y] = !mapa[x][y];
	
	floodfill(mapa,{pos.first+1,pos.second},color,visited);
	floodfill(mapa,{pos.first-1,pos.second},color,visited);
	floodfill(mapa,{pos.first,pos.second-1},color,visited);
	floodfill(mapa,{pos.first,pos.second+1},color,visited);
	
}
void mostrar(vector<vector<bool>>mapa){
	for(int i=0; i<4; i++){
		for(auto j:mapa[i]){
			cout<<j<<" ";
		}
		cout<<"\n";
	}
}

int main(){
	vector<vector<bool>>mapa = {{0,0,1,0},{1,1,0,1},{0,1,0,0},{0,1,0,1}};
	pair<int,int>pos;
	vector<vector<bool>>visited(4,vector<bool>(4));
	for(int i=0; i<4; i++)
		for(int j=0; j<4; j++)
			visited[i][j]=0;

	mostrar(mapa);

	cout<<"Indique lugar a pintar: ";cin>>pos.first>>pos.second;

	floodfill(mapa,pos,mapa[pos.first][pos.second],visited);
	cout<<"\nResultado: "<<endl;
	mostrar(mapa);
	
	
	return 0;
}
