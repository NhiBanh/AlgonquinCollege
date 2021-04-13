package Lab6;


/**
 * The Class BinaryTree.
 */
public class BinaryTree {
	
	/** The root. */
	protected BinaryTreeNode root = null;
	
	/**
	 * Insert in tree.
	 *
	 * @param newData the new data
	 */
	public void insertInTree (int newData) {
		if(root == null) {
			root = new BinaryTreeNode(newData);
		} else {
			root.insert(newData);
		}
	}
	
	/**
	 * Display in order.
	 */
	public void displayInOrder() {
		displayInOrder(root);
	}
	
	/**
	 * Display in order.
	 *
	 * @param subRoot the sub root
	 */
	public void displayInOrder(BinaryTreeNode subRoot) {
		if (subRoot == null) {
			return;
		}
		
		displayInOrder(subRoot.getLeft());
		System.out.print(" " + subRoot.getData() + " ");
		displayInOrder(subRoot.getRight());
	}
	
	/**
	 * Gets the height.
	 *
	 * @return the height
	 */
	public int getHeight() {
		//get size of left sub tree
		int left = getHeight(root, "left", 0);
		
		//get size of right sub tree
		int right = getHeight(root, "right", 0);
		
		
		//set height to largest of left or right
		int height = left >= right? left: right;
	
		return height;
	}
	
	/**
	 * Gets the height.
	 *
	 * @param subRoot the sub root
	 * @param side the side
	 * @param height the height
	 * @return the height
	 */
	public int getHeight (BinaryTreeNode subRoot, String side, int height) {
		
		//check if the root is null (at bottom of tree)
		if(subRoot == null) {
			return height;//return the height
		}
		
		if(side.equals("left")) {
			//go down left side recursively
			return getHeight(subRoot.getLeft(), "left", height+1);
		}else {
			//go down right side recursively
			return getHeight(subRoot.getRight(), "right", height+1);
		}
		
		
	}
}
