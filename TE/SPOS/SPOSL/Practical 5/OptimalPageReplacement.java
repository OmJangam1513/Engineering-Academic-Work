import java.util.Scanner;

public class OptimalPageReplacement 
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
        int faults = 0;

        // initialize all frames to empty (-1)
        for (int i = 0; i < frames; i++)
            frame[i] = -1;

        System.out.println("\nOptimal Page Replacement:");
        for (int i = 0; i < n; i++) 
        {
            int page = pages[i];
            boolean found = false;

            // check if page is already in frame
            for (int j = 0; j < frames; j++) 
            {
                if (frame[j] == page) 
                {
                    found = true;
                    break;
                }
            }

            // if page not found, replace using Optimal logic
            if (!found) 
            {
                int replace = -1;
                int farthest = i;

                for (int j = 0; j < frames; j++) 
                {
                    int k;
                    for (k = i + 1; k < n; k++) 
                    {
                        if (frame[j] == pages[k]) 
                            break;
                    }

                    // if page not used again in future, choose it immediately
                    if (k == n) 
                    {
                        replace = j;
                        break;
                    }

                    // otherwise, find page used farthest in future
                    if (k > farthest) 
                    {
                        farthest = k;
                        replace = j;
                    }
                }

                // if all frames are empty initially
                if (replace == -1) 
                    replace = 0;

                frame[replace] = page;
                faults++;
            }

            // display current frame status
            System.out.print("Page " + page + " -> ");
            for (int j = 0; j < frames; j++)
                System.out.print(frame[j] + " ");
            System.out.println();
        }

        System.out.println("Total Page Faults: " + faults);
        sc.close();
    }
}
