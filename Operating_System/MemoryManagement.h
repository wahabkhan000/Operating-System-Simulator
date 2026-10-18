#ifndef MemoryManagement_H
#define MemoryManagement_H

#include <utility>
#include <string>

class Memory_Management_Unit{
    int Process_Size{-1};
    int Page_Size{-1};
    int Process_ID{-1};
    int Logical_Address{-1};
    int Frame_Number{-1};
    int Physical_Address{-1};
    std::pair<int,int>Address_Translation{-1,-1};
    int Demand_Bit{-1};

    public:
    void set_process_size(const int &);
    void set_page_size(const int &);
    void set_process_id(const int &);
    void set_frame_number(const int &);
    void set_demand_bit();

    int get_process_size() const;
    int get_page_size() const;
    int get_process_id() const;
    int get_frame_number() const;
    int get_demand_bit() const;
    
};

class Frame_Manager{
    int Frame_Number{-1};
    std::string Frame_Status{"Free"};
    std::pair<int,int>Occupancy{-1,-1};

    public:
    void set_frame_number(const int &);
    void set_frame_status(const std::string &);
    void set_frame_occupancy(const int &,const int &);

    int get_frame_number() const;
    std::string get_frame_status() const;
    std::pair<int,int>get_frame_occupancy() const;
};

class Frame_Information{
    int Total_Frames{};
    int Free_Frames{};
    int Allocated_Frames{};

    public:
    void set_total_frame(const int &);
    void set_free_frames(const int &);
    void set_allocated_frames(const int &);

    int get_total_frame() const;
    int get_free_frames() const;
    int get_allocated_frames() const;
};

class Physical_Memory{
    int RAM_Size{};
    int Page_Size{};
    int Frame_Size{};
    int Number_of_Frames{};
    int Total_Used_Memory{};
        

    public: 
    bool *Frame_Check = nullptr;
        
    void set_ram_size();
    void set_frame_size();
    void set_number_of_frames();

    int get_ram_size() const;
    int get_frame_size() const;
    int get_page_size() const;
    int get_number_of_frames() const;

};

class MemoryManagement{
    public:
    Memory_Management_Unit MMU;
    Physical_Memory Main_Memeory;
    Frame_Information frame_information{};
    Frame_Manager *Frame = nullptr;
};

#endif
