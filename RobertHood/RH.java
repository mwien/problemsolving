import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.Stack;
import java.util.ArrayList;


public class RH {

        public static Point[] grahamScan(Point[] points) {
	    //find leftmost point with lowest y-coordinate
	    int xmin = Integer.MAX_VALUE;
	    int ymin = Integer.MAX_VALUE;
	    int index = -1;
	    for(int i = 0; i < points.length; i++) {
		if(points[i].y < ymin || (points[i].y == ymin && points[i].x < xmin)) {
		    xmin = points[i].x;
		    ymin = points[i].y;
		    index = i;
		}
	    }
	    //get that point to the start of the array
	    Point tmp = new Point(points[index].x, points[index].y);
	    points[index] = points[0];
	    points[0] = tmp;
	    for(int i = 1; i < points.length; i++) points[i].src = points[0];
	    Arrays.sort(points, 1, points.length);
	    //for collinear points eliminate all but the farthest
	    boolean[] isElem = new boolean[points.length];
	    for(int i = 1; i < points.length-1; i++) {
		Point a = new Point(points[i].x - points[i].src.x, points[i].y - points[i].src.y);
		Point b = new Point(points[i+1].x - points[i+1].src.x, points[i+1].y - points[i+1].src.y);
		if(Calc.crossProd(a, b) == 0) isElem[i] = true;
	    }
	    //works only if there are more than three non-collinear points
	    Stack<Point> s = new Stack<Point>();
	    int i = 0;
	    for(; i < 3; i++) {
		while(isElem[i]) {
		    i++;
		}
		s.push(points[i]);
	    }
	    for(; i < points.length; i++) {
		if(isElem[i]) continue;
		while(true) {
		    Point first = s.pop();
		    Point second = s.pop();
		    s.push(second);
		    Point a = new Point(first.x - second.x, first.y - second.y);
		    Point b = new Point(points[i].x - second.x, points[i].y - second.y);
		    //use >= if straight angles are needed
		    if(Calc.crossProd(a, b) > 0) {
			s.push(first);
			s.push(points[i]);
			break;
		    }
		}
	    }
	    Point[] convexHull = new Point[s.size()];
	    for(int j = s.size()-1; j >= 0; j--) convexHull[j] = s.pop();
	    return convexHull;
	}

    public static void main(String[] args) throws IOException {
	BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
	int C = Integer.parseInt(br.readLine());
	ArrayList<Point> points = new ArrayList<Point>();
	boolean[][] ex = new boolean[2001][2001];
	for(int c = 0; c < C; c++) {
	    String[] in = br.readLine().split(" ");
	    Point a = new Point(Integer.parseInt(in[0]), Integer.parseInt(in[1]));
	    if(!ex[a.x + 1000][a.y + 1000]) {
		points.add(a);
		ex[a.x + 1000][a.y + 1000] = true;
	    }
	}
	
	Point[] point = new Point[points.size()];
	for(int i = 0; i < points.size(); i++) {
	    point[i] = points.get(i);
	}
	if (point.length == 1) {
	System.out.println(0f);
	} else if(point.length == 2) {
	    System.out.println(Calc.euclDist(point[0], point[1]));
	} else {
	    point = grahamScan(point);
	    double maxdist = Double.MIN_VALUE;
	    for(int i = 0; i < point.length; i++) {
		for(int j = 0; j < i; j++) {
		    double dist = Calc.euclDist(point[i], point[j]);
		    if(dist > maxdist) maxdist = dist;
		} 
	    }
	    System.out.println(maxdist);
	}
    }
}

class Point implements Comparable<Point> {
    Point src; //set seperately

    int x;
    int y;
    public Point(int x, int y) {
	this.x = x;
	this.y = y;
    }
    //might crash if one point equals src
    public int compareTo(Point cmp) {
	Point a = new Point(this.x - src.x, this.y - src.y);
	Point b = new Point(cmp.x - src.x, cmp.y - src.y);
	if(a.x == b.x && a.y == b.y) return 0; //checks if points are identical
	if(Calc.crossProd(a, b) == 0 && Calc.dotProd(a, b) > 0) return Integer.valueOf(Calc.dotProd(a, a)).compareTo(Integer.valueOf(Calc.dotProd(b, b)));//if same angle, sort by dist
	if(a.y == 0 && a.x > 0) return -1; //angle of a is 0, thus b>a
	if(b.y == 0 && b.x > 0) return 1; //angle of b is 0, thus a>b
	if(a.y > 0 && b.y < 0) return -1; //a ist between 0 and 180, b between 180 and 360
	if(a.y < 0 && b.y > 0) return 1;
	return Integer.valueOf(0).compareTo(Integer.valueOf(Calc.crossProd(a, b))); //return negative value if cp larger than zero
    }
}

class Calc {
    public static int crossProd(Point p1, Point p2) {
	return p1.x * p2.y  - p2.x * p1.y;
    }
    public static int dotProd(Point p1, Point p2) {
	return p1.x * p2.x + p1.y * p2.y;
    }
    public static double euclDist(Point p1, Point p2) {
	return Math.sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y)); 
    }
}
