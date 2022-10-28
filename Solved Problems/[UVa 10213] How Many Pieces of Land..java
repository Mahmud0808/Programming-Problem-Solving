import java.util.Scanner;
import java.math.BigInteger;

public class Main {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		int S = input.nextInt();
		while (S > 0) {
			S--;
			int n = input.nextInt();
			BigInteger N = BigInteger.valueOf(n);
			BigInteger res = BigInteger.ONE.add((N.multiply(N.subtract(BigInteger.ONE))).divide(BigInteger.valueOf(2))).add((N.multiply(N.subtract(BigInteger.ONE)).multiply(N.subtract(BigInteger.valueOf(2))).multiply(N.subtract(BigInteger.valueOf(3)))).divide(BigInteger.valueOf(24)));
			System.out.println(res);
		}
	}
}

// We already have 1 piece of land because of the circle (1)
// Every 2 point creates a line which adds a piece of land (nC2)
// Every quadrilateral adds a piece of land (nC4)
// So we get Pieces = 1 + nC2 + nC4