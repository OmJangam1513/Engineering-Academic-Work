import java.io.*;

public class IntermediateCode 
{
     static String[][] MOT = {
        {"STOP","00","IS"},
        {"ADD","01","IS"},
        {"SUB","02","IS"},
        {"MULT","03","IS"},
        {"MOVER","04","IS"},
        {"MOVEM","05","IS"},
        {"COMP","06","IS"},
        {"BC","07","IS"},
        {"DIV","08","IS"},
        {"READ","09","IS"},
        {"PRINT","10","IS"},
        {"START","01","AD"},
        {"END","02","AD"},
        {"ORIGIN","03","AD"},
        {"EQU","04","AD"},
        {"LTORG","05","AD"},
        {"DS","01","DL"},
        {"DC","02","DL"},
        {"AREG","01","REG"},
        {"BREG","02","REG"},
        {"CREG","03","REG"},
        {"LT","01","CC"},
        {"LE","04","CC"},
        {"EQ","02","CC"},
        {"GT","03","CC"},
        {"GE","05","CC"},
        {"NE","06","CC"}
        };

    static boolean inMOT(String m) 
    {
        for (int i = 0; i < MOT.length; i++)
            if (MOT[i][0].equals(m))
                return true;
        return false;
    }

    static String getOpcode(String m) 
    {
        for (int i = 0; i < MOT.length; i++)
            if (MOT[i][0].equals(m))
                return MOT[i][1];
        return "";
    }

    public static void main(String[] args) throws IOException 
    {

        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter bw = new BufferedWriter(new FileWriter("IC.txt"));

        String line;
        int lc = 0;

        while ((line = br.readLine()) != null) 
        {
            line = line.trim();
            if (line.equals("")) continue;

            String[] w = line.split("\\s+");

            int index = 0;

            if (!inMOT(w[0]))
            {
                 index = 1;
            }

            if (index >= w.length)
            {
                 continue;
            }

            String op = w[index];

            if (op.equals("START")) 
            {
                lc = Integer.parseInt(w[index + 1]);
                bw.write("(AD,01)\t(C," + lc + ")\n");
            }
            else if (op.equals("DS")) 
            {
                bw.write("(DL,02)\t(C," + w[index + 1] + ")\n");
                lc += Integer.parseInt(w[index + 1]);
            
            } 
            else if (op.equals("DC")) 
            {
                bw.write("(DL,01)\t(C," + w[index + 1] + ")\n");
                lc++;
            } 
            else if (inMOT(op)) 
            {
                String opcode = getOpcode(op);
                bw.write("(IS," + opcode + ")\t");
                for (int i = index + 1; i < w.length; i++) 
                {
                    bw.write(w[i] + "\t");
                }
                bw.write("\n");
                lc++;
            }
        }

        bw.close();
        br.close();
    }
}
