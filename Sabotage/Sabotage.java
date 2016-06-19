import java.util.Scanner;
import java.util.LinkedList;
import java.util.Queue;
import java.util.HashMap;

public class Sabotage {

    public static boolean BFS(Vertex[] G, int s, int t) {
	int N = G.length;
	for(int i = 0; i < N; i++) {
	    G[i].vis = false;
	}
	
	Queue<Vertex> q = new LinkedList<Vertex>();
	G[s].vis = true;
	G[s].pre = -1;
	q.add(G[s]);
	
	while(!q.isEmpty()) {
	    Vertex u = q.poll();
	    if(u.id == t) return true;
	    for(int i : u.adj.keySet()) {
		Edge e = u.adj.get(i);
		Vertex v = e.t;
		if(!v.vis && e.rw > 0) {
		    v.vis = true;
		    v.pre = u.id;
		    q.add(v);
		}
	    }
	}
	return (G[t].vis);
    }

    public static int edmondsKarp(Vertex[] G, int s, int t) {
	
	int maxflow = 0;
	while(BFS(G, s, t)) {
	    int pathflow = Integer.MAX_VALUE;
	    for(int v = t; v!= s; v = G[v].pre) {
		int u = G[v].pre;
		pathflow = Math.min(pathflow, G[u].adj.get(v).rw);
	    }
	    
	    for(int v = t; v != s; v = G[v].pre) {
		int u = G[v].pre;
		G[u].adj.get(v).rw -= pathflow;
		G[v].adj.get(u).rw += pathflow;
	    }
	    
	    maxflow += pathflow;
	}
	return maxflow;
    }

    public static void bfs(Vertex[] G, int s) {
	for(int i = 0; i < G.length; i++) {
	    G[i].vis = false;
	}
	Queue<Vertex> q = new LinkedList<Vertex>();
	q.add(G[s]);

	while(!q.isEmpty()) {
	    Vertex u = q.poll();
	    u.vis = true;

	    for(int i : u.adj.keySet()) {
		Edge e = u.adj.get(i);
		if(e.rw == 0) continue;
		Vertex v = e.t;
		if(v.vis) continue;
		q.add(v);
	    }
	}
    }

    public static int minCut(Vertex[] G, int s, int t) {
	edmondsKarp(G, s, t);
	BFS(G, s);
	int sum = 0;
	for(int i = 0; i < G.length; i++) {
	    for(int j : G[i].adj.keySet()) {
		Edge e = G[i].adj.get(j);
		Vertex v = e.t;
		if(G[i].vis && !G[j].vis) System.out.println((i+1) + " " + (j+1));
		sum += e.w;
	    }
	}
	return sum;
    }

    public static void main(String[] args)  {
	Scanner s = new Scanner(System.in);
	while(true) {
	    int N = s.nextInt();
	    int M = s.nextInt();
	    if(N == 0 && M == 0) break;
	    Vertex[] G = new Vertex[N];
	    for(int i = 0; i < N; i++) {
		G[i] = new Vertex(i);
	    }
	    for(int i = 0; i < M; i++) {
		int a = s.nextInt()-1;
		int b = s.nextInt()-1;
		int w = s.nextInt();
		G[a].adj.put(b, new Edge(G[b], w));
		G[b].adj.put(a, new Edge(G[a], w));
	    }
	    minCut(G, 0, 1);
	    System.out.println();
	}
    }
}

class Vertex {

    int id;
    boolean vis = false;
    int pre = -1;

    HashMap<Integer, Edge> adj = new HashMap<Integer, Edge>();

    public Vertex(int id) {
	this.id = id;
    }

}

class Edge {

    Vertex t;
    int w;
    int rw;

    public Edge(Vertex t, int w) {
	this.t = t;
	this.w = w;
	this.rw = w;
    }

}
