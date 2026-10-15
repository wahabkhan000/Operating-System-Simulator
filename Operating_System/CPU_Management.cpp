#include "CPU_Management.h"
#include <string>


void CPU_Management::CPU::set_cpu_status(const std::string &status){
    Status = status;
}
void CPU_Management::CPU::set_running_process(const std::string &process){
    Running_Process = process;
}
int CPU_Management::CPU::get_cpu_core_id() const{
    return Core_ID;
}
std::string CPU_Management::CPU::get_cpu_status() const{
    return Status;
}
std::string CPU_Management::CPU::get_cpu_running_process() const{
    return Running_Process;
}


void CPU_Management::Ready_Queue::remove_process(Node *& curr,const int &time){
    if(time == 0){
        Node *temp = curr->next;
        delete curr;
        Head = temp;
    }
    else{
        to_tail(curr);
        Node *temp = curr->next;
        delete curr;
        Head = temp;
    }
}
void CPU_Management::Ready_Queue::to_front(Node *& curr){
    if(Head == nullptr){
        Head = curr;
        Tail = Head;
    }
    else{
        curr->next = Head;
        Head = curr;
    }
}
void CPU_Management::Ready_Queue::to_tail(Node *& curr){
    if(Tail == nullptr){
        Tail = curr;
        Head = Tail;
    }
    else{
        Tail->next = curr;
        Tail = curr;
    }
}
CPU_Management::Node *CPU_Management::Ready_Queue::get_front() const{
    return Head;
}
CPU_Management::Node *CPU_Management::Ready_Queue::get_tail() const{
    return Tail;
}


void CPU_Management::Round_Robin::set_next_process(const std::string &process){
    Next_Process = process;
}
void CPU_Management::Round_Robin::set_gant_chart(const std::string &chart){
    if(!Gant_Chart.empty()){
        Gant_Chart += "->";
    }
    Gant_Chart += chart;
}
int CPU_Management::Round_Robin::get_time_quantum() const{
    return Time_Quantum;
}
std::string CPU_Management::Round_Robin::get_algo_name() const{
    return Algorithm;
}
std::string CPU_Management::Round_Robin::get_next_process_name() const{
    return Next_Process;
}
std::string CPU_Management::Round_Robin::get_gant_chart() const{
    return Gant_Chart;
}


void CPU_Management::FCFS::set_next_process(const std::string &process){
    Next_Process = process;
}
std::string CPU_Management::FCFS::get_algo_name() const{
    return Algorithm;
}
std::string CPU_Management::FCFS::get_next_process_name() const{
    return Next_Process;
}