package il.co.ilrd.linked_list;

public class LinkedList {
    
	private Node head;
    
    public LinkedList() {

    	head  = new Node(null, null);
    }

    /**
     * Pushes element at the front of list.
     *
     * @param data Data to push into list.
     */
    public void pushFront(Object data) {
    	
    	head = new Node(this.head, data);
    }

    /**
     * Removes and returns the first element of this list.
     *
     * @return The element at the front of this list, if list is empty null is returned.
     */
    public Object popFront() {
    	
    	if (isEmpty()) {
    		return null;
    	}
    	
    	Object removedData = this.head.data;
        head = this.head.nextNode;
        
    	return removedData;
    }

    /**
     * Checks if list is empty.
     *
     * @return true if empty, otherwise false.
     */
    public boolean isEmpty() {
        
    	return (null == head.nextNode);
    }

    /**
     * Get number of elements in the list.
     *
     * @return Number of elements in the list.
     */
    public int size() {
    	
    	int counter = 0;
    	
    	ListIterator runner = new ListIterator(this.head);
    	
    	while (runner.hasNext()) {
    	
    		++counter;
    		
    		runner.next();
    	}
        
    	return counter;
    }

    /**
     * Finds data in Linked List.
     *
     * @param data Data to find.
     * @return Iterator with found data, otherwise null.
     */
    public Iterator find(Object data) {
    	
    	Iterator runner = this.begin();
    	Iterator current = this.begin();
    	
    	while (runner.hasNext()) {

    		if (runner.next().equals(data)) {
    			
    			return current;
    		}
    		
    		current.next();
    	}
        
    	return null;
    }

    /**
     * @return Iterator to the first element
     */
    public Iterator begin() {
    	
        return new ListIterator(this.head);
    }

    private class ListIterator implements Iterator {
       
    	private Node curr;
        
        private ListIterator(Node currNode) {
        	
        	this.curr = currNode;
        }
        
        @Override
        public boolean hasNext() {
            
        	return (null != this.curr.nextNode);
        }
        
        @Override
        public Object next() {
        	
        	Object thisData = this.curr.data;
        	
        	if (null == this.curr.nextNode) {
        		
        		return null;
        	}
        	
        	this.curr = this.curr.nextNode;
        	
        	return thisData;
        }
    }

    private class Node {
       
        private Node nextNode;
        private Object data;

        private Node(Node next, Object data) {
            
            this.nextNode = next;
            this.data = data;
        }
    }
}
