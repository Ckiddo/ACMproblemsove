import java.util.*;
public class Main{
	static int arr[] = new int[10000000];
	static int max = -1;
	static int min = 10000000;
	static void add(String s){
		char ss[] = s.toCharArray();
		int r = 0;
		int w = 0;
		for(; r < ss.length ; r++){
			if(ss[r]<='9' && ss[r] >= '0'){
				ss[w] = ss[r]; 
				w++;
			}else if(ss[r] <= 'P' && ss[r] >= 'A'){
				ss[w] = (char) (((((int)ss[r])-(59))/3) + '0');
				w++;
			}else if(ss[r] <= 'Y' && ss[r] >= 'R'){
				ss[w] = (char) (((((int)ss[r])-(60))/3) + '0');
				w++;
			}
		}
		int phoneNumber = 0;
		for(int i = 0 ; i<7 ; i++){
			phoneNumber = phoneNumber*10 + ss[i]-'0';
		}
		arr[phoneNumber]++;
		if(phoneNumber > max){
			max = phoneNumber;
		}
		if(phoneNumber < min){
			min = phoneNumber;
		}
	}
	public static void main(String args[]) throws Exception{
		Scanner sca = new Scanner(System.in);
		int n = Integer.valueOf(sca.nextLine());
		String input;
		for(int i = 0; i < n ; i++){
			input = sca.nextLine();
			add(input);
		}
		int count = 0;
		for(int i = min ; i <=max ;i++){
			if(arr[i] > 1){
				System.out.printf("%03d-%04d %d\n", i/10000, i%10000, arr[i]);
				count = 1;
			}
		}
		if(count == 0){
			System.out.println("No duplicates.");
		}
	}
}