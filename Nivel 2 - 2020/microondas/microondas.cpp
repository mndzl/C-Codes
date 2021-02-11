#include <string>
#include <vector>
#include <iostream>

using namespace std;

long long thor(vector<int> &a, vector<int> &f, vector<int> &p, int D) {
	long long cont = 0;
	long long ppl = a.size();
	for (long long i=0; i<ppl; i++){
		//cout<<"a"<<endl;
		for (auto obj:p){
			double d = (a[i] * f[i])/obj;
			if (d >= D) cont++; 
			
			//cout<<a[i]<<" x "<<f[i]<<" / "<<obj<<" = "<<d<<endl;
		}
	}
	
	return cont;
	
}
