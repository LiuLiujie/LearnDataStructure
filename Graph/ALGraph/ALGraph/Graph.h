#pragma once
#include "ALGraph.h"

class Graph
{
public:
	void CreateUDG();//��������ͼ

private:
	ALGraph* ALG;
	void CreateUDG(ALGraph *&G);
};

