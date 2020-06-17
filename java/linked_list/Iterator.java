package il.co.ilrd.linked_list;

public interface Iterator {

    /**
     * Check if there is a next element.
     *
     * @return true if next element is valid, otherwise false.
     */
   public boolean hasNext();

    /**
     * @return Data of current element.
     */
    public Object next();
}
