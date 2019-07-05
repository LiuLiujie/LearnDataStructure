#pragma once
#include "ALGraph.h"

class Graph
{
public:
	void CreateUDG();//创建无向图

private:
	ALGraph* ALG;
	void CreateUDG(ALGraph *&G);
};

