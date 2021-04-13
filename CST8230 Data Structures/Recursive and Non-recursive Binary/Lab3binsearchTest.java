package Lab3;
/**
 * This class contains a program to search for an integer in an array using recursive and non-recursive binary search.
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
import java.util.Scanner;

/**
 * The Class Lab3binsearchTest.
 */
public class Lab3binsearchTest {
	/** The Constant input. */
	public static final Scanner input = new Scanner(System.in);

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {

		int menuOption = 0;
		boolean mainLoop = true;
		int[] binArr = new int[20];
		int searchNum = 0;
		boolean initArr = false;
		Binarysearch binarysearch = new Binarysearch();

		//main loop for the program.
		while (mainLoop) {
			try {

				System.out.println("Select your option in the menu below:");
				System.out.println("1. Initialize and populate an array of 20 random integers.");
				System.out.println("2. Perform a recursive binary search.");
				System.out.println("3. Perform a non-recursive binary search.");
				System.out.println("4. Exit.");
				menuOption = input.nextInt();

				if (menuOption <= 0 || menuOption > 4) {

					System.err.flush();
					System.err.println("Please choose the option 1 to 4.\nThank you!");
					System.err.flush();
					System.out.println();
				} // end of if
				
				//option 1
				if (menuOption == 1) {
					
					//prompt user
					System.out.println("Array of randomly generated integers: ");
					binArr = binarysearch.generateRandomInts();
					initArr = true;
					
				} // end option 1
				//option 2
				if (menuOption == 2) {
					
					if(initArr == false) {
						//allert user about the initialize 
						System.out.println("Please initialize the array first (option 1), Thank you!");
					}else {
						try {

							System.out.println("Please enter an integer value to search:");
							searchNum = input.nextInt();
							
							//start time
							long startNano = System.nanoTime();
							long startMill= System.currentTimeMillis();
							
							//do recursive binary search
							binarysearch.recursiveBinarySearch(binArr,0,binArr.length-1, searchNum);
							
							//end time
							long endNano = System.nanoTime();
							long endMill= System.currentTimeMillis();
							
	                        //Print time taken for execution
							System.out.println("Time taken in nano seconds: " + (endNano - startNano));
							System.out.println("Time taken in milli seconds: " + (endMill - startMill)+ "\r\n");
							
						} catch (Exception e) {

							System.err.flush();
							System.err.println("*****Input Mismatch Exception*****");
							System.err.flush();

							input.next();
						} // end try catch
					} // end of if else
				} // option 3
				
				//option 3
				if (menuOption == 3) {
					if(initArr == false) {
						System.out.println("Please initialize the array first (option 1), Thank you!");
					}else {
						try {
							
							System.out.println("Please enter an integer value to search:");
							searchNum = input.nextInt();
							
							//start time
							long startNano = System.nanoTime();
							long startMill= System.currentTimeMillis();
							
							
							binarysearch.nonRecursiveBinarySearch(binArr, searchNum);
							
							//end time
							long endNano = System.nanoTime();
							long endMill= System.currentTimeMillis();
							
					        //Print time taken for execution
							System.out.println("Time taken in nano seconds: " + (endNano - startNano));
							System.out.println("Time taken in milli seconds: " + (endMill - startMill)+ "\r\n");
							
						} catch (Exception e) {

							System.err.flush();
							System.err.println("*****Input Mismatch Exception*****");
							System.err.flush();

							input.next();
						} //end of try catch 
					} // end else if 
				}// end option 3}
				
				//option 4
				if (menuOption == 4) {
					
					System.out.println("Exiting...");
					
					mainLoop = false; // break loop
					break; //sure about loop is beak
					
				} // end option 4
				
			} catch (Exception e) {

				System.err.flush();
				System.err.println("*****Input Mismatch Exception*****");
				System.err.flush();

				input.next();

			} //end try catch 
		} // end while 
	} // end of main class
} // end Lab3binsearchTest class
