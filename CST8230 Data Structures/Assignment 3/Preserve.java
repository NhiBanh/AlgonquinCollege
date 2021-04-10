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

// TODO: Auto-generated Javadoc
/**
 * The Class Preserve.
 */
public class Preserve extends FoodItem {
	
	/** The jar size. */
	private int jarSize;

	/**
	 * Instantiates a new preserve.
	 */
	public Preserve() {}
	
	
	/**
	 * To string.
	 *
	 * @return the string
	 */
	public String toString() {
		//call parent toString and add class variable for Preserve
		return super.toString() + " size: " + this.jarSize + "mL";
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
			//prompt for size of jar
			while (doLoop) {
				try {
					System.out.println("Enter the size of the jar in millitres: ");
					jarSize = scanner.nextInt();
					
					scanner.nextLine();//Consume newline left-over
					flag = true;
					doLoop = false;
				} catch (Exception e) {

					System.err.flush();
					System.err.println("*****Invalid entry*****");
					System.err.flush();

					scanner.next();
				} //end try catch
			}//end while
		}else {
			flag = false;
		}//end else
		return flag;
	}//end method addItem
}//end class Preserve
