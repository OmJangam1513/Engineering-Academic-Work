import java.util.Scanner;

public class BestFit 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int[] blockSize = new int[10];
        int[] processSize = new int[10];
        int[] allocation = new int[10];
        int m, n;

        System.out.print("Enter number of blocks: ");
        m = sc.nextInt();
        System.out.println("Enter block sizes:");
        for (int i = 0; i < m; i++)
        {
            blockSize[i] = sc.nextInt();
        }

        System.out.print("Enter number of processes: ");
        n = sc.nextInt();
        System.out.println("Enter process sizes:");
        for (int i = 0; i < n; i++)
        {
            processSize[i] = sc.nextInt();
        }
        
        for (int i = 0; i < n; i++)
        {
            allocation[i] = -1;
        }

        for (int i = 0; i < n; i++) 
        {
            int bestIdx = -1;
            for (int j = 0; j < m; j++) 
            {
                if (blockSize[j] >= processSize[i]) 
                {
                    if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx])
                    {
                        bestIdx = j;
                    }
                }
            }

            if (bestIdx != -1) 
            {
                allocation[i] = bestIdx;
                blockSize[bestIdx] -= processSize[i];
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
