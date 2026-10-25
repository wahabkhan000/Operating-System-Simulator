#include "ProcessManagement.h"
#include <string>
#include <utility>

void Static_Information::set_pid(const int &pid){
    PID = pid;
}
void Static_Information::set_arrival_time(const int &time){
    Arrival_Time = time;
}
void Static_Information::set_brust_time(const int &time){
    Burst_Time = time;
}
void Static_Information::set_memory_requirement(const int &memory){
    Memory_Requirement = memory;
}
void Static_Information::set_remaning_time(const int &time){
    Remaining_Time = time;
}
int Static_Information::get_pid() const {
    return PID;
}
int Static_Information::get_arrival_time() const{
    return Arrival_Time;
}
int Static_Information::get_burst_time() const{
    return Burst_Time;
}
int Static_Information::get_memory_requirement() const{
    return Memory_Requirement;
}
int Static_Information::get_remaining_time() const{
    return Remaining_Time;
}

void Process_Control_Block::set_process_state(const std::string &state){
    State = state;
}
void Process_Control_Block::set_completion_time(const int &time){
    Completion_Time = time;
}
void Process_Control_Block::set_waiting_time(const int &time){
    Waiting_Time = time;
}
void Process_Control_Block::set_turnaround_time(const int &time){
    Turnaround_Time = time;
}
void Process_Control_Block::set_response_time(const int &time){
    Response_Time = time;
}
std::string Process_Control_Block::get_process_state() const{
    return State;
}
int Process_Control_Block::get_completion_time() const{
    return Completion_Time;
}
int Process_Control_Block::get_waiting_time() const{
    return Waiting_Time;
}
int Process_Control_Block::get_turnaround_time() const{
    return Turnaround_Time;
}
int Process_Control_Block::get_response_time() const{
    return Response_Time;
}

void Page_Table_Entries::set_page_number(const int &num){
    Page_Number = num;
}
void Page_Table_Entries::set_frame_number(const int &num){
    Frame_Number = num;
}
void Page_Table_Entries::set_protection(const char &value){
    Protection = value;
}
void Page_Table_Entries::set_access_bit(const int &bit){
    Accessed = bit;
}
void Page_Table_Entries::set_valid_bit(const int &bit){
    Valid = bit;
}
void Page_Table_Entries::set_dirty_bit(const int &bit){
    Dirty = bit;
}

void Page_Table::set_number_of_page(const int &num){
    Number_of_Pages = num;
    page_table_entries = new Page_Table_Entries[Number_of_Pages];
}
void Page_Table::set_page_size(const int &size){
    Page_Size = size;
}
void Page_Table::set_process_size(const int &size){
    Process_Size = size;
}
int Page_Table::get_number_of_pages() const{
    return Number_of_Pages;
}
int Page_Table::get_page_size() const{
    return Page_Size;
}
int Page_Table::get_process_size() const{
    return Process_Size;
}
