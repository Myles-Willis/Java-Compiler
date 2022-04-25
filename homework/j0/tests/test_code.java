public class foo {

	public static void increment(int x, int y) {
	 	x = x + 1;
  	}

	public static void main(String[]argv) {
   		int i = 5;
   		i = i * i + 1;
   		increment(i, 3);
		// System.out.println(i);
   		// boolean b = i > 10;
   	}
}
