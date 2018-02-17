import java.util.Scanner;

public class Main {
	static long acSum(int n) {
		return (long)n * (n+1) / 2l;
	}
	public static void main(String[] args) {
		int a,b;
		Scanner I = new Scanner(System.in);
		a = I.nextInt();
		b = I.nextInt();
		if(b < 4) {
			System.out.println(0);
			return;
		}
		if(a <= 2) {
			System.out.println(acSum(b/2)*2l-2l);
			return;
		}
		System.out.println((acSum(b/2)-acSum((a-1)/2))*2l);
		I.close();
	}
}
