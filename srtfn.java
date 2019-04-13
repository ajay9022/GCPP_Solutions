import java.util.*;
import java.io.*;
import java.lang.*;

class job{
	int p,w,a,b;
	job(int p,int a,int b,int w){
		this.p = p;
		this.w = w;
		this.a = a;
		this.b = b;
	}
}
class comp implements Comparator<job>{
	public int compare(job x,job y){
		if(x.a!=y.a)
			return x.a-y.a;
		else
			return x.b-y.b;
	}
}
class srtfn{
	public static void fun(job arr[], int n){
		int in[] = new int[1000];
		for(int j=0;j<1000;++j){in[j]=-1;}
		int i=arr[0].a;
		int c=0;
		in[i] = arr[0].p;
		int next=0;
		while(c<n){
			in[i++] = arr[next].p;
			--arr[next].b;
			if(arr[next].b==0)	++c;
			if(c==n)	break;
			int min=999,ind=-1;
			for(int j=0;j<n;++j){
				if(arr[j].a<=i && arr[j].b>0 && arr[j].b<min){
					min = arr[j].b;
					ind = j;
				}
			}
			
			if(min==999){
				for(int j=0;j<n;++j){
					if(arr[j].a>0){
						ind = j;
						break;
					}
				}
			}
			next = ind;
		}
		for(int j=0;j<i;++j){
			System.out.print((in[j]+1)+" ");
		}
	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		job arr[] = new job[n];
		for(int i=0;i<n;++i){
			int a = sc.nextInt();
			int b = sc.nextInt();
			arr[i] = new job(i,a,b,0);
		}
		Arrays.sort(arr,new comp());
		for(int i=0;i<n;++i){
			System.out.println(arr[i].p+" "+arr[i].a+" "+arr[i].b+" "+arr[i].w);
		}
		fun(arr,n);
	}
}