import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.LinkedList;

public class Ordering {

    public static LinkedList<Integer> TS(Vertex[] G) {

	LinkedList<Integer> sorting = new LinkedList<Integer>();
	for(int i = 0; i < G.length; i++) {
	    if(!G[i].vis) {
		recTS(G[i], sorting);
	    }
	}

	return sorting;
    }

    public static LinkedList<Integer> recTS(Vertex u, LinkedList<Integer> sorting) {

	u.vis = true;
	for(Vertex v : u.adj) {
	    if(!v.vis)
	    recTS(v, sorting);
	}
	sorting.addFirst(u.id);
	return sorting;
    }

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	while(true) {
	    String[] in = br.readLine().split(" ");
	    int n = Integer.parseInt(in[0]);
	    int m = Integer.parseInt(in[1]);
	    if(n == 0 && m == 0) break;

	    Vertex[] G = new Vertex[n];
	    for(int i = 0; i < n; i++) {
		G[i] = new Vertex(i);
	    }
	    for(int i = 0; i < m; i++) {
		in = br.readLine().split(" ");
		G[Integer.parseInt(in[0])-1].adj.add(G[Integer.parseInt(in[1])-1]);
	    }
	    LinkedList<Integer> sorting = TS(G);
	    int cnt = 0;
	    for(int i : sorting) {
		if(cnt != 0) System.out.print(" ");
		cnt++;
		System.out.print(i+1);
	    }
	    System.out.println();
	}
    }

}

class Vertex {

    int id;
    boolean vis = false;
    ArrayList<Vertex> adj = new ArrayList<Vertex>();

    public Vertex(int id) {
	this.id = id;
    }

}
