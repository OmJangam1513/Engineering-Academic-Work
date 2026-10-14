import java.util.Scanner;

public class FirstFit 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int[] blockSize = new int[10];
        int[] processSize = new int[10];
        int[] allocation = new int[10];
        int m, n;

        System.out.print("Enter number of memory blocks: ");
        m = sc.nextInt();
        
        System.out.println("Enter size of each block:");
        for (int i = 0; i < m; i++)
        {
            blockSize[i] = sc.nextInt();
        }
        
        System.out.print("Enter number of processes: ");
        n = sc.nextInt();
        
        System.out.println("Enter size of each process:");
        for (int i = 0; i < n; i++)
        {
            processSize[i] = sc.nextInt();
        }
        
        // initialize
        for (int i = 0; i < n; i++)
        {
                allocation[i] = -1;
        }
        
        // First Fit logic
        for (int i = 0; i < n; i++) 
        {
            for (int j = 0; j < m; j++) 
            {
                if (blockSize[j] >= processSize[i]) 
                {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    break;
                }
            }
        }

        System.out.println("\nProcess No.\tProcess Size\tBlock No.");
        for (int i = 0; i < n; i++) 
        {
            System.out.print((i + 1) + "\t\t" + processSize[i] + "\t\t");
            if (allocation[i] != -1)
            {
                    System.out.println(allocation[i] + 1);
            }
            else
            {
                System.out.println("Not Allocated");
            }
        }
        sc.close();
    }
}
