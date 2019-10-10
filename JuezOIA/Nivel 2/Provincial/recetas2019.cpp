#include <vector>
#include <string>
#include <set>

using namespace std;

int recetas(vector<string> heladera, vector<vector<string> > libro, vector<int> &realizables)
{
	set<string>h;
	for(auto i:heladera)h.insert(i);
	
	for(int i=0; i<int(libro.size()); i++){
		bool valid = true;
		for(auto ing:libro[i]){
			if(!h.count(ing)){
				valid = false;
				break;
			}
		}
		if(valid)realizables.push_back(i+1);
	}
	
	return realizables.size();
	
}
