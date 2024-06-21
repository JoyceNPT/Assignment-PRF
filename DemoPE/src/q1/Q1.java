/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package q1;

import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.ArrayList;
import java.util.Scanner;

public class Q1 {
    //Change the name of input and output file based on practical paper
    String inputFile = "input.txt";
    String outputFile = "output.txt";

    //--VARIABLES - @STUDENT: DECLARE YOUR VARIABLES HERE:
	int n;
        String line;
        ArrayList<String> list = new ArrayList<>();
        String result = "";
        ArrayList<Shape> listShape = new ArrayList<>();



	//--FIXED PART - DO NOT EDIT ANY THINGS HERE--
	//--START FIXED PART--------------------------    
    String fi, fo;
    
    /**
     * Set input and output file for automatic rating
     * @param args path of input file and path of output file
     */
    public void setFile (String[] args){
        fi = args.length>=2? args[0]: inputFile;
        fo = args.length>=2? args[1]: outputFile;
    }
    
    /**
     * Reads data from input file
     */
    public void read(){
        try (Scanner sc  = new Scanner(new File(fi))){
    //--END FIXED PART----------------------------

            //INPUT - @STUDENT: ADD YOUR CODE FOR INPUT HERE:
        int n = Integer.parseInt(sc.nextLine());
        for(int i = 0; i < n; i++){
            line = sc.nextLine();
            list.add(line);
        }


	//--FIXED PART - DO NOT EDIT ANY THINGS HERE--
	//--START FIXED PART--------------------------    
            sc.close();
        }catch(FileNotFoundException ex){
            System.out.println("Input Exception # " + ex);
        }
    }
    //--END FIXED PART----------------------------
    
    //ALGORITHM - @STUDENT: ADD YOUROWN METHODS HERE (IF NEED):
    

    
	//--FIXED PART - DO NOT EDIT ANY THINGS HERE--
	//--START FIXED PART--------------------------    
    /**
     * Main algorithm
     */
    public void solve(){
    //--END FIXED PART----------------------------

        //ALGORITHM - @STUDENT: ADD YOUR CODE HERE:
        for (String str : list) {
            String[] arr = str.split("\\s+");
            
            if(arr[0].equals("Point")){
                int x = Integer.parseInt(arr[1]);
                int y = Integer.parseInt(arr[2]);
                Point p = new Point(x, y, "Black");
                p.inputData();
                result += p.getInfo() + "\n";
                listShape.add(p);
            }
            else if(arr[0].equals("Line")){
                int x1 = Integer.parseInt(arr[1]);
                int x2 = Integer.parseInt(arr[2]);
                int y1 = Integer.parseInt(arr[3]);
                int y2 = Integer.parseInt(arr[4]);

                Point p1 = new Point(x1, y1, "Black");
                Point p2 = new Point(x2, y2, "Black");
                StraightLine s = new StraightLine(p1, p2, "Black");
                s.inputData();
                result += s.getInfo() + "\n";
                listShape.add(s);
            }
            else if(arr[0].equals("Draw")){
                result += "---Draw---\n";
                for (Shape shape : listShape) {
                    shape.draw();
                    result += shape.getInfo() + "\n";
                }
                result += "-------\n";
            }
            else if(arr[0].equals("Clear")){
                listShape.clear();
            }
        }

        System.out.println(result);
	//--FIXED PART - DO NOT EDIT ANY THINGS HERE--
	//--START FIXED PART-------------------------- 
    }
    
    /**
     * Write result into output file
     */
    public void printResult(){
	    try{
            FileWriter fw = new FileWriter(fo);
	//--END FIXED PART----------------------------
                
        	//OUTPUT - @STUDENT: ADD YOUR CODE FOR OUTPUT HERE:
            fw.write(result);



	//--FIXED PART - DO NOT EDIT ANY THINGS HERE--
	//--START FIXED PART-------------------------- 
            fw.flush();
            fw.close();
        }catch (IOException ex){
            System.out.println("Output Exception # " + ex);
        }
    }

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        // TODO code application logic here
        Q1 q = new Q1();
        q.setFile(args);
        q.read();
        q.solve();
        q.printResult();
    }
	//--END FIXED PART----------------------------    
}
