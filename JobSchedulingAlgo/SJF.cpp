#include <iostream>
#include <algorithm>
using namespace std;

struct Process {
    int pid;
    int arrivalTime;
    int burstTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

bool compareArrivalTime(Process p1, Process p2) {
    return p1.arrivalTime < p2.arrivalTime;
}

bool compareBurstTime(Process p1, Process p2) {
    return p1.burstTime < p2.burstTime;
}

int main() {
    int n, i;
    float avwt = 0, avtat = 0;
    cout << "Enter total number of processes: ";
    cin >> n;
    Process processes[n];
    cout << "\nEnter Arrival Time and Burst Time for each process:\n";
    for (i = 0; i < n; i++) {
        cout << "P[" << i + 1 << "]: ";
        processes[i].pid = i + 1;
        cin >> processes[i].arrivalTime >> processes[i].burstTime;
    }

    // sort processes based on their arrival time
    sort(processes, processes + n, compareArrivalTime);

    int currentTime = processes[0].arrivalTime;
    // execute processes in order of shortest burst time
    for (i = 0; i < n; i++) {
        int j;
        for (j = i; j < n; j++) {
            if (processes[j].arrivalTime > currentTime) {
                break;
            }
        }
        sort(processes + i, processes + j, compareBurstTime);
        processes[i].completionTime = currentTime + processes[i].burstTime;
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;
        currentTime = processes[i].completionTime;
    }
    cout << "\nProcess\tArrival Time\tBurst Time\tCompletion Time\tWaiting Time\tTurnaround Time";
    // display process details and calculate average waiting and turnaround time
    for (i = 0; i < n; i++) {
        avwt += processes[i].waitingTime;
        avtat += processes[i].turnaroundTime;
        cout << "\nP[" << processes[i].pid << "]\t" << processes[i].arrivalTime << "\t\t" << processes[i].burstTime << "\t\t" << processes[i].completionTime << "\t\t" << processes[i].waitingTime << "\t\t" << processes[i].turnaroundTime;
    }
    avwt /= n;
    avtat /= n;
    cout << "\n\nAverage Waiting Time: " << avwt;
    cout << "\nAverage Turnaround Time: " << avtat;
    return 0;
}