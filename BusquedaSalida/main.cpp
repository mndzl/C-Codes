#include <bits/stdc++.h>
using namespace std;

int h=8,w=8;
char adj[100][100];

struct Estado{
	int x;
	int y;
	int d;
	Estado(int x2,int y2,int d2):x(x2),y(y2),d(d2){};
};

int bfs(int x, int y);
void makePath(pair<int,int>salida,vector<vector<char>>prev);

int main(){
ifstream e("entrada.in");

   
	int x=-1;
	int y=-1;
	// Carga de laberinto 
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			e>>adj[i][j];
			if(adj[i][j]=='I'){
				x=i;
				y=j; 
			}
		}
	}
	cout<<"Pasos mínimos: "<<bfs(x,y)<<endl;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout<<adj[i][j];
		}
		cout<<"\n";
	}
	
	e.close();
	return 0;
}

void makePath(pair<int,int>salida,vector<vector<char>>prev,int pasos){
	pair<int,int>a=salida;
	pair<int,int>vecino;
	for(int i=0; i<pasos-1; i++){
		switch(prev[a.first][a.second]){
			case 'a':vecino = make_pair(a.first+1,a.second);break;
			case 'A':vecino = make_pair(a.first-1,a.second);break;
			case 'd':vecino = make_pair(a.first,a.second+1);break;
			case 'i':vecino = make_pair(a.first,a.second-1);break;
			case 'n':vecino = make_pair(-1,-1);break;

		}
		adj[vecino.first][vecino.second]='*';
		a = vecino;
	}
}

int bfs(int x,int y){
	vector<vector<char>>prev;
	prev.resize(8);
	for(int i=0; i<8; i++){
		prev[i].resize(8);
	}
	for(int i=0; i<8; i++){
		for(int j=0; j<8; j++){
			prev[i][j]='-';
		}
	}
	pair<int,int>salida;
	queue<Estado>q;
	bool visited[h][w];
	for(int i=0;i<h; i++){
		for(int j=0; j<w;j++){
			visited[i][j]=0;
		}
	}
	Estado inicial(x,y,0);
	q.push(inicial);
	prev[inicial.x][inicial.y]='n';
	
	int dx[]={-1,1,0,0};
	int dy[]={0,0,-1,1};
	
	bool enc = false;
	int pasosFinales;
	
	while(!q.empty() and !enc){
		Estado actual = q.front();
		q.pop();
		if(adj[actual.x][actual.y]=='S'){
			salida = make_pair(actual.x,actual.y);
			enc = true;
			pasosFinales = actual.d;
		}
		visited[actual.x][actual.y]=true;
		for(int j=0; j<4; j++){
			int nx = actual.x+dx[j];
			int ny = actual.y+dy[j];
			if(nx>=0 and nx<h and ny>=0 and ny<w and adj[nx][ny]!='#' and !visited[nx][ny]){
				Estado vecino(nx,ny,actual.d+1);
				q.push(vecino);
				switch(j){
					case 0:prev[vecino.x][vecino.y]='a';break;
					case 1:prev[vecino.x][vecino.y]='A';break;
					case 2:prev[vecino.x][vecino.y]='d';break;
					case 3:prev[vecino.x][vecino.y]='i';break;
				}
			}
		}
	}
	if(enc){makePath(salida,prev,pasosFinales);return pasosFinales;}
	return -1;
}
