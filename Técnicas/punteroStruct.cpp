#include <bits/stdc++.h>
using namespace std;


struct nodo{
	int x;
	nodo* next;
}node[5];

int main(){
	node[2].x=12;
	node[1].next=&(node[2]);
	node[1].next->x=9;
	
	cout<<node[1].next->x;
	

	return 0;
}
