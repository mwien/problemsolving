import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Parentheses {
    
    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String input;
	while((input = br.readLine()) != null) {
	    String[] in = input.split(" ");
	    int n = in.length / 2 + 1;
	    int[] nums = new int[n];
	    char[] ops = new char[n];
	    ops[0] = '+';
	    int cnt = 0;
	    for(int i = 0; i < in.length; i++) {
		if(i % 2 == 0) {
		    nums[cnt] = Integer.parseInt(in[i]);
		    cnt++;
		} else {
		    ops[cnt] = in[i].charAt(0);
		}
	    }
	    for(int i = 0; i < n; i++) {
		System.out.println(ops[i] + " " + nums[i]);
	    }
	    boolean[][] T = new boolean[n][6002];
	    int[][] M = new int[n][n];
	    for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
		    int sum = 0;
		    boolean inv;
		    if(ops[i] == '+') {
			inv = false;
			sum = nums[i];
		    }
		    else {
			inv = true;
			sum = -nums[i];
		    }
		    for(int k = i+1; k <= j; k++) {
			if((ops[k] == '+' && !inv) || (ops[k] == '-' && inv)) {
			    sum += nums[k];
			} else {
			    sum -= nums[k];
			}
		    }
		    M[i][j] = sum;
		}
	    }
	    for(int i = 0; i < n; i++) {
		for(int j = i; j < n; j++) {
		    System.out.print(M[i][j] + " ");
		}
		System.out.println();
	    }
	    for(int i = 0; i < n; i++) {
		T[i][3000 + M[0][i]] = true;
	    }
	    for(int i = 0; i < n; i++) {
		for(int j = 0; j < i; j++) {
		    for(int k = 0; k < 6002; k++) {
			if(T[j][k]) {
			    T[i][k + M[j+1][i]] = true;
			}
		    }
		}
	    }
	    for(int i = 0; i < n; i++) {
		for(int j = 0; j < 6002; j++) {
		    if(T[i][j]) {
			System.out.println(i + " " + (j - 3000));
		    }
		}
	    }
	    int out = 0;
	    for(int i = 0; i < 6002; i++) {
		if(T[n-1][i]) out++;
	    }
	    System.out.println(out);
	}
    }
}