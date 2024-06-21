/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q1;

/**
 *
 * @author ngoth
 */
public class Point implements Shape{
    private int x;
    private int y;
    private String color;
    private String info;

    public Point(int x, int y, String color) {
        this.x = x;
        this.y = y;
        this.color = color;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    public String getInfo() {
        return info;
    }

    public void draw(){
        this.info = String.format("Point (%d,%d)", x, y);
    }
    
    public void inputData(){
        this.info = String.format("Add point(%d,%d)", x, y);
    }
}
