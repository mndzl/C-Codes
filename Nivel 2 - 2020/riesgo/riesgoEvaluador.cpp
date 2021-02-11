#include <iostream>
#include <string>
#include <vector>
#include "riesgo.cpp"

using namespace std;

vector<int> riesgo(vector<int> &x, vector<int> &y, int D, vector<int> &positivos);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    cin >> m;
    int D;
    cin >> D;
    vector<int> x;
    vector<int> y;
    x.resize(n);
    y.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> x[i];
        cin >> y[i];
    }
    vector<int> positivos;
    positivos.resize(m);
    for (int i0 = 0; i0 < m; i0++) {
        cin >> positivos[i0];
    }
    vector<int> returnedValue;
    returnedValue = riesgo(x,y,D,positivos);
    for (int i = 0; i < int(returnedValue.size()); i++) {
        if (i > 0) cout << " ";
        cout << returnedValue[i];
    }
    cout << "\n";
    return 0;
}
