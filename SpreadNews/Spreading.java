import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.Queue;


public class Spreading {
    public static void BFS(Vertex[] G, int s) {
	
	//make sure that all Vertices vis values are false etc
	
	Queue<Vertex> q = new LinkedList<Vertex>();
	
	G[s].vis = true;
	G[s].dist = 0;
	G[s].pre = -1;
	q.add(G[s]);
	
	//expand frontier between undiscovered and discovered vertices
	while(!q.isEmpty()) {
	    Vertex u = q.poll();
	    for(Vertex v : u.adj) {
		if(!v.vis) {
		    v.vis = true;
		    v.dist = u.dist + 1;
		    v.pre = u.id;
		    q.add(v);
		}
	    }
	}
	
    }

    
    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int E = Integer.parseInt(br.readLine());
	Vertex[] g = new Vertex[E];
	for(int i = 0; i < E; i++) {
	    g[i] = new Vertex(i);
	}
	for(int i = 0; i < E; i++) {
	    String[] in = br.readLine().split(" ");
	    for(int j = 1; j < in.length; j++) {
		g[i].adj.add(g[Integer.parseInt(in[j])]);
	    }
	}
	int T = Integer.parseInt(br.readLine());
	for(int t = 0; t < T; t++) {
	    int empl = Integer.parseInt(br.readLine());
	    int[] dailybooms = new int[E+1];
	    BFS(g, empl);
	    for(int i = 0; i < E; i++) {
		if(g[i].dist != Integer.MAX_VALUE) dailybooms[g[i].dist]++;
	    }
	    int maxdb = 0;
	    int fdb = -1;
	    for(int i = 1; i < E+1; i++) {
		if(dailybooms[i] > maxdb) {
		    maxdb = dailybooms[i];
		    fdb = i;
		}
	    }
	    if(fdb == -1) System.out.println(0);
	    else System.out.println(maxdb + " " + fdb);
	    for(int i = 0; i < E; i++) {
		g[i].vis = false;
		g[i].dist = Integer.MAX_VALUE;
	    }
	}
    }
}


class Vertex {
    int pre = -1;
    int id;
    public int dist = Integer.MAX_VALUE;
    public boolean vis = false;
    public ArrayList<Vertex> adj = new ArrayList<Vertex>();

    public Vertex(int id) {
	this.id = id;
    }

}
