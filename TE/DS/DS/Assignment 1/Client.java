import java.io.*;
import java.util.*;
import java.net.*;

public class Client 
{
  
    public static void main(String[] args)
    {
        try 
	    {
            Scanner sc = new Scanner(System.in);
            Socket s = new Socket("127.0.0.1", 5000);
            System.out.println("Connected");

            DataOutputStream out = new DataOutputStream(s.getOutputStream());
        
            String m = "";

            while (!m.equals("Over")) 
	        {
                m = sc.nextLine();
                out.writeUTF(m);
            }
        
            
            out.close();
            s.close();
        }
        catch (IOException e) 
        {
            System.out.println(e);
        }

    }
     
}