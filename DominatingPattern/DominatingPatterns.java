import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;

public class DominatingPatterns {


    public static int kmp(String s, String w) {

	int occ = 0;
	int[] N  = new int[w.length()+1];
	int i = 0; int j = -1; N[0] = -1;
	while(i < w.length()) {
	    while(j >= 0 && w.charAt(j) != w.charAt(i))
		j = N[j];
	    i++; j++; N[i] = j;
	}
	i = 0; j = 0;
	while(i < s.length()) {
	    while(j >= 0 && s.charAt(i) != w.charAt(j))
		j = N[j];
	    i++; j++;
	    if(j == w.length()) {
		occ++;
		j = N[j];
	    }
	}
	return occ;

    }


    public static void main(String[] args) throws IOException {

	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	while(true) {
	    int N = Integer.parseInt(br.readLine());
	    if(N == 0) break;
	    String[] patterns = new String[N];
	    for(int i = 0; i < N; i++) {
		patterns[i] = br.readLine();
	    }
	    String text = br.readLine();
	    ArrayList<String> dom = new ArrayList<String>();
	    int max = -1;
	    for(int i = 0; i < N; i++) {
		int occ = kmp(text, patterns[i]);
		if(occ > max) {
		    dom.clear();
		    dom.add(patterns[i]);
		    max = occ;
		} else if(occ == max) {
		    dom.add(patterns[i]);
		}
	    }
	    System.out.println(max);
	    for(int i = 0; i < dom.size(); i++) {
		System.out.println(dom.get(i));
	    }
	}

    }



}
