import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.PriorityQueue;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;

public class Babel {

    public static void dijkstra(Vertex[][] vertices, int src) {
	vertices[src][26].mindistance = 0;
	PriorityQueue<Vertex> queue = new PriorityQueue<Vertex>();
	queue.add(vertices[src][26]);
	while(!queue.isEmpty()) {
	    Vertex u = queue.poll();
	    if(u.visited) continue;
	    u.visited = true;
	    for(Edge e : u.adjacencies) {
		Vertex v = e.target;
		if(v.mindistance > u.mindistance  + e.distance) {
		    v.mindistance = u.mindistance + e.distance;
		    queue.add(v);
		}
	    }
	}
    }
    
    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	while(true) {
	    int M = Integer.parseInt(br.readLine());
	    if(M == 0) break;
	    String[] in = br.readLine().split(" ");
	    String O = in[0];
	    String D = in[1];

	    String[][] rin = new String[M][3];
	    HashMap<String, Integer> hm = new HashMap<String, Integer>();
	    int cnt = 0;
	    hm.put(O, cnt++);
	    hm.put(D, cnt++);
	    for(int i = 0; i < M; i++) {
		rin[i] = br.readLine().split(" ");
		if(!hm.containsKey(rin[i][0])) hm.put(rin[i][0], cnt++);
		if(!hm.containsKey(rin[i][1])) hm.put(rin[i][1], cnt++);
	    }
	    ArrayList<ArrayList<String>> edges = new ArrayList<ArrayList<String>>();
	    Vertex[][] g = new Vertex[hm.size()][27];
	    for(int i = 0; i < hm.size(); i++) {
		for(int j = 0; j < 27; j++) {
		    g[i][j] = new Vertex();
		}
	    }
	    for(int i = 0; i < hm.size(); i++) {
		edges.add(new ArrayList<String>());
	    }
	    for(int i = 0; i < M; i++) {
		int a = hm.get(rin[i][0]);
		int b = hm.get(rin[i][1]);
		String word = rin[i][2];
		char firstl = word.charAt(0);
		Edge e1 = new Edge(g[b][firstl - 'a'], word.length());
		Edge e2 = new Edge(g[a][firstl - 'a'], word.length());
		for(int j = 0; j < 27; j++) {
		    if((char) ('a' + j) == firstl) continue;
		    g[a][j].adjacencies.add(e1);
		    g[b][j].adjacencies.add(e2);
		}
	    }

	    dijkstra(g, hm.get(O));
	    int min = Integer.MAX_VALUE;
	    for(int i = 0; i < 27; i++) {
		int dist = g[hm.get(D)][i].mindistance;
		if(dist < min) min = dist;
	    }
	    if(min < Integer.MAX_VALUE) System.out.println(min);
	    else System.out.println("impossivel");
	}
    }
}

class Vertex implements Comparable<Vertex> {
    public int mindistance = Integer.MAX_VALUE;
    public boolean visited = false;
    public LinkedList<Edge> adjacencies = new LinkedList<Edge>();
    public int compareTo(Vertex other) {
	return Integer.compare(this.mindistance, other.mindistance);
    }
}

class Edge {
    public Vertex target;
    public int distance;

    public Edge(Vertex target, int distance) {
	this.target = target;
	this.distance = distance;
    }
}