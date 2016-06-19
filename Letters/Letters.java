import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;
import java.util.LinkedList;
import java.util.Queue;


public class Letters {

    public static boolean check(char a, int mask) {
	if(Character.isUpperCase(a)) {
	    return ((mask & 1 << (Character.toLowerCase(a)-'a')) == 0);
	} else {
	    return ((mask & 1 << (a-'a')) != 0);
	}
    }

    public static int BFS(char[][] G, int mask, int N) {

	if(!check(G[0][0], mask)) return Integer.MAX_VALUE;

	boolean[] vis = new boolean[N * N];
	int[] dist = new int[N * N];
	Arrays.fill(dist, Integer.MAX_VALUE);

	Queue<Integer> q = new LinkedList<Integer>();
	q.add(0);
	vis[0] = true;
	dist[0] = 1;

	while(!q.isEmpty()) {
	    int cur = q.poll();
	    if(cur == N*N -1) return dist[cur];
	    int x = cur / N;
	    int y = cur % N;
	    if(x > 0) {
		if(check(G[x-1][y], mask) && !vis[(x-1)*N + y]) {
		    vis[(x-1)*N + y] = true;
		    dist[(x-1)*N + y] = dist[x*N + y] + 1;
		    q.add((x-1)*N + y);
		}
	    }
	    if(x < N-1) {
		if(check(G[x+1][y], mask) && !vis[(x+1) * N + y]) {
		    vis[(x+1) * N + y] = true;
		    dist[(x+1) * N + y] = dist[x * N + y] + 1;
		    q.add((x+1)*N + y);
		}
	    }
	    if(y > 0) {
		if(check(G[x][y-1], mask) && !vis[x * N + (y-1)]) {
		    vis[x * N + (y-1)] = true;
		    dist[x * N + (y-1)] = dist[x * N + y] + 1;
		    q.add(x*N + (y-1));
		}
	    }
	    if(y < N-1) {
		if(check(G[x][y+1], mask) && !vis[x * N + (y+1)]) {
		    vis[x * N + (y+1)] = true;
		    dist[x * N + (y+1)] = dist[x * N + y] + 1;
		    q.add(x*N + (y+1));
		}
	    }
	}
	return Integer.MAX_VALUE;
    }

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String in;
	while((in = br.readLine()) != null)  {
	    int N = Integer.parseInt(in);
	    char[][] G = new char[N][N];
	    for(int i = 0; i < N; i++) {
		in = br.readLine();
		G[i] = in.toCharArray();
	    }
	    int min = Integer.MAX_VALUE;
	    for(int i = 0; i < (1 << 10); i++) {
		int res = BFS(G, i, N);
		if(res < min) min = res;
	    }
	    if(min == Integer.MAX_VALUE) min = -1;
	    System.out.println(min);
	}

    }

}
