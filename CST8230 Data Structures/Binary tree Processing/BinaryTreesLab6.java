package Lab6;

/**
 * This class contains a program using the Binary Trees
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */

/*
 * PROBLEM DISCRIPTION: 
 * Start with the Binary Tree Example from class (you can find this in the slides). 
 * Add a recursive method to the BinaryTree class which will calculate and return the height of the tree. 
 * In your “main”, add a choice to display of the height of the tree.  
 * During your demo, you will need to show your code.
 * 
 * HINTS:
 * Consider in general at any node….
 * calculate the height of the left subtree, 
 * and the height of the right subtree – then return the larger of the two heights (+1 to include the current node)
 * Consider how to end the recursion – and what the bottom nodes of the tree’s height is.
 * Add meaningful comments to your code.
 * */
import java.util.*;

/**
 * The Class BinaryTreesLab6.
 */
public class BinaryTreesLab6 {

	/** The Constant input. */
	public static final Scanner input = new Scanner(System.in);

	/**
	 * The main method.
	 *
	 * @param args the arguments
	 */
	public static void main(String[] args) {

		boolean mainLoop = true;
		int menuOption = 0;
		
		BinaryTree binaryTree = new BinaryTree();

		//main loop for the program.
		while(mainLoop) {

			try {

				//display menu option to user
				System.out.println("1. Add Value to Tree");
				System.out.println("2. Display Tree (In-Order Traserval)");
				System.out.println("3. Display Height");
				System.out.println("4. To Exit");
				System.out.print(">");
				menuOption = input.nextInt();

			} catch (Exception e) {

				System.err.flush();
				System.err.println("*****Input Mismatch Exception*****");
				System.err.flush();

				input.next();
				
			} // end of try catch 
			
			// wrong option of menu
			if(menuOption <= 0 || menuOption > 4) {

				System.err.flush();
				System.err.println("Please choose the option 1 to 4.\nThank you!");
				System.err.flush();
				System.out.println();

			} // end of if menu option smaller or equals 0 or menu option greater than 4
			
			//option 1
			if(menuOption == 1) {
				boolean flag = true;
				int addTree = 0;

				// local loop
				while (flag) {
					try {

						System.out.println("Enter an integer to add to the tree: ");
						addTree =input.nextInt();
						binaryTree.insertInTree(addTree);

						flag = false;
						break;

					} catch (Exception e) {
						System.err.flush();
						System.err.println("Please enter a number.\nThank you!");
						System.err.flush();
						System.out.println();
					} // end of try catch
				} // end of local ( flag ) loop
			} // end of option 1

			//option 2
			if(menuOption == 2) {
				binaryTree.displayInOrder();
				System.out.println();
			} // end of option 2
			
			//option 3
			if(menuOption == 3) {
				
				// print the height
				System.out.println("Tree Height");
				System.out.println(binaryTree.getHeight());
			} // end of option 3
			
			//option 4
			if(menuOption == 4) {
				
				System.out.println("Exiting...");
				//out of loop
				mainLoop = false;
				break;

			} // end of option 4
		} //ens of mainLoop
	} //end of main method
} // end class
