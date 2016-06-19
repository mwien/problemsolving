import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.math.BigInteger;

public class OceanDeep {

	public static void main(String[] args) throws IOException {
	    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	    String in = "";
	    String newin;
	    while ((newin = br.readLine()) != null) {
		in += newin;
	    }
	    String[] input = in.split("#");
	    BigInteger b = new BigInteger("131071");
	    for(int i = 0; i < input.length; i++) {
		if(input[i].equals("")) continue;
		BigInteger a = new BigInteger(input[i], 2);
		System.out.println(a.mod(b).equals(new BigInteger("0")) ? "YES" : "NO");
	    }
	}

}
