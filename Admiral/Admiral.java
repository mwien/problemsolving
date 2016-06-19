import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.lang.Comparable;
import java.util.PriorityQueue;
import java.util.HashMap;

public class Admiral {

    public static void dijkstra(Vertex[] G, int s) {
	G[s].dist = 0;

	Tuple st = new Tuple(s,0);
	PriorityQueue<Tuple> q = new PriorityQueue<Tuple>();
	q.add(st);

	while(!q.isEmpty()) {
	    Tuple sm = q.poll();
	    Vertex u = G[sm.id];

	    if(u.vis) continue;
	    //the Tuple is old
	    if(sm.dist > u.dist) continue;
	    u.vis = true;
	    for(Edge e : u.adj) {
		Vertex v = e.t;
		if(!v.vis && v.dist > u.dist + e.dist) {
		    v.dist = u.dist + e.dist;
		    v.pre = u.id;
		    Tuple nt = new Tuple(v.id, v.dist);
		    q.add(nt);
		}
	    }
	}
    }

    public static int suurballe(Vertex[] G, int s, int t) {
	dijkstra(G, s);
	//Modifying weights
	for(int i = 0; i < G.length; i++) {
	    for(Edge e : G[i].adj) {
		e.dist = e.dist - e.t.dist + G[i].dist;
	    }
	}
	//reversing path and storing used edges
	int old = t;
	int pre = G[t].pre;
	HashMap<Integer, Integer> hm = new HashMap<Integer, Integer>();
	while(pre != -1) {
	    for(int i = 0; i < G[pre].adj.size(); i++) {
		if(G[pre].adj.get(i).t.id == old) {
		    hm.put(pre * G.length + old, G[pre].adj.get(i).tdist);
		    G[pre].adj.remove(i);
		    break;
		}
	    }
	    boolean found = false;
	    for(int i = 0; i < G[old].adj.size(); i++) {
		if(G[old].adj.get(i).t.id == pre) {
		    G[old].adj.get(i).dist = 0;
		    found = true;
		    break;
		}
	    }
	    if(!found) {
		G[old].adj.add(new Edge(G[pre], 0));
	    }
	    old = pre;
	    pre = G[pre].pre;
	}
	//reset graph
	for(int i = 0; i < G.length; i++) {
	    G[i].pre = -1;
	    G[i].dist = Integer.MAX_VALUE;
	    G[i].vis = false;
	}
	
	dijkstra(G, s);
	//store edges of second path
	old = t;
	pre = G[t].pre;
	while(pre != -1) {
	    //store edges and remove if reverse
	    for(int i = 0; i < G[pre].adj.size(); i++) {
		if(G[pre].adj.get(i).t.id == old) {
		    if(!hm.containsKey(pre + old * G.length)) {
			hm.put(pre * G.length + old, G[pre].adj.get(i).tdist);
		    } else {
			hm.remove(pre + old * G.length);
		    }
		    break;
		}
	    }
	    old = pre;
	    pre = G[pre].pre;
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
	    Vertex[] G = new Vertex[2*v];
	    for(int i = 0; i < 2*v; i++) {
		G[i] = new Vertex(i);
	    }
	    for(int i = 0; i < v; i++) {
		G[2*i].adj.add(new Edge(G[2*i+1], 0));
	    }
	    for(int i = 0; i < e; i++) {
		in = br.readLine().split(" ");
		int a = Integer.parseInt(in[0]) - 1;
		int b = Integer.parseInt(in[1]) - 1;
		int c = Integer.parseInt(in[2]);
		G[2*a+1].adj.add(new Edge(G[2*b], c));
	    }
	    System.out.println(suurballe(G, 1, 2*(v-1)));
	}
    }
}

class Vertex implements Comparable<Vertex> {
    
    public int id;
    public int pre = -1;
    public int dist = Integer.MAX_VALUE;
    public ArrayList<Edge> adj = new ArrayList<Edge>();
    public boolean vis = false;
    
    public int compareTo(Vertex other) {
	return Integer.compare(this.dist, other.dist);
    }

    public Vertex(int id) {
	this.id = id;
    }
}

class Edge {
    
    public Vertex t;
    public int dist;
    public int tdist;
    public Edge(Vertex t, int dist) {
	this.t = t;
	this.dist = dist;
	this.tdist = dist;
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
