import java.util.Scanner;
import java.util.HashMap;
import java.util.Queue;
import java.util.LinkedList;

public class OneWay {

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
    

    public static int edKarp(Vertex[] G, int s, int t) {
	int maxflow = 0;
	while(BFS(G, s, t)) {
	    int pflow = Integer.MAX_VALUE;
	    for(int v = t; v!= s; v = G[v].pre) {
		int u = G[v].pre;
		pflow = Math.min(pflow, G[u].adj.get(v).rw);
	    }
	    for(int v = t; v != s; v = G[v].pre) {
		int u = G[v].pre;
		G[u].adj.get(v).rw -= pflow;
		G[v].adj.get(u).rw += pflow;
	    }
	    maxflow += pflow;
	}
	return maxflow;
    }
    

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int n = s.nextInt();
	int m = s.nextInt();
	Vertex[] G = new Vertex[n + m + 2];
	for(int i = 0; i < n + m + 2; i++) {
	    G[i] = new Vertex(i);
	}
	for(int i = 0; i < m; i++) {
	    G[n+m].adj.put(n + i, new Edge(G[n+i], 1));
	    G[n+i].adj.put(n + m, new Edge(G[n+m], 0));
	}
	for(int i = 0; i < m; i++) {
	    int a = s.nextInt()-1;
	    int b = s.nextInt()-1;
	    G[n+i].adj.put(a, new Edge(G[a], 1));
	    G[a].adj.put(n+i, new Edge(G[n+i], 0));
	    G[n+i].adj.put(b, new Edge(G[b], 1));
	    G[b].adj.put(n+i, new Edge(G[n+i], 0));
	}
	int lo = 0;
	int hi = n;
	int mid = (lo + hi) / 2;
	int lastsuccess = 0;
	while(lo <= hi) {
	    mid = (lo + hi) / 2;
	    for(int i = 0; i < n; i++) {
		G[i].adj.put(n+m+1, new Edge(G[n+m+1], mid));
		G[n+m+1].adj.put(i, new Edge(G[i], 0));
	    }
	    for(int i = 0; i < n + m + 2; i++) {
		for(int j : G[i].adj.keySet()) {
		    G[i].adj.get(j).rw = G[i].adj.get(j).w;
		}
	    }
	    int res = edKarp(G, n + m, n + m + 1);
	    if(m > res) {
		lo = mid +1;
	    } else if(m <= res) {
		hi = mid - 1;
		lastsuccess = mid;
	    }
	}
	System.out.println(lastsuccess);
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
