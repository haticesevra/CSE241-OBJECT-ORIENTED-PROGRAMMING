
import java.util.Scanner;

	public class Test {
		public static void main(String[] args){
			int con, rem, g;
			String con1, rem1;
				System.out.println("MENU");
				System.out.println("1- HashSet<Integer>");
				System.out.println("2- HashSet<String>");
				System.out.println("3- ArrayList<Integer>");
				System.out.println("4- ArrayList<String>");
				System.out.println("5- LinkedList<Integer>");
				System.out.println("6- LinkedList<String>");
				System.out.println("Choose one of them...");
				
				Scanner scan = new Scanner(System.in);
				int menu=  scan.nextInt();
	

					switch(menu){

						case 1: //HashSet<Integer>
							Collection<Integer> testHash =  new HashSet<>();
							System.out.println("Test 'add' function...");
							testHash.add(11); 
							testHash.add(22); 
							testHash.add(33); 
							testHash.add(44); 
							testHash.add(55); 
							testHash.add(66); testHash.printArray();

							System.out.println("\nTest 'size' function... \nsize-> "+ testHash.size());

							System.out.println("\nTest 'contains' function...");
							con=22; //you can change to check
							if(!testHash.contains(con))
								System.out.println(con +" is not contain in the HashSet.");
							else
								System.out.println(con+" is contain in the HashSet.");

							System.out.println("\nTest 'isEmpty' function...");
							if(testHash.isEmpty())
								System.out.println("HashSet is not empty.");
							else
								System.out.println("HashSet is empty.");

							System.out.println("\nTest 'remove' function...");
							rem=11;
							if(testHash.remove(rem)){
								System.out.println(rem+" is removed. Removed version is below...");
								testHash.printArray();
							}

							Collection<Integer> temp1 =  new HashSet<>();
							temp1.add(44);
							temp1.add(55);

							System.out.println("\nTest 'containsAll' function. Also 'iterator' function test." );
							if(testHash.containsAll(temp1))
								System.out.println("Yes, HashSet contains the given set.");
							else
								System.out.println("No, HashSet not contain the given set.");
							
							System.out.println("\nTest 'removeAll' function.  Also 'iterator' function test." );
							testHash.removeAll(temp1);
							testHash.printArray();
							
							Collection<Integer> temp2 =  new HashSet<>();
							temp2.add(77);
							temp2.add(88);

							System.out.println("\nTest 'addAll' function. Also 'iterator' function test." );
							testHash.addAll(temp2);
							testHash.printArray();
							
							System.out.println("\nTest 'retainAll' function. Also 'iterator' function test." );
							testHash.retainAll(temp2);
							testHash.printArray();

							System.out.println("\nTest 'clear' function." );
							testHash.clear();
							testHash.printArray();
							System.out.println("\nIf program prints nothing, clear() is working:) " );

							break;
					case 2:
							Collection<String> testHash2 =  new HashSet<>();
							System.out.println("Test 'add' function...");
							testHash2.add("a"); 
							testHash2.add("b"); 
							testHash2.add("c"); 
							testHash2.add("d"); 
							testHash2.add("e"); 
							testHash2.add("f"); testHash2.printArray();

							System.out.println("\nTest 'size' function... \nsize-> "+ testHash2.size());

							System.out.println("\nTest 'contains' function...");
							con1="b"; //you can change to check
							if(!testHash2.contains(con1))
								System.out.println(con1 +" is not contain in the HashSet.");
							else
								System.out.println(con1+" is contain in the HashSet.");

							System.out.println("\nTest 'isEmpty' function...");
							if(testHash2.isEmpty())
								System.out.println("HashSet is not empty.");
							else
								System.out.println("HashSet is empty.");

							System.out.println("\nTest 'remove' function...");
							rem1="a";
							if(testHash2.remove(rem1)){
								System.out.println(rem1+" is removed. Removed version is below...");
								testHash2.printArray();
							}

							Collection<String> temp3 =  new HashSet<>();
							temp3.add("d");
							temp3.add("e");

							System.out.println("\nTest 'containsAll' function. Also 'iterator' function test." );
							if(testHash2.containsAll(temp3))
								System.out.println("Yes, HashSet contains the given set.");
							else
								System.out.println("No, HashSet not contain the given set.");
							
							System.out.println("\nTest 'removeAll' function.  Also 'iterator' function test." );
							testHash2.removeAll(temp3);
							testHash2.printArray();
							
							Collection<String> temp4 =  new HashSet<>();
							temp4.add("g");
							temp4.add("h");

							System.out.println("\nTest 'addAll' function. Also 'iterator' function test." );
							testHash2.addAll(temp4);
							testHash2.printArray();
							
							System.out.println("\nTest 'retainAll' function. Also 'iterator' function test." );
							testHash2.retainAll(temp4);
							testHash2.printArray();

							System.out.println("\nTest 'clear' function." );
							testHash2.clear();
							testHash2.printArray();
							System.out.println("\nIf program prints nothing, clear() is working:) " );

						break;

						case 3:
           					ArrayList<Integer> testArrayList = new ArrayList<>();
							System.out.println("Test 'add' function...");
							testArrayList.add(11); 
							testArrayList.add(22); 
							testArrayList.add(33); 
							testArrayList.add(44); 
							testArrayList.add(55); 
							testArrayList.add(66); testArrayList.printArray();
							g=4;
							System.out.println("\nTest 'get' function... \nget(" + g +")-> "+ testArrayList.get(g));

							System.out.println("\nTest 'size' function... \nsize-> "+ testArrayList.size());

							System.out.println("\nTest 'contains' function...");
							con=100; //you can change to check
							if(!testArrayList.contains(con))
								System.out.println(con +" is not contain in the ArrayList.");
							else
								System.out.println(con+" is contain in the ArrayList.");

							System.out.println("\nTest 'isEmpty' function...");
							if(testArrayList.isEmpty())
								System.out.println("HashSet is not empty.");
							else
								System.out.println("ArrayList is empty.");

							System.out.println("\nTest 'remove' function...");
							rem=11;
							if(testArrayList.remove(rem)){
								System.out.println(rem+" is removed. Removed version is below...");
								testArrayList.printArray();
							}
           					
           					Collection<Integer> temp5 = new ArrayList<>();

							temp5.add(44);
							temp5.add(66);

							System.out.println("\nTest 'containsAll' function. Also 'iterator' function test." );
							if(testArrayList.containsAll(temp5))
								System.out.println("Yes, ArrayList contains the given set.");
							else
								System.out.println("No, ArrayList not contain the given set.");
							
							System.out.println("\nTest 'removeAll' function.  Also 'iterator' function test." );
							testArrayList.removeAll(temp5);
							testArrayList.printArray();
							
           					Collection<Integer> temp6 = new ArrayList<>();

							temp6.add(77);
							temp6.add(88);


							System.out.println("\nTest 'addAll' function. Also 'iterator' function test." );
							testArrayList.addAll(temp6);
							testArrayList.printArray();
							
							System.out.println("\nTest 'retainAll' function. Also 'iterator' function test." );
							testArrayList.retainAll(temp6);
							testArrayList.printArray();

							System.out.println("\nTest 'clear' function." );
							testArrayList.clear();
							testArrayList.printArray();
							System.out.println("\nIf program prints nothing, clear() is working:) " );

						break;

					case 4:
           					ArrayList<String> testArrayList2 = new ArrayList<>();
							System.out.println("Test 'add' function...");
							testArrayList2.add("a"); 
							testArrayList2.add("b"); 
							testArrayList2.add("c"); 
							testArrayList2.add("d"); 
							testArrayList2.add("e"); 
							testArrayList2.add("f"); testArrayList2.printArray();
							g=4;
							System.out.println("\nTest 'get' function... \nget(" + g +")-> "+ testArrayList2.get(g));

							System.out.println("\nTest 'size' function... \nsize-> "+ testArrayList2.size());

							System.out.println("\nTest 'contains' function...");
							con1="b"; //you can change to check
							if(!testArrayList2.contains(con1))
								System.out.println(con1 +" is not contain in the ArrayList.");
							else
								System.out.println(con1+" is contain in the ArrayList.");

							System.out.println("\nTest 'isEmpty' function...");
							if(testArrayList2.isEmpty())
								System.out.println("ArrayList is not empty.");
							else
								System.out.println("ArrayList is empty.");

							System.out.println("\nTest 'remove' function...");
							rem1="a";
							if(testArrayList2.remove(rem1)){
								System.out.println(rem1+" is removed. Removed version is below...");
								testArrayList2.printArray();
							}
           					
           					Collection<String> temp7 = new ArrayList<>();

							temp7.add("d");
							temp7.add("e");

							System.out.println("\nTest 'containsAll' function. Also 'iterator' function test." );
							if(testArrayList2.containsAll(temp7))
								System.out.println("Yes, ArrayList contains the given set.");
							else
								System.out.println("No, ArrayList not contain the given set.");
							
							System.out.println("\nTest 'removeAll' function.  Also 'iterator' function test." );
							testArrayList2.removeAll(temp7);
							testArrayList2.printArray();
							
           					Collection<String> temp8 = new ArrayList<>();

							temp8.add("g");
							temp8.add("h");


							System.out.println("\nTest 'addAll' function. Also 'iterator' function test." );
							testArrayList2.addAll(temp8);
							testArrayList2.printArray();
							
							System.out.println("\nTest 'retainAll' function. Also 'iterator' function test." );
							testArrayList2.retainAll(temp8);
							testArrayList2.printArray();

							System.out.println("\nTest 'clear' function." );
							testArrayList2.clear();
							testArrayList2.printArray();
							System.out.println("\nIf program prints nothing, clear() is working:) " );

						break;

					case 5:
           					LinkedList<Integer> testLinkedList = new LinkedList<>();
							System.out.println("Test 'add' function...");
							testLinkedList.add(11); 
							testLinkedList.add(22); 
							testLinkedList.add(33); 
							testLinkedList.add(44); 
							testLinkedList.add(55); 
							testLinkedList.add(66); testLinkedList.printArray();
							g=4;
							System.out.println("\nTest 'get' function... \nget(" + g +")-> "+ testLinkedList.get(g));

							System.out.println("\nTest 'size' function... \nsize-> "+ testLinkedList.size());

							System.out.println("\nTest 'contains' function...");
							con=55; //you can change to check
							if(!testLinkedList.contains(con))
								System.out.println(con +" is not contain in the LinkedList.");
							else
								System.out.println(con+" is contain in the LinkedList.");

							System.out.println("\nTest 'isEmpty' function...");
							if(testLinkedList.isEmpty())
								System.out.println("LinkedList is not empty.");
							else
								System.out.println("LinkedList is empty.");

							System.out.println("\nTest 'remove' function...");
							rem=22;
							if(testLinkedList.remove(rem)){
								System.out.println(rem+" is removed. Removed version is below...");
								testLinkedList.printArray();
							}

							System.out.println("\nTest 'poll' function...");
							System.out.println("The head of the linked list (" + testLinkedList.poll()+") is removed. Removed version is below...");
							testLinkedList.printArray();
							
							System.out.println("\nTest 'element' function...");
							System.out.println("The head of the linked list -> " + testLinkedList.element());

							System.out.println("\nTest 'offer' function...");
							testLinkedList.offer(25);
							testLinkedList.printArray();
				           					
           					Collection<Integer> temp9 = new ArrayList<>();

							temp9.add(44);
							temp9.add(55);

							System.out.println("\nTest 'containsAll' function. Also 'iterator' function test." );
							if(testLinkedList.containsAll(temp9))
								System.out.println("Yes, LinkedList contains the given set.");
							else
								System.out.println("No, LinkedList not contain the given set.");
							
							System.out.println("\nTest 'removeAll' function.  Also 'iterator' function test." );
							testLinkedList.removeAll(temp9);
							testLinkedList.printArray();
							
           					Collection<Integer> temp10 = new ArrayList<>();

							temp10.add(77);
							temp10.add(99);

							System.out.println("\nTest 'addAll' function. Also 'iterator' function test." );
							testLinkedList.addAll(temp10);
							testLinkedList.printArray();
							
							System.out.println("\nTest 'retainAll' function. Also 'iterator' function test." );
							testLinkedList.retainAll(temp10);
							testLinkedList.printArray();

							System.out.println("\nTest 'clear' function." );
							testLinkedList.clear();
							testLinkedList.printArray();
							System.out.println("\nIf program prints nothing, clear() is working:) " );

						break;

					case 6:
           					LinkedList<String> testLinkedList2 = new LinkedList<>();
							System.out.println("Test 'add' function...");
							testLinkedList2.add("a"); 
							testLinkedList2.add("b"); 
							testLinkedList2.add("c"); 
							testLinkedList2.add("d"); 
							testLinkedList2.add("e"); 
							testLinkedList2.add("f"); testLinkedList2.printArray();
							g=4;
							System.out.println("\nTest 'get' function... \nget(" + g +")-> "+ testLinkedList2.get(g));

							System.out.println("\nTest 'size' function... \nsize-> "+ testLinkedList2.size());

							System.out.println("\nTest 'contains' function...");
							con1="b"; //you can change to check
							if(!testLinkedList2.contains(con1))
								System.out.println(con1 +" is not contain in the LinkedList.");
							else
								System.out.println(con1+" is contain in the LinkedList.");

							System.out.println("\nTest 'isEmpty' function...");
							if(testLinkedList2.isEmpty())
								System.out.println("LinkedList is not empty.");
							else
								System.out.println("LinkedList is empty.");

							System.out.println("\nTest 'remove' function...");
							rem1="a";
							if(testLinkedList2.remove(rem1)){
								System.out.println(rem1+" is removed. Removed version is below...");
								testLinkedList2.printArray();
							}

							System.out.println("\nTest 'poll' function...");
							System.out.println("The head of the linked list (" + testLinkedList2.poll()+") is removed. Removed version is below...");
							testLinkedList2.printArray();
							
							System.out.println("\nTest 'element' function...");
							System.out.println("The head of the linked list -> " + testLinkedList2.element());

							System.out.println("\nTest 'offer' function...");
							testLinkedList2.offer("z");
							testLinkedList2.printArray();
				           					
           					Collection<String> temp11 = new ArrayList<>();

							temp11.add("d");
							temp11.add("b");

							System.out.println("\nTest 'containsAll' function. Also 'iterator' function test." );
							if(testLinkedList2.containsAll(temp11))
								System.out.println("Yes, LinkedList contains the given set.");
							else
								System.out.println("No, LinkedList not contain the given set.");
							
							System.out.println("\nTest 'removeAll' function.  Also 'iterator' function test." );
							testLinkedList2.removeAll(temp11);
							testLinkedList2.printArray();
							
           					Collection<String> temp12 = new ArrayList<>();

							temp12.add("g");
							temp12.add("h");

							System.out.println("\nTest 'addAll' function. Also 'iterator' function test." );
							testLinkedList2.addAll(temp12);
							testLinkedList2.printArray();
							
							System.out.println("\nTest 'retainAll' function. Also 'iterator' function test." );
							testLinkedList2.retainAll(temp12);
							testLinkedList2.printArray();

							System.out.println("\nTest 'clear' function." );
							testLinkedList2.clear();
							testLinkedList2.printArray();
							System.out.println("\nIf program prints nothing, clear() is working properly :)" );

						break;

						default:System.err.println("Invalid choose...");
					}

				}
	}
	

