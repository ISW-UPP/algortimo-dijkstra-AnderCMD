//Librerias
#include <iostream>
#include <queue>
#include <vector>
#define MaxVertices 100 //Cantidad de Vertices
#define oo 0x3f3f3f3f
using namespace std;


struct Edge
{
	int Nodo; // El nodo destino de la arista.
	int Costo; // El costo de la arista.
	Edge(int _node, int _cost) : Nodo(_node), Costo(_cost) {} // Constructor parametrizado.
	Edge() : Nodo(-1), Costo(-1) {} // Constructor por defecto.
};

struct Graph
{
	vector<Edge> G[MaxVertices]; // Lista de adyacencias.
	int Vertices; // Cantidad de vertices.
	int Aristas; // Cantidad de aristas.
};

struct State
{
	int Nodo; // El nodo actual.
	int Costo; // El costo del camino.
	State(int _node, int _cost) : Nodo(_node), Costo(_cost) {}
	bool operator <(const State &b) const 
	{
		return Costo > b.Costo;
	}
};

int Algoritmo(const int begin, const int end, const Graph Grafo)
{
	priority_queue<State> pq; // La cola de prioridad.
	vector<int> Dist(Grafo.Vertices, oo); // La distancia hacia todos los vertices. Inicialmente para cada vertice su valor es infinito.
	vector<bool> mark(Grafo.Vertices, false);

	Dist[begin] = 0; // Valor inicial del vertice de partida.
	pq.push(State(begin, 0));
	while(!pq.empty())
	{
		State st = pq.top(); pq.pop(); // Se desencola el elemento minimo.
		mark[st.Nodo] = true; // Se marca el nodo como visitado.
		if (st.Nodo == end)
			return st.Costo;

		int T = (int)Grafo.G[st.Nodo].size();
		for(int i = 0; i < T; ++i)
		{
			if (!mark[Grafo.G[st.Nodo][i].Nodo] && ((Dist[st.Nodo] + Grafo.G[st.Nodo][i].Costo) < Dist[Grafo.G[st.Nodo][i].Nodo]))
			{
				Dist[Grafo.G[st.Nodo][i].Nodo] = st.Costo + Grafo.G[st.Nodo][i].Costo;
				pq.push(State(Grafo.G[st.Nodo][i].Nodo, st.Costo + Grafo.G[st.Nodo][i].Costo));
			}
		}
	}
	return -1;
}

struct Programa
{
	int Vertices, Aristas;
	int Comienzo, Fin;
	void DefinirGrafo(Graph& Grafo)
	{
		cout << "Ingresa Cantidad de Vertices: " << endl;
		cin >> Vertices;
		cout << "Ingresa Cantidad de Aristas: " << endl;
		cin >> Aristas;

		Grafo.Vertices = Vertices;
		Grafo.Aristas = Aristas;
	}
	void CargarGrafo(Graph & Grafo)
	{
		for (int i = 0; i < Aristas; ++i)
		{
			int Origen, Destino, Peso;
			cout << "Ingresa Origen: " << endl;
			cin >> Origen;
			cout << "Ingresa Destino: " << endl;
			cin >> Destino;
			cout << "Ingresa Peso de la Arista: " << endl;
			cin >> Peso;

			Grafo.G[Origen].push_back(Edge(Destino, Peso));
			Grafo.G[Destino].push_back(Edge(Origen, Peso));
		}
	}
	void Dijkstra(Graph Grafo)
	{
		cout << "Ingresa Vertice Inicial: " << endl;
		cin >> Comienzo;
		cout << "Ingresa Vertice Final: " << endl;
		cin >> Fin;
		int n = Algoritmo(Comienzo, Fin, Grafo);
		cout << "Longitud del Camino mas Corto: " << n << endl;
	}
};

int main()
{
	bool out=false;
	char Salir;

	Programa Software; //TAD
	Graph Grafo; // Grafo.

	cout << "Algoritmo de Dijkstra en C++" << endl;

	while (!out)
	{
	Software.DefinirGrafo(Grafo); //Se define cantidad de vertices y cantidad de aristas del grafo
	Software.CargarGrafo(Grafo); //Se cargan las aristas del Grafo
	Software.Dijkstra(Grafo); //Se aplica el Algoritmo de Dijkstra

	//Salir
	cout << "Salir? (S/N)" << endl;
	cin >> Salir;
		if (Salir == 'S')
		{
			out = true;
		}
	}
}