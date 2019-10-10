#include <bits/stdc++.h>
#define INF 999999
using namespace std;

int main(){
	int cn = 6; // Cantidad de nodos
	vector<vector<int>>adj = {{0,4,1,0,10,0},
									  {4,12,0,0,0,3},
									  {1,0,0,2,0,0},
									  {0,0,2,0,0,5},
									  {10,4,0,0,0,0},
									  {0,12,0,5,0,0}};
	vector<int>pertenece(cn);
	vector<vector<int>>newAdj(cn,vector<int>(cn)); // Creamos donde se almacenará el arbol de expansión
	
	for(int i=0; i<cn; i++){
		newAdj[i] = vector<int>(cn,0); // Definicion de matriz a 0
		pertenece[i] = i; // Nodo i pertenece a arbol i
	}
	
	int arcos = 1;
	int nodoA=0;
	int nodoB=0;
	
	while(arcos<cn){ // El arbol de expansión tendrá cn-1 arcos
		int min = INF;

		
		// Busqueda de arco menor sin ciclos
		for(int i=0; i<cn; i++){
			for(int j=0; j<cn; j++){
				if((adj[i][j] < min) && adj[i][j]!=0 && pertenece[i]!=pertenece[j]){
					/*Comprobamos si la conexión es la menor, si no es 0 y
						si no pertenecen al mismo arbol.*/
						min = adj[i][j];		/* Almaceno la distancia menor
													y sus correspondientes nodos */
						nodoA = i;							
						nodoB = j;
				}
			}
		}
		
		if(pertenece[nodoA]!=pertenece[nodoB]){
			newAdj[nodoA][nodoB] = min; // Actualizo la nueva matriz con el arbol final
			newAdj[nodoB][nodoA] = min;
			
			int ref = pertenece[nodoB]; // Referencio al antiguo arbol del nodo B
			pertenece[nodoB] = pertenece[nodoA]; // Almaceno el nodoB como nodo del arbol del nodoA
			for(int k=0; k<cn; k++){
				if(pertenece[k]==ref){ // Cambio todas las apariciones del nodo B en otros arboles
					pertenece[k]=pertenece[nodoA]; // para actualizarlo a perteneciente del arbol del nodo A
				}
			}
			arcos++;
		}

		
	}
	
	for(int i=0; i<cn; i++){
		for(int j=0; j<cn; j++){
			cout<<newAdj[i][j]<<" ";
		}
		cout<<endl;
	}
	
	
	return 0;
}
