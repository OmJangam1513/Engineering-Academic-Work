import java.io.*;
import java.net.*;
import java.util.*;

public class RPCClient {
    public static void main(String[] args) {
        try 
        {
            Socket s = new Socket("localhost", 5000);

            DataInputStream in = new DataInputStream(s.getInputStream());
            DataOutputStream out = new DataOutputStream(s.getOutputStream());
            
            Scanner sc = new Scanner(System.in);

            System.out.print("Enter First Number: ");
            int num1 = sc.nextInt();

            System.out.print("Enter Second Number: ");
            int num2 = sc.nextInt();

            out.writeInt(num1);
            out.writeInt(num2);

            int sum = in.readInt();

            System.out.println("Sum Received: " + sum);

            in.close();
            out.close();
            s.close();
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
    }
}
