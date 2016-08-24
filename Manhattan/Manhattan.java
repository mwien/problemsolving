import java.util.Scanner;
import java.util.ArrayList;
import java.util.LinkedList;

public class Manhattan {

    public static void fDFS(Vertex u, LinkedList<Integer> sorting) {

	//compare with TS
	u.vis = true;
	for(Vertex v : u.out) {
	    if(!v.vis) {
		fDFS(v, sorting);
	    }
	}
	sorting.addFirst(u.id);
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
    
    
    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int T = s.nextInt();
	for(int t = 0; t < T; t++) {
	    int S = s.nextInt();
	    int A = s.nextInt();
	    int m = s.nextInt();
	    Vertex[] G = new Vertex[(S+A)*2];
	    for(int i = 0; i < G.length; i++) {
		G[i] = new Vertex(i);
	    }
	    for(int i = 0; i < m; i++) {
		int s1 = s.nextInt()-1;
		int a1 = s.nextInt()-1 + S;
		int s2 = s.nextInt()-1;
		int a2 = s.nextInt()-1 + S;
		int neqs = -1;
		int neqa = -1;
		if(s1 < s2) neqs = 0;
		else if(s1 > s2) neqs = 1;
		if(a1 < a2) neqa = 0;
		else if(a1 > a2) neqa = 1;
		if(neqa == -1  && neqs != -1) {
		    G[(a1 + S + A + neqs*(S + A)) % ((S+A)*2)].out.add(G[(a1 + neqs*(S + A)) % ((S+A)*2)]);
		    continue;
		}
		if(neqs == -1 && neqa != -1) {
		    G[(s1 + S + A + neqa*(S + A)) % ((S+A)*2)].out.add(G[(s1 + neqa*(S + A)) % ((S + A)*2)]);
		    continue;
		}
		if(neqs == -1 && neqa == -1) continue;
		G[(s1 + S + A + neqa * (S + A)) % ((S+A)*2)].out.add(G[(s2 + neqa * (S + A)) % ((S+A)*2)]);
		G[(s2 + S + A + neqa * (S + A)) % ((S+A)*2)].out.add(G[(s1 + neqa * (S + A)) % ((S+A)*2)]);
		G[(s1 + S + A + neqa * (S + A)) % ((S+A)*2)].out.add(G[(a1 + neqs * (S + A)) % ((S+A)*2)]);
		G[(a1 + S + A + neqs * (S + A)) % ((S+A)*2)].out.add(G[(s1 + neqa * (S + A)) % ((S+A)*2)]);
		G[(a2 + S + A + neqs * (S + A)) % ((S+A)*2)].out.add(G[(s2 + neqa * (S + A)) % ((S+A)*2)]);
		G[(s2 + S + A + neqa * (S + A)) % ((S+A)*2)].out.add(G[(a2 + neqs * (S + A)) % ((S+A)*2)]);
		G[(a2 + S + A + neqs * (S + A)) % ((S+A)*2)].out.add(G[(a1 + neqs * (S + A)) % ((S+A)*2)]);
		G[(a1 + S + A + neqs * (S + A)) % ((S+A)*2)].out.add(G[(a2 + neqs * (S + A)) % ((S+A)*2)]);
	    }
	    for(int i = 0; i < G.length; i++) {
		for(Vertex v : G[i].out) {
		    v.in.add(G[i]);
		}
	    }
	    doubleDFS(G);
	    
	    boolean poss = true;
	    for(int i = 0; i < S+A; i++) {
		if(G[i].comp == G[i + (S+A)].comp) {
		    poss = false;
		}
	    }
	    System.out.println(poss ? "Yes" : "No");
	}
	
    }

}

class Vertex {

    int id;
    boolean vis = false;
    int pre = -1;
    int comp = -1;
    ArrayList<Vertex> in = new ArrayList<Vertex>();
    ArrayList<Vertex> out = new ArrayList<Vertex>();

    public Vertex(int id) {
	this.id = id;
    }
}
