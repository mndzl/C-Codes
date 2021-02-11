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

//AGAAGAGG

int main(){
	string cadena;
	cin>>cadena;
    int size = cadena.length() / 2;
    
	if(cadena.length()%2!=0){
		vector<int>res = {-1,-1};
		cout<<"-1 -1"<<endl;
		return 0;
    }
    
    int x = 0;
    int y = size;
    
    int corteX = -1;
    int corteY = -1;
    
    int cadenaVentana = ventana(cadena);
    
    while(x<cadena.length()-size){
		cout<<x<<endl;
        int s1 = ventana(cadena.substr(x,size));
        int s2 = abs(s1 - cadenaVentana);
        cout<<"s1: "<<cadena.substr(x,size)<<" - "<<s1<<endl;
        cout<<"s2: "<<s2<<endl;

        if(s1==s2){
            corteX = x;
            corteY = y;
            break;
        }else{
			x++;
        }
    }

    cout<<corteX<<endl;
    cout<<corteY<<endl;

    return 0;
}
