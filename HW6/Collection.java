/**
* The HelloWorld program implements an application that
* simply displays "Hello World!" to the standard output.
*
* @author  Hatice Sevra Genc

*/


	public interface Collection<E>{
		/** Ensures that this collection contains the specified element. **/
		boolean add(E e);

		/** Returns the number of elements in this collection. **/
		int size();
		
		/** Returns true if this collection contains the specified element. **/
		boolean contains(E e);

		/** Removes all of the elements from this collection. **/
		void clear();

		/** Prints the array to the screen. **/
		void printArray();
		
		/** Returns true if this collection contains no elements.**/
		boolean isEmpty();

		/** Removes a single instance of the specified element from this collection, if it is present. **/
		boolean remove(E e);
		
		/** Returns true if this collection contains all of the elements in the specified collection. **/
		boolean containsAll(Collection c);

 		/** Removes all of this collection's elements that are also contained in the specified collection. **/ 
		void removeAll(Collection c);

		/** Adds all of the elements in the specified collection to this collection. **/
		void addAll(Collection c); 

		/** Retains only the elements in this collection that are contained in the specified collection. **/
		void retainAll(Collection c) ;

		/** Returns an iterator over the collection. **/
    	Iterator<E> iterator();

	


	}



