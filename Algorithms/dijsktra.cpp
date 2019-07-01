#include<bits/stdc++.h>
#define INF 99999999
using namespace std;


struct node{
	int distance;
	bool visited;
	int provent;
}nodo[7];

int main(){
	// Definicion del grafo
	vector<vector<int>>graph;
	graph.resize(7);
	for(int i=0; i<7; i++){
		graph[i].resize(7);
	}
	graph[0]={0,9,2,5,0,0,4};
	graph[1]={9,0,0,0,0,0,0};
	graph[2]={2,0,0,0,5,0,0};
	graph[3]={5,0,0,0,1,3,0};
	graph[4]={0,0,5,1,0,0,0};
	graph[5]={0,0,0,3,0,0,2};
	graph[6]={4,0,0,0,0,2,0};
	
	// Definicion de Nodos
	for(int i=0; i<7; i++){
		nodo[i].distance=INF;
		nodo[i].visited=false;
	}
	nodo[0].distance=0;
	
	int actual;
	
	
	// Algoritmo
	
	while(true){//Bucle infinito que espera un break;
		//Busqueda de nodo con distancia menor no-visitado (actual)
		int menor=INF;
		for(int i=0; i<7; i++){
			if(nodo[i].distance<menor and nodo[i].visited==false){
				actual = i;
				menor = nodo[i].distance;
			}
		}
		if(menor<INF){
			// Actualizacion de valores de los vecinos
			for(int i=0; i<7; i++){
				if(actual==i)continue;//Anti ciclo
				else
				if(graph[actual][i]!=0){ //Verficación de conexión
					
					/* Si la distancia del nodo actual + el camino entre el
					 * nodo actual y el nodo i es mayor a la distancia del 
					 * nodo[i], actualizo y guardo nodo actual en .provent */
					if((nodo[actual].distance+graph[actual][i])<nodo[i].distance){
						nodo[i].distance=(nodo[actual].distance+graph[actual][i]);
						nodo[i].provent=actual;
					}
				}
			}
		}else break;
		// Nodo actual marcado como visitado
		nodo[actual].visited=true;
		
	}
	
	// Salida de camino del nodo
	int n;
	cout<<"Ingrese nodo: ";cin>>n;
	cout<<"\nDistancia: "<<nodo[n].distance;
	cout<<"\nCamino: "<<nodo[n].provent<<" ";
	int a = nodo[n].provent;
	while(a!=0){
		cout<<nodo[a].provent<<" ";
		a = nodo[a].provent;
	}
	
	return 0;
}
