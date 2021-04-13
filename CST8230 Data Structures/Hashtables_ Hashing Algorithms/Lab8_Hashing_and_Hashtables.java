package Lab8;
/**
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */

import java.util.*;
import java.io.*;

public class Lab8_Hashing_and_Hashtables {
	public static final Scanner input = new Scanner(System.in);

	public static void main(String[] args) {
    boolean mainLoop = true;
		int menuOption = 0;

    String[] dataBucket = new String[100];

		//main loop for the program.
		while(mainLoop){
			try {
        //display menu option to user
				System.out.println("1. Add");
				System.out.println("2. Search");
				System.out.println("3. Delete");
				System.out.println("4. Display entire hashtable");
  			System.out.println("5. Exit");
				System.out.print(">");
				menuOption = input.nextInt();

      } catch (Exception e) {
        input.nextLine();
				System.err.flush();
				System.err.println("*****Input Mismatch Exception*****");
				System.err.flush();
			} // end of try catch

      // wrong option of menu
      if(menuOption <= 0 || menuOption > 5) {
        System.err.flush();
        System.err.println("Please choose an option between 1 and 4.\nThank you!");
        System.err.flush();
        System.out.println();
      }else{
        //option 1
        if(menuOption == 1) {
          add(dataBucket);
        } // end of option 1

        //option 2
        if(menuOption == 2) {
          search(dataBucket);
        } // end of option 2

        //option 3
        if(menuOption == 3) {
          delete(dataBucket);
        } // end of option 3

        //option 41
        if(menuOption == 4) {
          display(dataBucket);
        } // end of option 4

        //option 5
        if(menuOption == 5) {
          System.out.println("Nhi Banh has ended the program");
          //out of loop
          mainLoop = false;
          break;
        } // end of option 5
      }//end else
    }//end while
  }//end main

  public static void add(String [] dataBucket){
    boolean loop = true;

    String dataString = "";
    while(loop){
      //prompt for string
      System.out.print("Enter String: ");

      try {
        dataString = input.next();
  		} catch (Exception e) {
        System.err.flush();
        System.err.println("*****Input Mismatch Exception*****");
        System.err.flush();
      }

      //calculate sum for index
      int sum = 0;

      //go through each char in string
      for(int i = 0; i < dataString.length(); i++){
        char c = dataString.charAt(i);
        sum += (int) c;
      }

      //set to number between 0 and 99
      sum = sum % 100;

      //check if value exists at index
      if( dataBucket[sum] != null ){
        //loop until last index, if needed
        while(sum <= 99){
          //check if index is empty
          if(dataBucket[sum] == null){
            //set the value
            dataBucket[sum] = dataString;
            System.out.println("entered at " + sum);
            loop = false;//exit loop
            break;//break out of loop
          }
          sum++;//increment sum (for next available index)
        }

        //if index is at 99 print message cannot be added
        if(sum == 100){
          System.out.println("String cannot be added");
          loop = false;//exit loop
          break;
        }

      }else{
        //set the value
        dataBucket[sum] = dataString;
        System.out.println("entered at " + sum);
        loop = false;//exit loop
      }
    }
  }//end method

  public static void search(String [] dataBucket){
    boolean loop = true;

    String dataString = "";
    while(loop){
      //prompt for string
      System.out.print("Enter String: ");

      try {
        dataString = input.next();
      } catch (Exception e) {
        System.err.flush();
        System.err.println("*****Input Mismatch Exception*****");
        System.err.flush();
      }

      boolean found = false;
      int index = 0;

      for (int i = 0; i<dataBucket.length; i++) {
        if(dataBucket[i] != null){
          if (dataBucket[i].equals(dataString)) {
              index = i;
              found = true;
              break;//vreak for loop
          }
        }
      }

      if(found == true){
        System.out.println(dataString + " found at index " + index);
        loop = false;
        break;
      }else{
        System.out.println(dataString + " not found");
        loop = false;
        break;
      }
    }//end while
  }//end method

  public static void delete(String [] dataBucket){
    boolean loop = true;

    String dataString = "";
    while(loop){
      //prompt for string
      System.out.print("Enter String: ");

      try {
        dataString = input.next();
      } catch (Exception e) {
        System.err.flush();
        System.err.println("*****Input Mismatch Exception*****");
        System.err.flush();
      }

      boolean found = false;
      int index = 0;
      for (int i=0; i<dataBucket.length; i++) {
        if(dataBucket[i] != null){
          if (dataBucket[i].equals(dataString)) {
              index = i;
              found = true;
              break;//break for loop
          }
        }
      }

      if(found == true){
        //delete string by setting to null
        dataBucket[index] = null;
        System.out.println(dataString + " deleted at index " + index);
        loop = false;
        break;
      }else{
        System.out.println(dataString + " not found");
        loop = false;
        break;
      }
    }//end while
  }//end method

  public static void display(String [] dataBucket){
    System.out.println("_______________");
    System.out.println("| Index | Value  |");

    for(int i = 0; i< dataBucket.length; i++){
      if(dataBucket[i] != null){
        System.out.printf("| %-7d | %-7s |\n", i, dataBucket[i]);
      }
    }
    System.out.println("|_______________|");
  }//end method
}//end class
