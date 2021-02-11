#include <string>
#include <vector>

using namespace std;

//{{'abcd'},
// {'acxy'},
// {'abcd'},
// {'acxy'}};

//ACCAGAGGGGACCGAA

bool alocar(vector<string> mosaico, string i, string j){
	int cambioJ = j+1; 
	
	while(j+=1<mosaico[i].size()){
		if (mosaico[i][j] == mosaico[i-1][j] or mosaico[i][j] == mosaico[i-1][j+1]){
			cambioJ += 1;
		}
	}
	
	if (mosaico[i][j] != mosaico[i-1][j] and mosaico[i][j] != mosaico[i-1][j+1]){
		swap(mosaico[i][j], mosaico[i][cambioJ]);
		//Anunciar cambio
	}else{
		backtrack(mosaico,j-1,i-1);
	}
}

int ii=0;
int ji=1;

bool backtrack(vector<string> mosaico, int abajo, int arriba){
	if (arriba < 0){
		swap(mosaico[0][ii],mosaico[0][ji]);
		//Anunciar cambio
		if(ji+1>=mosaico[0].size()){
			if(ii>=mosaico[0].size()){
				ii+=1;
				return -1;
			}
			j=0;
		}
	}
	
	for(int i=0; i<mosaico[abajo].size(); i++){
		if(!alocar(string mosaico, abajo, i)){
			backtrack(mosaico, abajo-1, arriba-1);
		}
	}

}


int teselas(vector<string> &mosaico) {
	vector<string>mosaico = {{'abcd'},
							 {'acxy'},
							 {'abcd'},
							 {'acxy'}};
	int n = mosaico.size();
	int m = mosaico[0].size();
	
	bool finished = false;
	while(!finished){
		backtrack(mosaico, 1, 0);
	}
}
