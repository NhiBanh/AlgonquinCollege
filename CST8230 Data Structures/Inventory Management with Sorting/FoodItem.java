/**
 * Assignment 3 - Inventory Management with Sorting.
 *
 * @author Nhi Banh.
 * Student Number:  xxx xxx xxx
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
import java.util.Scanner;

/**
 * The Class FoodItem.
 */
public class FoodItem {
	
	/** The item code. */
	protected int itemCode;
	
	/** The item name. */
	private String itemName;
	
	/** The item price. */
	private float itemPrice;
	
	/** The item quantity in stock. */
	private int itemQuantityInStock;
	
	/** The item cost. */
	private float itemCost;

	/**
	 * Instantiates a new food item.
	 */
	public FoodItem() {}
	
	/**
	 * Instantiates a new food item.
	 *
	 * @param itemcode the itemcode
	 */
	public FoodItem(int itemcode) {
		
		this.itemCode = itemcode;
	}

	/**
	 * To string.
	 *
	 * @return the string
	 */
	public String toString() {
		String price = String.format("%.2f",this.itemPrice);
		String cost = String.format("%.2f",this.itemCost);
		//add class variable to output string for display 
		String output = "Item: " + this.itemCode + " " + this.itemName;
		output += " price: $" + price + " cost: $" + cost;
		
		return output;
	}//end method toString

	/**
	 * Update item.
	 *
	 * @param amount the amount
	 * @return true, if successful
	 */
	public boolean updateItem ( int amount) {
		int quantityUpdate = this.itemQuantityInStock + amount;
		
		//check that quantity can be updated by the amount
		//has to result in number 0 or greater
		if(quantityUpdate >= 0) {
			//update the quantity
			this.itemQuantityInStock =  quantityUpdate;
			return true;
		}else {//cannot update quantity number is less than 0	
			return false;//cannot update
		}//end else
	}//end method updateItem


	/**
	 * Adds the item.
	 *
	 * @param scanner the scanner
	 * @return true, if successful
	 */
	public boolean addItem ( Scanner scanner) {
		boolean flag = true;
		boolean doLoop = true;
		
		//prompt for item name
		doLoop = true;
		while (doLoop) {
			try {
				System.out.println("Enter the name for the item:");
				itemName = scanner.nextLine();

				doLoop = false;
				//do try catch 
			} catch (Exception e) {

				System.err.flush();
				System.err.println("*****Invalid entry*****");
				System.err.flush();

				scanner.next();
			}//end try catch
		}//end while
		
	
		
		//prompt for item cost
		doLoop= true;
		while (doLoop) {
			try {
				System.out.println("Enter the cost of the item:");
				itemCost = scanner.nextFloat();

				//make sure cost is greater than 0
				if ( itemCost > 0) {
					scanner.nextLine();//Consume newline left-over
					doLoop = false;
				} else {
					System.out.println("The cost of the item much be a positive number.\nPlease retry it.");
				}//end else
			} catch (Exception e) {
				
				System.err.flush();
				System.err.println("*****Invalid entry*****");
				System.err.flush();

				scanner.next();
			}//end try catch
		}//end while
		
		//prompt for item sales price
		doLoop= true;
		while (doLoop) {
			try {
				System.out.println("Enter the sales price of the item:");
				itemPrice = scanner.nextFloat();
				
				//make sure price is greater than 0
				if ( itemPrice > 0) {
					scanner.nextLine();//Consume newline left-over 
					doLoop = false;
				} else {
					System.out.println("Sales price much be a positive number.\nPlease retry it.");
				}//end else
			} catch (Exception e) {

				System.err.flush();
				System.err.println("*****Invalid entry*****");
				System.err.flush();

				scanner.next();
			}//end try catch
		}//end while
		return flag;
	}//end method addItem
}//end class FoodItem
