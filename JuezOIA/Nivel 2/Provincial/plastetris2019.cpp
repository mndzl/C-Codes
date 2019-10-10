#include <vector>
#include <string>
#include <stack>

using namespace std;

vector<vector<bool>>visited(4,vector<bool>(4));
int piezas = 0;

void piezasConectadas(int x, int y, vector<string>matrix){
		stack<pair<int,int>> s;
		s.push({x,y});
		pair<int,int>actual;
		int dy[] = {0,0,-1,1};
		int dx[] = {-1,1,0,0};	
		
		while(!s.empty()){
			actual = s.top();
			s.pop();
			piezas++;
			visited[actual.first][actual.second]=true;
			//cout<<"Posicion actual: "<<actual.first<<" "<<actual.second<<endl;
			
			for(int i=0; i<4; i++){
				int newX = actual.first + dx[i];
				int newY = actual.second + dy[i];
				if((newX < 4 and newX >= 0) and (newY < 4  and newY >= 0) ){
					//cout<<"Viendo a "<<newX<<" "<<newY<<": ";
					if(matrix[newX][newY]=='X' and !visited[newX][newY]){
						s.push({newX,newY});
						visited[newX][newY] = true;
						//cout<<"vecino ";
					}
					//cout<<endl;
				}
			}
	}
			//cout<<"Termina funcion"<<endl;
}

string plastetris(vector<string> cajita)
{
	for(int i=0; i<16; i++){
		int x = i/4;
		int y = i%4;
		if(cajita[x][y]=='X' and !visited[x][y]){
			piezasConectadas(x,y,cajita);
			if(piezas<4) return "NO";
			if(piezas>4) return "NO";
		}
	}
	if(piezas == 0) return "NO";
	if(piezas == 4) return "SI";

}



