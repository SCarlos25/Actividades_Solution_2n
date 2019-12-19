#include <iostream>
#include <fstream>
#include <vector>

//EJERCICIO 1
void SaveVector(std::vector<int> o, std::string fileName) {
	std::ofstream myFile;
	myFile.open(fileName, std::ios::out | std::ios::binary); // Controlar si no se abre..!
	myFile.write(reinterpret_cast<char *>(&o[0]), o.size() * sizeof(int));
	myFile.close();
}

void RecoverVector(std::vector<int> &o, std::string fileName) {
	// saber el length del vector que hay en el fichero y reconvertir el fichero al que vamos a meter la info a la misma length
	std::ifstream myFile(fileName, std::ios::in | std::ios::binary);
	myFile.read(reinterpret_cast<char *>(&o[0]), o.size() * sizeof(int));
}

//EJERCICIO 2
struct Object {
	char type;
	int x;
	int y;
};

void Save(std::vector<Object> o, std::string fileName) {
	std::ofstream myFile;
	myFile.open(fileName, std::ios::out | std::ios::binary);
	myFile.write(reinterpret_cast<char *>(&o[0]), o.size() * sizeof(Object));
	myFile.close();
}

void Recover(std::vector<Object> &o, std::string fileName) {
	// saber el length del vector que hay en el fichero y reconvertir el fichero al que vamos a meter la info a la misma length
	std::ifstream myFile(fileName, std::ios::in | std::ios::binary);
	myFile.read(reinterpret_cast<char *>(&o[0]), o.size() * sizeof(Object));
}
