#include <string>
#include <vector>

using namespace std;

int decada(int fecha) {
    return fecha%100; // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
}

bool esmayor(int edad) {
    return (edad>=18)?true:false; // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
}

string nombrecompleto(string nombre, string apellido) {
    return nombre + " " + apellido; // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
}

int cantidadmayores(vector<int> &edades) {
	int c;
	for (auto ed:edades){
		if (ed>=18)
			c++;
	}
    return c; // AQUI SE DEBE IMPLEMENTAR LA SOLUCION
}
