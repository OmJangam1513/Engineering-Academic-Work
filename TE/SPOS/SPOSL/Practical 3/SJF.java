import java.util.*;

public class SJF 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter number of processes: ");
        int n = sc.nextInt();

        int pid[] = new int[n];
        int at[] = new int[n];   // Arrival time
        int bt[] = new int[n];   // Burst time
        int rt[] = new int[n];   // Remaining time
        int ct[] = new int[n];   // Completion time
        int tat[] = new int[n];  // Turnaround time
        int wt[] = new int[n];   // Waiting time

        for (int i = 0; i < n; i++) 
        {
            pid[i] = i + 1;
            System.out.print("Enter Arrival Time of P" + pid[i] + ": ");
            at[i] = sc.nextInt();
            System.out.print("Enter Burst Time of P" + pid[i] + ": ");
            bt[i] = sc.nextInt();
            rt[i] = bt[i];
        }

        int completed = 0;
        int currentTime = 0;
        int minRT = Integer.MAX_VALUE;
        int shortest = -1;
        boolean found = false;

        while (completed < n) 
        {
            // Find process with minimum remaining time among arrived processes
            shortest = -1;
            minRT = Integer.MAX_VALUE; // Initially assume mininum remainig time is 1000
            for (int i = 0; i < n; i++) 
            {
                if (at[i] <= currentTime && rt[i] > 0 && rt[i] < minRT) 
                {
                    minRT = rt[i];
                    shortest = i;
                    found = true;
                }
            }

            if (!found) 
            {
                currentTime++;
                continue;
            }

            // Reduce remaining time
            rt[shortest]--;
            currentTime++;

            // If process finishes
            if (rt[shortest] == 0) 
            {
                completed++;
                found = false;
                ct[shortest] = currentTime;
                tat[shortest] = ct[shortest] - at[shortest];
                wt[shortest] = tat[shortest] - bt[shortest];
                
            }
        }

        // Display results
        System.out.println("\n--- SJF (Preemptive) / SRTF Scheduling Results ---");
        System.out.println("PID\tAT\tBT\tCT\tTAT\tWT");
        for (int i = 0; i < n; i++) 
        {
            System.out.println("P" + pid[i] + "\t" + at[i] + "\t" + bt[i] + "\t" +ct[i] + "\t" + tat[i] + "\t" + wt[i]);
        }

        double totalWT = 0;
        double totalTAT = 0;

        for(int i=0; i<n; i++)
        {
            totalWT += wt[i];
            totalTAT += tat[i];
        }
        System.out.printf("\nAverage Waiting Time: %.2f", (totalWT / n));
        System.out.printf("\nAverage Turnaround Time: %.2f\n", (totalTAT / n));

        sc.close();
    }
}
