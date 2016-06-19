import java.util.Scanner;
import java.util.ArrayList;
import java.util.PriorityQueue;

public class Routing {

    public static void dijkstra(Vertex[] G, int s) {
	G[s].dist = 0;
	Tuple st = new Tuple(s, 0);
	PriorityQueue<Tuple> q = new PriorityQueue<Tuple>();
	q.add(st);
	
	while(!q.isEmpty()) {
	    Tuple sm = q.poll();
	    Vertex u = G[sm.id];
	    //this checks if the Tuple is still useful, both checks should be equivalent
	    if(u.vis || sm.dist > u.dist) continue;
	    u.vis = true;
	    for(Edge e : u.adj) {
		Vertex v = e.t;
		if(!v.vis && v.dist > u.dist + e.w) {
		    v.dist = u.dist + e.w;
		    Tuple nt = new Tuple(v.id, v.dist);
		    q.add(nt);
		}
	    }
	}
    }
    

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int n = s.nextInt();
	Vertex[] G = new Vertex[n*n+1];
	for(int i = 0; i < n*n+1; i++) {
	    G[i] = new Vertex(i);
	}
	for(int i = 0; i < n; i++) {
	    int m = s.nextInt();
	    int t = s.nextInt();
	    if(i == n-1) {
		for(int j = 0; j < n; j++) {
		    G[n*(n-1) + j].adj.add(new Edge(G[n*n], t));
		}
	    }
	    for(int j = 0; j < m; j++) {
		int S = s.nextInt();
		int x = s.nextInt()-1;
		boolean[] p = new boolean[n];
		for(int k = 0; k < S; k++) {
		    p[s.nextInt()-1] = true;
		}
		for(int k = 0; k < n; k++) {
		    if(p[k]) continue;
		    G[i*n + k].adj.add(new Edge(G[x*n + i], t));
		}
	    }
	}
	dijkstra(G, 0);
	System.out.println(G[n*n].dist == Integer.MAX_VALUE ? "impossible" :G[n*n].dist);
    }

}

class Vertex {

    int id;
    boolean vis = false;
    int dist = Integer.MAX_VALUE;

    ArrayList<Edge> adj = new ArrayList<Edge>();

    public Vertex(int id) {
	this.id = id;
    }

}

class Edge {

    Vertex t;
    int w;

    public Edge(Vertex t, int w) {
	this.t = t;
	this.w = w;
    }

}

class Tuple implements Comparable<Tuple> {

    int id;
    int dist;

    public Tuple(int id, int dist) {
	this.id = id;
	this.dist = dist;
    }

    public int compareTo(Tuple other) {
	return Integer.compare(this.dist, other.dist);
    }
    
}
