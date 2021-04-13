/*
 * Course: 20F_CST8132 Intro to Computer programming.
 * Section: 300 & 301.
 * Lab : 9.
 * Student: Nhi Banh.
 */
package Lab9;

import java.util.Scanner;

/**
 * The Class Regular.
 */
public class Regular extends Employee{

	/** The salary. */
	private double salary;

	/**
	 * Instantiates a new regular.
	 *
	 * @param employeeNumber the employee number
	 * @param firstName the first name
	 * @param lastName the last name
	 * @param email the email
	 * @param phoneNumber the phone number
	 * @param salary the salary
	 */
	//parameterized constructor
	public Regular(int employeeNumber, String firstName, String lastName, String email, long phoneNumber, double salary) {

		super(employeeNumber, firstName, lastName, email, phoneNumber);
		this.salary = salary;
	} // end parameterized constructor


	/**
	 * Instantiates a new regular.
	 */
	public Regular() {
		// TODO Auto-generated constructor stub
	}


	/**
	 * Read info.
	 *
	 * @param input the input
	 */
	/*readEmployee():
	 * accepts nothing, returns nothing.
	 * Make a call to the readEmployee() method of the parent class.
	 * Then, reads annual salary from the user,
	 * converts it to monthly salary and store it in salary instance variable*/
	@Override
	public void readInfo(Scanner input) {
		try {
			super.readInfo(input);
			System.out.print("Enter annual salary: ");
			salary = input.nextDouble();
		}  catch (Exception e) {

			System.out.println("*****Input Mismatch Exception while reading number of employees*****");
			input.next();
		}
	} // end readEmployee method


	/**
	 * Prints the info.
	 */
	/*printEmployee(): accepts nothing, returns nothing.
	 * Make a call to the printEmployee() of the parent class.
	 * Then, prints salary info (formatted output)*/
	@Override
	public void printInfo() {
		super.printInfo();
		System.out.printf( "%15.2f |\n", salary/12);
	} //end printEmployee method


} //end Regular class
