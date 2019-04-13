import java.util.*;
import java.io.*;

class bankers{
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		int m = sc.nextInt();
		int allocated[][] = new int[n][m];
		int max_needed[][] = new int[n][m];
		int need[][] = new int[n][m];
		int available[] = new int[m];
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)
				allocated[i][j] = sc.nextInt();
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)
				max_needed[i][j] = sc.nextInt();
		}
		for(int i=0;i<m;++i){
			available[i] = sc.nextInt();
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j)
				need[i][j] = max_needed[i][j] - allocated[i][j];
		}
		int order[] = new int[n];
		int flg[] = new int[n];
		for(int j=0;j<n;++j){flg[j]=0;}
		int c=0;
		while(c<n){
			int d=c;
			int mind=-1;
			for(int i=0;i<n;++i){
				
				if(flg[i]==0){
					int flag=0;
					for(int j=0;j<m;++j){
						if(need[i][j]>available[j]){
							flag=1;break;
						}
					}
					if(flag==0){
						System.out.print("c"+c);
						order[c++] = i;
						flg[i]=1;
						for(int j=0;j<m;++j){
							available[j] += allocated[i][j];	
							System.out.print(available[j]+" ");
						}System.out.println();
						break;
						
					}
				}
			}
			if(c==d){
				System.out.println("Unsafe");
			}
		}
		System.out.println("Safe\n");
		for(int i=0;i<n;++i){
			System.out.print(order[i]+" ");
		}

	}
}
/*
5 3
0 1 0
2 0 0
3 0 2
2 1 1
0 0 2
     

7 5 3
3 2 2
9 0 2
2 2 2
4 3 3

3 3 2
*/