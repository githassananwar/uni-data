package problem3;
import java.util.*;

public abstract class Shape
{
    private int x;       //the x coordinate of the shape
    private int y;       //the y coordinate of the shape

    public String toString()
    {
        return "(" + x + ", " + y + ")";
    }
    public abstract double area ();
    public abstract String getName();    // returns the shape’s name
}
