public class redeclared {

public static int n1 ;
public static int n2 ;

public static void f(double n1) {
   double n2;
   int y;

   double n1;
   System.out.println(""+ n1);
   return;
}
}
