import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Queue;
import java.util.LinkedList;

public class WordTransformation {

    public static void BFS(Vertex[] graph, int src, int target) {
	Queue<Vertex> queue = new LinkedList<Vertex>();
	queue.add(graph[src]);
	graph[src].visited = true;
	graph[src].distance = 0;
	while(!queue.isEmpty()) {
	    Vertex u = queue.poll();
	    if(u.id == target) return;
	    for(Vertex v : u.adj) {
		if(v.visited == true) continue;
		v.visited = true;
		v.distance = u.distance + 1;
		queue.add(v);
	    }
	}
    }

    public static boolean compStrings(String a, String b) {
	if(a.length() != b.length()) return false;
	int cnt = 0;
	for(int i = 0; i < a.length(); i++) {
	    if(a.charAt(i) != b.charAt(i)) cnt++;
	}
	if(cnt == 1) return true;
	else return false;
    }

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int T = Integer.parseInt(br.readLine());
	br.readLine();
	for(int t = 0; t < T; t++) {
	    if(t != 0) System.out.println();
	    String in;
	    int cnt = 0;
	    HashMap<String, Integer> dict = new HashMap<String, Integer>();
	    ArrayList<String> ind = new ArrayList<String>();
	    while(!(in = br.readLine()).equals("*")) {
		dict.put(in, cnt++);
		ind.add(in);
	    }
	    Vertex[] graph = new Vertex[dict.size()];
	    for(int i = 0; i < dict.size(); i++) {
		String a = ind.get(i);
		int f = dict.get(a);
		graph[f] = new Vertex(f);
		for(int j = 0; j < i; j++) {
		    String b = ind.get(j);
		    if(compStrings(a, b)) {
			int s = dict.get(b);
			graph[f].adj.add(graph[s]);
			graph[s].adj.add(graph[f]);
		    }
		}
	    }
	    String start;
	    String end;
	    while((in=br.readLine())!=null && in.length()!=0 && !in.isEmpty()) {
		String[] input = in.split(" ");
		start = input[0];
		end = input[1];
		int src = dict.get(start);
		int target = dict.get(end);
		BFS(graph, src, target);
		System.out.println(start + " " + end + " " + graph[target].distance);
		for(int i = 0; i < dict.size(); i++) {
		    graph[i].visited = false;
		    graph[i].distance = Integer.MAX_VALUE;
		}
	    }
	}
    }
}

class Vertex {
    public int id;
    public boolean visited = false;
    public int distance = Integer.MAX_VALUE;
    public ArrayList<Vertex> adj = new ArrayList<Vertex>();

    public Vertex(int id) {
	this.id = id;
    }
}