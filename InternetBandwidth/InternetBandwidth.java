import java.util.LinkedList;
import java.util.Queue;
import java.util.Scanner;
import java.util.HashMap;


public class InternetBandwidth {
    
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
    //We store the edges in the graph in a hashmap
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
    
    public static void main(String[] args) {
        Scanner s = new Scanner(System.in);
        int cnt = 1;
        while(true) {
           int n = s.nextInt();
           if(n == 0) break;
           System.out.println("Network " + cnt);
           cnt++;
           Vertex[] G = new Vertex[n];
	   for(int i = 0; i < n; i++) {
	       G[i] = new Vertex(i);
	   }
           int start = s.nextInt()-1;
           int target = s.nextInt()-1;
           int c = s.nextInt();
           for(int i = 0; i < c; i++) {
               int a = s.nextInt()-1;
               int b = s.nextInt()-1;
               int bandwidth = s.nextInt();
	       if(G[a].adj.containsKey(b)) {
		   Edge e = G[a].adj.get(b);
		   e.w += bandwidth;
		   e.rw += bandwidth;
	       } else {
		   Edge e = new Edge(G[b], bandwidth);
		   G[a].adj.put(b, e);
	       }
	       if(G[b].adj.containsKey(a)) {
		   Edge e = G[b].adj.get(a);
		   e.w += bandwidth;
		   e.rw += bandwidth;
	       } else {
		   Edge e = new Edge(G[a], bandwidth);
		   G[b].adj.put(a, e);
	       }
           }
           int res = edmondsKarp(G, start, target);
           System.out.println("The bandwidth is " + res + ".");
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

    int rw;
    Vertex t;
    int w;

    public Edge(Vertex t, int w) {

	this.t = t;
	this.w = w;
	this.rw = w;

    }

}

