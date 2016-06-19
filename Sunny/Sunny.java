import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Comparator;
import java.util.Arrays;

public class Sunny {

    public static double calcfront(Point top, Point down, int light) {
	
	double hor = (double) (top.y - light) * (down.x - top.x) / (top.y - down.y);
	return Math.sqrt((top.y - light)*(top.y - light) + hor * hor);
	
	
    }

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int C = Integer.parseInt(br.readLine());
	for(int c = 0; c < C; c++) {
	    int N = Integer.parseInt(br.readLine());
	    Point[] pinx = new Point[N];
	    Point[] piny = new Point[N];
	    for(int n = 0; n < N; n++) {
		String[] in = br.readLine().split(" ");
		int x = Integer.parseInt(in[0]);
		int y = Integer.parseInt(in[1]);
		pinx[n] = new Point(x, y);
		piny[n] = new Point(x, y);
	    }
	    Arrays.sort(pinx, new CompAscX());
	    Arrays.sort(piny, new CompDescY());
	    double sum = 0;
	    Point lowest = piny[0];
	    for(int i = 1; i < N; i++) {
		Point neighb = pinx[N-1];
		for(int j = 0; j < N - 1; j++) {
		    if(pinx[j].x == lowest.x) {
			neighb = pinx[j+1];
			break;
		    }
		}
		Point p = piny[i];
		if(p.x < lowest.x) continue;
		double tmp = calcfront(lowest, neighb, p.y);
		//System.out.println(lowest.x + " " + lowest.y + " " + neighb.x + " " + neighb.y + " " + p.x + " " + p.y + " " + tmp);
		sum += tmp;
		lowest = p;
		if(neighb.x == pinx[N-1].x) break;
		
	    }
	    System.out.printf("%.2f\n", sum);
	}
    }

}

class Point {

    int x;
    int y;

    public Point(int x, int y) {
	this.x = x;
	this.y = y;
    }

}

class CompDescY implements Comparator<Point> {

    public int compare(Point a, Point b) {
	if(Integer.compare(a.y, b.y) != 0) return -Integer.compare(a.y, b.y);
	else return -Integer.compare(a.x, b.x);
    }

}

class CompAscX implements Comparator<Point> {

    public int compare(Point a, Point b) {
	return Integer.compare(a.x, b.x);
    }

}