#include "Binary.h"

int main()
{
	//AA1_05: Ejercicio 1
	std::vector<int> a({ 1,2,3,4,5,6,7,8,9,10 });
	SaveVector(a, "TestSaveVector.bin");
	for (int i = 0; i < 10; i++) { a[i] = a[i] + 10; };
	a.push_back(1000);
	RecoverVector(a, "TestSaveVector.bin");
	std::cout << "Ejercicio1: ";
	for (int i = 0; i < a.size(); i++) { std::cout << a[i] << ","; };

	std::cout << std::endl;

	//AA1_05: Ejercicio 2

	std::vector<Object> objects;

	objects.push_back({ 'a',1,11 });
	objects.push_back({ 'b',2,22 });
	objects.push_back({ 'c',3,33 });
	objects.push_back({ 'd',4,44 });
	objects.push_back({ 'e',5,55 });
	//guardo 5
	Save(objects, "TestSaveObjects.bin");
	objects[0] = { 'x',6,66 };
	objects[4] = { 'z',9,99 };
	objects.push_back({ 'f',7,77 });
	//hay 6
	Recover(objects, "TestSaveObjects.bin");
	//recupero
	std::cout << "Ejercicio2: " << std::endl;
	for (int i = 0; i < objects.size(); i++) {
		std::cout << i << ":" << objects[i].type << "," << objects[i].x << "," << objects[i].y;
		std::cout << std::endl;
	};

	return 0;
}