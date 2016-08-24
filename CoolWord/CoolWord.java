import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class CoolWord {


    public static void main(String[] args) throws IOException {

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String noc;
	int casecnt = 1;
	while((noc = br.readLine()) != null) {
	    int n = Integer.parseInt(noc);
	    int cnt = 0;
	    for(int i = 0; i < n; i++) {
		String in = br.readLine();
		int[] letters = new int[26];
		int[] occur = new int[31];
		for(int j = 0; j < in.length(); j++) {
		    letters[in.charAt(j) - 'a']++;
		}
		for(int j = 0; j < 26; j++) {
		    occur[letters[j]]++;
		}
		boolean corr = true;
		int cnt2 = 0;
		for(int j = 1; j < 31; j++) {
		    if(occur[j] > 1) {
			corr = false;
			break;
		    }
		    if(occur[j] == 1) {
			cnt2++;
		    }
		}
		if(cnt2 > 1 && corr) cnt++;
	    }
	    System.out.println("Case " + casecnt++ + ": " + cnt); 
	}
	
    }



}
