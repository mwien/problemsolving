import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Queue;
import java.util.LinkedList;

public class Bombs {

    public static int BFS(int[][] bloc, int startr, int startc, int endr, int endc, int R, int C) {
	Queue<Integer> queue = new LinkedList<Integer>();
	queue.add(startr * C + startc);
	while(!queue.isEmpty() && bloc[endr][endc] == 0) {
	    int node = queue.poll();
	    int r = node / C;
	    int c = node % C;
	    int up = node - C;
	    int down = node + C;
	    int left = node - 1;
	    int right = node + 1;
	    if(r > 0 && bloc[r-1][c] == 0) {
		queue.add(up);
		bloc[r-1][c] = bloc[r][c] + 1;
	    }
	    if(r < R - 1 && bloc[r+1][c] == 0) {
		queue.add(down);
		bloc[r+1][c] = bloc[r][c] + 1;
	    }
	    if(c > 0 && bloc[r][c-1] == 0) {
		queue.add(left);
		bloc[r][c-1] = bloc[r][c] + 1;
	    }
	    if(c < C - 1 && bloc[r][c+1] == 0) {
		queue.add(right);
		bloc[r][c+1] = bloc[r][c] + 1;
	    }
	}
	return bloc[endr][endc];
    }


    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	while(true) {
	    String[] input = br.readLine().split(" ");
	    int R = Integer.parseInt(input[0]);
	    int C = Integer.parseInt(input[1]);
	    if(R == 0 && C == 0) break;
	    int[][] bloc = new int[R][C];
	    for(int i = 0; i < R; i++) {
		for(int j = 0; j < C; j++) {
		    bloc[i][j] = 0;
		}
	    }
	    int r = Integer.parseInt(br.readLine());
	    for(int i = 0; i < r; i++) {
		input = br.readLine().split(" ");
		int row = Integer.parseInt(input[0]);
		int nob = Integer.parseInt(input[1]);
		for(int j = 2; j < nob + 2; j++) {
		    bloc[row][Integer.parseInt(input[j])] = -1;
		}
	    }
	    input = br.readLine().split(" ");
	    int startr = Integer.parseInt(input[0]);
	    int startc = Integer.parseInt(input[1]);
	    input = br.readLine().split(" ");
	    int endr = Integer.parseInt(input[0]);
	    int endc = Integer.parseInt(input[1]);
	    System.out.println(BFS(bloc, startr, startc, endr, endc, R, C));
	}
    }
}
