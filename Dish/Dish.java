import java.util.Scanner;
import java.lang.Comparable;
import java.util.Arrays;

public class Dish {

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int n = s.nextInt();
	int m = s.nextInt();
	s.nextLine();
	Tuple[] dishes = new Tuple[n];
	for(int i = 0; i < n; i++) {
	    String in = s.nextLine();
	    String[] split = in.split(" ");
	    int S = Integer.parseInt(split[1]);
	    double t = Double.parseDouble(split[2]);
	    dishes[i] = new Tuple(S, t);
	}
	Arrays.sort(dishes);
	double sum = 0;
	for(int i = 0; i < n; i++) {
	    if(dishes[i].s < m) {
		sum += dishes[i].s * dishes[i].t;
		m -= dishes[i].s;
	    } else if(dishes[i].s >= m) {
		sum += m * dishes[i].t;
		break;
	    }
	}
	System.out.println(sum);
    }

}

class Tuple implements Comparable<Tuple> {

    int s;
    double t;

    public Tuple(int s, double t) {
	this.s = s;
	this.t = t;
    }

    public int compareTo(Tuple other) {
	return Double.compare(other.t, this.t);
    }
}
