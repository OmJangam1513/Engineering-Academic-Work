import java.io.*;

public class SymbolTable {
    static String MOT[][] = {
        {"STOP","00","IS"},{"ADD","01","IS"},{"SUB","02","IS"},
        {"MULT","03","IS"},{"MOVER","04","IS"},{"MOVEM","05","IS"},
        {"COMP","06","IS"},{"BC","07","IS"},{"DIV","08","IS"},
        {"READ","09","IS"},{"PRINT","10","IS"},
        {"START","01","AD"},{"END","02","AD"},{"ORIGIN","03","AD"},
        {"EQU","04","AD"},{"LTORG","05","AD"},
        {"DS","01","DL"},{"DC","02","DL"},
        {"AREG","01","RG"},{"BREG","02","RG"},{"CREG","03","RG"},
        {"LT","01","CC"},{"LE","04","CC"},{"EQ","02","CC"},
        {"GT","03","CC"},{"GE","05","CC"},{"NE","06","CC"}
    };

    static String sym[] = new String[50];
    static int symAddr[] = new int[50];
    static int symCount = 0;
    static int lc = 0;

    public static void main(String args[]) throws Exception 
    {
        BufferedReader br = new BufferedReader(new FileReader("input.txt"));
        BufferedWriter st = new BufferedWriter(new FileWriter("ST.txt"));

        String line=null;
        while ((line = br.readLine()) != null) 
        {
            line = line.trim();
            if (line.equals(""))
            { 
                continue;
            }

            String w[] = line.split("\\s+");
            int index = 0;

            if (!inMOT(w[0])) 
            {  // label
                addSymbol(w[0], lc);
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
            } 
            else if (op.equals("DS")) 
            {
                String symb = w[index - 1];
                setSymbolAddress(symb, lc);
                lc += Integer.parseInt(w[index + 1]);
            } 
            else if (op.equals("DC")) 
            {
                String symb = w[index - 1];
                setSymbolAddress(symb, lc);
                lc++;
            } 
            else if (inMOT(op)) 
            {
                lc++;
            }
        }

        st.write("SYMBOL\tADDRESS\n");
        for (int i = 0; i < symCount; i++) {
            st.write(sym[i] + "\t" + symAddr[i] + "\n");
        }

        br.close();
        st.close();
        System.out.println("Symbol Table created in ST.txt");
    }

    static boolean inMOT(String m) {
        for (int i = 0; i < MOT.length; i++)
        {
            if (MOT[i][0].equals(m))
            {
                 return true;
            }
        }
        return false;
    }

    static void addSymbol(String s, int addr) 
    {
        for (int i = 0; i < symCount; i++)
        {
            if (sym[i].equals(s))
            {
                return;
            }
        }
        sym[symCount] = s;
        symAddr[symCount] = addr;
        symCount++;
    }

    static void setSymbolAddress(String s, int addr) 
    {
        for (int i = 0; i < symCount; i++)
        {   
            if (sym[i].equals(s)) 
            {
                symAddr[i] = addr;
                return;
            }
        }   
    }
}
