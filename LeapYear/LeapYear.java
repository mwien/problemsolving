import java.util.Scanner;


public class LeapYear {

public static void main(String[] args) {
		
		Scanner sc = new Scanner(System.in);
		
		while(sc.hasNextInt()){
			int z = sc.nextInt();
			boolean leap = false;
			boolean ordinary = true;
			
			if ((z%4==0 && z%100!=0) || z%400==0){
				System.out.println("This is leap year.");
				leap = true;
				ordinary = false;
			}
			if (z%15==0){
				System.out.println("This is huluculu festival year.");
				ordinary = false;
			}
			if(z%55==0 && leap){
				System.out.println("This is bulukulu festival year.");
				ordinary = false;
			}
			if(ordinary){
				System.out.println("This is an ordinary year.");
			}
			System.out.println("");
		
		}

	}
}
