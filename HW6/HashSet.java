
/**This is an implementation class that implements Set<E> interface**/
	public class HashSet<E> implements Set<E>{
		private int size;
		private E[] array;

		/*Constructor*/
		public HashSet () {
			size=1;
			array = (E[]) new Object[size];
		}

		public int size(){	return size-1; }

		public boolean contains(E e){
			for(int i=0; i<size-1; i++){
				if(array[i] == e){
					return true;
				}
			}return false;
		}


		public boolean containsAll(Collection c){
			Iterator iter = c.iterator();
			while(iter.hasNext()){
				Object temp =  new Object[c.size()];
				temp=iter.next(); 
				if(contains((E)temp)){ }
				else
					return false;
 			}return true;    		
		}
 	
 
		public boolean add(E e){
			int i;
			if(contains(e))	//if it is already in the HashSet, don't add again
				return false;
			else{
				E[] temp = (E[]) new Object[size+1];	//to hold copy of the array content
				for(i=0; i<size; i++)
					temp[i]=array[i];
				temp[size-1]=e;
				size=size+1;

				array = (E[]) new Object[size];
		        for (i=0; i<size; i++)
		            array[i]=temp[i];
		       // printArray();
		    }return true;
		}
		
		/*prints the array*/
		public void printArray(){
			System.out.println("");
			for(int i=0; i<size-1; i++)
				System.out.println("hashSet[" +i+ "]-> " +array[i]);
		}

		public void clear(){
			array=null;
			size=0;
		}

		public boolean isEmpty(){
			if(size==1)
				return false;
			else
				return true;
		}


		public boolean remove(E e){
			int flag=0, i, j;
			if(size==1){
				System.out.println("There is no element to remove");
				return false;
			}
			else{
				for(i=0; i<size-1; i++){
					if(array[i] == e){
						flag=1;
						break;
				}}
				if(flag==1){
					E[] temp = (E[]) new Object[size-i+1];	
					for(j=i; j<size-1; j++)
						temp[j]=array[j+1];
					
					for(j=i; j<size-1; j++)
						array[j] = temp[j];
					size=size-1;
				}else{
					System.out.println("The element you want to remove does not exist in the set.");	
					return false;
				}
			}
			return true;
		}

		public void removeAll(Collection c){
			for(int i=0; i<size-1; i++){
				Iterator iter = c.iterator();
				while(iter.hasNext()){
					Object temp =  new Object[c.size()+1];
					temp=iter.next(); 
					if(temp==array[i]){
 						remove(array[i]);
 						i--;
						break;
			}}}
		}

		public void retainAll(Collection c){
			int flag=0;
			if(containsAll(c)){	
				for(int i=0; i<size-1; i++){
					Iterator iter = c.iterator();
					while(iter.hasNext()){
						Object temp =  new Object[c.size()];
						temp=iter.next(); 
						flag=0;
						if(temp==array[i])
							break;
						else
							flag=1;
 					}
	 				if(flag==1){
	 					remove(array[i]);
	 					i--;
 			}}}
			else
				System.out.println("There are elements include Collection but not HashSet.");
		}		

		

		public void addAll(Collection c){
			Iterator iter = c.iterator();
			while(iter.hasNext()){
				Object temp =  new Object[c.size()+1];
				temp=iter.next(); 

				if(!contains((E)temp))
					add((E)temp);		
 			}
		}
    	
    	public Iterator<E> iterator(){
        	Iterator<E> ret = new Iterator(this,array);
  			return ret;
  		}


	}