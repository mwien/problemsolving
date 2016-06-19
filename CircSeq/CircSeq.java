import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class CircSeq {

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	String in = br.readLine();
	int T = Integer.parseInt(in);
	for(int t = 0; t < T; t++) {
	    in = br.readLine();
	    String smallest = in;
	    for(int i = 0; i < in.length(); i++) {
		in = in.substring(1, in.length()) + in.substring(0,1);
		if(in.compareTo(smallest) < 0) smallest = in;
	    }
	    System.out.println(smallest);
	}
    }

}
