#include "MemoryManagement.h"
#include <string>

void MemoryManagement::Memory_Management_Unit::set_process_size(const int &size){
    Process_Size = size;
}
void MemoryManagement::Memory_Management_Unit::set_page_size(const int &size){
    Page_Size = size;
}
void MemoryManagement::Memory_Management_Unit::set_process_id(const int &id){
    Process_ID = id;
}
void MemoryManagement::Memory_Management_Unit::set_frame_number(const int &num){
    Frame_Number = num;
}
void MemoryManagement::Memory_Management_Unit::set_demand_bit(){
    Demand_Bit = 0;
}
int MemoryManagement::Memory_Management_Unit::get_process_size() const{
    return Process_Size;
}
int MemoryManagement::Memory_Management_Unit::get_page_size() const{
    return Page_Size;
}
int MemoryManagement::Memory_Management_Unit::get_process_id() const{
    return Process_ID;
}
int MemoryManagement::Memory_Management_Unit::get_frame_number() const{
    return Frame_Number;
}
int MemoryManagement::Memory_Management_Unit::get_demand_bit() const{
    return Demand_Bit;
}

void MemoryManagement::Frame_Manager::set_frame_number(const int &num){
    Frame_Number = num;
}
void MemoryManagement::Frame_Manager::set_frame_status(const std::string &status){
    Frame_Status = status;
}
void MemoryManagement::Frame_Manager::set_frame_occupancy(const int &page,const int &frame){
    Occupancy.first = page;
    Occupancy.second = frame;
}
int MemoryManagement::Frame_Manager::get_frame_number() const{
    return Frame_Number;
}
std::string MemoryManagement::Frame_Manager::get_frame_status() const{
    return Frame_Status;
}
std::pair<int,int>MemoryManagement::Frame_Manager::get_frame_occupancy() const{
    return Occupancy;
}

void MemoryManagement::Frame_Information::set_total_frame(const int &total){
    Total_Frames = total;
}
void MemoryManagement::Frame_Information::set_free_frames(const int &free){
    Free_Frames = free;
}
void MemoryManagement::Frame_Information::set_allocated_frames(const int &alloc){
    Allocated_Frames = alloc;
}
int MemoryManagement::Frame_Information::get_total_frame() const{
    return Total_Frames;
}
int MemoryManagement::Frame_Information::get_free_frames() const{
    return Free_Frames;
}
int MemoryManagement::Frame_Information::get_allocated_frames() const{
    return Allocated_Frames;
}

void MemoryManagement::Physical_Memory::set_ram_size(){
    RAM_Size = 64;
}
void MemoryManagement::Physical_Memory::set_frame_size(){
    Frame_Size = 2;
}
void MemoryManagement::Physical_Memory::set_number_of_frames(){
    Number_of_Frames = RAM_Size/Frame_Size;
}
int MemoryManagement::Physical_Memory::get_ram_size() const{
    return RAM_Size;
}
int MemoryManagement::Physical_Memory::get_frame_size() const{
    return Frame_Size;
}
int MemoryManagement::Physical_Memory::get_page_size() const{
    return Page_Size;
}
int MemoryManagement::Physical_Memory::get_number_of_frames() const{
    return Frame_Size;
}