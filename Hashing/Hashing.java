import java.util.*;
import java.io.*;

class Hashing{
	public static void main(String args[]){
	//HashMap to store key/value pairs
	HashMap<String,Long> map = new HashMap<>();

	// 'put' method to store keys with their corresponding value
	map.put("Sam",1203456789L);
	map.put("Mike",5439284721L);
	map.put("John",4321298670L);


	//'get' method to retreive values
	System.out.println(map.get("Mike"));     // Output  5439284721
	System.out.println(map.get("John"));     // Output  4321298670

	}
}