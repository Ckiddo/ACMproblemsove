//import java.io.*;
import java.util.*;
import java.math.*;
public class Main{
	/*
	static double dvalueOf(String s){
		char ss[] = s.toCharArray();
		double result = 0;
		for(int i = 0 ; i < ss.length ; i++){
			if(ss[i]<='9'&& ss[i]>='0'){
				result = result*10 + (ss[i]-'0');
			}else if(ss[i] == '.'){
				int j = 1;
				i++;
				for(;i < ss.length;i++){
					if(ss[i]<='9'&& ss[i]>='0'){
						result = result*10 + (ss[i]-'0');
						j = j * 10;
					}else{
						continue;
					}
				}
				result = result / j;
			}else{
				continue;
			}
		}
		return result;
	}
	*/
	static int ivalueOf(String s){
		char ss[] = s.toCharArray();
		int result = 0;
		for(int i = 0; i < ss.length ;i++){
			if(ss[i] <= '9' && ss[i] >= '0'){
				result = result*10 + (ss[i]-'0');
			}
		}
		return result;
	}
	public static void main(String args[]) throws Exception{
		Scanner sca = new Scanner(System.in);
		while(sca.hasNext()){
			String input = sca.nextLine();
			BigDecimal R = new BigDecimal(input.substring(0,6));
			int n = ivalueOf(input.substring(7));
			String end2;
			if(n == 0){
				System.out.println("1");
			}else{
				BigDecimal end = new BigDecimal(input.substring(0,6));
				for(int i = 1 ; i < n ; i++){
					end = end.multiply(R);
				}
				//System.out.println(end);
				end2 = end.toPlainString();
				while((end2.lastIndexOf("0")) == (end2.length()-1)){
					end2 = end2.substring(0,end2.length()-1);
				}
				if((end2.lastIndexOf(".")) == end2.length()-1){
					end2 = end2.substring(0,end2.length()-1);
				}
				if(end2.indexOf(".") == 1 && end2.indexOf("0") == 0){
					end2 = end2.substring(1);
				}
				System.out.println(end2);
			}
			
		}
	}
}