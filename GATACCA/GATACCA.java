import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.Arrays;

public class GATACCA {

    public static void main(String[]  args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int T = Integer.parseInt(br.readLine());
	for(int t = 0; t < T; t++) {
	    String in = br.readLine();
	    String[] suffix = new String[in.length()];
	    for(int i = 0; i < in.length(); i++) {
		suffix[i] = in.substring(i);
	    }
	    Arrays.sort(suffix);
	    int longest = 0;
	    String lstring = "";
	    int cnt = 2;
	    for(int i = 0; i < in.length()-1; i++) {
		int j = 0;
		for(; j < suffix[i].length(); j++) {
		    if(suffix[i].charAt(j) != suffix[i+1].charAt(j)) break;
		}
		if(j < longest) continue;
		if(j == longest) {
		    if(suffix[i].substring(0, j).equals(lstring)) cnt++;
		    continue;
		}
		longest = j;
		lstring = suffix[i].substring(0, j);
		cnt = 2;
	    }
	    if(longest == 0) System.out.println("No repetitions found!");
	    else System.out.println(lstring + " " + cnt);
	}
    }
}
