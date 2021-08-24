

public class Iterator<E> {
    private E[] arr;
    private int count;
    private int size;
    private Collection<E> c;
  

        public Iterator(Collection<E> c, E[] e ){
            this.size = c.size();
            count=0;
            this.arr=e;
            this.c=c;
        }


        public boolean hasNext() {
            return count < size;
        }

        public E next() {
            if(!hasNext())
                return null;
            else{
                int t=0;    
                    t = count;
                    count++;
                return arr[t];
            }
        }



    public void remove(){
        try{
            if(c instanceof Queue)
                throw new UnsupportedOperationException ("This is function is not work in Queue type."); 
                        //I learned from the real Iterator class that this exception should be used.
            else{
                if (c.size() == 1) //This is not 0, its about my algorithm. I used starting of the size as 1.
                    System.err.println("Given array is empty already.");
                else
                    c.remove(arr[count]);
            }

        }
        catch(Exception UnsupportedOperationException ){
            System.err.println("This is function is not work in Queue type.");
        }       
    }

}

