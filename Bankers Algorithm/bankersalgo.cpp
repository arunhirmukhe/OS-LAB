#include<bits/stdc++.h>
using namespace std;
int main()
{
    int no_of_processes, no_of_resources, i, j, k;
    cout<<"Enter number of processes: ";
    cin>>no_of_processes;

    cout<<"Enter number of resources: ";
    cin>>no_of_resources;

    //Allocation Matrix;
    int allocate[no_of_processes][no_of_resources];
    cout<<"Enter allocation matrix: \n";
    for(i=0; i<no_of_processes; i++){
        for(j=0; j<no_of_resources; j++){
            cin>>allocate[i][j];
        }
    }

    //Max need
    int max[no_of_processes][no_of_resources];
    cout<<"Enter maximum matrix: \n";
    for(i=0;i<no_of_processes; i++){
        for(j=0;j<no_of_resources; j++){
            cin>>max[i][j];
        }
    }


    //Available resources
    int available[no_of_resources];
    cout << "Enter the available resources:" << endl;
    for (i = 0; i < no_of_resources; i++) {
        cout << "Resource " << i << ": ";
        cin >> available[i];
}

    int finish[no_of_processes] = {0};
    int safe_seq[no_of_processes], index = 0;
    int need[no_of_processes][no_of_resources];

    for(i=0; i<no_of_processes; i++){
        for(j=0; j<no_of_resources; j++){
            //calculate need 
            need[i][j] = max[i][j] - allocate[i][j];

        }
    }


int y=0;
bool safe_state = true;
for(int k=0; k<no_of_processes; k++){
    for(i=0; i<no_of_processes; i++){
        if(finish[i]==0){
            bool flag = true;
            for(j=0; j<no_of_resources; j++){
                if(need[i][j]>available[j]){
                    flag = false;
                    break;
                }
            }

            if(flag==true){
                safe_seq[index++] = i;
                for(y=0; y<no_of_resources; y++){
                    available[y] += allocate[i][y];
                }
                finish[i] = 1;
                safe_state = true;
            }
            else {
                safe_state = false;
            }

        }
    }
}

if(safe_state == true){
    cout<<"System is in safe state\n";
    cout<<"Safe sequence is: \n";
    for(i=0; i<no_of_processes-1; i++){
        cout<<" P"<<safe_seq[i]<<"->";
    }
    cout<<" P"<<safe_seq[no_of_processes-1];
}
else {
    cout<<"System is not in a safe state.";
}

}