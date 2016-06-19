import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.ArrayList;
import java.util.HashMap;

public class Window {

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String in;
	while((in = br.readLine()) != null) {
	    ArrayList<HashMap<String, Integer>> windows = new ArrayList<HashMap<String, Integer>>();
	    for(int i = 0; i < in.length(); i++) {
		windows.add(new HashMap<String, Integer>());
	    }
	    boolean corr = true;
	    int ind = -1;
	    for(int i = 0; i <= in.length(); i++) {
		if(!corr) break;
		for(int j = 0; j < i; j++) {
		    windows.get(i - j - 1).put(in.substring(j, i), 0);
		    if(windows.get(i- j - 1).size() > i-j+1) {
			corr = false;
			ind = i;
			break;
		    }
		}
	    }
	    System.out.println(corr ? "YES" : "NO:" + ind); 
	}

    }

}
