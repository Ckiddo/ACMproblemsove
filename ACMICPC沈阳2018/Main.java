import java.util.*;
import java.math.*;

public class Main{
	Scanner sca = new Scanner(System.in);
	String numberN;
	int caseNum;
	char _7[] = "753210".toCharArray();
	boolean lessThan(char str[],String ss){
		String st = new String(str);
		BigInteger stBi = new BigInteger(st);
		BigInteger ssBi = new BigInteger(ss);
		if(stBi.compareTo(ssBi) != 1){
			return true;
		}
		return false;
	}
	boolean isSuperMe(char str[],int n){
		for(int i = 0;i < n;i++){
			String test = "0";
			for(int j = i;j < n;j++){
				test += str[j];
			}
			BigInteger testBi = new BigInteger(test);
			if(testBi.equals(BigInteger.ZERO)){
				return false;
			}
			if(!testBi.isProbablePrime(1000)){
				return false;
			}
		}
		return true;
	}
	void printAns(char str[]){
		String s = new String(str);
		BigInteger sBi = new BigInteger(s);
		System.out.println("Case #"+(caseNum+1) + ": "+sBi);
	}
	void showStr(char str[],int n){
		String s = "";
		for(int i = 0;i < n;i++){
			s += str[i];
		}
		System.out.println("showStr:"+s);
	}
	void dp(char str[],int st,int length){
		showStr(str,st);
		if(st == length){
			if(isSuperMe(str,st) && lessThan(str,numberN)){
				printAns(str);
				return;
			}
		}else{
			if(!isSuperMe(str,st)){
				return;
			}else{
				for(int i = 0;i < _7.length;i++){
					str[st] = _7[i];
					dp(str,st+1,length);
				}
			}
		}
	}
	void compute(int caseNum){
		this.caseNum = caseNum;
		numberN = sca.next();
		String numberNs[] = numberN.split("");
		char ans[] = new char[numberNs.length];
		dp(ans,0,numberNs.length);
	}

	void solve(){
		int T;
		T = sca.nextInt();
		for(int i = 0;i < T;i++){
			compute(i);
		}
	}
	public static void main(String args[]){
		Main solver = new Main();
		solver.solve();
		char str[] = "125".toCharArray();
		String s = "124";
		System.out.println(solver.lessThan(str,s));
	}
}