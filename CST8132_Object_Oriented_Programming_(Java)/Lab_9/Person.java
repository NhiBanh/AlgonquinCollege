/*
 * Course: 20F_CST8132 Intro to Computer programming.
 * Section: 300 & 301.
 * Lab : 9.
 * Student: Nhi Banh.
 */
package Lab9;

import java.util.Scanner;

/**
 * The Class Person.
 */

public abstract class Person {

	/** The first name. */
	//Instance variables
	protected String firstName;

	/** The last name. */
	protected String lastName;

	/** The email. */
	protected String email;

	/** The phone number. */
	protected long phoneNumber;


	/**
	 * Instantiates a new person.
	 */
	//no-arg construction
	public Person() {
	}

	/**
	 * Instantiates a new person.
	 *
	 * @param firstName the first name
	 * @param lastName the last name
	 * @param email the email
	 * @param phoneNumber the phone number
	 */
	//parameterized constructor
	public Person (String firstName, String lastName, String email, long phoneNumber) {
		this.firstName = firstName;
		this.lastName = lastName;
		this.email = email;
		this.phoneNumber = phoneNumber;
	}

	/**
	 * Read info.
	 *
	 * @param input the input
	 */
	public abstract void readInfo(Scanner input);

	/**
	 * Prints the info.
	 */
	public abstract void printInfo();


} // end Person class
