import java.util.Scanner;
import java.util.Queue;
import java.util.LinkedList;

public class PT {

    public static boolean BFS(int[][] g, int s, int t, int[] parent) {
	int N = g.length;
	boolean visited[] = new boolean[N];
	for(int i = 0; i < N; i++) {
	    visited[i] = false;
	}
	Queue<Integer> q = new LinkedList<Integer>();
	q.add(s);
	visited[s] = true;
	parent[s] = -1;
	while(!q.isEmpty()) {
	    int u = q.poll();
	    if(u == t) return true;
	    for(int v = 0; v < N; v++) {
		if(visited[v] == false && g[u][v] > 0) {
		    q.add(v);
		    parent[v] = u;
		    visited[v] = true;
		}
	    }
	}
	return (visited[t]);
    }

    public static int fordFulkerson(int[][] g, int s, int t) {
	int N = g.length;
	int[][] rg = new int[N][N];
	for(int u = 0; u < N; u++) {
	    for(int v = 0; v < N; v++) {
		rg[u][v] = g[u][v];
	    }
	}
	int[] parent = new int[N];
	int maxflow = 0;
	while(BFS(rg, s, t, parent)) {
	    int pathflow = Integer.MAX_VALUE;
	    for(int v = t; v != s; v = parent[v]) {
		int u = parent[v];
		pathflow = Math.min(pathflow, rg[u][v]);
	    }
	    for(int v = t; v != s; v = parent[v]) {
		int u = parent[v];
		rg[u][v] -= pathflow;
		rg[v][u] += pathflow;
	    }
	    maxflow += pathflow;
	}
	return maxflow;
    }

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	while(s.hasNext()) {
	    int N = s.nextInt();
	    int[][] g = new int[2*N+2][2*N+2];
	    for(int i = 0; i < N; i++) {
		g[2*i][2*i+1] = s.nextInt();
	    }
	    int M = s.nextInt();
	    for(int i = 0; i < M; i++) {
		int a = s.nextInt()-1;
		int b = s.nextInt()-1;
		int c = s.nextInt();
		g[2*a+1][2*b] = c;
	    }
	    int B = s.nextInt();
	    int D = s.nextInt();
	    for(int i = 0; i < B; i++) {
		int in = s.nextInt()-1;
		g[2*N][2*in] = Integer.MAX_VALUE;
	    }
	    for(int i = 0; i < D; i++) {
		int out = s.nextInt()-1;
		g[2*out+1][2*N+1] = Integer.MAX_VALUE;
	    }
	    System.out.println(fordFulkerson(g, 2*N, 2*N+1));
	}
    }
}

