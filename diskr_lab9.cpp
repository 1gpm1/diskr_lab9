#include <iostream>
#include <fstream>
#include <vector>
#include <queue>
#include <Windows.h>
using namespace std;

// Клас для представлення графа
class Graph {
private:
    int V; // Кількість вершин
    vector<vector<int>> adj; // Список суміжності

public:
    // Конструктор
    Graph(int v) : V(v), adj(v) {}

    // Додає зв'язок у граф
    void addEdge(int v, int w) {
        adj[v].push_back(w);
    }

    // Обхід графа пошуком в ширину
    void BFS(int s) {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[s] = true;
        q.push(s);

        // Початок обходу
        cout << "Початкова вершина: " << s << endl;
        int level = 0; // Початковий рівень (BFS-номер)

        while (!q.empty()) {
            int currentVertex = q.front();
            q.pop();
            cout << "Поточна вершина: " << currentVertex << ", BFS-номер: " << level << endl;

            for (int n : adj[currentVertex]) {
                if (!visited[n]) {
                    visited[n] = true;
                    q.push(n);
                }
            }
            level++;
        }
    }
};

int main() {
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    // Зчитування графа з файлу
    ifstream file("graph.txt");
    if (!file) {
        cerr << "Файл не знайдено!" << endl;
        return 1;
    }

    int V, E;
    file >> V >> E; // Кількість вершин та ребер
    Graph graph(V);
    for (int i = 0; i < E; i++) {
        int v, w;
        file >> v >> w;
        graph.addEdge(v, w);
    }
    file.close();

    // Ввід початкової вершини для обходу
    cout << "Введіть початкову вершину для обходу: ";
    int startVertex;
    cin >> startVertex;

    // Обхід графа пошуком в ширину
    graph.BFS(startVertex);

    return 0;
}
