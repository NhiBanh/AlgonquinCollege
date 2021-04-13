/*
 * Course: 20F_CST8132 Intro to Computer programming.
 * Section: 300 & 301.
 * Lab : 9.
 * Student: Nhi Banh.
 */
package Lab9;
import java.io.IOException;
import java.nio.file.NoSuchFileException;
import java.nio.file.Paths;
import java.util.ArrayList;
import java.util.NoSuchElementException;
import java.util.Scanner;

/*
 * Section: 300 & 301.
 * Lab : 3.
 * Due day: 09/29/2020.
 * Student: Nhi Banh.
 * #ID: 040 932 192.
 */

/**
 * The Class Store.
 */
public class Store {

	/** The employees. */
	//Instance variables: an array of Employee named employees.
	//	private Employee [] employees ;

	private ArrayList<Employee> employees = new ArrayList<Employee>();

	/** The count. */
	private static int count;

	/**
	 * Instantiates a new store.
	 */
	/*Constructor:
	 * parameterized constructor that creates the array of employees
	 * with the given size (this size will be read in main(),
	 * and will be sent here when creating the Store object)
	 */
	public Store () {

	} // end constructor method

	/*readEmployeeDetails():
	 * accepts nothing, returns nothing.
	 * In a for loop, read details of all employees.
	 * First, read the type of the employee.
	 * Based on the type of the employee,
	 * corresponding array object needs to be created (Polymorphism).
	 * Then, call readEmployee() method*/

	/**
	 * Read details.
	 *
	 * @param input the input
	 */
	public void readDetails(Scanner input) {
		/*
		 * if (count == employees.size()) {
		 * System.out.println("All employees info has been entered."); } else {
		 */

		boolean continueLoop = true;
		while (continueLoop) {
			try {
				System.out.println("Enter details of employee " + (count +1));
				System.out.println("1. Regular");
				System.out.println("2. Contractor");
				System.out.print("Enter type of employee: ");
				int typeEmployee = input.nextInt();


				if (typeEmployee == 1) {

					//	employees[count] = new Regular();
					employees.add(new Regular());

				} else if (typeEmployee == 2) {

					//	employees[count] = new Contractor();

					employees.add(new Contractor());

				} else {
					System.out.println("Your type of employee is wrong. \nPlease try it again. \nThank you!");
					System.out.println("1.. Regular\n2.. Contract \nEnter type of employee: ");
					typeEmployee = input.nextInt();
				}

				//	employees[count].readInfo(input);
				employees.get(count).readInfo(input);

				count++;
				continueLoop = false;
			}
			catch (Exception e) {
				System.err.flush();
				System.err.println("*****Input Mismatch Exception while reading number of employees*****");
				System.err.flush();
				input.next();
			} // end catch
		} //end while
		//	} //end else
	} // end the method


	/**
	 * Prints the details.
	 */
	/* printEmployeeDetails(): accepts nothing, returns nothing.
	 * In a for loop, call printEmployee() to print details of all employees
	 * */
	public void printDetails(){
		for (int i = 0; i < count; i++) {

			//	employees[i].printInfo();
			employees.get(i).printInfo();

		} //end for loop
	} // end printDetails method

	/**
	 * Prints the line.
	 */
	/*printLine(): static method that prints a line using "="*/
	public static void printLine() {
		System.out.println("=========================================================================================");
		/*
		 * for (int i = 0; i < 80; i++) { System.out.print("="); System.out.println(); }
		 */
	} // end printLine method

	/*printTitle(): static method that prints the title of the output.
	 * this method gets the name of the store as a parameter,
	 * which will be used in the formatted print statement.
	 * printLine() method will be called from will be called
	 * from this method to print lines*/

	/**
	 * Prints the title.
	 *
	 * @param storeName the store name
	 */
	public static void printTitle(String storeName) {
		printLine();
		System.out.printf("%30s Store Management System\n",storeName);
		printLine();
	} //end printTitle method

	/**
	 * Open file.
	 *
	 * @param input the input
	 */
	public void openFile(Scanner input) {
		try {

			input = new Scanner(Paths.get("src/lab8/employees.txt"));
			readInfoFromFiles(input);

		} catch (NoSuchFileException fe) {

			System.err.flush();
			System.err.println("File not found");
			System.err.flush();

		} catch (IOException ioe) {

			System.out.println(ioe);
		} //end catch

	} // end openFile method

	/**
	 * Read info from files.
	 *
	 * @param input the input
	 */
	public void readInfoFromFiles(Scanner input) {
		try {
			while( input.hasNext()) { // go until the end of fiel
				//	if (arrayIsFull()) {
				//		break;
				//	} else {
				String type = input.next();
				if (type.equals("r")) {
					//add regular eployee
					//	employees [count] = new Regular (input.nextInt(), input.next(), input.next(), input.next(), input.nextLong(), input.nextDouble());
					employees.add(new Regular (input.nextInt(), input.next(), input.next(), input.next(), input.nextLong(), input.nextDouble()));
					count++;

				} // end if == r

				if (type.equals("c")) {
					//	employees [count] = new Contractor(input.nextInt(), input.next(), input.next(), input.next(),input.nextLong(), input.nextDouble(), input.nextDouble());
					employees.add(new Contractor(input.nextInt(), input.next(), input.next(), input.next(),input.nextLong(), input.nextDouble(), input.nextDouble()));
					count++;
				} //end if == c

				//	}	// end else
			} // end while loop
		} catch (NoSuchElementException e) {

			System.out.println("No such element in file");

		} catch (IllegalStateException e) {

			System.out.println("Scanner closed");
			e.printStackTrace();
			e.getMessage();

		} //end catch
	} // end of readInfoFromFiles


	/**
	 * Close file.
	 *
	 * @param input the input
	 */
	public void closeFile (Scanner input) {
		if (input != null) {

			input.close();

		} // end of if
	} // end of closeFile method

	/**
	 * Array is full.
	 *
	 * @return true, if successful
	 */
	public boolean arrayIsFull () {
		if (employees.size() == count ) {
			return true;
		} else {
			return false;
		} // end else if
	} // end arrayIsFull method

	/**
	 * Array is empty.
	 *
	 * @return true, if successful
	 */
	public boolean arrayIsEmpty () {

		if ( count == 0 ) {
			return true;
		} else {
			return false;
		}// end else if
	} // end arryIsEmpty method


} //end Store class
