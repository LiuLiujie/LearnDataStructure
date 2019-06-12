#include "Graph.h"

void Graph::CreateUDN(AMGraph* G)
{
	std::cout << "输入总顶点数和总边数:" << std::endl;
	std::cin >> G->vexNum >> G->arcNum;//输入总顶点数,总边数
	int i,j;
	std::cout << "输入各顶点名称:" << std::endl;
	for ( i = 0; i < G->vexNum; i++)//输入点信息
	{
		std::cin >> G->vexs[i];
	}
	for ( i = 0; i < G->vexNum; i++)//初始化邻接矩阵
	{
		for ( j = 0; j < G->vexNum; j++)
		{
			G->arcs[i][j] = MaxInt;
		}
	}
	VerTexType v1, v2;
	int w;
	std::cout << "按<顶点1> <顶点2> <权重>输入边" << std::endl;
	for (int k = 0; k < G->arcNum; k++)
	{
		std::cin >> v1 >> v2 >> w;//输入边的两个顶点和权重
		i = LocateVex(AMG, v1);
		j = LocateVex(AMG, v2);
		G->arcs[i][j] = w;//无向图设置为对称矩阵
		G->arcs[j][i] = w;
	}
}

void Graph::CreateDN(AMGraph* G)
{
	std::cout << "输入总顶点数和总边数:" << std::endl;
	std::cin >> G->vexNum >> G->arcNum;//输入总顶点数,总边数
	int i, j;
	std::cout << "输入各顶点名称:" << std::endl;
	for (i = 0; i < G->vexNum; i++)//输入点信息
	{
		std::cin >> G->vexs[i];
	}
	for (i = 0; i < G->vexNum; i++)//初始化邻接矩阵
	{
		for (j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = MaxInt;
		}
	}
	VerTexType v1, v2;
	int w;
	std::cout << "按<始点> <终点> <权重>输入边" << std::endl;
	for (int k = 0; k < G->arcNum; k++) {
		std::cin >> v1 >> v2 >> w;//输入边的两个顶点和权重
		i = LocateVex(AMG, v1);
		j = LocateVex(AMG, v2);
		G->arcs[i][j] = w;
	}
}

int Graph::LocateVex(AMGraph* G, VerTexType u)
{
	for (int i = 0; i < G->vexNum; i++)
	{
		if (G->vexs[i] == u) {
			return i;
		}
	}
	return -1;
}

void Graph::DFS_AM(AMGraph* G, int v)
{
	std::cout << G->vexs[v];//
	visited[v] = true;
	for (int w = 0; w < G->vexNum; w++)
	{
		if ((G->arcs[v][w] != MaxInt) && (!visited[w])) //该点为邻接点且未遍历
		{
			DFS_AM(G, w);
		}
	}
}

int Graph::Min(Closedge* closedge)
{
	int min = MaxInt;
	int pos=-1;
	for (int i = 0; i < AMG->vexNum; i++)
	{
		if (closedge[i].lowcost > 0 && closedge[i].lowcost < min) {
			min = closedge[i].lowcost;
			pos = i;
		}
	}
	return pos;
}

void Graph::MiniSpanTree_Prim(AMGraph* G, VerTexType u)
{
	int k = LocateVex(G, u);
	for (int j = 0; j < G->vexNum; j++)
	{
		if (j != k) {//初始化其他每一个顶点到初始点u的距离
			closedge[j] = { u,G->arcs[k][j] };
		}
	}
	closedge[k].lowcost = 0;//初始化u到u距离:0

	for (int i = 1; i < G->vexNum; i++)//连续寻找n-1个最短边加入closedge
	{
		k = Min(closedge);//找到最短边的新顶点在closedge位置
		VerTexType u0 = closedge[k].adjvex;//最小边集中的已有顶点
		VerTexType v0 = G->vexs[k];//最小边的另一个新顶点
		std::cout << u0 <<" - "<< v0 << std::endl;
		closedge[k].lowcost = 0;//新顶点并入已求最小边集中,即权重归为0
		for (int j = 0; j < G->vexNum; j++)//更新边集,寻找其他n-2个顶点到顶点k的位置是否比到u的短
		{
			if (G->arcs[k][j] < closedge[j].lowcost) 
			{
				closedge[j] = { G->vexs[k],G->arcs[k][j] };
			}
		}
	}
}

void Graph::MiniSpanTree_Kruskal(AMGraph* G)
{
	Sort(edge);
	for (int i = 0; i < G->vexNum; i++)
	{
		Vexset[i] = i;
	}
	for (int i = 0; i < G->arcNum; i++)
	{
		int v1 = LocateVex(AMG, edge[i].Head);
		int v2 = LocateVex(AMG, edge[i].Tail);
		int vs1 = Vexset[v1];
		int vs2 = Vexset[v2];
		if (vs1 != vs2)
		{
			std::cout << edge[i].Head << "-" << edge[i].Tail << std::endl;
			for (int j = 0; j < G->vexNum; j++)
			{
				if (Vexset[j] == vs2)
				{
					Vexset[j] = vs1;
				}
			}
		}
	}
}

void Graph::Sort(Edge* edge)
{
	for (int i = 0; i < AMG->arcNum - 1; i++)
	{
		for (int j = 0; j < AMG->arcNum - i - 1; j++)
		{
			if (edge[j].lowcast > edge[j + 1].lowcast)
			{
				Edge t = { edge[j].Head,edge[j].Tail,edge[j].lowcast };
				edge[j] = { edge[j + 1].Head,edge[j + 1].Tail,edge[j + 1].lowcast };
				edge[j + 1] = { t.Head,t.Tail,t.lowcast };
			}
		}
	}
}

void Graph::ShortestPath(AMGraph* G, int v0)
{
	/*错误抓取*/
	if (v0 == -1)
	{
		std::cout << "节点不存在" << std::endl;
		return;
	}
	/*初始化*/
	int n = G->vexNum;//保存顶点个数
	for (int v = 0; v < n; v++)
	{
		S[v] = false;
		D[v] = G->arcs[v0][v];//将v0到各顶点最短路径集初始为顶点到各点权值
		if (D[v] < MaxInt) {//若v0到v之间有弧,将v前驱设为v0,无则设为-1
			Path[v] = v0;
		}else {
			Path[v] = -1;
		}
	}
	S[v0] = true;//初始化v0,将v0最短路径设为已找到,路径设为0
	D[v0] = 0;
	/*主循环,依次求得v0到某个顶点v的最短路径,加入S中*/
	for (int i = 0; i < n; i++)
	{
		int min = MaxInt;
		int v = 0;
		for (int w = 0; w < n; w++)
		{
			if (!S[w] && D[w] < min) {//找到一条最短路径,从v0到v
				v = w;
				min = D[w];
			}
		}
		S[v] = true;//将v加入S
		for (int w = 0; w < n; w++) //更新从v0到集合V-S上所有顶点最短路径
		{
			if (!S[w] && (D[v] + G->arcs[v][w] < D[w])) {//S未找到且从新的v到该节点距离会缩短
				D[w] = D[v] + G->arcs[v][w];//更新距离
				Path[w] = v;//更新前驱
			}
		}
	}
	/*输出*/
	for (int i = 0; i < G->vexNum; i++) {
		if (i != v0) {
			std::cout << "从< " << G->vexs[v0] << " >到< " << G->vexs[i] << " >的最短距离为: "
				<< D[i] << std::endl;
			std::cout << "对应最短路径为: " << G->vexs[i] << " - ";
			int p=Path[i];
			while (p!=-1) {
				std::cout << G->vexs[p];
				p = Path[p];
				if (p!=-1) {
					std::cout << " - ";
				}
			}
			std::cout << std::endl;
			std::cout << std::endl;
		}
	}
}

Graph::Graph()
{
	AMG = new AMGraph;
}

Graph::~Graph()
{
	delete AMG;
	delete edge;
}

void Graph::CreateUDN()
{
	CreateUDN(AMG);
}

void Graph::CreateDN()
{
	CreateDN(AMG);
}

void Graph::DFS(int v)
{
	for (int i = 0; i < AMG->vexNum; i++)
	{
		visited[i] = false;
	}
	DFS_AM(AMG, v);
}

void Graph::MiniSpanTree(VerTexType u)
{
	MiniSpanTree_Prim(AMG, u);

}

void Graph::MiniSpanTree()
{
	edge = new Edge[MVNum];
	int m = 0;
	for (int i = 0; i < AMG->vexNum; i++)
	{
		for (int j = i; j < AMG->vexNum; j++)
		{
			if (AMG->arcs[i][j] != MaxInt) {
				edge[m].Head = AMG->vexs[i];
				edge[m].Tail = AMG->vexs[j];
				edge[m].lowcast = AMG->arcs[i][j];
				m++;
			}
		}
	}
	MiniSpanTree_Kruskal(AMG);
}

void Graph::ShortestPath(VerTexType u)
{
	int v0 = LocateVex(AMG, u);
	if (v0 != -1)
	{
		ShortestPath(AMG, v0);
	}
	else {
		std::cout << "节点不存在" << std::endl;
		return;
	}
}
