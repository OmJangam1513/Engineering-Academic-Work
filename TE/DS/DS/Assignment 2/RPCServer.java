import java.io.*;
import java.net.*;

public class RPCServer 
{
    public static void main(String[] args) 
    {
        try 
        {
            ServerSocket ss = new ServerSocket(5000);
            
            System.out.println("Server Started...");
            System.out.println("Waiting For Client");

            Socket s = ss.accept();
            System.out.println("Client Connected");

            DataInputStream in = new DataInputStream(s.getInputStream());
            DataOutputStream out = new DataOutputStream(s.getOutputStream());

            int num1 = in.readInt();
            int num2 = in.readInt();

            int sum = num1 + num2;

            System.out.println("Sum Sending: " + sum);

            out.writeInt(sum);

            in.close();
            out.close();
            s.close();
            ss.close();
        } 
        catch (Exception e) 
        {
            System.out.println(e);
        }
    }
}
