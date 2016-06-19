import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.ArrayList;

public class TIH {

    public static void main(String[] args) throws IOException {
	while(true) {
	    String in = br.readLine();
	    if(in.equals("END")) break;
	    String name = in.substring(2, in.length);
	    ArrayList<Point> p = new ArrayList<Point>();
	    while(true) {
		in = br.readLine();
		if(in.charAt(0) == 'S') break;
		if(in.charAt(0) == 'E') break;
		String input[] = in.split(" ");
		int n = Integer.parseInt(
	    }
	}
    }

}