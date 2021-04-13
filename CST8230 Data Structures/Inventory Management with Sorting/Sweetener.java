/**
 * Assignment 3 - Inventory Management with Sorting.
 *
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
import java.util.Scanner;

/**
 * The Class Sweetener.
 */
public class Sweetener extends FoodItem {
	
	/** The farm name. */
	private String farmName;
	
	/**
	 * Instantiates a new sweetener.
	 */
	public Sweetener() {}
	
	/**
	 * To string.
	 *
	 * @return the string
	 */
	//@
	public String toString() {
		//call parent toString and add class variable for Sweetener
		return super.toString() + " Sweetener supplier: " + this.farmName;	
	}//end method toString
	
	/**
	 * Adds the item.
	 *
	 * @param scanner the scanner
	 * @return true, if successful
	 */
	public boolean addItem(Scanner scanner) {
		boolean doLoop = true;
		boolean flag = true;
		
		//do parent addItem
		if(super.addItem(scanner)) {
			//prompt for farm supplier
			while (doLoop) {
				try {
					System.out.println("Enter the name of the farm supplier: ");
					farmName = scanner.nextLine();
					
					flag = true;
					doLoop = false;
				} catch (Exception e) {

					System.err.flush();
					System.err.println("*****Invalid entry*****");
					System.err.flush();

					scanner.next();
				}//end try catch
			}//end while
		}else {
			flag = false;
		}//end else	
		return flag;
	}//end method addItem
}//end class Sweetener
