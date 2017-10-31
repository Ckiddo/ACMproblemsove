import java.util.Scanner;

public class Main {
	public static void main(String args[]){
		int p,e,i,k,d,t,r,x;
		Scanner sca = new Scanner(System.in);
		x=0;
		while(sca.hasNext()){
			//scanf("%d %d %d %d",&p,&e,&i,&d) && p!=-1
			p = sca.nextInt();
			e = sca.nextInt();
			i = sca.nextInt();
			d = sca.nextInt();
			if(p+e+i+d == -4){
				break;
			}
			x++;
			p=p%23; e=e%28; i=i%33;
			t=e-p;
			k=0;
			while(t%23!=0){
				k++;
				t+=5;
			}

			t=e+k*28;

			r=t-i;
			k=0;
			while(r%33!=0){
				k++;
				r+=611;
			}

			r=t+k*644;

			if(r>d){
				r=r-d;
			}else{
				r=r+21252-d;
			}
				
			System.out.printf("Case %d: the next triple peak occurs in %d days.\n",x,r);
		}
	}
}