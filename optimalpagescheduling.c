#include <stdio.h>
#include <stdbool.h>

int FRAME_SIZE;

int findOptimalPage(int pages[], int referenceString[], int start, int end)
{
    int index = -1;
    int farthest = start;

    for (int i = 0; i < FRAME_SIZE; i++)
    {
        int currentPage = pages[i];
        bool found = false;

        for (int j = start; j < end; j++)
        {
            if (referenceString[j] == currentPage)
            {
                found = true;
                if (j > farthest)
                {
                    farthest = j;
                    index = i;
                }
                break;
            }
        }

        if (!found)
        {
            return i;
        }
    }

    return index;
}

int main(void)
{
    printf("Enter the number of frames: ");
    scanf("%d", &FRAME_SIZE);

    printf("Enter number of pages: ");
    int referenceLength;
    scanf("%d", &referenceLength);

    printf("Enter reference string: ");
    int referenceString[referenceLength];
    for (int i = 0; i < referenceLength; i++)
    {
        scanf("%d", &referenceString[i]);
    }

    int frames[FRAME_SIZE];
    for (int i = 0; i < FRAME_SIZE; i++)
    {
        frames[i] = -1;
    }

    int pageFaults = 0;

    for (int i = 0; i < referenceLength; i++)
    {
        int currentPage = referenceString[i];

        bool found = false;
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frames[j] == currentPage)
            {
                found = true;
                break;
            }
        }

        if (!found)
        {
            int index = findOptimalPage(frames, referenceString, i + 1, referenceLength);
            frames[index] = currentPage;
            pageFaults++;
        }

        printf("Frames: ");
        for (int j = 0; j < FRAME_SIZE; j++)
        {
            if (frames[j] != -1)
            {
                printf("%d ", frames[j]);
            }
            else
            {
                printf("- ");
            }
        }
        printf("\n");
    }

    printf("Total Page Faults: %d\n", pageFaults);
}