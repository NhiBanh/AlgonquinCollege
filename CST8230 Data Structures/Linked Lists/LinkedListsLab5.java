package Lab5;

/**
 * This class contains a program using the LinkedLists
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */
import java.util.LinkedList;
import java.util.Scanner;

/**
 * The Class LinkedListsLab5.
 */
public class LinkedListsLab5 {

	/** The name. */
	public static String name;

	/** The Constant input. */
	//scanner for user input
	public static final Scanner input = new Scanner(System.in);
	
	/** The is balanced. */
	//create the linked list for managing
	public static LinkedList<Character>  isBalanced = new LinkedList<Character>(); 


	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {

		boolean mainLoop = true;

		String expression;

		getName();//get the name from the user

		//while loop for main program execution
		while(mainLoop) {

			int flag = 0;//0 means no mismatch

			expression = getExpression();//get the expression from the user


			if( expression.toLowerCase().equals("exit") ) {
				System.out.println();
				System.out.println("Terminating....");
				//exit main loop
				mainLoop = false;
				break;
			}else {

				//main logic

				//iterate through each character
				for(int i = 0; i < expression.length(); i++) {

					//get the char at current index
					char c = expression.charAt(i);

					//check if ( or {
					if(c == '(' || c == '{'){
						//add to the list
						isBalanced.addFirst(c);
					}

					//check if list has elements
					if(isBalanced.size() > 0){
						//check if )
						if(c == ')'){

							//check if bracket match is in the head
							if(isBalanced.getFirst() == '(') {
								//is matching, remove head
								isBalanced.removeFirst();
							}else {
								//mismatch
								flag = 1;
							}
						}


						//check if }
						if(c == '}'){
							//check if bracket match is in the head
							if(isBalanced.getFirst() == '{') {
								//is matching, remove head
								isBalanced.removeFirst();
							}else {
								//mismatch
								flag = 1;
							}					
						}
					}else {//size == 0

						//check for invalid bracket. ( or { needs to be first
						if(c == ')'|| c == '}'){
							flag = 1;
						}
					}

				}

				//check if list still has items
				if(isBalanced.size() > 0) {	
					//list is mismatched
					flag = 1;
				}

				//Expression is mismatched
				if(flag == 1) {
					System.out.println("The expression is NOT balanced");
					System.out.println();
				} else {
					System.out.println("The expression is balanced");
					System.out.println();
				}
				
				//clear list
				isBalanced.clear();

			}

		}
	}

	/**
	 * Gets the expression.
	 *
	 * @return the expression
	 */
	//get the expression from the user
	public static String getExpression() {
		boolean exLoop = true;
		String expression = "";

		while(exLoop) {

			try {
				System.out.print("Enter an expression (or exit to terminate):");
				expression = input.nextLine();

				//check if name is empty
				if(expression.isEmpty()) {
					System.out.println("Invalid entry");
				}else {
					exLoop = false;//exit loop
					break;
				}
			}catch( Exception e) {
				System.out.println("***Input Missmatch, Please enter valid input\r\n***");
				input.nextLine();
			}//end catch

		}

		return expression;
	}
	
	/**
	 * Gets the name.
	 *
	 * @return the name
	 */
	//Get users name
	public static void getName() {
		boolean nameLoop = true;

		while(nameLoop) {

			try {
				System.out.print("Enter your Full Name:");
				name = input.next();

				//check if name is empty
				if(name.isEmpty()) {
					System.out.println("Invalid entry");
				}else {
					input.nextLine();
					nameLoop = false;//exit loop
					break;
				}
			}catch( Exception e) {
				System.out.println("***Input Missmatch, Please enter valid input\r\n***");
				input.next();
			}//end catch	
		}
	}
}
