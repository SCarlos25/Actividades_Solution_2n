#include "Grafos.h"

int main() {

	std::vector<edge> ele;
	
	edge ed1 = { 1,2 };
	edge ed2 = { 2,3 };
	edge ed3 = { 1,3 };

	ele.push_back(/*ed1*/std::pair<int,int>(1,2));
	ele.push_back(/*ed1*/std::pair<int, int>(2,3));
	ele.push_back(/*ed1*/std::pair<int, int>(1,3));

	GraphD* g = new GraphD(ele);

}