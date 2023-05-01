#include <iostream>
#include <queue>
#include <unordered_set>

using namespace std;

// function to calculate the page fault rate
double getPageFaultRate(int pageFaults, int numPages) {
    return (double)pageFaults / numPages * 100.0;
}

// function to calculate the hit rate
double getHitRate(int pageHits, int numPages) {
    return (double)pageHits / numPages * 100.0;
}

// function to perform LRU page replacement algorithm
void lruPageReplace(int pages[], int numPages, int capacity) {
    int cache[1000] = {0};  // assume page numbers are integers between 0 and 999
    int cacheAge[1000] = {0}; // array to keep track of the age of each page in the cache
    int pageFaults = 0;
    int pageHits = 0;
    int numInCache = 0; // number of pages currently in the cache

    cout << "Page\tCache\tFaults\tHits\n";

    for (int i = 0; i < numPages; i++) {
        int page = pages[i];
        int pageInCache = -1; // flag to indicate whether the page is in the cache
        // check if the page is already in the cache
        for (int j = 0; j < numInCache; j++) {
            if (cache[j] == page) {
                pageInCache = j;
                break;
            }
        }
        if (pageInCache == -1) { // page fault
            if (numInCache == capacity) { // cache is full, need to replace a page
                int lruPage = 0; // initialize the LRU page to the first page in the cache
                // loop through the pages in the cache to find the least recently used page
                for (int j = 1; j < numInCache; j++) {
                    if (cacheAge[j] < cacheAge[lruPage]) {
                        lruPage = j;
                    }
                }
                // replace the LRU page with the current page
                cache[lruPage] = page;
                cacheAge[lruPage] = i;
            } else { // cache is not full, add the page to the cache
                cache[numInCache] = page;
                cacheAge[numInCache] = i;
                numInCache++;
            }
            pageFaults++; // increment the page fault counter
        } else { // page hit
            // update the age of the page in the cache
            cacheAge[pageInCache] = i;
            pageHits++; // increment the page hit counter
        }
        cout << page << "\t";
        for (int j = 0; j < numInCache; j++) {
            cout << cache[j] << " ";
        }
        cout << "\t";
        cout << pageFaults << "\t" << pageHits << endl;
    }

    // print the results
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
    lruPageReplace(pages, numPages, capacity);
    return 0;
}