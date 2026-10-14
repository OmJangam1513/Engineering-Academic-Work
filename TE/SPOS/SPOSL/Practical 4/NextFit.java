import java.util.Scanner;

public class NextFit 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);
        int[] blockSize = new int[10];
        int[] processSize = new int[10];
        int[] allocation = new int[10];
        int m, n, last = 0;

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
            boolean allocated = false;
            for (int j = last; j < m; j++) 
            {
                if (blockSize[j] >= processSize[i]) 
                {
                    allocation[i] = j;
                    blockSize[j] -= processSize[i];
                    last = j;
                    allocated = true;
                    break;
                }
            }
            if (!allocated) 
            {
                for (int j = 0; j < last; j++) 
                {
                    if (blockSize[j] >= processSize[i]) 
                    {
                        allocation[i] = j;
                        blockSize[j] -= processSize[i];
                        last = j;
                        break;
                    }
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
