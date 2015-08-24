
//THIS PROBLEM HAS BEEN SOLVED THROUGH A SIMPLE ALGORITHM AND SOME TRIVIAL COMPUTATIONS WITH MY MIND
//HARDER INPUTS SHOULD BE FACED WITH ANOTHER WAY
import java.io.BufferedReader;
import java.io.FileReader;
import java.io.IOException;
import java.util.List;
import java.util.ArrayList;

public class PasswordDerivation {

	public static void main(String[] args) {
		List []digits ;
		digits = new ArrayList[10];
		
		boolean numbersOnMyLeft [][];
		numbersOnMyLeft= new boolean[10][10];
		for ( int i=0; i<digits.length; i++) {
			digits[i]=new ArrayList();
		}

		
		try (BufferedReader br = new BufferedReader(new FileReader("/Users/SubtleX/Desktop/p079_keylog.txt")))
		{
			String sCurrentLine;
 
			while ((sCurrentLine = br.readLine()) != null) {
				int x,y,z,num;
				
				num = Integer.parseInt(sCurrentLine);
				z = num %10;
				num = num/10;
				y = num % 10;
				x= num/10;
				digits[x].add(y);
				digits[x].add(z);
				digits[y].add(z);
				numbersOnMyLeft[z][x]=true;
				numbersOnMyLeft[z][y]=true;
				numbersOnMyLeft[y][x]=true;
			}
 
		} catch (IOException e) {
			e.printStackTrace();
		} 
 

//		for (int i=0; i< digits.length ; i++) {
//			for(Object object : digits[i]) {
//			    int element = (int) object;
//			    System.out.println(element);
//			}
//			System.out.print("\n\n");
//		}
		for (int i=0; i< 10; i++) {
			System.out.println(i+" is after:");
			for (int j=0; j<10; j++) 
			{
				if ( numbersOnMyLeft[i][j]) {
					System.out.println(""+j);
				}
			}
			
		}
	}

}

