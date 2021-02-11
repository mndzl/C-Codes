#include <iostream>
#include <string>
#include <vector>

using namespace std;

int teselas(vector<string> &mosaico);

struct LlamadaIntercambiar
{
    int fila1,columna1, fila2, columna2;
};

vector<LlamadaIntercambiar> listaDeLlamadasAIntercambiar;

void intercambiar(int fila1, int columna1, int fila2, int columna2)
{
    listaDeLlamadasAIntercambiar.push_back({fila1, columna1, fila2, columna2});
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m;
    cin >> m;
    vector<string> mosaico;
    mosaico.resize(n);
    for (int i0 = 0; i0 < n; i0++) {
        cin >> mosaico[i0];
    }
    int returnedValue;
    returnedValue = teselas(mosaico);
    cout << returnedValue << "\n";
    for (auto x : listaDeLlamadasAIntercambiar)
    {
        cout << x.fila1 << " " << x.columna1 << " " << x.fila2 << " " << x.columna2 << "\n";
    }
    return 0;
}
