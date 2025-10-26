#include <iostream>
#include <stack>
#include <queue>

using namespace std;

class graph {
  public:
    int edges[100][100]; // Adjacency matrix
    int s_v; 

    graph(int n) {
        s_v = n;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                edges[i][j] = 0; 
            }
        }
    }

    void addEdge(int u, int v, int w) {
        edges[u][v] = w;
    }

    void depthFirstTraversal(int start) {
        bool visited[100] = {false};
        stack<int> s;

        s.push(start);

        while (!s.empty()) {
            int current = s.top();
            s.pop();

            if (!visited[current]) {
                cout << current << " ";
                visited[current] = true;
            }

            for (int i = s_v - 1; i >= 0; i--) {
                if (edges[current][i] != 0 && !visited[i]) {
                    s.push(i);
                }
            }
        }
        cout << endl;
    }

    void breadthFirstTraversal(int start) {
        bool visited[100] = {false}; 
        queue<int> q;

        q.push(start);
        visited[start] = true;

        while (!q.empty()) {
            int current = q.front();
            q.pop();
            cout << current << " ";

            
            for (int i = 0; i < s_v; i++) {
                if (edges[current][i] != 0 && !visited[i]) {
                    q.push(i);
                    visited[i] = true;
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int n;
    cin >> n;
    graph g(n);
    
    char inp;
    int v1,v2,w,s;
    while(true){
    	cin >> inp;
    	if(inp == 'e'){
    		cin >> v1 >> v2 >> w;
    		g.addEdge(v1, v2, w);
    		g.addEdge(v2, v1, w);
		}
		else if(inp == 's'){
			while(true){
				
				cin >> inp;
				
					if(inp == 'd'){
					cin >> s;
					g.depthFirstTraversal(s);
				}
			
				if(inp == 'b'){
					cin >>s;
					g.breadthFirstTraversal(s);
				}
				
				if(inp == 'q'){
					return 0;
				}
			}
		}
		else if(inp == 'q'){
			return 0;
		}
	}
	
	return 0;
}