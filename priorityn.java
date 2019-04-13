import java.util.*;
import java.io.*;
import java.lang.*;

class job{
	int p,pr,a,b;
	job(int p,int a,int b,int pr){
		this.p = p;
		this.pr = pr;
		this.a = a;
		this.b = b;
	}
}
class comp implements Comparator<job>{
	public int compare(job x,job y){
		if(x.a!=y.a)
			return x.a-y.a;
		else
			return y.pr-x.pr;
	}
}
class priorityn{
	public static void fun(job arr[], int n){
		int in[] = new int[1000];
		for(int j=0;j<1000;++j){in[j]=-1;}
		int c=0;
		int i=arr[0].a;
		int next = 0;
		while(c<n){
			in[i++] = arr[next].p;
			arr[next].b -= 1;
			if(arr[next].b==0){
				++c;
				if(c==n) break;
			}
			int max = -1,ind=-1;
			for(int j=0;j<n;++j){
				if(arr[j].b>0 && arr[j].a<=i){
					if(arr[j].pr>max){
						ind = j;max = arr[j].pr;
					}
				}
			}

			int min=9999;
			if(ind==-1){
				for(int j=0;j<n;++j){
					if(arr[j].b>0){
						if(arr[j].a<=min && arr[j].a>i){
							min = arr[j].a;ind=j;
						}
					}
				}
			}
			next = ind;
		}
		for (int j=0;j<i;++j){
			System.out.print(in[j]+" ");
		}
	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		job arr[] = new job[n];
		for(int i=0;i<n;++i){
			int a = sc.nextInt();
			int b = sc.nextInt();
			int pr = sc.nextInt();
			arr[i] = new job(i,a,b,pr);
		}
		Arrays.sort(arr,new comp());
		for(int i=0;i<n;++i){
			System.out.println(arr[i].p+" "+arr[i].a+" "+arr[i].b+" "+arr[i].pr);
		}
		fun(arr,n);
	}
}