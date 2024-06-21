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
public class StraightLine implements Shape{
    private Point p1;
    private Point p2;
    private String color;
    private String info;

    public StraightLine(Point p1, Point p2, String color) {
        this.p1 = p1;
        this.p2 = p2;
        this.color = color;
    }

    public Point getP1() {
        return p1;
    }

    public void setP1(Point p1) {
        this.p1 = p1;
    }

    public Point getP2() {
        return p2;
    }

    public void setP2(Point p2) {
        this.p2 = p2;
    }

    public String getColor() {
        return color;
    }

    public void setColor(String color) {
        this.color = color;
    }

    @Override
    public String getInfo() {
        return info;
    }

    @Override
    public void draw(){
        this.info = String.format("Line from (x1,y1) to (x2,y2)", p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }
    
    @Override
    public void inputData(){
        this.info = String.format("Add line (x1,y1)->(x2,y2)", p1.getX(), p1.getY(), p2.getX(), p2.getY());
    }
    
    public float getLength(){
        float x = p2.getX() - p1.getX();
        float y = p2.getY() - p1.getY();
        return (float) Math.sqrt(x*x + y*y);
    }
}
