import java.util.Scanner;

public class FIFOPageReplacement 
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
        for (int i = 0; i < frames; i++)
        {
            frame[i] = -1;
        }
        
        int index = 0, faults = 0;

        System.out.println("\nFIFO Page Replacement:");
        for (int i = 0; i < n; i++) 
        {
            int page = pages[i];
            boolean found = false;

            for (int j = 0; j < frames; j++)
            {
                if (frame[j] == page)
                { 
                    found = true;
                }
            }
            if (!found) 
            {
                frame[index] = page;
                index = (index + 1) % frames;
                faults++;
            }

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
