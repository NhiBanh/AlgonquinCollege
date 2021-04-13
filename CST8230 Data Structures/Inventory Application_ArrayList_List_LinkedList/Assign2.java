import java.util.Scanner;


/**
 * Assignment 2 - Inventory Management System by using Arraylist and Linked list.
 *
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
/**
 * The Class Assign2.
 */
public class Assign2 {

	/** The scanner. */
	public static Scanner scanner = new Scanner(System.in);

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {
		int menuOption;
		boolean flag = true;
		Inventory inventory = new Inventory();
		
		while (flag) {
			try {
				
				displayMenu();
				menuOption = scanner.nextInt();
				
				//check for incorrect value
				if (menuOption < 1 || menuOption > 6) {	
					
					System.out.println("Incorrect value entered");		
				}//end if

				//option 1 - add item
				if (menuOption == 1) {
					inventory.addItem(scanner);		
				}//end if

				//option 2 - print
				if (menuOption == 2) {
					//print all items in inventory array
					System.out.println(inventory.toString());
				}//end if

				//option 3 - buy item
				if (menuOption == 3) {
					//call buy action to update item quantity
					inventory.updateQuantity(scanner, true);
				}//end if

				//option 4 - sell item
				if (menuOption == 4) {
					//call sell action to update item quantity
					inventory.updateQuantity(scanner, false);
				}//end if
				
				if(menuOption == 5) {
					inventory.toLinkedList();
				}
				
				//option 5 to exit
				if (menuOption == 6) {
					System.out.println("Exiting...");
					flag = false;
					break;
				}//end if

			} catch (Exception e) {

				System.err.flush();
				System.err.println("*****Input Mismatch Exception*****");
				System.err.flush();

				scanner.next();
			}//end try catch
		}//end while
	} // end main class

	/**
	 * Display menu.
	 */
	public static void displayMenu() {
		System.out.println("Please select one of the following: ");
		System.out.println("1. Add item to inventory");
		System.out.println("2. Display current to inventory");
		System.out.println("3. Buy item(s)");
		System.out.println("4. Sell item(s)");
		System.out.println("5. Convert ArrayList to Linkedlist and print it.");
		System.out.println("6. To exit");
		System.out.print("> ");
	}
}
