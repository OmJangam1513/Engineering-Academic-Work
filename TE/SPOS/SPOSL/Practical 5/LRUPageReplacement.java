import java.util.Scanner;

public class LRUPageReplacement 
{
    public static void main(String[] args) 
    {
        Scanner sc = new Scanner(System.in);

        System.out.print("Enter length of reference string: ");
        int n = sc.nextInt();

        int pages[] = new int[n];
        System.out.println("Enter the reference string:");
        for (int i = 0; i < n; i++)
        {
            pages[i] = sc.nextInt();
        }

        System.out.print("Enter number of frames: ");
        int frames = sc.nextInt();

        int frame[] = new int[frames];
        int used[] = new int[frames];
    
        // initialize all frames to empty (-1)
        for (int i = 0; i < frames; i++) 
        {
            frame[i] = -1;
            used[i] = 0;
        }

        int time = 0, faults = 0;

        System.out.println("\nLRU Page Replacement:");
        for (int i = 0; i < n; i++) 
        {
            int page = pages[i];
            boolean found = false;

            // check if page already exists in a frame
            for (int j = 0; j < frames; j++) 
            {
                if (frame[j] == page) 
                {
                    found = true;
                    used[j] = ++time; // update last used time
                    break;
                }
            }

            // if not found, replace the least recently used page
            if (!found) 
            {
                int pos = 0;
                for (int j = 1; j < frames; j++)
                {    
                    if(used[j] < used[pos])
                    {
                            pos = j; // find LRU position
                    } 
                }
                frame[pos] = page;
                used[pos] = ++time;
                faults++;
            }

            // display current frame status
            System.out.print("Page " + page + " -> ");
            for (int j = 0; j < frames; j++)
            {
                System.out.print(frame[j] + " ");
            }
            System.out.println();
        }

        System.out.println("Total Page Faults: " + faults);
        sc.close();
    }
}
