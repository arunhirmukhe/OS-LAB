//opt
#include <iostream>

using namespace std;

// Function to calculate page fault rate
double getPageFaultRate(int pageFaults, int numPages) {
    return (double)pageFaults / numPages * 100.0;
}

// Function to calculate hit rate
double getHitRate(int pageHits, int numPages) {
    return (double)pageHits / numPages * 100.0;
}

// Function to perform optimal page replacement
void optimalPageReplace(int pages[], int numPages, int capacity) {
    int cache[1000] = {0};  // Array to store pages in cache, assume page numbers are integers between 0 and 999
    int cacheNextUse[1000] = {0};  // Array to store the next use of each page in cache
    int pageFaults = 0;
    int pageHits = 0;
    int numInCache = 0;  // Variable to keep track of number of pages in cache

    cout << "Page\tCache\tFaults\tHits\n";
    // Loop through each page in the input sequence
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        int pageInCache = -1;

        // Check if the current page is already in the cache
        for (int j = 0; j < numInCache; j++) {
            if (cache[j] == page) {
                pageInCache = j;
                break;
            }
        }

        // If the page is not in the cache
        if (pageInCache == -1) {
            // If the cache is already full, choose a page to replace
            if (numInCache == capacity) {
                int farthestUse = -1;
                int pageToReplace = -1;
                // Loop through each page in the cache and find the one that won't be used for the longest time
                for (int j = 0; j < numInCache; j++) {
                    int nextUse = 1000000000;
                    // Loop through the remaining pages in the input sequence to find the next use of the current page in the cache
                    for (int k = i + 1; k < numPages; k++) {
                        if (cache[j] == pages[k]) {
                            nextUse = k;
                            break;
                        }
                    }
                    // If the next use of the current page is farther than any other page in the cache, choose this page to replace
                    if (nextUse > farthestUse) {
                        farthestUse = nextUse;
                        pageToReplace = j;
                    }
                }
                // Replace the chosen page with the current page
                cache[pageToReplace] = page;
                cacheNextUse[pageToReplace] = farthestUse;
            } else {
                // If the cache is not yet full, add the current page to the cache
                cache[numInCache] = page;
                int nextUse = 1000000000;
                // Loop through the remaining pages in the input sequence to find the next use of the current page
                for (int j = i + 1; j < numPages; j++) {
                    if (page == pages[j]) {
                        nextUse = j;
                        break;
                    }
                }
                // Store the next use of the current page in cacheNextUse array
                cacheNextUse[numInCache] = nextUse;
                numInCache++;
            }
            // Increment the page fault counter
            pageFaults++;
        } else {
            // If the page is already in the cache, increment the page hit counter
            pageHits++;
        }
        cout << page << "\t";
        for (int j = 0; j < numInCache; j++) {
            cout << cache[j] << " ";
        }
        cout << "\t";
        cout << pageFaults << "\t" << pageHits << endl;
    }

    cout << "Number of page faults: " << pageFaults << endl;
    cout << "Number of page hits: " << pageHits << endl;
    cout << "Page fault rate: " << getPageFaultRate(pageFaults, numPages) << "%" << endl;
    cout << "Hit rate: " << getHitRate(pageHits, numPages) << "%" << endl;
}

int main() {
    int numPages, capacity;
    cout << "Enter the number of pages: ";
    cin >> numPages;
    int pages[numPages];
    cout << "Enter the pages: ";
    for (int i = 0; i < numPages; i++) {
        cin >> pages[i];
    }
    cout << "Enter the cache capacity: ";
    cin >> capacity;
    optimalPageReplace(pages, numPages, capacity);
    return 0;
}