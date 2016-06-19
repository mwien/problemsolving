import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.PriorityQueue;
import java.util.ArrayList;
import java.lang.Comparable;

public class DarkRoadsPrim {

    public static int prim(Vertex[] G, int s) {

    //make sure dists are maxint
    G[s].dist = 0;
    Tuple st = new Tuple(s, 0);

    PriorityQueue<Tuple> q = new PriorityQueue<Tuple>();
    q.add(st);

    //we will store the sum and each nodes predecessor
    int sum = 0;
    
    while(!q.isEmpty()) {
	Tuple sm = q.poll();
	Vertex u = G[sm.id];
	//u has been visited already
	if(u.vis) continue;
	//this is not the latest version of u
	if(sm.dist > u.dist) continue;
	u.vis = true;
	//u is part of the new tree and u.dist the cost of adding it
	sum += u.dist;
	for(Edge e : u.adj) {
	    Vertex v = e.t;
	    if(!v.vis && v.dist > e.w) {
		v.pre = u.id;
		v.dist = e.w;
		Tuple nt = new Tuple(v.id, e.w);
		q.add(nt);
	    }
	}
	
    }
    return sum;

}

    
    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	while(true) {
	    String in = br.readLine();
	    String[] split = in.split(" ");
	    int N = Integer.parseInt(split[0]);
	    int M = Integer.parseInt(split[1]);
	    if(N == 0 && M == 0) break;
	    Vertex[] G = new Vertex[N];
	    for(int i = 0; i < N; i++) {
		G[i] = new Vertex(i);
	    }
	    int sum = 0;
	    for(int i = 0; i < M; i++) {
		in = br.readLine();
		split = in.split(" ");
		int a = Integer.parseInt(split[0]);
		int b = Integer.parseInt(split[1]);
		int w = Integer.parseInt(split[2]);
		G[a].adj.add(new Edge(G[b], w));
		G[b].adj.add(new Edge(G[a], w));
		sum += w;
	    }
	    System.out.println(sum - prim(G, 0));

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
