import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.PriorityQueue;
import java.util.LinkedList;

public class MiceMaze {

    public static void dijkstra(Vertex[] vertices, int src) {
	vertices[src].mindist = 0;
	PriorityQueue<Vertex> queue = new PriorityQueue<Vertex>();
	queue.add(vertices[src]);
	while(!queue.isEmpty()) {
	    Vertex u = queue.poll();
	    if(u.visited) continue;
	    u.visited = true;
	    for(Edge e : u.adj) {
		Vertex v = e.target;
		if(v.mindist > u.mindist + e.distance) {
		    v.mindist = u.mindist + e.distance;
		    queue.add(v);
		}
	    }
	}
    }
    
    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int C = Integer.parseInt(br.readLine());
	for(int c = 0; c < C; c++) {
	    br.readLine();
	    if(c > 0) System.out.println();
	    int N = Integer.parseInt(br.readLine());
	    Vertex[] g = new Vertex[N];
	    for(int i = 0; i < N; i++) {
		g[i] = new Vertex();
	    }
	    int E = Integer.parseInt(br.readLine()) - 1;
	    int T = Integer.parseInt(br.readLine());
	    int M = Integer.parseInt(br.readLine());
	    for(int i = 0; i < M; i++) {
		String[] in = br.readLine().split(" ");
		int a = Integer.parseInt(in[0]) -1;
		int b = Integer.parseInt(in[1]) -1;
		int w = Integer.parseInt(in[2]);
		g[b].adj.add(new Edge(g[a], w));
	    }
	    dijkstra(g, E);
	    int cnt = 0;
	    for(int i = 0; i < N; i++) {
		if(g[i].mindist <= T) cnt++;
	    }
	    System.out.println(cnt);
	}
    }
}

class Vertex implements Comparable<Vertex> {
    public int mindist = Integer.MAX_VALUE;
    public LinkedList<Edge> adj = new LinkedList<Edge>();
    public boolean visited = false;

    public int compareTo(Vertex other) {
	return Integer.compare(this.mindist, other.mindist);
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