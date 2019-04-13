import java.util.*;
import java.io.*;
import java.lang.*;
class job{
	public int p,a,b,w;
	job(int p, int a, int b, int w){
		this.p=p;
		this.a=a;
		this.b=b;
		this.w=w;
	}
}
class comp implements Comparator<job>{
	public int compare(job x,job y){
		return x.a-y.a;
	}
}
public class rrbn{
	
	public static void fun(job arr[], int n, int t){
		int in[] = new int[1000];
		for(int j=0;j<1000;++j)	in[j]=-1;
		ArrayList<Integer> al = new ArrayList<>();
		HashMap<Integer,Integer> hm = new HashMap<>();
		int i=arr[0].a;
		int c=0;
		for(int j=1;j<n;++j){
			hm.put(arr[j].p,0);
		}
		int next = 0;
		al.add(0);
		hm.put(arr[0].p,1);
		int k=0;
		while(c<n){
			next = al.get(0);
			for(int j=0;j<Math.min(arr[next].b,t);++j){
				in[i++]=arr[next].p;
			}

			arr[next].b -= Math.min(arr[next].b,t);
			al.remove(0);
			if(arr[next].b==0) c+=1;
			for(int j=0;j<n;++j){
				if(hm.get(arr[j].p)==0 && arr[j].a<=i && arr[j].b>0){
					System.out.println(k+".."+j);
					al.add(j);
					hm.put(arr[j].p,1);
				}
			}
			if(arr[next].b>0){
				al.add(next);
			}

			if(al.isEmpty() && c<n){
				int min=99999;
				for(int j=0;j<n;++i){
					if(arr[j].b>0 && hm.get(arr[j].p)==0 && arr[j].a<min){
						min=arr[j].a;
						next = j;
					}
				}
				al.add(next);
			}
			
			++k;
		}
		System.out.println();
		for(int j=0;j<i;++j){
			System.out.print(in[j]+" ");
		}
	}
	public static void main(String args[]){
		Scanner sc = new Scanner(System.in);

		int n = sc.nextInt();
		int t = sc.nextInt();
		job arr[] = new job[n];
		for(int  i=0;i<n;++i){
			int a = sc.nextInt();
			int b = sc.nextInt();
			arr[i] = new job(i,a,b,0);
			
		}
		Arrays.sort(arr,new comp());
		for(int  i=0;i<n;++i){
			System.out.println(arr[i].p+" "+arr[i].a+" "+arr[i].b+" "+arr[i].w);
			
		}
		fun(arr, n, t);
	}
}