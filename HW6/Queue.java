


public interface Queue<E> extends Collection<E>{
    
    /** Inserts the specified element into this queue. **/
    boolean offer(E e); 

    /** Inserts the specified element into this queue. **/
    boolean add(E e);

    /** Retrieves, but does not remove, the head of this queue. **/
    E element();
 	
 	/** Retrieves and removes the head of this queue, or throws if this queue is empty. **/
 	E poll();
}