import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class Dromicpalin {


    public static void main(String[] args) throws IOException {

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int T = Integer.parseInt(br.readLine());
	for(int t = 0; t < T; t++) {
	    String in = br.readLine();
	    boolean[][] table = new boolean[in.length()+1][26];
	    for(int i = 0; i < in.length()+1; i++) {
		for(int j = 0; j < 26; j++) {
		    table[i][j] = false;
		}
	    }
	    for(int i = in.length()-1; i >= 0; i--) {
		for(int j = 0; j < 26; j++) {
		    if(in.charAt(i) - 'a' == j) {
			table[i][j] = !table[i+1][j];
		    } else {
			table[i][j] = table[i+1][j];
		    }
		}
	    }
	    int total = 0;
	    for(int i = 0; i < in.length(); i++) {
		for(int j = i; j < in.length(); j++) {
		    int cnt = 0;
		    for(int k = 0; k < 26; k++) {
			boolean parity = table[i][k] ^ table[j+1][k];
			if(parity) cnt++;
		    }
		    if(cnt <= 1) total++;
		}
	    }
	    System.out.println("Case " + (t+1) + ": " + total);
	}

    }



}
