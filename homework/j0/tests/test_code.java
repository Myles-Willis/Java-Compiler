// public class hello {
//    public static void main(String argv[]) {
//       int x;
//       x = 1;
//       x = x + 2;
//       if (x > 3) {
//          System.out.println("hello, jzero!");
//          x = x - 1;
//       }
//    }
// }

// public class hello {
//
// 	public static void write(int x) {
// 		x = 1;
// 	}
//
// 	public static void main(String argv[]) {
// 	   int i;
// 	   i = 5;
// 	   i = i * i + 1;
// 	   write(i);
// 	}
// }

// public class basic {
// public static int x ;
// public static void main(String []argv) {
//    x = 5;
//    x = x * x;
// }
// }

// public class typeck {
// public static int fib(int i) {
//    return 11;
// }
//
// public static void main(String [] argv) {
//    int i;
//    i = 0 + 1;
//    return 0;
// }
// }

// public class jstuff {
//
// public static void main(String [] argv) {
//   String m;
//   m = "h";
//   m = m + "3";
//   m = m + "l";
//   m = m + "l";
//   m = m + "o";
//   m = m + "0";
//   System.out.println("" + m);
// }
// }





// ** working
// public class basic {
// public static void main(String []argv) {
//    int i;
//    i = 5;
//    while (i > 0) {
//       i = i - 1;
//    }
// }
// }



// ** working

public class exprs {
public static void main() {
   int i;
   int j;
   int k;
   i = 5;
   j = i + i;
   k = j + j * i;
   i = k / j;
   i = k / (j + 1);
}
}


//***runs
// public class gotos {
// public static String itoa(int i) {
//    return "not implemented";
// }
// public static void main() {
//   int i;
//   int j;
//   int k;
//    i = 5;
//    k = 0;
//    while (i>0) {
//    i = i - 1;
//    }
//    for (i=0; i<5; i = i+1) {
//       for (j=0; j<5; j=j+1) {
//         if (i<j) {
// 	k = k + 1;
// 	}
//         if (i==j) {
// 	k = k + 2;
// 	} else {
// 	k = k - 1;
// 	}
//       }
//       }
//    System.out.println("k "+ itoa(k));
// }
// }




//** runs
// public class funcs {
//
// public static int fib(int n) {
//  int m;
//  if (n < 2) {
//     return 1;
//     }
// 	 m = fib(n-1);
// 	 m = m + fib(n-2);
// 	 return m;
// }
//
// public static void main() {
//   int i;
//    i = 5;
//    i = fib(i);
// }
//
// }
//
//

// **working
// public class decls {
// public static int x;
// public static String y;
// public static double z;
//
// public static void main(String []argv) {
//   int i;
//   String y;
//   double k;
//   i = 5;
//   y = "x";
//   z = 3.14;
//   System.out.println(""+ i);
//   }
// }

// **working
//
// filnam: "btest.java"
// public class btest {
// public static void main(String [] argv) {
//     int j;
//     int i;
//     j = 1;
//     i = 10+(2 + j);
// }
// }

// public class list {
// public static void main(String [] argv) {
//    int []a;
//    a = new int[8];
//    a[5] = 5;
//    System.out.println(""+ a[5]);
// }
// }


// **runs
// public class predecl {
// public static void main(String [] argv) {
//    System.out.println("hello" + 0);
// }
// }

// **runs
// public class redeclared {
//
// public static int n1 ;
// public static int n2 ;
//
// public static void f(double n1) {
//    double n2;
//    int y;
//
// //   double n1;
//    System.out.println(""+ n1);
//    return;
// }
// }

//*****runs
// public class typeck_fn {
// public static int fib(int i) {
//    return 11;
// }
//
// public static int main(String [] argv) {
//    int i ;
//    i = 0 +
//       fib(/*1,*/2);
//    return 0;
// }
// }



// public class typeck {
// public static int fib(int i) {
//    return 11;
// }
//
// public static void main(String [] argv) {
//    int i;
//    i = 0 + fib(3);
// }
// }
//
//
//
//
//



// public class typeck_struct {
//   public double dd;
//
// public static typeck_struct mkFoo() {
//   typeck_struct s;
//   s = new typeck_struct();
//   s.dd = 5.5;
//   return s;
// }
//
// public static double fib(typeck_struct f, int i) {
//    double x;
//    x = f.dd * 2.0;
//    return x;
// }
//
// public static void main(String [] argv) {
//    typeck_struct f;
//    double i;
//    int j;
//    i = 0.0 + fib(null, 3);
//    i = 5.0;
//    i = fib(null, 2 /* "hello" */);
//    j = 5;
//    System.out.println(j + "\n");
// }
// }




// public class undeclared {
// public static void main(String []argv) {
//    System.out.println(argv[1]);
// }
// }
