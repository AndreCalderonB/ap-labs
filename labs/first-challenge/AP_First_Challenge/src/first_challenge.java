public class first_challenge {
	
	
	public static void main(String[] args) {
		Object[] myarray = new Object[] {
		         new Object[] { new int[] { 1, 2 }, 
		                        new int[] { 3, 4 }
		         },
		         new int[] { 5, 6 },
		         1
		    };
		System.out.println(arrayLength(myarray));
	}
	
    public static int arrayLength(Object[] array) {
    	int sum = 0;
        for (Object object : array) {
            if(object instanceof Object[]) {
            	System.out.println("Array");
                sum += arrayLength((Object[]) object, sum);
            }else if(object instanceof int[]) {
            	System.out.println(object);
            	sum += ((int[]) object).length;
            }else {
            	sum += 1;
            }
        }
        return sum;
    }
    public static int arrayLength(Object[] array, int sum) {
        for (Object object : array) {
            if(object instanceof Object[]) {
            	System.out.println("Array");
                sum += arrayLength((Object[]) object, sum);
            }else if(object instanceof int[]) {
            	System.out.println(object);
            	sum += ((int[]) object).length;
            }else {
            	sum += 1;
            }
        }
        return sum;
    }
}
