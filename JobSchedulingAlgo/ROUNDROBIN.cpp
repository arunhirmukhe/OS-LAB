#include <iostream>
#include <vector>

using namespace std;

struct Process {
    int id;
    int arrival_time;
    int burst_time;
    int remaining_time;
    int completion_time;
    int turnaround_time;
    int waiting_time;
};

int main() {
    int n, time_quantum;
    cout << "Enter the number of processes: ";
    cin >> n;
    cout << "Enter the time quantum: ";
    cin >> time_quantum;
    
    vector<Process> processes(n);
    for (int i = 0; i < n; i++) {
        cout << "Enter arrival time and burst time for process " << i+1 << ": ";
        cin >> processes[i].arrival_time >> processes[i].burst_time;
        processes[i].id = i+1;
        processes[i].remaining_time = processes[i].burst_time;
    }
    
    int current_time = 0;
    int total_waiting_time = 0;
    int total_turnaround_time = 0;
    
    bool all_processes_completed;
    do {
        all_processes_completed = true;
        for (int i = 0; i < n; i++) {
            Process& current_process = processes[i];
            if (current_process.remaining_time > 0) {
                all_processes_completed = false;
                int executed_time = min(time_quantum, current_process.remaining_time);
                current_process.remaining_time -= executed_time;
                current_time += executed_time;
                
                if (current_process.remaining_time == 0) {
                    current_process.completion_time = current_time;
                    current_process.turnaround_time = current_process.completion_time - current_process.arrival_time;
                    current_process.waiting_time = current_process.turnaround_time - current_process.burst_time;
                    total_waiting_time += current_process.waiting_time;
                    total_turnaround_time += current_process.turnaround_time;
                }
            }
        }
    } while (!all_processes_completed);
    
    double avg_waiting_time = static_cast<double>(total_waiting_time) / n;
    double avg_turnaround_time = static_cast<double>(total_turnaround_time) / n;
    
    cout << "Process\tArrival Time\tBurst Time\tCompletion Time\tTurnaround Time\tWaiting Time\n";
    for (Process p : processes) {
        cout << p.id << "\t\t" << p.arrival_time << "\t\t" << p.burst_time << "\t\t";
        if (p.completion_time > 0) {
            cout << p.completion_time << "\t\t";
            cout << p.turnaround_time << "\t\t\t" << p.waiting_time << endl;
        } else {
            cout << "Not Completed\n";
        }
    }
    
    cout << "Average Waiting Time: " << avg_waiting_time << endl;
    cout << "Average Turnaround Time: " << avg_turnaround_time << endl;
    
    return 0;
}