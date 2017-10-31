import java.util.*;
public class Main{
	public static void main(String args[]) throws Exception{
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		double a;
		double b;
		int t;
		for(int i = 1 ; i <= n ; i++){
			a = sca.nextDouble();
			b = sca.nextDouble();
			t = (int)(3.14159 * (a * a + b * b)/100);
			System.out.printf("Property %d: This property will begin eroding in year %d.\n",i,t+1);
		}
		System.out.printf("END OF OUTPUT.");
	}
}