import java.util.*;
public class Main{
	static int inversions (String s){
		char ss[] =s.toCharArray();
		int inversions = 0;
		for(int i = 0; i < ss.length-1;i++){
			for(int j = i+1;j<ss.length;j++){
				if(ss[i] > ss[j]){
					inversions++;
				}
			}
		}
		return inversions;
	}
	public static void main(String args[]) throws Exception{
		Scanner sca = new Scanner(System.in);
		int n = sca.nextInt();
		int m = sca.nextInt();
		String[] result = new String[(n+1)*n/2];
		sca.nextLine();
		for(int i = 0; i < m ;i++){
			String s = sca.nextLine();
			int y = inversions(s);
			if(result[y] == null){
				result[y] = s+"\n";
			}else{
				result[y] += (s+"\n");
			}
			
		}
		for(int i = 0 ;i < result.length ;i++){
			if(result[i] != null){
				System.out.print(result[i]);
			}
		}
	}
}