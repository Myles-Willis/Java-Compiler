public class pet {
//    This tests a sample virtual pet type

    public static int hunger;
    public static int happy;

    public static int play() {
        int choice;
        System.out.println("What should we play?\n");
        System.out.println( "Fetch (1) \n Roll over (2)\n" );
        choice = 2;
        if (choice == 1) {
            System.out.println("Fetch, eh");
            happy = happy+10;
        } else if (choice == 2) {
            System.out.println("Roll over?  Really?");
            //hunger=hunger+ 1;
        }
    }

    public static void main(String[] argv) {
        // pet myDog = new pet();
        pet myDog = new pet();
        // int x = new pet();
        // myDog.play();

    }
}
