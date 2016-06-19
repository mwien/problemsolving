import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;

public class TinkersPuzzle {

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int T = Integer.parseInt(br.readLine());
	for(int t = 0; t < T; t++) {
	    String[] in = br.readLine().split(" ");
	    int D = Integer.parseInt(in[0]);
	    int V = Integer.parseInt(in[1])*282;
	    System.out.print("Case " + (t+1) + ": ");
	    System.out.printf("%.3f\n", 4*Math.sqrt(3*V/(7*D*Math.PI)));
	}
    }

}
