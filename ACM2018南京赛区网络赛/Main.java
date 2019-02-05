import java.util.Scanner;
import java.math.BigInteger;
public class Main{	
	Scanner sca = new Scanner(System.in);
	void solve(){
		int T = sca.nextInt();
		for(int i = 0;i < T;i++){
			BigInteger bi = new BigInteger(sca.next());
			caculate(bi);
		}
	}
	void caculate(BigInteger n){
		// BigInteger ans = new BigInteger("0");
		// for(BigInteger t = new BigInteger("1");!t.equals(n);t = t.add(BigInteger.ONE)){
		// 	ans = (ans.add(kNJ(t,n))).mod(n);
		// }
		System.out.println(n.subtract(BigInteger.ONE));
	}
	BigInteger kNJ(BigInteger n,BigInteger mod){
		BigInteger ans = new BigInteger("1");
		for(BigInteger t = new BigInteger("1");!t.equals(n);t = t.add(BigInteger.ONE)){
			ans = ans.multiply(t).mod(mod);
		}
		ans = ans.multiply(n).mod(mod);
		ans = ans.multiply(n).mod(mod);
		return ans;
	}
	public static void main(String[] args) {
		Main solver = new Main();
		solver.solve();
	}
}