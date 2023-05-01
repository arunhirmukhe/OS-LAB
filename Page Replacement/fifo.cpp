//FIFO
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

// function to implement First-In-First-Out page replacement algorithm
void fifoPageReplace(int pages[], int numPages, int capacity) {
    queue<int> cache;                       // queue to maintain the page frames in cache
    unordered_set<int> pageSet;             // unordered set to maintain the unique pages in cache
    int pageFaults = 0;                     // variable to store the number of page faults
    int pageHits = 0;                       // variable to store the number of page hits

    // table header
    cout << "Page\tCache\tFaults\tHits\n";
    for (int i = 0; i < numPages; i++) {
        int page = pages[i];                // current page
        if (pageSet.find(page) != pageSet.end()) {   // if page is already in cache
            pageHits++;                     // increment the number of page hits
        } else {                            // if page is not in cache
            if (cache.size() == capacity) { // if cache is already full
                int lruPage = cache.front();    // remove the least recently used page
                cache.pop();                // pop the least recently used page from cache
                pageSet.erase(lruPage);     // remove the least recently used page from pageSet
            }
            cache.push(page);               // add the current page to cache
            pageSet.insert(page);           // add the current page to pageSet
            pageFaults++;                   // increment the number of page faults
        }
        cout << page << "\t";
        queue<int> temp = cache;
        while (!temp.empty()) {
            cout << temp.front() << " ";
            temp.pop();
        }
        cout << "\t";
        cout << pageFaults << "\t" << pageHits << endl;
    }

    // print the results
    cout << "\nNumber of page faults: " << pageFaults << endl;
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
    fifoPageReplace(pages, numPages, capacity); // call the FIFO page replacement function
    return 0;
}
