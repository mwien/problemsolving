import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.HashMap;
import java.util.ArrayList;
import java.util.LinkedList;

public class Calling {

    public static LinkedList<Integer> fDFS(Vertex u, LinkedList<Integer> sorting) {

	//compare with TS
	u.vis = true;
	for(Vertex v : u.out) {
	    if(!v.vis) {
		fDFS(v, sorting);
	    }
	}
	sorting.addFirst(u.id);
	return sorting;
    }
    
    public static void sDFS(Vertex u, int cnt) {
	//basic DFS, all visited vertices get cnt
	u.vis = true;
	u.comp = cnt;
	for(Vertex v : u.in) {
	    if(!v.vis) {
		sDFS(v, cnt);
	    }
	}
    }
    
    public static void doubleDFS(Vertex[] G) {
	
	//first calc a topological sort by first DFS
	LinkedList<Integer> sorting = new LinkedList<Integer>();
	for(int i = 0; i < G.length; i++) {
	    if(!G[i].vis) {
		fDFS(G[i], sorting);
	    }
	}
	for(int i = 0; i < G.length; i++) {
	    G[i].vis = false;
	}
	//then go through the sort and do another DFS on G^T
	//each tree is a component and gets a unique number
	int cnt = 0;
	for(int i : sorting) {
	    if(!G[i].vis) {
		sDFS(G[i], cnt++);
	    }
	}
    }
    
    


    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int c = 0;
	while(true) {
	    String[] in = br.readLine().split(" ");
	    int n = Integer.parseInt(in[0]);
	    int m = Integer.parseInt(in[1]);
	    if(n == 0 && m == 0) break;
	    if(c > 0) System.out.println();
	    String[][] calls = new String[m][2];
	    HashMap<String, Integer> names = new HashMap<String, Integer>();
	    String[] ns = new String[n];
	    int cnt = 0;
	    for(int i = 0; i < m; i++) {
		calls[i] = br.readLine().split(" ");
		if(!names.containsKey(calls[i][0])) {
		    names.put(calls[i][0], cnt++);
		    ns[cnt-1] = calls[i][0];
		}
		if(!names.containsKey(calls[i][1])) {
		    names.put(calls[i][1], cnt++);
		    ns[cnt-1] = calls[i][1];
		}
	    }
	    Vertex[] G = new Vertex[n];
	    for(int i = 0; i < n; i++) {
		G[i] = new Vertex(i);
	    }
	    for(int i = 0; i < m; i++) {
		int a = names.get(calls[i][0]);
		int b = names.get(calls[i][1]);
		G[a].out.add(G[b]);
		G[b].in.add(G[a]);
	    }
	    doubleDFS(G);
	    System.out.println("Calling circles for data set "  + (++c) + ":");
	    for(int i = 0; i < n; i++) {
		int cp = 0;
		for(int j = 0; j < n; j++) {
		    if(G[j].comp == i) {
			if(cp > 0) System.out.print(", ");
			System.out.print(ns[j]);
			cp++;
		    }
		}
		if(cp == 0) break;
		System.out.println();
	    }
	}
    }
}

class Vertex {

    int id = -1;
    boolean vis = false;
    int comp = -1;

    ArrayList<Vertex> in = new ArrayList<Vertex>();
    ArrayList<Vertex> out = new ArrayList<Vertex>();

    public Vertex(int id) {
	this.id = id;
    }

}
