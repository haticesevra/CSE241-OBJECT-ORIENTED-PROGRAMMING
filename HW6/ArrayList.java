
/**This is an implementation class that implements List<E> interface **/

	public class ArrayList<E> implements List<E>{
		private int size;
		private E[] array;

	    public E get(int index){   
	    	if(size-1>=index)
	    		return array[index];
	 
	        else
	            System.err.println("There is no element with this index.");
	        
	       return null;
	    }

		public ArrayList() {
			size=1;
			array = (E[]) new Object[size];
		}
		
		public int size(){
			return size-1;
		}

 
		public boolean add(E e){
			int i;

			if(contains(e))
				return false;
			else{
				E[] temp = (E[]) new Object[size+1];
				for(i=0; i<size; i++){
					temp[i]=array[i];
				}
				temp[size-1]=e;

				size=size+1;

				array = (E[]) new Object[size];
		        for (i=0; i<size; i++)
		            array[i]=temp[i];


		    }
			return true;
		}

	
		public boolean contains(E e){
			for(int i=0; i<size-1; i++){
				if(array[i] == e){
						return true;
				}
			}
			return false;
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
 	
		public void printArray(){
			System.out.println("");

			for(int i=0; i<size-1; i++)
				System.out.println("ArrayList[" +i+ "]-> " +array[i]);
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
					E[] temp = (E[]) new Object[size-i+2];	
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
 						if(i!=0)
 							i--;
						break;
			}}}
		}

		public void retainAll(Collection c){
			int flag=0;
			if(containsAll(c)){	
				for(int i=0; i<size-1; i++){
					Iterator iter = c.iterator()  ;
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