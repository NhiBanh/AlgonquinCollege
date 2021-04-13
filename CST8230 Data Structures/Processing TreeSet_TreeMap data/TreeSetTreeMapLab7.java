package Lab7;
/**
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */

import java.util.*;
import java.io.*;
import java.nio.file.NoSuchFileException;
import java.nio.file.Paths;

public class TreeSetTreeMapLab7 {

	public static final Scanner input = new Scanner(System.in);
	public static TreeSet<Integer> treeSet = new TreeSet<Integer>();
	public static TreeSet<String> treeSetString = new TreeSet<String>();
	public static TreeMap<Integer, String> treeMap = new TreeMap<Integer,String>();

	public static void main(String[] args) {

		boolean mainLoop = true;
		int menuOption = 0;
		int count = 0;

		//main loop for the program.
		while(mainLoop) {

			try {
				//display menu option to user
				System.out.println("1. Create a TreeMap of data from the text file.");
				System.out.println("2. Display The TreeMap.");
				System.out.println("3. Search for a given key or value in the TreeMap.");
				System.out.println("4. Create and display a keys TreeSet and a values TreeSet from the TreeMap.");
				System.out.println("5. Add new key-value data to the TreeMap.");
				System.out.println("6. Sort and display values TreeSet in descending order.");
				System.out.println("7. Exit");
				System.out.print(">");
				menuOption = input.nextInt();
				input.nextLine();

			} catch (Exception e) {

				System.err.flush();
				System.err.println("*****Input Mismatch Exception*****");
				System.err.flush();

				input.next();

			} // end of try catch

			// wrong option of menu
			if(menuOption <= 0 || menuOption > 7) {

				System.err.flush();
				System.err.println("Please choose the option 1 to 7.\nThank you!");
				System.err.flush();
				System.out.println();

			} // end of if menu option smaller or equals 0 or menu option greater than 4

			//option 1
			if(menuOption == 1) {
				System.out.println("....TreeMap created....");
				populateTreeMap(input);

			} // end of option 1

			//option 2
			if(menuOption == 2) {
				System.out.println(treeMap.toString());
				System.out.print("");
			} // end of option 2

			//option 3
			if(menuOption == 3) {
				int key = 0 ;

				try{

					System.out.println("Enter a key to search");
					key = input.nextInt();

				} catch (Exception e) {

					System.err.flush();
					System.err.println("*****Input Mismatch Exception*****");
					System.err.flush();

					input.next();

				} // end of try catch

				if ( treeMap.containsKey(key)) {

					System.out.println("....key "+ key +" if found " );

				} else {
					System.out.println("....key "+ key +" is not found " );
				} // end of else if

			} // end of option 3
			//option 4
			if(menuOption == 4) {
				treeSet = new TreeSet<Integer>();//create new TreeSet for keys;
				treeSetString = new TreeSet<String>();//create new TreeSet for values;

				for(Map.Entry<Integer, String> entry : treeMap.entrySet()) {
				  Integer key = entry.getKey();
				  String value = entry.getValue();

					treeSet.add(key);
					treeSetString.add(value);
				}
				System.out.println("Key TreeSet is: " + treeSet.toString());
				if(count > 0){
					System.out.println("More keys have been added, set is larger");
				}
				System.out.println("Names TreeSet is: " + treeSetString.toString());
				if(count > 0){
					System.out.println("Duplicate names are not displayed so set is same size");
				}
				count++;
			} // end of option 4

			//option 6
			if(menuOption == 5) {
				String inputString = "";
				String[] inputArr = new String [2];
				String name ;
				int key;
				boolean flag = true;

				while (flag) {
					try {
						System.out.println("Enter key-value data: ");
						inputString=input.nextLine();
						inputArr = inputString.split(",", 2);

						if(inputArr.length < 2) {
							System.out.println("Invalid. Please provide name and key.");
						} else {
							name = inputArr[0];
							key = Integer.parseInt( inputArr[1].replaceAll("\\s+","") );
							treeMap.put(key, name);
							flag = false;
						}

					} catch (Exception e) {
						e.printStackTrace();
						System.err.flush();
						System.err.println("*****Input Mismatch Exception*****");
						System.err.flush();

						input.next();
					}
				}

			} // end of option 6

			//option 5
			if(menuOption == 6) {
				System.out.println("...Names Treeset was sorted in descending order...");

				System.out.println(treeSetString.descendingSet().toString());
			} // end of option 5

			//option 7
			if(menuOption == 7) {

				System.out.println("Exiting...");
				//out of loop
				mainLoop = false;
				break;

			} // end of option 7
		} //ens of mainLoop
		input.close();
	}

	public static void populateTreeMap (Scanner input) {
		try {

			input = new Scanner(Paths.get("src/lab7/productowners.txt"));
		
			readInfoFromFiles( input);

		} catch (NoSuchFileException fe) {

			System.err.flush();
			System.err.println("File not found");
			System.err.flush();

		} catch (IOException ioe) {

			System.out.println(ioe);
		} //end catch

	}

	public static void readInfoFromFiles(Scanner input) {
		try {
			while(input.hasNext()) {
				String firstName = input.next();
				String lastName = input.next();
				int key = input.nextInt();

				treeMap.put(key, firstName +' ' + lastName);

			}

		} catch (NoSuchElementException e) {

			System.out.println("No such element in file");

		} catch (IllegalStateException e) {

			System.out.println("Scanner closed");
			e.printStackTrace();
			e.getMessage();

		} // end catch
	} // end of readInfoFromFiles method

	public void closedFile (Scanner input) {

		if (input != null) {
			input.close();

		}//end if
	} // end closedFile method
}
