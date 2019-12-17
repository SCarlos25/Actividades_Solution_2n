#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <forward_list>
#include <algorithm>

typedef int vertex;
typedef std::pair<int, int> edge;

class GraphD
{
private:
	std::map< vertex, std::vector<vertex>> g;
public:
	GraphD();
	//1. Constructor por copia
	GraphD(GraphD *g);

	//2. Constructor a partir de la lista de arcos
	GraphD(std::vector<edge> el) {
		for (int i = 0; i < el.size(); i++) {
			Insert(el[i]);
		}
	
	}

	~GraphD();

	//3. Inserta el arco si no existe
	void Insert(edge ed) {
		std::map<vertex, std::vector<vertex>>::iterator it = g.find(ed.first);
		std::map<vertex, std::vector<vertex>>::iterator it2 = g.find(ed.second);

		if (it2 == g.end()) { g[ed.second]; it2 = g.find(ed.second); }
		if (it != g.end()) {

			std::vector<vertex>::iterator it3;
			
			if (g[ed.first].size() == 0) { g[ed.first].push_back(ed.second); it3 = g[ed.first].end(); } // si está vacío
			else if (g[ed.first].size() == 1 && g[ed.first][0] != ed.second) { // si sólo tiene un elemento
				
				g[ed.first].push_back(ed.second);
				it3 = g[ed.first].end();
			}
			else { it3 = std::find(g[ed.first].begin(), g[ed.first].end(), ed.second); }

			if (it3 != g[ed.first].end() && ed.second !=*it3) { g[ed.first].push_back(ed.second); }

			}
			else {
				g[ed.first];
				g[ed.first].push_back(ed.second);
			}

		}

	

	//4. Borra el arco si existe
	void Remove(edge ed) {

		std::map<vertex, std::vector<vertex>>::iterator it = g.find(ed.first);
		std::map<vertex, std::vector<vertex>>::iterator it2 = g.find(ed.second);

		if (it != g.end() && it2 !=g.end()) {

			std::vector<vertex>::iterator it3;

			if (g[ed.first].size() == 0) { g.erase(ed.first); it3 = g[ed.first].end(); }

			else if (g[ed.first].size() == 1 && g[ed.first][0] == ed.second) {

				g.erase(ed.first);
				it3 = g[ed.first].end();
			}

			else { it3 = std::find(g[ed.first].begin(), g[ed.first].end(), ed.second); }

			if (it3 != g[ed.first].end() && ed.second == *it3) { g[ed.first].erase(it3); }

		}
	}

	//5. Verifica si existe un camino desde el vértice initial
	bool Path(vertex initial, vertex final);

	//6. Verifica si existe un camino desde el vértice initial hasta el vértice final, si no existe devuelve false
	//y la vlist estará vacía.Si existe, devuelve true y construye en vlist la lista
	bool Path(vertex initial, vertex final, std::forward_list<vertex> vlist);


	//7. Imprime por pantalla la lista de los arcos representando al grafo /////
	void Print() {
		std::map<vertex, std::vector<vertex>>::iterator it = g.begin();
		while (it != g.end()) {
			std::cout << it->first << ": ";
			std::vector<vertex>::iterator v_it = it->second.begin();
			for (; v_it != it->second.end(); v_it++) {
				std::cout << *v_it << " ";
			}
			it++;
			std::cout << std::endl;
		}
	
	}

	//8. Verifica que el grafo es euleriano
	bool IsEulerian();

	//9. Calcula el índice de un vértice
	int Index(vertex);

};
