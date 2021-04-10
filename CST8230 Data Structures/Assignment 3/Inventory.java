/**
 * Assignment 3 - Inventory Management with Sorting.
 *
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
import java.util.*;

/**
 * The Class Inventory.
 */
public class Inventory {

	/** The inventory. */	
	protected ArrayList<InventoryItem> inventory = new ArrayList<InventoryItem>();

	/** The num items. */
	private int numItems = 0;

	/**
	 * Instantiates a new inventory.
	 */
	public Inventory() {}

	/**
	 * To string.
	 *
	 * @return the string
	 */
	@Override
	public String toString() {
		String output = "Inventory: \r\n";

		//only print if there are items
		if(numItems > 0) {
			//for loop to go through each item, add to output string
			for(int i = 0; i < numItems; i++) {
				output += inventory.get(i).toString() + "\r\n";
			}//end for
		}//end if
		return output;
	}//end method toString

	/**
	 * Already exists.
	 *
	 * @param item the item
	 * @return the int
	 */
	public int alreadyExists (FoodItem item) {
		int match = -1; // index for match

		//only search when there are item
		if(numItems > 0) {

			InventoryItem itemInven = new InventoryItem(item);
			match = Collections.binarySearch(inventory, itemInven);
			
			if(match < 0) {
				match = -1;
			}

		}//end if
		return match; // pass whole class
	}//end method alreadExists

	/**
	 * Adds the item.
	 *
	 * @param scanner the scanner
	 * @return true, if successful
	 */
	public boolean addItem (Scanner scanner) {
		boolean doLoop = true;
		boolean flag = true;
		String option = "";


		if (numItems >= 20) {
			System.out.println("Inventory is full");
			flag = false;
		} else {
			while(doLoop) {
				try {

					System.out.print("Do you wish to add a fruit(f), vegetable(v), sweetener(s), or a preserve(p)?");
					option = scanner.next();

					//if option is fruit
					if (option.equals("f")) {
						//create new fruit
						Fruit addFruit = new Fruit();
						
						InventoryItem inventoryItem = new InventoryItem(addFruit);
					
						//add itemcode to fruit then check if item exists already
						if(inventoryItem.inputCode(scanner)) {

							//check if item is in array
							if(alreadyExists(addFruit) == -1) {
								//add other fields
								addFruit.addItem(scanner);

								inventoryItem.addItem(scanner);
								inventory.add(inventoryItem);

								numItems++;//increment the item count
							}else {
								//item exists
								System.out.println("Item code already exists");
								flag = false;
							}//end else

						}else {
							flag = false;	
						}//end else

						doLoop = false;//exit loop
					} else if (option.equals("v")) { //if option is vegetable
						//create new Vegetable
						Vegetable addVegetable = new Vegetable();

						InventoryItem inventoryItem = new InventoryItem(addVegetable);

						//add itemcode to vegetable then check if item exists already
						if(inventoryItem.inputCode(scanner)) {

							//check if item is in array
							if(alreadyExists(addVegetable) == -1) {
								//add other fields
								addVegetable.addItem(scanner);
								inventoryItem.addItem(scanner);

								inventory.add(inventoryItem);

								numItems++;//increment the item count
							}else {
								//item exists
								System.out.println("Item code already exists");
								flag = false;
							}//end else

						}else {
							flag = false;	
						}//end else

						doLoop = false;//exit loop
					} else if (option.equals("s")) { //if option is Sweetener
						Sweetener addSweetener = new Sweetener();
						InventoryItem inventoryItem = new InventoryItem(addSweetener);


						//add itemcode to sweetener then check if item exists already
						if( inventoryItem.inputCode(scanner)) {

							//check if item is in array
							if(alreadyExists(addSweetener) == -1) {
								//add other fields
								addSweetener.addItem(scanner);
								inventoryItem.addItem(scanner);


								//add the item to the food item array
								inventory.add(inventoryItem);

								numItems++;//increment the item count
							}else {
								//item exists
								System.out.println("Item code already exists");
								flag = false;
							}//end else
						}else {
							flag = false;	
						}//end else
						doLoop = false;//exit loop						
					} else if (option.equals("p")) { //if option is preserve
						Preserve addPreserve = new Preserve();
						InventoryItem inventoryItem = new InventoryItem(addPreserve);


						//add itemcode to preserve then check if item exists already
						if(inventoryItem.inputCode(scanner)) {

							//check if item is in array
							if(alreadyExists(addPreserve) == -1) {
								//add other fields
								addPreserve.addItem(scanner);
								inventoryItem.addItem(scanner);


								//add the item to the food item array
								inventory.add(inventoryItem);

								numItems++;//increment the item count
							}else {
								//item exists
								System.out.println("Item code already exists");
								flag = false;
							}//end else
						}else {
							flag = false;	
						}//end else
						doLoop = false;//exit loop		
					} else {
						System.out.println("Invalid Entry");
					}//end else
				} catch (Exception e) {

					System.err.flush();
					System.err.println("*****Invalid inventory entry*****");
					System.err.flush();

					scanner.next();
				}//end catch
			}//end while loop
		}//end else
		
		if ( numItems > 1) {
			//sort ArrayList 
			Collections.sort(inventory);
		}
		
		return flag;
	}//end method addItem

	/**
	 * Update quantity.
	 *
	 * @param scanner the scanner
	 * @param buyOrSell the buy or sell
	 * @return true, if successful
	 */
	public boolean updateQuantity (Scanner scanner, boolean buyOrSell) {
		boolean flag = true;
		int quantity;
		int itemIndex;
		//check if array has at least 1 entry
		if(numItems > 0){

			//create new food item to use to check for existance of item code
			FoodItem fItem = new FoodItem();
			InventoryItem inventoryItem = new InventoryItem(fItem);

			//prompt for item code
			if(inventoryItem.inputCode(scanner)) {

				//check if food item with that code exists
				itemIndex = alreadyExists(fItem);
				if(itemIndex > -1) {	
					//item exists
					if(buyOrSell) {	
						//prompt for quantity to buy
						try {
							System.out.println("Enter the quantity to buy:");
							quantity = scanner.nextInt();

							//check that quantity is valid 
							if(quantity > 0) {
								//update quantity
								//	inventory[itemIndex].updateItem(quantity);

								inventory.get(itemIndex).updateQuantity(scanner, quantity);

							}else {
								System.out.println("Invalid quantity...");
								flag = false;
							}//end else
						} catch (Exception e) {
							System.err.flush();
							System.err.println("Invalid quantity...");
							System.err.flush();

							scanner.next();
						}//end catch
					}else {//selling action
						//prompt for quantity to sell
						try {
							System.out.println("Enter the quantity to sell:");
							quantity = scanner.nextInt();

							//check that quantity is valid 
							if(quantity > 0) {
								//update quantity (passing as negative value
								boolean upresult = inventory.get(itemIndex).updateQuantity(scanner, quantity * -1);



								//if failed (not enough stock)
								if(upresult == false) {
									System.out.println("Insufficient stock in inventory...");
									flag = false;
								}	
							}else {
								System.out.println("Invalid quantity...");
								flag = false;
							}//end else

						} catch (Exception e) {
							System.err.flush();
							System.err.println("Invalid quantity...");
							System.err.flush();

							scanner.next();
						}//end catch
					}//end else
				}else {//item does not exist
					System.out.println("Code not found in inventory...");
					flag = false;
				}//end else

			}else{
				//failed to add item code
				flag = false;
			}//end else
		}else {//no items in array
			flag = false;
		}//end else

		//print for error case
		if(flag == false) {
			if(buyOrSell) {	//sell action
				System.out.println("Error...could not buy item");
			}else {//selling action
				System.out.println("Error...could not sell item");
			}//end else
		}//end if
		return flag;
	}//end method updateQuantity

	

} // end of class 
