/*
 * Course: 20F_CST8132 Intro to Computer programming.
 * Section: 300 & 301.
 * Lab : 9.
 * Student: Nhi Banh.
 */
package Lab9;

import java.util.Scanner;

/**
 * The Class Lab9.
 */

public class Lab9 {

	/** The input. */
	public static Scanner input = new Scanner(System.in);

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		boolean continueLoop = true;

		//read the name of the store
		System.out.print("Enter the name of the store: ");
		String storeName = input.next();
		int num = 0;

		while (continueLoop ) {
			try {
				System.out.print("How many employees do you have? ");
				num = input.nextInt();

				while (num <= 0) {
					System.out.print("How many employees do you have? ");
					num = input.nextInt();
				}

				continueLoop = false;
			}
			catch (Exception e){
				System.err.flush();
				System.err.println("*****Input Mismatch Exception while reading number of employees*****");
				System.err.flush();

				input.next();
			}
		} // end while



		//A Store object will be created with 'num'.
		//	Store a = new Store(num);
		Store a = new Store();
		int userOption = 0 ;

		//loop until quit
		while (userOption != 4) {
			try {

				System.out.println("1. Read Employee Details from the User ");
				System.out.println("2. Read Employee Details from the File ");
				System.out.println("3. Print Employee Details \n4. Quit");
				System.out.print("Enter your option: ");
				userOption = input.nextInt();


				if (userOption > 4 || userOption <= 0) {
					System.out.println("Invalid option.... please try again...\n");
				}

			}
			catch (Exception e) {

				System.err.flush();
				System.err.println("*****Input Mismatch Exception while reading number of employees*****");
				System.err.flush();

				input.next();
			}
			if (userOption == 1) {

				/*		if (a.arrayIsFull()) {

					System.out.println("\n***** Array is full.... cannot add more elements\n");

				} else { */

				a.readDetails(input);

				//	}

			}
			if (userOption == 2) {
				/*	if (a.arrayIsFull()) {

		//			System.out.println("\n***** Array is full.... cannot add more elements\n");

				} else { */

				a.openFile(input);

				//		}

			}
			if (userOption == 3) {

				if ( a.arrayIsEmpty()) {

					System.out.println("\n***** No elements in the ArrayList *****\n");

				} else {

					//print the title and the header row
					Store.printTitle(storeName);
					System.out.printf("%10s | %20s | %15s | %15s | %15s | \n", "Empl#", "Name", "Email", "Phone", "Salary" );

					//Call printEmplyee() method to print details of all employees.
					Store.printLine();
					a.printDetails();
				}

			}

			if (userOption == 4) {
				System.out.println("Goodbye...\nHave a great day!");
			}
		} //end while loop !=4
		a.closeFile(input);

	} // end the main class


} // end class
