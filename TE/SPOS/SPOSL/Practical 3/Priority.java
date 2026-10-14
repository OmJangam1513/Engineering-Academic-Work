import java.util.*;

public class Priority 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        int pid[] = new int[n];
        int pr[] = new int[n];
        int ct[] = new int[n];
        int bt[] = new int[n];
        int wt[] = new int[n];
        int tat[] = new int[n];

        for (int i = 0; i < n; i++) 
        {
            pid[i] = i + 1;
            System.out.print("Enter burst time of P" + pid[i] + ": ");
            bt[i] = sc.nextInt();
            System.out.print("Enter priority of P" + pid[i] + ": ");
            pr[i] = sc.nextInt();
        }

        for (int i = 0; i < n - 1; i++) 
        {
            for (int j = i + 1; j < n; j++) 
            {
                if (pr[i] > pr[j]) 
                {
                    int temp=0;
                    temp = pr[i]; pr[i] = pr[j]; pr[j] = temp;
                    temp = bt[i]; bt[i] = bt[j]; bt[j] = temp;
                    temp = pid[i]; pid[i] = pid[j]; pid[j] = temp;
                }
            }
        }

        wt[0] = 0;
        for (int i = 1; i < n; i++)
        {
            wt[i] = wt[i - 1] + bt[i - 1];
        }
        for (int i = 0; i < n; i++)
        {
            tat[i] = wt[i] + bt[i];
            ct[i] = tat[i];
        }
        
        System.out.println("\nPID\tBT\tPR\tCT\tWT\tTAT");
        
        for (int i = 0; i < n; i++)
        {
            System.out.println(pid[i] + "\t" + bt[i] + "\t" + pr[i] +"\t"+ct[i]+ "\t" + wt[i] + "\t" + tat[i]);
        }    
    }
}
