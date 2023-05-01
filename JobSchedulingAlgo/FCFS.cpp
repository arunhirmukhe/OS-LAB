#include <iostream>
using namespace std;

int main() {
    int n, at[20], bt[20], wt[20], tat[20], ct[20], i, j;
    float avwt = 0, avtat = 0;
    cout << "Enter total number of processes: ";
    cin >> n;
    cout << "\nEnter Arrival Time and Burst Time for each process:\n";
    for (i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        cin >> at[i] >> bt[i];
    }

    // bubble sort to sort processes based on their arrival time
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            if (at[j] > at[j + 1]) {
                swap(at[j], at[j + 1]);
                swap(bt[j], bt[j + 1]);
            }
        }
    }
    
    ct[0] = bt[0];
    // calculating completion time for each process
    for (i = 1; i < n; i++) {
        ct[i] = ct[i-1] + bt[i];
    }
    wt[0] = 0;
    // waiting time for first process is 0
    // calculating waiting time
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
        wt[i] -= at[i];
        if (wt[i] < 0) {
            wt[i] = 0;
        }
    }
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time";
    // calculating turnaround time
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        avwt += wt[i];
        avtat += tat[i];
        cout << "\nP[" << i + 1 << "]\t" << at[i] << "\t\t" << bt[i] << "\t\t" << ct[i] << "\t\t" << wt[i] << "\t\t" << tat[i];
    }
    avwt /= i;
    avtat /= i;
    cout << "\n\nAverage Waiting Time: " << avwt;
    cout << "\nAverage Turnaround Time: " << avtat;
    return 0;
}