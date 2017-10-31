import java.util.*;
public class Main{
	public static void main(String args[]) throws Exception{
		Scanner sca = new Scanner(System.in);
		double sum= 0.0;
		for(int i = 0 ;i < 12 ;i++){
			sum = sum + sca.nextDouble();
		}
		System.out.printf("$%.2f\n",sum/(double)12);
	}
}