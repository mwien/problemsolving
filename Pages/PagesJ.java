import java.util.Scanner;
import java.util.ArrayList;
import java.util.HashMap;
import java.lang.Comparable;
import java.util.PriorityQueue;
import java.util.ArrayList;

public class PagesJ {

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
		    v.pre = u.id;
		    v.dist = u.dist + e.w;
		    Tuple nt = new Tuple(v.id, v.dist);
		    q.add(nt);
		}
	    }
	}
    }
    
    
    public static boolean bellmanFord(Vertex[] G, int s) {
	//source is 0
	G[s].dist = 0;
	//calc distances
	//the path has max length |V|-1
	for(int i = 0; i < G.length-1; i++) {
	    //each iteration relax all edges
	    for(int j = 0; j < G.length; j++) {
		for(Edge e : G[j].adj) {
		    if(G[j].dist != Integer.MAX_VALUE 
		       && e.t.dist > G[j].dist + e.w) {
			e.t.dist = G[j].dist + e.w;
		    }
		}
	    }
	}
	//check for negative-length cycle
	for(int i = 0; i < G.length; i++) {
	    for(Edge e : G[i].adj) {
		if(G[i].dist != Integer.MAX_VALUE && e.t.dist > G[i].dist + e.w) {
		    return true;
		}
	    }
	}
	return false;
    }


    public static int[][] johnson(Vertex[] G) {

	//compute a new graph G'
	Vertex[] Gd = new Vertex[G.length+1];
	int s = G.length;
	for(int i = 0; i < G.length; i++) {
	    Gd[i] = G[i];
	}
	//init new vertex with zero-weight-edges to each vertex
	Vertex S = new Vertex(G.length);
	for(int i = 0; i < G.length; i++) {
	    S.adj.add(new Edge(Gd[i], 0));
	}
	Gd[G.length] = S;
	
	//bellman-ford to check for neg-weight-cycles and to adapt edges to enable running dijkstra
	if(bellmanFord(Gd, s)) {
	    System.out.println("False");
	    //this should not happen and will cause troubles
	    return null;
	}
	//change weights
	for(int i = 0; i < G.length; i++) {
	    for(Edge e : Gd[i].adj) {
		e.w = e.w + Gd[i].dist - e.t.dist;
	    }
	}
	//store distances to invert this step later
	int[] h = new int[G.length];
	for(int i = 0; i < G.length; i++) {
	    h[i] = G[i].dist;
	}
	
	//create shortest path matrix
	int[][] apsp = new int[G.length][G.length];
	
	//now use original graph G
	//start a dijkstra for each vertex
	for(int i = 0; i < G.length; i++) {
	    //reset weights
	    for(int j = 0; j < G.length; j++) {
		G[j].vis = false;
		G[j].dist = Integer.MAX_VALUE;
	    }
	    dijkstra(G, i);
	    for(int j = 0; j < G.length; j++) {
		apsp[i][j] = G[j].dist + h[j] - h[i];
	    }
	}
	return apsp;
    }

    
    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int gcnt = 1;
	while(true) {
	    HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
	    ArrayList<Integer> from = new ArrayList<Integer>();
	    ArrayList<Integer> to = new ArrayList<Integer>();
	    int cnt = 0;
	    while(true) {
		int a = s.nextInt();
		int b = s.nextInt();
		if(a == 0 && b == 0) break;
		if(hm.containsKey(a)) a = hm.get(a);
		else {
		    hm.put(a, cnt++);
		    a = cnt - 1;
		}
		if(hm.containsKey(b)) b = hm.get(b);
		else {
		    hm.put(b, cnt++);
		    b = cnt - 1;
		}
		from.add(a);
		to.add(b);
	    }
	    if(from.isEmpty() && to.isEmpty()) break;
	    Vertex[] G = new Vertex[cnt];
	    for(int i = 0; i < cnt; i++) {
		G[i] = new Vertex(i);
	    }
	    for(int i = 0; i < from.size(); i++) {
		G[from.get(i)].adj.add(new Edge(G[to.get(i)], 1));
	    }
	    int[][] apsp = johnson(G);
	    int sum = 0;
	    for(int i = 0; i < apsp.length; i++) {
		for(int j = 0; j < apsp.length; j++) {
		    if(i != j) sum += apsp[i][j];
		}
	    }
	    int div = G.length * (G.length - 1);
	    System.out.print("Case " + gcnt++ + ": average length between pages = ");
	    System.out.printf("%.3f", (double) sum / div);
	    System.out.println(" clicks");
	}
    }

}

class Vertex {

    int id;
    boolean vis = false;
    int pre = -1;
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
