#include <bits/stdc++.h>

using namespace std;

struct persona{
	int lvl;
	int x;
	int y;
};
vector<int> riesgo(vector<int> &x, vector<int> &y, int D, vector<int> &positivos) {
	vector<bool>positivo(x.size());
	for(auto pos:positivos){
		positivo[pos] = true;
	}
	
	vector<persona>ppl(x.size());
	queue<persona>q;
	vector<vector<int>>lvl(x.size(),vector<int>(x.size()));
	vector<int>lvl_res(x.size()+1);
	lvl_res[0] = positivos.size();
	lvl_res[x.size()] = x.size() - positivos.size();
	
	
	for(int i=0; i<x.size(); i++){
		ppl[i].x = x[i];
		ppl[i].y = y[i];
		ppl[i].lvl = (positivo[i])?0:x.size();
		if(positivo[i]){
			q.push(ppl[i]);
			//cout<<"Positivo encontrado en "<<ppl[i].x<<" "<<ppl[i].y<<endl;
		}
		//cout<<"PPL "<<i<<".lvl = "<<ppl[i].lvl<<endl;
	}
	
	//cout<<"Comienza algoritmo"<<endl;
	while(!q.empty()){
		persona actual = q.front();
		q.pop();
		//cout<<"Persona actual: "<<actual.x<<" "<<actual.y<<endl;
		for(int i=0; i<x.size(); i++){
			int dx = abs(actual.x - ppl[i].x);
			int dy = abs(actual.y - ppl[i].y);
			int d = dx + dy;
			if (d<=D)
				if (actual.lvl+1<ppl[i].lvl){
					if(ppl[i].lvl == x.size()) lvl_res[x.size()]--;
					ppl[i].lvl = actual.lvl+1;
					lvl_res[ppl[i].lvl]++;
					q.push(ppl[i]);
				}
			//cout<<"Riesgo persona "<<i<<": "<<ppl[i].lvl<<endl;
		}
		//cout<<"----------------"<<endl;
	}
	
	
	
	return lvl_res;
	
}
