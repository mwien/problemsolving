import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class Short {

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int T = Integer.parseInt(br.readLine());
	for(int t = 0; t < T; t++) {
	    int n = Integer.parseInt(br.readLine());
	    String[] names = new String[n];
	    for(int i = 0; i < n; i++) {
		names[i] = br.readLine();
	    }
	    Arrays.sort(names);
	    int prev = 0;
	    for(int i = 0; i < n-1; i++) {
		int j = 0;
		for(; j < names[i].length(); j++) {
		    if(names[i].charAt(j) != names[i+1].charAt(j)) break;
		}
		if (j > prev) {
		    names[i] = names[i].substring(0, j+1);
		} else {
		    names[i] = names[i].substring(0, prev+1);
		}
		prev = j;
	    }
	    names[n-1] = names[n-1].substring(0, prev+1);
	    int cnt = 0;
	    for(int i = 0; i < n; i++) {
		cnt += names[i].length();
	    }
	    System.out.println(cnt);
	}
    }

}
