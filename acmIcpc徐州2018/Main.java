import java.util.*;
import java.math.*;

public class Main {
	Scanner sca = new Scanner(System.in);

	class MyNum{
		BigInteger startIn;
		BigInteger endIn;
		BigInteger justSum;
		BigInteger stareSum;
		MyNum(){
			startIn = BigInteger.ZERO;
			endIn = BigInteger.ZERO;
			justSum = BigInteger.ZERO;
			stareSum = BigInteger.ZERO;
		}
		MyNum(BigInteger startIn,String s){
			this.startIn = startIn;
			this.endIn = startIn.add(BigInteger.ONE);
			justSum = new BigInteger(s);
			stareSum = new BigInteger(s);
		}

		MyNum(BigInteger startIn,BigInteger endIn,BigInteger a,BigInteger b){
			this.startIn = startIn;
			this.endIn = endIn;
			justSum = a;
			stareSum = b;
		}
		public String toString(){
			return "start:" + startIn + " endIn:" + endIn + " justSum" + justSum + " stareSum" + stareSum;
		}
	}
	void showARRAY(ArrayList<MyNum> store){
		int i = 0;
		for(MyNum mn : store){
			System.out.println("index:" +i + mn);
			i++;
		}
	}
	void solve(){
		// System.out.println("ck1");
		int n = sca.nextInt();
		// System.out.println("ck2");
		int q = sca.nextInt();
		// System.out.println("n:"+n + " q:" + q);
		ArrayList<MyNum> store = new ArrayList<MyNum>();
		for(int i = 0;i < n;i++){
			store.add(new MyNum());
		}
		for(int i = 0;i < n;i++){
			store.add(new MyNum(new BigInteger(String.valueOf(i)),sca.next()));
		}
		for(int i = n-1 ;i > 0;i--){
			BigInteger startIn = store.get(i*2).startIn;
			BigInteger endIn = store.get(i*2+1).endIn;
			BigInteger left = store.get(i*2).justSum.add(store.get(i*2+1).justSum);
			BigInteger right = store.get(i*2 + 1).stareSum.add(store.get(i*2).stareSum.add(store.get(i*2).justSum.multiply(store.get(i*2+1).endIn.subtract(store.get(i*2+1).startIn))));
			MyNum mn = new MyNum(startIn,endIn,left,right);
			store.set(i,mn);
		}

		for(int i = 0;i < q;i++){

			int a = sca.nextInt();
			if(a == 1){
				int l = sca.nextInt()-1+n;
				int r = sca.nextInt()+n;
				BigInteger ans = BigInteger.ZERO;
				int ll = l;
				int rr = r;
				while(ll < rr){
					if((ll & 1) == 1){

						BigInteger leftSt = store.get(ll).stareSum;
						BigInteger leftJu = store.get(ll).justSum.multiply(new BigInteger(String.valueOf(r-n)).subtract(store.get(ll).endIn));

						ans = ans.add(leftSt);
						ans = ans.add(leftJu);

						ll++;
					}
					if((rr & 1) == 1){
						rr--;

						BigInteger leftSt = store.get(rr).stareSum;
						BigInteger leftJu = store.get(rr).justSum.multiply((new BigInteger(String.valueOf(r-n))).subtract(store.get(rr).endIn));
						ans = ans.add(leftSt);
						ans = ans.add(leftJu);
					}
					ll >>= 1;
					rr >>= 1;
				}
				System.out.println(ans);
			}else{
				int index = sca.nextInt() - 1 + n;
				String newNum = sca.next();
				store.set(index,new MyNum(new BigInteger(String.valueOf(index - n)),newNum));
				while(index > 1){
					index /= 2;
					BigInteger startIn = store.get(index*2).startIn;
					BigInteger endIn = store.get(index*2+1).endIn;
					BigInteger left = store.get(index*2).justSum.add(store.get(index*2+1).justSum);
					BigInteger right = store.get(index*2+1).stareSum.add(store.get(index*2).stareSum.add(store.get(index*2).justSum.multiply(store.get(index*2+1).endIn.subtract(store.get(index*2+1).startIn))));
					MyNum mn = new MyNum(startIn,endIn,left,right);
					store.set(index,mn);
				}
			}
		}
	}
	public static void main(String[] args) {
		Main solver = new Main();
		solver.solve();
	}
}