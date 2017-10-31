import java.util.*;
public class Main{
	static String[] month = {"pop", "no", "zip", "zotz", "tzec",
				      "xul", "yoxkin", "mol", "chen", "yax",
				      "zac", "ceh", "mac", "kankin", "muan", 
				      "pax", "koyab", "cumhu"};
	static String[] Tzolkin = {"ahau","imix", "ik", "akbal", "kan", "chicchan",
							   "cimi", "manik", "lamat", "muluk", "ok", 
							   "chuen", "eb", "ben", "ix", "mem", 
							   "cib", "caban", "eznab", "canac"};
	static int result(String s){
		char[] ss = s.toCharArray();
		int d = 0;
		int m = 0;
		int y = 0;
		for(int i = 0; i < ss.length ;i++){
			if(ss[i] == '.'){
				for(;i<ss.length;i++){
					if(ss[i]<='9' && ss[i]>='0'){
						y = y*10 + ss[i]-'0';
					}
				}
			}else{
				d = d*10 + ss[i]-'0';
			}
		}
		for(String mm : month){
			if(s.contains(mm)){
				break;
			}
			m++;
		}
		//System.out.println(d + "," + m +"," + y);
		return d+1+(m*20) + y*365;
	}
	public static void main(String args[]) throws Exception{
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		sca.nextLine();
		System.out.println(n);
		for(int i = 0; i < n ;i++){
			String s = sca.nextLine();
			int result = result(s);
			System.out.printf("%d %s %d\n",(result-1)%13+1,Tzolkin[(result%20)],(result-1)/260);
		}
	}
}