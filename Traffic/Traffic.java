import java.util.Scanner;
import java.util.ArrayList;

public class Traffic {

    public static void bellmanFord(Vertex[] G) {
	//source is 0
	if(G.length > 0)
	G[0].dist = 0;
	//calc distances
	boolean used = true;
	//the path has max length |V|-1
	for(int i = 0; i < G.length-1; i++) {
	    used = true;
	    //each iteration relax all edges
	    for(int j = 0; j < G.length; j++) {
		for(Edge e : G[j].adj) {
		    if(G[j].dist != Integer.MAX_VALUE 
		       && e.t.dist > G[j].dist + e.w) {
			e.t.dist = G[j].dist + e.w;
			used = false;
		    }
		}
	    }
	    if(used) break;
	}
	//each iteration relax all edges
	for(int j = 0; j < G.length; j++) {
	    for(Edge e : G[j].adj) {
		if(G[j].dist == Integer.MIN_VALUE || (G[j].dist != Integer.MAX_VALUE 
						 && e.t.dist > G[j].dist + e.w)) {
		    e.t.dist = Integer.MIN_VALUE;
		}
	    }
	}
    }
    
    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int cnt = 1;
	while(s.hasNextInt()) {
	    int N = s.nextInt();
	    int[] bn = new int[N];
	    for(int i = 0; i < N; i++) {
		bn[i] = s.nextInt();
	    }
	    Vertex[] G = new Vertex[N];
	    for(int i = 0; i < N; i++) {
		G[i] = new Vertex();
	    }
	    int M = s.nextInt();
	    for(int i = 0; i < M; i++) {
		int a = s.nextInt()-1;
		int b = s.nextInt()-1;
		if(a >= N || b >= N) continue;
		G[a].adj.add(new Edge(G[b], (bn[b]-bn[a]) * (bn[b]-bn[a]) * (bn[b]-bn[a]) ));
	    }
	    System.out.println("Set #" + (cnt++));
	    bellmanFord(G);
	    /*for(int i = 0; i < G.length; i++) {
		System.out.println(i + " " + G[i].pre + " " + G[i].dist);
		}*/
	    int Q = s.nextInt();
	    for(int i = 0; i < Q; i++) {
		int t = s.nextInt()-1;
		if(t >= N) {
		    System.out.println("?");
		    continue;
		}
		if(G[t].dist < 3 || G[t].dist == Integer.MAX_VALUE) {
		    System.out.println("?");
		} else {
		    System.out.println(G[t].dist);
		}
	    }
	}
    }
}

class Vertex {

    int dist = Integer.MAX_VALUE;
    boolean vis = false;

    ArrayList<Edge> adj = new ArrayList<Edge>();


}

class Edge {

    int w;
    Vertex t;

    public Edge(Vertex t,int w) {
	this.t = t;
	this.w = w;
    }

}
