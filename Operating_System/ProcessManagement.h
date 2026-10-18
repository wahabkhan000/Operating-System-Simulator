#ifndef ProcessManagement_H
#define ProcessManagement_H

#include <utility>
#include <string>

class Static_Information{
    int PID{-1};
    int Arrival_Time{-1};
    int Burst_Time{-1};
    int Memory_Requirement{-1};
    int Remaining_Time{-1};

    public:
    void set_pid(const int &);
    void set_arrival_time(const int &);
    void set_brust_time(const int &);
    void set_memory_requirement(const int &);
    void set_remaning_time(const int &);

    int get_pid() const;
    int get_arrival_time() const;
    int get_burst_time() const;
    int get_memory_requirement() const;
    int get_remaining_time() const;
};

class Process_Control_Block{
    std::string State{"-1"};
    int Completion_Time{-1};
    int Waiting_Time{-1};
    int Turnaround_Time{-1};
    int Response_Time{-1};

    public:
    void set_process_state(const std::string &);
    void set_completion_time(const int &);
    void set_waiting_time(const int &);
    void set_turnaround_time(const int &);
    void set_response_time(const int &);

    std::string get_process_state() const;
    int get_completion_time() const;
    int get_waiting_time() const;
    int get_turnaround_time() const;
    int get_response_time() const;
};

class Page_Table_Entries{
    int Page_Number{-1};
    int Frame_Number{-1};
    char Protection{'1'};
    int Accessed{-1};
    int Valid{-1};
    int Dirty{-1};

    public:
    void set_page_number(const int &);
    void set_frame_number(const int &);
    void set_protection(const char &);
    void set_access_bit(const int &);
    void set_valid_bit(const int &);
    void set_dirty_bit(const int &);

    int get_page_number() const;
    int get_frame_number() const;
    char get_prtection() const;
    int get_access_bit() const;
    int get_valid_bit() const;
    int get_dirty_bit() const;
};

class Page_Table{
    int Number_of_Pages{-1};
    int Page_Size{-1};
    int Process_Size{-1};

    public:
    Page_Table_Entries *page_table_entries = nullptr;
    void set_number_of_page(const int &);
    void set_page_size(const int &);
    void set_process_size(const int &);

    int get_number_of_pages() const;
    int get_page_size() const;
    int get_process_size() const;
};

class Process_Manager{
    public:
    int Number_of_Process{-1};
    int *Completion_Time_Array{nullptr};
    Static_Information *Information{nullptr};
    Process_Control_Block *PCB{nullptr};
    Page_Table *page_table{nullptr};
};

#endif
