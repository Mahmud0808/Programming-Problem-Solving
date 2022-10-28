import java.util.*;
import java.math.*;

class Main {
	public static void main(String[] args) throws java.lang.Exception {
		Scanner input = new Scanner(System.in);
		while (input.hasNext()) {
			BigInteger t;
			int a, b;
			t = input.nextBigInteger();
			a = input.nextInt();
			b = input.nextInt();
			System.out.printf("(%d^%d-1)/(%d^%d-1) ", t, a, t, b);
			if (t.compareTo(BigInteger.ONE) == 0 || a < b)
				System.out.println("is not an integer with less than 100 digits.");
			else if (a == b)
				System.out.println(1);
			else if (a % b != 0)
				System.out.println("is not an integer with less than 100 digits.");
			else if (a == 0)
				System.out.println(0);
			else if ((a - b) * Math.log10(Integer.parseInt(t.toString())) > 99)
				System.out.println("is not an integer with less than 100 digits.");
			else {
				BigInteger numerator = t.pow(a).subtract(BigInteger.ONE);
				BigInteger denominator = t.pow(b).subtract(BigInteger.ONE);
				if (numerator.mod(denominator).compareTo(BigInteger.valueOf(0)) != 0 || numerator.divide(denominator).toString().length() > 99)
					System.out.println("is not an integer with less than 100 digits.");
				else
					System.out.println(numerator.divide(denominator));
			}
		}
	}
}
