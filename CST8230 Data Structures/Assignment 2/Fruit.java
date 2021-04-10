/**
 * Assignment 2 - Inventory Management System by using Arraylist and Linked list
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
import java.util.Scanner;

/**
 * The Class Fruit.
 */
public class Fruit extends FoodItem {
	
	/** The orchard name. */
	private String orchardName;
	
	/**
	 * Instantiates a new fruit.
	 */
	public Fruit () {}

	/**
	 * To string.
	 *
	 * @return the string
	 */
	public String toString() {
		//call parent toString and add class variable for fruit
		return super.toString() + " orchard supplier: " + orchardName;
	}//end method toString

	/**
	 * Adds the item.
	 *
	 * @param scanner the scanner
	 * @return true, if successful
	 */
	public boolean addItem( Scanner scanner) {
		boolean doLoop = true;
		boolean flag = true;
		
		//do parent addItem
		if(super.addItem(scanner)) {
			//prompt for orchard supplier
			while (doLoop) {
				try {
					System.out.println("Enter the name of the orchard supplier: ");
					orchardName = scanner.nextLine();
					
					//make sure name is not empty
					if(orchardName.isEmpty()) {
						System.out.println("Invalid entry");
					} else {
						flag = true;
						doLoop = false;
					}//end else
				} catch (Exception e) {

					System.err.flush();
					System.err.println("*****Invalid food entry*****");
					System.err.flush();

					scanner.next();
				} //end try catch
			}//end while
		}else {
			flag = false;
		}//end else
		return flag;
	}//end method addItem
}//end class Fruit

