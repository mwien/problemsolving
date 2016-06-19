import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.lang.Comparable;
import java.util.PriorityQueue;
import java.util.HashMap;

public class TestDijkstra {

    public static void dijkstra(Vertex[] g, int s) {
	g[s].md = 0;
	PriorityQueue<Vertex> queue = new PriorityQueue<Vertex>();
	queue.add(g[s]);
	while(!queue.isEmpty()) {
	    Vertex u = queue.poll();
	    if(u.visited) continue;
	    System.out.println(u.id + " " + u.md);
	    System.out.println(queue);
	    u.visited = true;
	    for(Edge e : u.adj) {
		Vertex v = e.target;
		if(v.md > u.md + e.dist) {
		    v.md = u.md + e.dist;
		    queue.add(v);
		    v.pred = u;
		}
	    }
	}
    }

    public static int suurballe(Vertex[] g, int s, int t) {
	dijkstra(g, s);
	//Modifying weights
	for(int i = 0; i < g.length; i++) {
	    for(Edge e : g[i].adj) {
		e.dist = e.dist - e.target.md + g[i].md;
	    }
	}
	//reversing path and storing used edges
	Vertex old = g[t];
	Vertex pre = g[t].pred;
	HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
	while(pre != null) {
	    for(int i = 0; i < pre.adj.size(); i++) {
		if(pre.adj.get(i).target == old) {
		    hm.put(pre.id * g.length + old.id, pre.adj.get(i).totaldist);
		    pre.adj.remove(i);
		    break;
		}
	    }
	    boolean found = false;
	    for(int i = 0; i < old.adj.size(); i++) {
		if(old.adj.get(i).target == pre) {
		    old.adj.get(i).dist = 0;
		    found = true;
		    break;
		}
	    }
	    if(!found) {
		old.adj.add(new Edge(pre, 0));
	    }
	    old = pre;
	    pre = pre.pred;
	}
	//reset graph
	for(int i = 0; i < g.length; i++) {
	    g[i].pred = null;
	    g[i].md = Integer.MAX_VALUE;
	    g[i].visited = false;
	}
	
	//dijkstra(g, s);
	//store edges of second path
	old = g[t];
	pre = g[t].pred;
	while(pre != null) {
	    //store edges and remove if reverse
	    for(int i = 0; i < pre.adj.size(); i++) {
		if(pre.adj.get(i).target == old) {
		    if(!hm.containsKey(pre.id + old.id * g.length)) {
			hm.put(pre.id * g.length + old.id, pre.adj.get(i).totaldist);
		    } else {
			hm.remove(pre.id + old.id * g.length);
		    }
		    break;
		}
	    }
	    old = pre;
	    pre = pre.pred;
	}
	//sum up weights
	int sum = 0;
	for(int i : hm.keySet()) {
	    sum += hm.get(i);
	}
	return sum;
    } 

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String str;
	while((str = br.readLine()) != null) {
	    String[] in = str.split(" ");
	    int v = Integer.parseInt(in[0]);
	    int e = Integer.parseInt(in[1]);
	    Vertex[] g = new Vertex[2*v];
	    for(int i = 0; i < 2*v; i++) {
		g[i] = new Vertex(i);
	    }
	    for(int i = 0; i < v; i++) {
		g[2*i].adj.add(new Edge(g[2*i+1], 0));
	    }
	    for(int i = 0; i < e; i++) {
		in = br.readLine().split(" ");
		int a = Integer.parseInt(in[0]) - 1;
		int b = Integer.parseInt(in[1]) - 1;
		int c = Integer.parseInt(in[2]);
		g[2*a+1].adj.add(new Edge(g[2*b], c));
	    }
	    System.out.println(suurballe(g, 1, 2*(v-1)));
	}
    }
}

class Vertex implements Comparable<Vertex> {
    
    public int id;
    public Vertex pred;
    public int md = Integer.MAX_VALUE;
    public ArrayList<Edge> adj = new ArrayList<Edge>();
    public boolean visited = false;
    
    public int compareTo(Vertex other) {
	return Integer.compare(this.md, other.md);
    }

    public Vertex(int id) {
	this.id = id;
    }
    public String toString() {
	return ("(" + id + " " + md + ")");
    }
}

class Edge {
    
    public Vertex target;
    public int dist;
    public int totaldist;
    public Edge(Vertex target, int dist) {
	this.target = target;
	this.dist = dist;
	this.totaldist = dist;
    }

}
