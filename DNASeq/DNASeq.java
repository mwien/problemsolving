import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.TreeSet;

public class DNASeq {


    public static TreeSet<String> LCS(String a, String b) {

	int[][] t = new int[a.length()+1][b.length()+1];
	for(int i = 0; i <= b.length(); i++) {
	    t[0][i] = 0;
	}

	for(int i = 0; i <= a.length(); i++) {
	    t[i][0] = 0;
	}

	for(int i = 1; i <= a.length(); i++) {
	    for(int j = 1; j <= b.length(); j++) {
		if(a.charAt(i-1) == b.charAt(j-1)) {
		    t[i][j] = t[i-1][j-1] + 1;
		} else {
		    t[i][j] = 0;
		}
	    }
	}
	int max = -1;
	for(int i = 0; i <= a.length(); i++) {
	    for(int j = 0; j <= b.length(); j++) {
		if(max < t[i][j]) {
		    max = t[i][j];
		}
	    }
	}
	if(max == 0 || max == -1) return new TreeSet<String>();
	TreeSet<String> res = new TreeSet<String>();
	for(int i = 0; i <= a.length(); i++) {
	    for(int j = 0; j <= b.length(); j++) {
		if(max == t[i][j]) {
		    res.add(a.substring(i-max, i));
		}
	    }
	}
	return res;

    }


    public static void main(String[] args) throws IOException {

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String a;
	int cnt = 0;
	while((a = br.readLine()) != null) {
	    if(cnt != 0) System.out.println();
	    cnt++;
	    String b = br.readLine();
	    br.readLine();
	    TreeSet<String> res = LCS(a, b);
	    int n = res.size();
	    if(n == 0) System.out.println("No common sequence.");
	    for(int i = 0; i < n; i++) {
		System.out.println(res.pollFirst());
	    }
	}
	
    }


}
