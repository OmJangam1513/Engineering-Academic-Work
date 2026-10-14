import java.io.*;

public class LiteralTable {

    static String lit[] = new String[50];   // literal names like =’5’
    static int litAddr[] = new int[50];     // literal addresses
    static int litCount = 0;
    static int lc = 0;

    static void addLiteral(String l) 
    {
        for (int i = 0; i < litCount; i++)
        {    if (lit[i].equals(l))
            {
                return; // already exists
            }
        }
        lit[litCount++] = l;
        
    }

    public static void main(String[] args) throws IOException 
    {

        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("LT.txt"));

        String line;

        while ((line = br.readLine()) != null) 
        {
            line = line.trim();
            if (line.equals("")) continue;

            String[] w = line.split("\\s+");

            for (int i = 0; i < w.length; i++) 
            {
                if (w[i].startsWith("=")) 
                {     // check if literal
                    addLiteral(w[i]);
                }
            }
            lc++;
        }

        bw.write("Literal Address \n");

        for (int i = 0; i < litCount; i++) 
        {
            litAddr[i] = lc++;
            bw.write(lit[i] + "\t" + litAddr[i] + "\n");
        }

        bw.close();
        br.close();
    }
}
