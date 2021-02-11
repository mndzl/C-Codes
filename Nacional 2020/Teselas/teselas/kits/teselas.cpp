#include <string>
#include <vector>

using namespace std;

bool alocar(string abajo, string arriba, string i){
	
}
bool backtrack(string mosaico, int abajo, int arriba){
	for(int i=0; i<abajo.size(); i++){
		if(!alocar(string abajo, string arriba, i)){
			backtrack()
		}
	}

}

void intercambiar(int fila1, int columna1, int fila2, int columna2);

int teselas(vector<string> &mosaico) {
	int n = mosaico.size();
	int m = mosaico[0].size();
	
	bool finished = false;
	while(!finished){
		backtrack(mosaico, 1, 0);
	}

	return 1;
}
