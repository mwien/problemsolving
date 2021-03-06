import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class MM {

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int cnt = 1;
	while(true) {
	    String[] in = br.readLine().split(" ");
	    int B = Integer.parseInt(in[0]);
	    int S = Integer.parseInt(in[1]);
	    if(B == 0 && S == 0) break;
	    int[] b = new int[61];
	    int[] s = new int[61];
	    for(int i = 0; i < B; i++) {
		b[Integer.parseInt(br.readLine())]++;
	    }
	    for(int i = 0; i < S; i++) {
		s[Integer.parseInt(br.readLine())]++;
	    }
	    boolean end = false;
	    while(!end) {
		for(int i = 60; i >= 0; i--) {
		    if(b[i] > 0) {
			b[i]--;
			B--;
			int ci = -1;
			int dist = Integer.MAX_VALUE;
			for(int j = 0; j <= 60; j++) {
			    if(s[j] > 0 &&  Math.abs(b[i] - s[j]) < dist) {
				dist = Math.abs(b[i] - s[j]);
				ci = j;
			    }
			}
			if(ci == -1) {
			    end = true;
			    B++;
			    break;
			} else {
			    s[ci]--;
			    break;
			}
		    } else if(i == 0) {
			end = true;
			break;
		    }
		}
	    }
	    System.out.print("Case " + cnt++ + ": " + B);
	    if(B == 0) System.out.println();
	    else {
		for(int i = 0; i <= 60; i++) {
		    if(b[i] > 0) {
			System.out.println(" " + i);
			break;
		    }
		}
	    }
	}
    }

}