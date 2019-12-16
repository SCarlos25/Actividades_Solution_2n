#include "Grafos.h"

int main() {

	std::vector<edge> ele;
	
	edge ed1 = { 1,2 };
	edge ed2 = { 2,3 };
	edge ed3 = { 1,3 };

	edge ed4 = { 2,2 };
	edge ed5 = { 1,5 };

	//ele.push_back(/*ed1*/std::pair<int, int>(2,3));
	//ele.push_back(/*ed1*/std::pair<int, int>(1,3));
	//ele.push_back(/*ed1*/std::pair<int,int>(1,2));

	ele.push_back(ed1);
	ele.push_back(ed2);
	ele.push_back(ed3);
	ele.push_back(ed4);
	//ele.push_back(ed4);

	GraphD* g = new GraphD(ele);

	g->Insert(ed4);
	g->Insert(ed2);

	g->Remove(ed5);
	g->Remove(ed2);

	g->Print();

}