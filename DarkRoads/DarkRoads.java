import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.lang.Comparable;

public class DarkRoads {

    public static int kruskal(Edge[] edges, int n) {

	Arrays.sort(edges);
	UnionFind uf = new UnionFind(n);
	int sum = 0;
	int cnt = 0;
	for(int i = 0; i < edges.length; i++) {
	    if(cnt == n-1) break;
	    if(uf.union(edges[i].s, edges[i].t)) {
		System.out.println(edges[i].s + " " + edges[i].t + " " + edges[i].w);
		sum += edges[i].w;
		cnt++;
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
	    Edge[] edges = new Edge[M];
	    int sum = 0;
	    for(int i = 0; i < M; i++) {
		in = br.readLine();
		split = in.split(" ");
		int a = Integer.parseInt(split[0]);
		int b = Integer.parseInt(split[1]);
		int w = Integer.parseInt(split[2]);
		edges[i] = new Edge(a, b, w);
		sum += w;
	    }
	    System.out.println(sum - kruskal(edges, N));

	}

    }

}

class UnionFind {
   private int[] p = null;
   private int[] r = null;
   private int count = 0;

   public int count() {
      return count;
   } // number of sets

   public UnionFind(int n) {
      count = n; // every node is its own set
      r = new int[n]; // every node is its own tree with height 0
      p = new int[n];
      for (int i = 0; i < n; i++)
         p[i] = -1; // no parent = -1
   }

   public int find(int x) {
      int root = x;
      while (p[root] >= 0) { // find root
         root = p[root];
      }
      while (p[x] >= 0) { // path compression
         int tmp = p[x];
         p[x] = root;
         x = tmp;
      }
      return root;
   }

   // return true, if sets merged and false, if already from same set
   public boolean union(int x, int y) {
      int px = find(x);
      int py = find(y);
      if (px == py)
         return false; // same set -> reject edge
      if (r[px] < r[py]) { // swap so that always h[px]>=h[py]
         int tmp = px;
         px = py;
         py = tmp;
      }
      p[py] = px; // hang flatter tree as child of higher tree
      r[px] = Math.max(r[px], r[py] + 1); // update (worst-case) height
      count--;
      return true;
   }
}


class Edge implements Comparable<Edge> {

    int s;
    int t;
    int w;

    public Edge(int s, int t, int w) {
	this.s = s;
	this.t = t;
	this.w = w;
    }

    public int compareTo(Edge other) {
	return Integer.compare(this.w, other.w);
    }

}
