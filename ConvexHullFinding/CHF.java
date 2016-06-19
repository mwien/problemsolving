import java.util.Arrays;
import java.util.Stack;
import java.util.Scanner;

public class CHF {

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
	/*Sometimes it might be necessary to also add points to the convex hull that form 
	  a straight angle. The following lines of code achieve this. Only at the first and last diagonal we have to add those. Of course the previous return-statement has to be deleted as well as allowing straight angles in the above implementation. */
	
    }

    public static void main(String[] args) {
	Scanner s = new Scanner(System.in);
	int K = s.nextInt();
	System.out.println(K);
	for(int i = 0; i < K; i++) {
	    int N = s.nextInt();
	    Point[] points = new Point[N-1];
	    for(int j = 0; j < N-1; j++) {
		points[j] = new Point(s.nextInt(), s.nextInt());
	    }
	    s.nextInt();
	    s.nextInt();
	    points = grahamScan(points);
	    System.out.println(points.length + 1);
	    if(i < K-1) s.nextInt();
	    for(int j = 0; j < points.length; j++) {
		System.out.println(points[j].x + " " + points[j].y);
	    }
	    System.out.println(points[0].x + " " + points[0].y);
	    if(i < K - 1) System.out.println(-1);
	}
    }

}

class Point implements Comparable<Point> {
    Point src; //set seperately in GrahamScan method

    int x;
    int y;
    public Point(int x, int y) {
	this.x = x;
	this.y = y;
    }
    //might crash if one point equals src
    //major issues with multiple points on same location!
    public int compareTo(Point cmp) {
	Point a = new Point(this.x - src.x, this.y - src.y);
	Point b = new Point(cmp.x - src.x, cmp.y - src.y);
	if(a.x == b.x && a.y == b.y) return 0; //checks if points are identical
	if(Calc.crossProd(a, b) == 0 && Calc.dotProd(a, b) > 0) return Integer.compare(Calc.dotProd(a, a), Calc.dotProd(b, b));//if same angle, sort by dist
	if(a.y == 0 && a.x > 0) return -1; //angle of a is 0, thus b>a
	if(b.y == 0 && b.x > 0) return 1; //angle of b is 0, thus a>b
	if(a.y > 0 && b.y < 0) return -1; //a ist between 0 and 180, b between 180 and 360
	if(a.y < 0 && b.y > 0) return 1;
	return Integer.compare(0, Calc.crossProd(a, b)); //return negative value if cp larger than zero
    }
}

class Calc {
    public static int crossProd(Point p1, Point p2) {
	return p1.x * p2.y  - p2.x * p1.y;
    }
    public static int dotProd(Point p1, Point p2) {
	return p1.x * p2.x + p1.y * p2.y;
    }
}

