import java.util.*;

public class RoundRobin 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        int pid[] = new int[n];
        int bt[] = new int[n];
        int rt[] = new int[n];
        int tat[] = new int[n];
        int wt[] = new int[n];
        
        System.out.print("Enter time quantum: ");
        int tq = sc.nextInt();

        for (int i = 0; i < n; i++) 
        {
            pid[i] = i + 1;
            System.out.print("Enter burst time of P" + pid[i] + ": ");
            bt[i] = sc.nextInt();
            rt[i] = bt[i];
        }

        int time = 0;
        boolean done;
        do 
        {

            done = true;
            for (int i = 0; i < n; i++) 
            {
                if (rt[i] > 0) 
                {
                    done = false;
                    if (rt[i] > tq) 
                    {
                        time += tq;
                        rt[i] -= tq;
                    } 
                    else 
                    {
                        time += rt[i];
                        wt[i] = time - bt[i];
                        rt[i] = 0;
                    }
                }
            }
        }while (!done);

        for (int i = 0; i < n; i++)
        {
             tat[i] = bt[i] + wt[i];
        }

        System.out.println("\nPID\tBT\tWT\tTAT");
        for (int i = 0; i < n; i++)
        {
            System.out.println(pid[i] + "\t" + bt[i] + "\t" + wt[i] + "\t" + tat[i]);
        }
    }
}
