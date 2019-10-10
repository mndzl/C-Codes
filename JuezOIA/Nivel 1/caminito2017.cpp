#include <bits/stdc++.h>
using namespace std;


char libre(map<char,bool>used){
	for(auto i:{'B','G','N'}) if(used[i]==false) return i;
}
void caminito(string &baldosas)
{
	map<char,bool>used;
	for(int i=0; i<baldosas.size(); i++){
		if(baldosas[i]=='R'){
			used['N'] = false;
			used['G'] = false;
			used['B'] = false;
			if(i-1>=0)used[baldosas[i-1]]=true;
			if(i+1<baldosas.size() && baldosas[i+1]!='R')used[baldosas[i+1]]=true;
			baldosas[i] = libre(used);
		}
	}
}
