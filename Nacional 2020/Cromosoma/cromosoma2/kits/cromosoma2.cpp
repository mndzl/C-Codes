#include <bits/stdc++.h>
using namespace std;

int ventana(string s){
    map<char, int>mapping;
    mapping['A'] = 1;
    mapping['C'] = 2;
    mapping['G'] = 3;
    mapping['T'] = 4;

    int count = 0;
    for (auto c:s){
		if (c == 'A' or c == 'C' or  c == 'G' or  c == 'T'){ 
			c = mapping[c];
			count+=c;
		}else{
			return -1;
		}
    }
   

    return count;

}

vector<int> cromosoma(string cadena) {
	int size = cadena.length() / 2;
	if(cadena.length()%2!=0){
		vector<int>res = {-1,-1};
		return res;
    }
    
    
    int x = 0;
    int y = size;
    
    int cadenaVentana = ventana(cadena);
    
    int corteX = -1;
    int corteY = -1;
    while(x<cadena.length()-size){
        int s1 = ventana(cadena.substr(x,size));
        int s2 = abs(s1 - cadenaVentana);

        if(s1==s2){
            corteX = x;
            corteY = y;
            break;
        }else{
            x++;
        }
    }
    
    vector<int>res = {corteX,corteY};

    
    return res;

}
