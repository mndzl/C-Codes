#include <bits/stdc++.h>
#include <fstream>
#define in 1
#define out 2
#define closed 3
#define free 4
#define visited 5
using namespace std;

int mapa[6][6];
queue<pair<int,int>>q;
pair<int,int>salida;
bool outFinded=false;
void bfs(int x, int y);

int pasos=0;

int main(){
ifstream e("entrada.in");
	
	// Creacion del mapa
	int i=-1;
	pair<int,int>entrada;
	
	do{
		i++;
			for(int j=0; j<6; j++){
				char a;
				e>>a;
				switch(a){
					case 'I':mapa[i][j]=in;entrada=make_pair(i,j);break;
					case 'S':mapa[i][j]=out;break;
					case '#':mapa[i][j]=closed;break;
					case '-':mapa[i][j]=free;break;
				}
			}
	}while(i<5);

	
	// Algoritmo de búsqueda BFS
	
	q.push({entrada.first,entrada.second});
	pair<int,int>actual;
	mapa[entrada.first][entrada.second]=visited;
	int dx[]={-1,1,0,0};
	int dy[]={0,0,-1,1};

	while(!q.empty()){
		actual = q.front();
		q.pop();
		int x = actual.first;
		int y = actual.second;
		pasos++;

		for(int z=0; z<4; z++){
			int nx = x+dx[z];
			int ny = y+dy[z];
			if(nx>=0 && nx<6 && ny>=0 && ny<6)bfs(nx,ny);
			if(outFinded)return 0;
		}
	}
	
	cout<<"No se ha encontrado una salida";
	
e.close();	
	return 0;
}
void bfs(int x, int y){
	if(mapa[x][y]==out){
		outFinded=true;
		cout<<"Salida encontrada en: "<<x<<" "<<y<<" en "<<pasos<<" pasos";
	}else
	if(mapa[x][y]==free){
		q.push({x,y});
		mapa[x][y]=visited;
	}
}
