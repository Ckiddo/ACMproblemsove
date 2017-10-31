import java.util.*;
import java.math.*;
public class Main{
	public static void main(String args[]) throws Exception{
		Scanner sca = new Scanner(System.in);
		String input;
		BigDecimal dou ;
		BigDecimal n;
		while(sca.hasNext()){
			input = sca.nextLine();
			dou = new BigDecimal(input);
			if(dou.equals(new BigDecimal("0.00"))){
				break;
			}
			for(int i = 2 ; i <= 280 ; i++){
				n = new BigDecimal(String.valueOf(i));
				dou = dou.subtract(BigDecimal.ONE.divide(n, 30,RoundingMode.HALF_UP));
				if(dou.compareTo(BigDecimal.ZERO) < 0){
					System.out.printf("%d card(s)\n", i-1);
					break;
				}
			}
		}
	}
}