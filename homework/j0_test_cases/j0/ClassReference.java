public class Fan {
    String name;
    double speed;
    String color;
    int numberOfSpeeds;
}

public class Room {
	String name;
    double area;
    String paintColor;
    String flooring;
    Fan ceilingFan; //Reference to other declcared class
}
