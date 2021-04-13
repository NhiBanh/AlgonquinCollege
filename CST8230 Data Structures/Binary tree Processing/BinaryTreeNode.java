package Lab6;

/**
 * This class contains a program using the Binary Trees.
 *
 * @author Nhi Banh.
 * Student Number:  040 932 192.
 * Course: CST8130 - Data Structures
 * CET-CS-Level 3
 * Professor James Mwangi PhD.
 */

public class BinaryTreeNode {
	
	/** The data. */
	//instance variable 
	private int data;
	
	/** The left. */
	private BinaryTreeNode left;
	
	/** The right. */
	private BinaryTreeNode right;
	
	/**
	 * Instantiates a new binary tree node.
	 *
	 * @param data the data
	 */
	//parameter constructor 
	public BinaryTreeNode(int data) {
		left = null;
		right = null;
		this.data = data;
	} // end parameter constructor
	
	/**
	 * Gets the data.
	 *
	 * @return the data
	 */
	//get data method 
	public int getData() {
		return data;
	} // end of get data method 
	
	/**
	 * Gets the left.
	 *
	 * @return the left
	 */
	//get left
	public BinaryTreeNode getLeft() {
		return left;
	} // end of get left method
	
	/**
	 * Gets the right.
	 *
	 * @return the right
	 */
	//get right
	public BinaryTreeNode getRight() {
		return right;
	} // end of get right method
	
	/**
	 * Insert.
	 *
	 * @param newData the new data
	 */
	public void insert(int newData) {
		
		//check if newdata less than current data
		if(newData < data) {
			
			// if left equal null
			if(left == null) {
				left = new BinaryTreeNode(newData);
			} else { // left != null
				left.insert(newData);
			}
			
			// check data
		} else if(newData > data) {
			
			// if right equal null
			if(right == null) {
				right = new BinaryTreeNode(newData);
			} else {  // right != null
				right.insert(newData);
			} //end of if else 
		} else {
			System.out.println("Duplicate - not adding" + newData);
		} // end of if else 
	} // end of insert method 
} // end of class 
