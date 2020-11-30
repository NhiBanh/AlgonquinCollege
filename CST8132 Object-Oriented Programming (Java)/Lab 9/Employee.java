/*
 * Course: 20F_CST8132 Intro to Computer programming.
 * Section: 300 & 301.
 * Lab : 9.
 * Student: Nhi Banh.
 */
package Lab9;

import java.util.Scanner;


/**
 * The Class Employee.
 */
public class Employee extends Person {

	/** The employee number. */
	private int employeeNumber;


	/**
	 * Instantiates a new employee.
	 */
	public Employee () {

	}

	/**
	 * Instantiates a new employee.
	 *
	 * @param employeeNumber the employee number
	 * @param firstName the first name
	 * @param lastName the last name
	 * @param email the email
	 * @param phoneNumber the phone number
	 */
	//parameterized constructor
	public Employee( int employeeNumber, String firstName, String lastName, String email, long phoneNumber ){
		super(firstName,lastName, email, phoneNumber);
		this.employeeNumber = employeeNumber;
	} //end parameterized constructor


	/**
	 * Read info.
	 *
	 * @param input the input
	 */
	@Override
	public void readInfo(Scanner input) {
		boolean doloop = true;

		while (doloop) {
			try {

				System.out.print("Enter employee number: ");
				this.employeeNumber = input.nextInt();
				doloop = false;
			} catch (Exception e) {

				System.out.println("*****Input Mismatch Exception while reading number of employees*****");
				input.next();
			}
		}
		doloop = true;
		while (doloop) {
			try {

				System.out.print("Enter first name: ");
				this.firstName = input.next();
				doloop = false;
			} catch (Exception e) {

				System.out.println("*****Input Mismatch Exception while reading first name*****");
				input.next();
			}
		}

		doloop = true;
		while (doloop) {
			try {

				System.out.print("Enter last name: ");
				this.lastName = input.next();
				doloop = false;
			} catch (Exception e) {

				System.out.println("*****Input Mismatch Exception while reading last name*****");
				input.next();
			}
		} // end while name

		doloop = true;
		while (doloop) {
			try {

				System.out.print("Enter email Id: ");
				this.email = input.next();
				doloop = false;
			} catch (Exception e) {

				System.out.println("*****Input Mismatch Exception while reading email ID*****");
				input.next();
			}
		}

		doloop = true;
		while (doloop) {
			try {

				System.out.print("Enter phone number: ");
				this.phoneNumber = input.nextLong();
				doloop = false;
			} catch (Exception e) {

				System.out.println("*****Input Mismatch Exception while reading phone number*****");
				input.next();
			} // end catch
		} // end while
	} // end method

	/**
	 * Prints the info.
	 */
	@Override
	public void printInfo() {
		String fullName = firstName +' '+ lastName;

		System.out.printf("%10s | %20s | %15s | %15s | ", employeeNumber, fullName , email, phoneNumber);

	}


} // end of class
