/**
 * Assignment 3 - Inventory Management with Sorting.
 *
 * @author Nhi Banh.
 * Student Number:  xxx xxx xxx
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
import java.time.LocalDate;
import java.time.format.DateTimeFormatter;
import java.time.format.DateTimeParseException;
import java.util.*;


/**
 * The Class InventoryItem.
 */
public class InventoryItem implements Comparable<InventoryItem> {
	
	/** The item quantity in stock. */
	private int itemQuantityInStock;
	
	/** The item. */
	private FoodItem item = new FoodItem();
	
	/** The expiries. */
	private Queue<LocalDate> expiries = new LinkedList<>();
	
	
	/**
	 * Instantiates a new inventory item.
	 *
	 * @param fitem the fitem
	 */
	public InventoryItem( FoodItem fitem) {
		this.item = fitem;
	}
	
	/**
	 * Adds the item.
	 *
	 * @param scanner the scanner
	 * @return true, if successful
	 */
	public boolean addItem(Scanner scanner) {	
		boolean flag = true;
		boolean doLoop = true;
		
		//prompt for item quantity
		doLoop= true;
		while (doLoop) {
			try {
				System.out.println("Enter the quantity for the item:");
				itemQuantityInStock = scanner.nextInt();
				
				//make sure quantity is greater or = to 0
				if ( itemQuantityInStock > 0) {
					scanner.nextLine();//consume the newline
					doLoop = false;
				} else {
					System.out.println("The quantity item much be a positive number.\nPlease retry it.");
				}//end else
			} catch (Exception e) {

				System.err.flush();
				System.err.println("*****Invalid entry*****");
				System.err.flush();

				scanner.next();
			}//end try catch
		}//end while
		
		//prompt for item quantity date
		doLoop= true;
		String date;
		LocalDate day = LocalDate.now();
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");

		
		while (doLoop) {
			try {
				System.out.println("Enter the expiry date of the item (yyyy-mm-dd or none): ");
				date = scanner.next();
				
				if (date.equals("none") || date == "none") {
					day = LocalDate.MAX;
					
				} else {
					day = LocalDate.parse(date, formatter);
					
				} //end if else 
				

				//add expiries for amount of item quantity in Stock
				for (int i = 0; i < itemQuantityInStock; i++) {
					
					expiries.add(day);
				}
				
				doLoop = false;
				
			} catch (DateTimeParseException dayException) {
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
		}//end while
		
	
	
		return flag;
	}
	
	/**
	 * Gets the item code.
	 *
	 * @return the item code
	 */
	public int getItemCode() {
		return item.itemCode;
	}
	
	/**
	 * Input code.
	 *
	 * @param scanner the scanner
	 * @return true, if successful
	 */
	public boolean inputCode(Scanner scanner) {
		boolean flag = true;
		boolean doLoop = true;
		
		//prompt for input code
		while (doLoop) {
			try {
				System.out.println("Enter the code for the item:");
				item.itemCode = scanner.nextInt();
				
				scanner.nextLine();//Consume newline left-over
				doLoop = false;
				//do try catch 
			} catch (Exception e) {

				System.err.flush();
				System.err.println("*****Invalid entry*****");
				System.err.flush();
			
				scanner.next();
			}//end try catch
		}//end while
		return flag;
		
	}
	
	/**
	 * Prints the expiry summary.
	 *
	 * @param scanner the scanner
	 */
	public void printExpirySummary(Scanner scanner) {

				
		Map<LocalDate,Integer> expidayMap = new HashMap<LocalDate, Integer>();
		Integer val;
		
		for (LocalDate i: expiries) {
			
			 val = expidayMap.get(i);
			
			if (val==null) {
				expidayMap.put(i,1);	
				
			} else {
				
				expidayMap.put(i, val+=1);
			}
		}
		
		System.out.println("Expiry Details:");
		
		for(Map.Entry<LocalDate, Integer> itm: expidayMap.entrySet()) {
			
			if(itm.getKey().isEqual(LocalDate.MAX)) {
				System.out.print("No Expiry: ");
			}else {
				System.out.print(itm.getKey()+": ");
			}
			System.out.print(itm.getValue()+"\n");
		}
		
	}
	
	/**
	 * Removes the expired items.
	 *
	 * @param today the today
	 */
	public void removeExpiredItems (LocalDate today) {
		Queue<LocalDate> newExpiries = new LinkedList<>();
	
		for(LocalDate itemDate: expiries) {
			if(itemDate.isAfter(today)|| itemDate.isEqual(today)) {
				newExpiries.add(itemDate);
			}
		}
		
		expiries = newExpiries;
		itemQuantityInStock = expiries.size();
		
	}
	
	/**
	 * Update quantity.
	 *
	 * @param scanner the scanner
	 * @param amount the amount
	 * @return true, if successful
	 */
	public boolean updateQuantity(Scanner scanner, int amount ) {
		Boolean flag = false;
		DateTimeFormatter formatter = DateTimeFormatter.ofPattern("yyyy-MM-dd");
		
		//check if sell (quantity is negative)
		if(amount < 0) {
			//selling
			if(amount > itemQuantityInStock) {
				flag = false;
			}else {
				
				itemQuantityInStock += amount;
				
				for(int i = 0; i<amount; i++) {
					
					expiries.remove();
				}
				flag = true;
			}
	
		}else {
			LocalDate day = LocalDate.now();
			String date;
			//buying 
			boolean doLoop = true;
			while (doLoop) {
				try {
					
					System.out.println("Enter the expiry date of the item (yyyy-mm-dd or none): ");
					date= scanner.next();
					 
					if (date.equals("none") || date == "none") {
						day = LocalDate.MAX;
						
					} else {
						day = LocalDate.parse(date, formatter);
					} //end if else 
					
					//update quantity
					itemQuantityInStock+= amount;
					
					//add expiries for amount of item quantity in Stock
					for (int i = 0; i < amount; i++) {
						expiries.add(day);
					}
					
					flag = true;
					doLoop = false;
				} catch (DateTimeParseException dayException) {
				
					System.out.println("Could not create date from input, please use format yyyy-mm-dd");
					System.out.println("Text '" + dayException.getParsedString() + "' could not be parsed at index " + dayException.getErrorIndex() );

					scanner.nextLine();
				
				} catch (Exception e) {

					System.err.flush();
					System.err.println("*****Invalid Entry*****");
					System.err.flush();

					scanner.next();
				}
			}//end while
		}
		return flag;
	}
	
	/**
	 * To string.
	 *
	 * @return the string
	 */
	public String toString() {
		String output = item.toString() + " qty: " + this.itemQuantityInStock;
		return output;
	}

	/**
	 * Compare to.
	 *
	 * @param item the item
	 * @return the int
	 */
	@Override
	public int compareTo(InventoryItem item) {
		int compareCode = item.getItemCode();
		
		return this.getItemCode() - compareCode;
	}

	

}
