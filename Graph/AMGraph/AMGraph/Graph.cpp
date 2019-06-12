#include "Graph.h"

void Graph::CreateUDN(AMGraph* G)
{
	std::cout << "�����ܶ��������ܱ���:" << std::endl;
	std::cin >> G->vexNum >> G->arcNum;//�����ܶ�����,�ܱ���
	int i,j;
	std::cout << "�������������:" << std::endl;
	for ( i = 0; i < G->vexNum; i++)//�������Ϣ
	{
		std::cin >> G->vexs[i];
	}
	for ( i = 0; i < G->vexNum; i++)//��ʼ���ڽӾ���
	{
		for ( j = 0; j < G->vexNum; j++)
		{
			G->arcs[i][j] = MaxInt;
		}
	}
	VerTexType v1, v2;
	int w;
	std::cout << "��<����1> <����2> <Ȩ��>�����" << std::endl;
	for (int k = 0; k < G->arcNum; k++)
	{
		std::cin >> v1 >> v2 >> w;//����ߵ����������Ȩ��
		i = LocateVex(AMG, v1);
		j = LocateVex(AMG, v2);
		G->arcs[i][j] = w;//����ͼ����Ϊ�Գƾ���
		G->arcs[j][i] = w;
	}
}

void Graph::CreateDN(AMGraph* G)
{
	std::cout << "�����ܶ��������ܱ���:" << std::endl;
	std::cin >> G->vexNum >> G->arcNum;//�����ܶ�����,�ܱ���
	int i, j;
	std::cout << "�������������:" << std::endl;
	for (i = 0; i < G->vexNum; i++)//�������Ϣ
	{
		std::cin >> G->vexs[i];
	}
	for (i = 0; i < G->vexNum; i++)//��ʼ���ڽӾ���
	{
		for (j = 0; j < G->vexNum; j++) {
			G->arcs[i][j] = MaxInt;
		}
	}
	VerTexType v1, v2;
	int w;
	std::cout << "��<ʼ��> <�յ�> <Ȩ��>�����" << std::endl;
	for (int k = 0; k < G->arcNum; k++) {
		std::cin >> v1 >> v2 >> w;//����ߵ����������Ȩ��
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
		if ((G->arcs[v][w] != MaxInt) && (!visited[w])) //�õ�Ϊ�ڽӵ���δ����
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
		if (j != k) {//��ʼ������ÿһ�����㵽��ʼ��u�ľ���
			closedge[j] = { u,G->arcs[k][j] };
		}
	}
	closedge[k].lowcost = 0;//��ʼ��u��u����:0

	for (int i = 1; i < G->vexNum; i++)//����Ѱ��n-1����̱߼���closedge
	{
		k = Min(closedge);//�ҵ���̱ߵ��¶�����closedgeλ��
		VerTexType u0 = closedge[k].adjvex;//��С�߼��е����ж���
		VerTexType v0 = G->vexs[k];//��С�ߵ���һ���¶���
		std::cout << u0 <<" - "<< v0 << std::endl;
		closedge[k].lowcost = 0;//�¶��㲢��������С�߼���,��Ȩ�ع�Ϊ0
		for (int j = 0; j < G->vexNum; j++)//���±߼�,Ѱ������n-2�����㵽����k��λ���Ƿ�ȵ�u�Ķ�
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
	/*����ץȡ*/
	if (v0 == -1)
	{
		std::cout << "�ڵ㲻����" << std::endl;
		return;
	}
	/*��ʼ��*/
	int n = G->vexNum;//���涥�����
	for (int v = 0; v < n; v++)
	{
		S[v] = false;
		D[v] = G->arcs[v0][v];//��v0�����������·������ʼΪ���㵽����Ȩֵ
		if (D[v] < MaxInt) {//��v0��v֮���л�,��vǰ����Ϊv0,������Ϊ-1
			Path[v] = v0;
		}else {
			Path[v] = -1;
		}
	}
	S[v0] = true;//��ʼ��v0,��v0���·����Ϊ���ҵ�,·����Ϊ0
	D[v0] = 0;
	/*��ѭ��,�������v0��ĳ������v�����·��,����S��*/
	for (int i = 0; i < n; i++)
	{
		int min = MaxInt;
		int v = 0;
		for (int w = 0; w < n; w++)
		{
			if (!S[w] && D[w] < min) {//�ҵ�һ�����·��,��v0��v
				v = w;
				min = D[w];
			}
		}
		S[v] = true;//��v����S
		for (int w = 0; w < n; w++) //���´�v0������V-S�����ж������·��
		{
			if (!S[w] && (D[v] + G->arcs[v][w] < D[w])) {//Sδ�ҵ��Ҵ��µ�v���ýڵ���������
				D[w] = D[v] + G->arcs[v][w];//���¾���
				Path[w] = v;//����ǰ��
			}
		}
	}
	/*���*/
	for (int i = 0; i < G->vexNum; i++) {
		if (i != v0) {
			std::cout << "��< " << G->vexs[v0] << " >��< " << G->vexs[i] << " >����̾���Ϊ: "
				<< D[i] << std::endl;
			std::cout << "��Ӧ���·��Ϊ: " << G->vexs[i] << " - ";
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
		std::cout << "�ڵ㲻����" << std::endl;
		return;
	}
}
