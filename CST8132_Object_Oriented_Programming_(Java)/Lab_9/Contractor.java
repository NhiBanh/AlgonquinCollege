/*
 * Course: 20F_CST8132 Intro to Computer programming.
 * Section: 300 & 301.
 * Lab : 9.
 * Student: Nhi Banh.
 */
package Lab9;

import java.util.Scanner;


/**
 * The Class Contractor.
 */
public class Contractor extends Employee {

	/** The hourly rate. */
	private double hourlyRate;

	/** The num hours. */
	private double numHours;

	/**
	 * Instantiates a new contractor.
	 *
	 * @param employeeNumber the employee number
	 * @param firstName the first name
	 * @param lastName the last name
	 * @param email the email
	 * @param phoneNumber the phone number
	 * @param hourlyRate the hourly rate
	 * @param numHours the num hours
	 */
	public Contractor(int employeeNumber, String firstName, String lastName, String email, long phoneNumber, double hourlyRate, double numHours) {
		super(employeeNumber, firstName, lastName, email, phoneNumber);
		// TODO Auto-generated constructor stub

		this.hourlyRate = hourlyRate;
		this.numHours = numHours;
	}

	/**
	 * Instantiates a new contractor.
	 */
	public Contractor() {
		// TODO Auto-generated constructor stub
	}

	/**
	 * Read info.
	 *
	 * @param input the input
	 */
	/*readEmployee(): accepts nothing, returns nothing.
	 * Make a call to the readEmployee() method of the parent class.
	 * Then, reads hourly rate and number of hours worked*/
	@Override
	public void readInfo(Scanner input) {

		super.readInfo(input);
		System.out.print("Enter hourly rate: ");
		hourlyRate = input.nextDouble();
		System.out.print("Enter number of hours worked: ");
		numHours = input.nextDouble();

	}

	/**
	 * Prints the info.
	 */
	/*printEmployee(): accepts nothing, returns nothing.
	 * Make a call to the printEmployee() of the parent class.
	 * Then, prints salary, which is the product of hourly rate
	 * and the number of hours worked (formatted output).
	 * */
	@Override
	public void printInfo() {
		super.printInfo();
		System.out.printf("%15.2f |\n", hourlyRate*numHours);
	}

}
