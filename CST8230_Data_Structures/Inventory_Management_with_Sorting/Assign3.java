import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.*;


/**
 * Assignment 3 - Inventory Management with Sorting.
 *
 * @author Nhi Banh.
 * Student Number:  xxx xxx xxx
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
/**
 * The Class Assign3.
 */
public class Assign3 {

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
		LocalDate currentDate = LocalDate.now();
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");

		
		while (flag) {
			try {
				
				displayMenu();
				menuOption = scanner.nextInt();
				
				//check for incorrect value
				if (menuOption < 1 || menuOption > 9) {	
					
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
					int code; 
					boolean doLoop = true;
					
					
					while (doLoop) {
						try {
							System.out.println("Enter the code for the item: ");
							code = scanner.nextInt();
							
							FoodItem item = new FoodItem(code);
							
							int exists = inventory.alreadyExists(item);
							
							//check if item exists
							if(exists != -1) {
								System.out.println("Item Found:");
								inventory.inventory.get(exists).toString();
							}else {
								System.out.println("No item found. Please search again. ");
							}
							
							doLoop = false;
						
						} catch (Exception e) {

							System.err.flush();
							System.err.println("*****Invalid Entry*****");
							System.err.flush();

							scanner.next();
						}
					}
				}
				if(menuOption == 6) {
					for (InventoryItem item : inventory.inventory) {
						item.removeExpiredItems(currentDate);
					}
	
				}
				if(menuOption == 7) {
					int code; 
					boolean doLoop = true;
					
					
					while (doLoop) {
						try {
							System.out.println("Enter the code for the item: ");
							code = scanner.nextInt();
							
							FoodItem item = new FoodItem(code);
							
							
							int exists = inventory.alreadyExists(item);
							
							//check if item exists
							if(exists != -1) {
								System.out.println(inventory.inventory.get(exists).toString());
								inventory.inventory.get(exists).printExpirySummary(scanner);
							}else {
								System.out.println("No item in the stock. Please try it again. ");
							}
							
							doLoop = false;
						
						} catch (Exception e) {

							System.err.flush();
							System.err.println("*****Invalid Entry*****");
							System.err.flush();

							scanner.next();
						}
					}
				
				}
				if(menuOption == 8) {
					boolean doLoop = true;
					String dateInput;
					while (doLoop) {
						try {
						    System.out.println("Enter today's date (yyyy-mm-dd): ");
							dateInput= scanner.next();
							
							currentDate = LocalDate.parse(dateInput, formatter);
							
							doLoop=false;
							
						}  catch (DateTimeParseException dayException) {
							System.err.flush();
							System.err.println("*****Invalid Date*****");
							System.err.flush();
			               
							scanner.nextLine();
						
						} catch (Exception e) {

							System.err.flush();
							System.err.println("*****Invalid Entry*****");
							System.err.flush();

							scanner.next();
						}
						
					}
				}
				
				//option 5 to exit
				if (menuOption == 9) {
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
		System.out.println("1. Add Item to Inventory");
		System.out.println("2. Display Current Inventory");
		System.out.println("3. Buy Item(s)");
		System.out.println("4. Sell Item(s)");
		System.out.println("5. Search for Item");
		System.out.println("6. Remove Expired Items");
		System.out.println("7. Print Expiry");
		System.out.println("8. Change Today's Date");
		System.out.println("9. To exit");
		System.out.print("> ");
	}
}
