#ifndef CPU_Management_H
#define CPU_Management_H

#include <utility>
#include <string>
class Node{
    public:
    int *Process_ID{};
    Node *next;
    // Node(int *Process_ID){
    //     this->Process_ID = Process_ID;
    //     next = nullptr;
    // }
};
class CPU{
    int Core_ID{};
    std::string Status{"NONE"};
    std::string Running_Process{"IDLE"};

    public:
    void set_cpu_status(const std::string &);
    void set_running_process(const std::string &);

    int get_cpu_core_id() const;
    std::string get_cpu_status() const;
    std::string get_cpu_running_process() const;
};
class Ready_Queue{
    Node *Head{};
    Node *Tail{};
        
    public:
    void remove_process(Node *&,const int &);
    void to_front(Node *&);
    void to_tail(Node *&);
    Node *get_front() const;
    Node *get_tail() const;
};
class Round_Robin{
    int Time_Quantum{1};
    std::string Algorithm = "Round-Robin";
    std::string Next_Process{"NONE"};
    std::string Gant_Chart{};

    public:
    void set_next_process(const std::string &);
    void set_gant_chart(const std::string &);

    int get_time_quantum() const;
    std::string get_algo_name() const;
    std::string get_next_process_name() const;
    std::string get_gant_chart() const;
};

class FCFS{
    std::string Algorithm = "First Come First Serve";
    std::string Next_Process{"NONE"};

    public:
    void set_next_process(const std::string &);
    std::string get_algo_name() const;
    std::string get_next_process_name() const;
};
class CPU_Management{
    public:
    Node node;
    CPU cpu;
    Ready_Queue Queue;
    Round_Robin algo_round;
    FCFS algo_fcfs;
};
#endif
