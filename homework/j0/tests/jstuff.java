public class jstuff {
/*
	multi line
	comment
*/
// single line comment

boolean logicalValue;
// global scope variable declaration
int d6;
int x;
int y45;
int g0var;
int d6Var;
double dubVal;

public static void assignments(int a, int b, int c) {
	// a = 1;
	// b = 2;
	// c = c- 3;
}

public static void Operators() {
// int w=0, x, y=0, z=0, q=0 ;
	int w;
	int y;
	int z;
	int q;

	x = -1;
	if (x < y && y <= z || z < q && q != x) {
	   x = y;
	   y = z;
	} else {
	   w = x + y * z / q - 4;
	   }
	logicalValue = w > 20;
}

public static void WhileStuff() {
int x;
   x = 0;
   for( ; x < 20; ){
	   x = d6;
	  return;
	  }
}

public static void RollTheDice() {
	d6Var = 6;
	y45 = d6Var;
}

public static void main() {
	RollTheDice();
	System.out.println("stuff and things\n");
	g0var = 2;
}

// class variable declaration
public static void MakeAPet() {
	// local scope variable declaration
   // pet p = new pet();
   // p.play();
   System.out.println("%d\n" + x);
}

public static String stringOps() {
	String S1;
	String S2;
	S1 = "One";
	S2 = S1 + "Two"; // uh oh
	return S2;
}

// public static int []listOps()  {
// 	int [] L = new int[3];
// 	L[0] = 1; L[1] = 2; L[2] = 3;
// 	return L; // uh oh
// }
}
// jstuff.java output [expect a monstrosity]
