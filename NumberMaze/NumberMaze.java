import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.PriorityQueue;

public class NumberMaze {

    public static void update(Field a, Field b, PriorityQueue<Field> queue) {
	if(b.mindistance > a.mindistance + b.weight) {
	    b.mindistance = a.mindistance + b.weight;
	    queue.add(b);
	}
    }

    public static void dijkstra(Field[][] f, int N, int M) {
	PriorityQueue<Field> queue = new PriorityQueue<Field>();
	f[0][0].mindistance = f[0][0].weight;
	queue.add(f[0][0]);
	while(!queue.isEmpty()) {
	    Field u = queue.poll();
	    if(u.visited) continue;
	    u.visited = true;
	    if(u.row > 0) update(u, f[u.row - 1][u.col], queue);
	    if(u.row < N-1) update(u, f[u.row + 1][u.col], queue);
	    if(u.col > 0) update(u, f[u.row][u.col - 1], queue);
	    if(u.col < M-1) update(u, f[u.row][u.col + 1], queue);
	}
    }

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String input = br.readLine();
	int T = Integer.parseInt(input);
	for(int t = 0; t < T; t++) {
	    input = br.readLine();
	    int N = Integer.parseInt(input);
	    input = br.readLine();
	    int M = Integer.parseInt(input);
	    Field[][] f = new Field[N][M];
	    for(int i = 0; i < N; i++) {
		input = br.readLine();
		String[] in = input.split(" ");
		for(int j = 0; j < M; j++) {
		    f[i][j] = new Field(i, j, Integer.parseInt(in[j]));
		}
	    }
	    dijkstra(f, N, M);
	    System.out.println(f[N-1][M-1].mindistance);
	}
    }
}

class Field implements Comparable<Field> {
    public int mindistance = Integer.MAX_VALUE;
    public boolean visited = false;

    public int row;
    public int col;
    public int weight;
    
    public Field(int row, int col, int weight) {
	this.row = row;
	this.col = col;
	this.weight = weight;
    }

    public int compareTo(Field other) {
	return Integer.compare(this.mindistance, other.mindistance);
    }
}