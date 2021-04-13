package Lab3;
/**
 * This class contains a program to search for an integer in an array using recursive and non-recursive binary search.
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
import java.security.SecureRandom;
import java.util.Arrays;
import java.util.Scanner;

/**
 * The Class Binarysearch.
 */
public class Binarysearch {

	/** The input. */
	public static Scanner input = new Scanner(System.in);

	/** The num array. */
	//declaring instance variable.
	private int numArray[];
	
	/** The ret. */
	private int ret = -1;
	
	/** The first index. */
	private int firstIndex = 0;
	
	/** The last index. */
	private int lastIndex = 0;
	
	/** The middle. */
	private int middle = 0;

	/**
	 * Non recursive binary search.
	 *
	 * @param number the number
	 * @param searchkey the searchkey
	 * @return the int
	 */
	public int nonRecursiveBinarySearch(int[] number, int searchkey) {

		lastIndex = number.length - 1;
		middle = (firstIndex + lastIndex + 1)/2;
		ret = -1;

		boolean check = true;

		while(check) {
			//print remaining elements
			System.out.printf(remainingElements(number, firstIndex, lastIndex));
			
			//find the number by diviving in half 
			if(searchkey == numArray[middle]) {

				System.out.printf("\n%d was found at index position %d: Iterative Binary Search\r\n", searchkey, middle);
				ret = middle; // location in middle 

				check = false; //get out the loop
				break;
				
				// middle element in last Index
			} else if ( searchkey < numArray[middle]) {
				lastIndex = middle - 1; // middle element is last index half
			} else {
				// middle element is first index half
				firstIndex = middle + 1;
			} // end else if 

			//check all binary indexes were searched
			if (lastIndex == middle || firstIndex == middle) {
				System.out.printf("\n%d was not found\n\n", searchkey);
				check = false; // out of loop
				break; //  out of loop
			} //end of if 
			
			// recalculate the middle
			middle = (firstIndex + lastIndex + 1)/2;

		} // end of while

		return ret; // return location of searchkey

	} //end nonRecursiveBinarySearch() method

	/**
	 * Recursive binary search.
	 *
	 * @param numArr the num arr
	 * @param firstIndex the first index
	 * @param lastIndex the last index
	 * @param searchNum the search num
	 * @return the int
	 */
	public int recursiveBinarySearch(int[] numArr,int firstIndex, int lastIndex, int searchNum) {

		//print remaining elements
		System.out.printf(remainingElements(numArr, firstIndex, lastIndex));
		ret = -1;
		middle = (firstIndex + lastIndex + 1)/2;

		//find the number by diviving in half 
		if(searchNum == numArr[middle] ) {
			System.out.printf("\n%d was found at index position %d: recursive Binary Search\r\n", searchNum, middle);
			return middle;
		} else if (searchNum < numArr[middle]) {
			lastIndex = middle - 1;
		}else {
			firstIndex = middle + 1;
		} // end of else if

		//check all binary indexes were searched
		if (firstIndex == middle || lastIndex == middle) {
			System.out.printf("\n%d was not found\n\n", searchNum);
		} else {
			//recursive the method
			ret = recursiveBinarySearch(numArr, firstIndex, lastIndex, searchNum);
		} // end of else if

		// return the location
		return ret;	

	} // end recursiveBinarySearch() method

	/**
	 * Generate random ints.
	 *
	 * @return the int[]
	 */
	public int[] generateRandomInts() {
		
		SecureRandom random = new SecureRandom();
		//set array to 20 
		numArray = new int [20];

		for (int i = 0; i < numArray.length; i++) {

			//create array
			numArray[i] = 10 + random.nextInt(90);

		} //end for loop

		//sort array
		Arrays.sort(numArray); 
		//display array
		System.out.printf("%s\n\n", Arrays.toString(numArray)); 
		return numArray;

	} //end generateRandomInts() method


	/**
	 * Remaining elements.
	 *
	 * @param num the num
	 * @param first the first
	 * @param last the last
	 * @return the string
	 */
	public static String remainingElements(int [] num, int first, int last ){
		//create a new string builder
		StringBuilder remain = new StringBuilder();
		
		// append spaces for alignment
		for (int i = 0; i < first; i++) {
			remain.append(" "); 
		} // end of for loop

		//append elements left in array
		for (int i = first; i <= last; i++) {
			remain.append(num[i] + " ");
		} // end of for loop

		return String.format("%s\n", remain);

	}//end remainingElements() method	
} //end of Binarysearch class
