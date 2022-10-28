import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int n;
		while (input.hasNextInt()) {
			n = input.nextInt();
			BigInteger ans = BigInteger.ZERO;
			for (int i = 2; i <= n; i++) {
				if (i % 2 == 1)
					ans = ans.multiply(BigInteger.valueOf(2)).subtract(BigInteger.ONE);
				else
					ans = ans.multiply(BigInteger.valueOf(2)).add(BigInteger.ONE);
			}
			System.out.println(ans);
		}
	}
}