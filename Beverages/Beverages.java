import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;
import java.util.PriorityQueue;

public class Beverages {

    public static LinkedList<Integer> TS(Vertex[] G) {
	LinkedList<Integer> sorting = new LinkedList<Integer>();
	PriorityQueue<Vertex> p = new PriorityQueue<Vertex>();
	for(int i = 0; i < G.length; i++) {
	    if(G[i].inc == 0) {
		p.add(G[i]);
		G[i].vis = true;
	    }
	}
	while(!p.isEmpty()) {
	    Vertex u = p.poll();
	    sorting.add(u.id);
	    for(Vertex v : u.out) {
		if(v.vis) continue;
		v.inc--;
		if(v.inc == 0) {
		    p.add(v);
		    v.vis = true;
		}
	    }
	}
	return sorting;
    }
    
    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int c = 1;
	String in;
	while((in = br.readLine()) != null) {
	    int N = Integer.parseInt(in);
	    HashMap<String, Integer> bev = new HashMap<String, Integer>();
	    Vertex[] G = new Vertex[N];
	    for(int i = 0; i < N; i++) {
		String name = br.readLine();
		bev.put(name, i);
		G[i] = new Vertex(i, name);
	    }
	    int M = Integer.parseInt(br.readLine());
	    for(int i = 0; i < M; i++) {
		String[] e = br.readLine().split(" ");
		int a = bev.get(e[0]);
		int b = bev.get(e[1]);
		G[a].out.add(G[b]);
		G[b].in.add(G[a]);
		G[b].inc++;
	    }
	    System.out.print("Case #" + c++ + ": Dilbert should drink beverages in this order:");
	    LinkedList<Integer> sorting = TS(G);
	    for(int i : sorting) {
		System.out.print(" " + G[i].name);
	    }
	    System.out.println(".");
	    System.out.println();
	    br.readLine();
	}
    }

}

class Vertex implements Comparable<Vertex> {

    boolean vis = false;
    int id = -1;
    String name = "";
    int inc = 0;

    ArrayList<Vertex> out = new ArrayList<Vertex>();
    ArrayList<Vertex> in = new ArrayList<Vertex>();

    public Vertex(int id, String name) {
	this.id = id;
	this.name = name;
    }

    public int compareTo(Vertex other) {
	return Integer.compare(this.id, other.id);
    }
}
