import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;
import java.util.Collections;

public class Adjoin {

    public static int cDia(int s, Vertex[] G, int comp) {
	Queue<Vertex> q = new LinkedList<Vertex>();
	G[s].comp = comp;
	q.add(G[s]);
	Vertex last = G[s];
	while(!q.isEmpty()) {
	    Vertex u = q.poll();
	    for(Vertex v : u.adj) {
		if(v.comp == -1) {
		    v.comp = comp;
		    q.add(v);
		    last = v;
		}
	    }
	}
	q.clear();
	last.dist = 0;
	q.add(last);
	while(!q.isEmpty()) {
	    Vertex u = q.poll();
	    for(Vertex v : u.adj) {
		if(!v.vis) {
		    v.vis = true;
		    v.dist = u.dist + 1;
		    last = v;
		    q.add(v);
		}
	    }
	}
	return last.dist;
    }

    public static ArrayList<Integer> BFS(Vertex[] G) {
	int comp = 0;
	ArrayList<Integer> d = new ArrayList<Integer>();
	for(int i = 0; i < G.length; i++) {
	    if(G[i].comp == -1) {
		d.add(cDia(i, G, comp++));
	    }
	}
	return d;
    }
    
    
    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int c = s.nextInt();
	int l = s.nextInt();
	Vertex[] G = new Vertex[c];
	for(int i = 0; i < c; i++) {
	    G[i] = new Vertex(i);
	}
	for(int i = 0; i < l; i++) {
	    int a = s.nextInt();	 
	    int b = s.nextInt();
	    G[a].adj.add(G[b]);
	    G[b].adj.add(G[a]);
	}
	//find comps DFS
	ArrayList<Integer> dists = BFS(G);
	ArrayList<Integer> radii = new ArrayList<Integer>();
	for(int i : dists) {
	    if(i % 2 == 0) {
		radii.add(i/2);
	    } else {
		radii.add((i+1) / 2);
	    }
	}
	Collections.sort(dists);
	Collections.sort(radii);
	int max = Integer.MIN_VALUE;
	int N = dists.size();
	if(max < dists.get(N-1)) max = dists.get(N-1);
	if(N > 1) {
	    if(max < radii.get(N-1) + radii.get(N-2) + 1) max = radii.get(N-1) + radii.get(N-2) + 1;
	}
	if(N > 2) {
	    if(max < radii.get(N-2) + radii.get(N-3) + 2) max = radii.get(N-2) + radii.get(N-3) + 2;
	}
	System.out.println(max);
    }

}

class Vertex {

    int id;
    int comp = -1;
    boolean vis = false;
    int dist = Integer.MAX_VALUE;

    ArrayList<Vertex> adj = new ArrayList<Vertex>();
    public Vertex(int id) {
	this.id = id;
    }
}
