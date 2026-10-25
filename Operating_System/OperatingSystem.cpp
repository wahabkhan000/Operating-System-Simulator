#include <iostream>
#include <ctime>
#include "MemoryManagement.h"
#include "ProcessManagement.h"
#include "CPU_Management.h"

// Function For checking PID is repeated or not
bool pid_repeat_check(const int &value,const Individual_Information *P,const int &number){
    for(int i{}; i < number; i++){
        if(value == P[i].Information.get_pid()){
            return true;
        }
    }
    return false;
}
// Function for Swaping Values
void Arrival_Time_Sorting(Process_Manager *P){
    for(int i{}; i < P->Number_of_Process; i++){
        for(int j{}; j < P->Number_of_Process; j++){
            // Condition Check
            if(P->Process_Information[i].Information.get_arrival_time() > P->Process_Information[j].Information.get_arrival_time()){
                // Swaping values of Process for convenience

                // Setting PID
                int temp = P->Process_Information[i].Information.get_pid();
                P->Process_Information[i].Information.set_pid(P->Process_Information[j].Information.get_pid());
                P->Process_Information[j].Information.set_pid(temp);

                // Swap Arrival Time
                temp = P->Process_Information[i].Information.get_arrival_time();
                P->Process_Information[i].Information.set_arrival_time(P->Process_Information[j].Information.get_arrival_time());
                P->Process_Information[j].Information.set_arrival_time(temp);

                // Swap Burst Time;
                temp = P->Process_Information[i].Information.get_burst_time();
                P->Process_Information[i].Information.set_brust_time(P->Process_Information[j].Information.get_burst_time());
                P->Process_Information[j].Information.set_brust_time(temp);

                // Swap Completion Time
                temp = P->Completion_Time_Array[i];
                P->Completion_Time_Array[i] = P->Completion_Time_Array[j];
                P->Completion_Time_Array[j] = temp;

                // Swap Remaning Time
                temp = P->Process_Information[i].Information.get_remaining_time();
                P->Process_Information[i].Information.set_remaning_time(P->Process_Information[j].Information.get_remaining_time());
                P->Process_Information[j].Information.set_remaning_time(temp);

                // Swap Required Memory
                temp = P->Process_Information[i].Information.get_memory_requirement();
                P->Process_Information[i].Information.set_memory_requirement(P->Process_Information[j].Information.get_memory_requirement());
                P->Process_Information[i].Information.set_memory_requirement(temp);

            }
        }
    }
}

int main(){
    srand(time(0));

    // objects of classes

    Process_Manager P;
    MemoryManagement M;
    CPU_Management C;

    // Argument for selecting Scheduling Algorithm
    int argument = 0;
    do {
        if (argument == 0) {
            std::cout<<"============================================================\n"
            "=================== CPU SCHEDULER ==========================\n"
            "============================================================\n"
            "Available Scheduling Algorithms\n"
            "------------------------------------------------------------\n"
            "1. Round Robin\n"
            "0. First Come First Serve (FCFS)\n"
            "------------------------------------------------------------\n\n"
            "Enter Your Choice: \n\n";
        }
        else {
            std::cout<<"Invalid Input! Please Try Again:\n";
        }
        std::cin>>argument;
    }while (argument<0 || argument>1);

    if (argument == 1) {
        std::cout<<"================= You Selected Round Robin =================\n\n";
    }
    else {
        std::cout<<"======== You Selected First Come First Serve (FCFS) ========\n\n";
    }

    // setting values of atributes using member functions

    // Setting RAM Size
    M.Main_Memory.set_ram_size();

    // Setting Frame Size
    M.Main_Memory.set_frame_size();

    // Setting Number of Frames
    M.Main_Memory.set_number_of_frames();

    // Setting Page Size;
    M.Main_Memory.set_page_size();

    // Setting Total Number of Frame in Frame Manager
    M.frame_information.set_total_frame(M.Main_Memory.get_number_of_frames());

    // Resizing Frame Allocation Check
    M.Main_Memory.Frame_Check = new bool[M.Main_Memory.get_number_of_frames()]();

    int number_of_process= 0;
    do{
        if(number_of_process == 0){
            std::cout<<"Please Enter number of Process: \n";
        }
        else{
            std::cout<<"Invalid Input! Please TRY AGAIN.\n";
        }
        std::cin>>number_of_process;
    }while(number_of_process < 0);

    // Setting Number of Process Count
    P.Number_of_Process = number_of_process;

    // Resizing Completion Time Collective Dynamic Array
    P.Completion_Time_Array = new int[P.Number_of_Process]();

    // Resizing Individual Process Information for all Process
    P.Process_Information = new Individual_Information[P.Number_of_Process]();

    for(int i{}; i<P.Number_of_Process; i++){

        int temp_value = rand()+1;
        while(pid_repeat_check(temp_value,P.Process_Information,P.Number_of_Process)){
            temp_value = rand()+1;
        }

        // Setting PID
        P.Process_Information[i].Information.set_pid(temp_value);

        // Setting Arrival Time
        P.Process_Information[i].Information.set_arrival_time(rand()%10);

        // Setting Burst Time
        P.Process_Information[i].Information.set_brust_time((rand()%10) + 1);

        // Setting Remaining Time
        P.Process_Information[i].Information.set_remaning_time(P.Process_Information[i].Information.get_burst_time());

        // Seting Completion Time
        P.Completion_Time_Array[i] = P.Process_Information[i].Information.get_arrival_time() + P.Process_Information[i].Information.get_burst_time();
        
        // Setting Memory Requirement
        temp_value = 0;
        while(temp_value == 0 || temp_value % M.Main_Memory.get_page_size() != 0){
            temp_value = (rand()%10)+1;
        }

        // Setting Total Memory Used
        M.Main_Memory.set_total_memory_used(temp_value);

        // Setting Process memory Requirement
        P.Process_Information[i].Information.set_memory_requirement(temp_value);

    }

    // Arrival Time Sorting
    Arrival_Time_Sorting(&P);

    // Completion Time Calculation
    for(int i{1}; i<P.Number_of_Process; i++){
        if(P.Process_Information[i-1].Information.get_arrival_time() == P.Process_Information[i].Information.get_arrival_time()){
            P.Completion_Time_Array[i-1] += P.Completion_Time_Array[i];
        }
        else if(P.Process_Information[i-1].Information.get_arrival_time() > P.Process_Information[i].Information.get_arrival_time()){
            int remain_time{};
            remain_time = P.Completion_Time_Array[i-1] - P.Process_Information[i].Information.get_arrival_time();
            P.Completion_Time_Array[i-1] += remain_time;
        }
    }


    // Process Control Block Information
    for(int i{}; i<P.Number_of_Process; i++){

        // Process State
        P.Process_Information[i].PCB.set_process_state("NEW");

        // Completion Time
        P.Process_Information[i].PCB.set_completion_time(P.Completion_Time_Array[i]);

        // Trunaround Time
        P.Process_Information[i].PCB.set_turnaround_time(P.Completion_Time_Array[i] - P.Process_Information[i].Information.get_arrival_time());
        
        // Waiting Time
        P.Process_Information[i].PCB.set_waiting_time(P.Process_Information[i].PCB.get_turnaround_time() - P.Process_Information[i].Information.get_burst_time());
        
        // Response Time
        int first_CPU = P.Process_Information[i].Information.get_arrival_time();

        if(i != 0){
            first_CPU = P.Completion_Time_Array[i-1];
        }
        P.Process_Information[i].PCB.set_response_time(first_CPU);
    }

    // Frame Number Assign
    int frame_count{};
    // Total Frame Record
    M.frame_information.set_total_frame(M.Main_Memory.get_number_of_frames());

    // Process Page Table
    for(int i{}; i<P.Number_of_Process; i++){

        // Process Size
        P.Process_Information[i].page_table.set_process_size(P.Process_Information[i].Information.get_memory_requirement());

        // Page Size
        P.Process_Information[i].page_table.set_page_size(M.Main_Memory.get_page_size());

        // Number of Pages
        P.Process_Information[i].page_table.set_number_of_page(P.Process_Information[i].Information.get_memory_requirement()/P.Process_Information[i].page_table.get_page_size());

        for(int j{}; j<P.Process_Information[i].page_table.get_number_of_pages(); j++){
            // Random Premission Assignment
            char Protection_Value[3] = {'R','W','X'};

            // Protection Value
            P.Process_Information[i].page_table.page_table_entries[j].set_protection(Protection_Value[rand()%3]);

            // Page Number
            P.Process_Information[i].page_table.page_table_entries[j].set_page_number(j);

            // Accessed Bit
            P.Process_Information[i].page_table.page_table_entries[j].set_access_bit(0);

            // Valid bit
            P.Process_Information[i].page_table.page_table_entries[j].set_valid_bit(1);

            // Dirty bit
            P.Process_Information[i].page_table.page_table_entries[j].set_dirty_bit(0);

            // Validate Frame is free
            int temp_value = rand()%M.Main_Memory.get_number_of_frames();
            while(M.Main_Memory.Frame_Check[temp_value] == true){
                temp_value = rand()%M.Main_Memory.get_number_of_frames();
            }

            // change Frame Status in record
            M.Main_Memory.Frame_Check[temp_value] = true;

            M.Frame = new Frame_Manager[M.Main_Memory.get_number_of_frames()];

            // Assign Frame Owner
            M.Frame[frame_count].set_frame_owner(P.Process_Information[i].Information.get_pid());

            // Frame Status
            M.Frame[frame_count].set_frame_status("Occupied");

            // Frame Occupancy
            M.Frame[frame_count].set_frame_occupancy(j,temp_value);

            // Frame Number record in Page Table
            P.Process_Information[i].page_table.page_table_entries[j].set_frame_number(M.Frame[frame_count].get_frame_occupancy().second);

            // Frame Information Allocated
            M.frame_information.set_allocated_frames();

            // Frame Count
            frame_count++;

        }
    }
    std::cout<<1;
}
