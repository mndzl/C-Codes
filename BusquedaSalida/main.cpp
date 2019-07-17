#include <bits/stdc++.h>
#include <fstream>
#define in 1
#define out 2
#define closed 3
#define free 4
#define visited 5
using namespace std;

vector<vector<int>>mapa(6,vector<int>(6));
queue<pair<int,int>>q;
pair<int,int>salida;
bool outFinded=false;
void bfs(int x, int y);

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
	
	while(!q.empty()){
		actual = q.front();
		q.pop();
		int x = actual.first;
		int y = actual.second;
	
		// Arriba
		if(x-1>=0){
			bfs(x-1,y);
			if(outFinded)return 0;
		}
		// Abajo
		if(x+1<=5){
			bfs(x+1,y);
			if(outFinded)return 0;
		}
		// Izquierda
		if(y-1>=0){
			bfs(x,y-1);
			if(outFinded)return 0;
		}
		// Derecha
		if(y+1<=5){
			bfs(x,y+1);
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
		cout<<"Salida encontrada en: "<<x<<" "<<y;
	}else
	if(mapa[x][y]==free){
		q.push({x,y});
		mapa[x][y]=visited;
	}
}