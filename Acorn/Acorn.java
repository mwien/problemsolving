import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Acorn {
    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String inLine = br.readLine();
	int C = Integer.parseInt(inLine);
	for(int c = 0; c < C; c++) {
	    inLine = br.readLine();
	    String[] inArr = inLine.split(" ");
	    int t = Integer.parseInt(inArr[0]);
	    int h = Integer.parseInt(inArr[1]);
	    int f = Integer.parseInt(inArr[2]);
	    int[][] forest = new int[t][h+1];
	    for(int i = 0; i < t; i++) {
		inLine = br.readLine();
		inArr = inLine.split(" ");
		int a = Integer.parseInt(inArr[0]);
		for(int j = 1; j < a + 1; j++) {
		    forest[i][Integer.parseInt(inArr[j])]++;
		}
	    }
	    int[] maxatH = new int[h+1];
	    int[][] maxTH = new int[t][h+1];
	    for(int i = h; i >= 0; i--) {
		int max = Integer.MIN_VALUE;
		for(int j = 0; j < t; j++) {
		    if(i == h) {
			maxTH[j][i] = forest[j][i];
		    } else if(i > h - f) {
			maxTH[j][i] = maxTH[j][i+1] + forest[j][i];
		    } else {
			maxTH[j][i] = Math.max(maxTH[j][i+1], maxatH[i+f]) + forest[j][i];
		    }
		    if(maxTH[j][i] > max) {
			    max = maxTH[j][i];
		    }
		}
		maxatH[i] = max;
	    }
	    System.out.println(maxatH[0]);
	}
    }
}