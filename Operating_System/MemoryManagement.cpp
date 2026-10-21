#include "MemoryManagement.h"
#include <iostream>
#include <string>
#include <utility>

void Memory_Management_Unit::set_process_size(const int &size){
    Process_Size = size;
}
void Memory_Management_Unit::set_page_size(const int &size){
    Page_Size = size;
}
void Memory_Management_Unit::set_process_id(const int &id){
    Process_ID = id;
}
void Memory_Management_Unit::set_frame_number(const int &num){
    Frame_Number = num;
}
void Memory_Management_Unit::set_demand_bit(){
    Demand_Bit = 0;
}
int Memory_Management_Unit::get_process_size() const{
    return Process_Size;
}
int Memory_Management_Unit::get_page_size() const{
    return Page_Size;
}
int Memory_Management_Unit::get_process_id() const{
    return Process_ID;
}
int Memory_Management_Unit::get_frame_number() const{
    return Frame_Number;
}
int Memory_Management_Unit::get_demand_bit() const{
    return Demand_Bit;
}

void Frame_Manager::set_frame_number(const int &num){
    Frame_Number = num;
}
void Frame_Manager::set_frame_status(const std::string &status){
    Frame_Status = status;
}
void Frame_Manager::set_frame_occupancy(const int &page,const int &frame){
    Occupancy.first = page;
    Occupancy.second = frame;
}
int Frame_Manager::get_frame_number() const{
    return Frame_Number;
}
std::string Frame_Manager::get_frame_status() const{
    return Frame_Status;
}
std::pair<int,int>Frame_Manager::get_frame_occupancy() const{
    return Occupancy;
}

void Frame_Information::set_total_frame(const int &total){
    Total_Frames = total;
}
void Frame_Information::set_free_frames(const int &free){
    Free_Frames = free;
}
void Frame_Information::set_allocated_frames(const int &alloc){
    Allocated_Frames = alloc;
}
int Frame_Information::get_total_frame() const{
    return Total_Frames;
}
int Frame_Information::get_free_frames() const{
    return Free_Frames;
}
int Frame_Information::get_allocated_frames() const{
    return Allocated_Frames;
}

void Physical_Memory::set_ram_size(){
    int size = -1;
    
    do{
        if(size == -1){
            std::cout<<"Enter the size of RAM: \n";
        }
        else{
            std::cout<<"Invalid Input! Please TRY AGAIN: \n";
        }
        std::cin>>size;
    }while(size % 2 != 0 || size == 0);

    RAM_Size = size;
}
void Physical_Memory::set_frame_size(){
    int size = -1;

    do{
        if(size == -1){
            std::cout<<"Enter the size of Frame: \n";
        }
        else{
            std::cout<<"Invalid Input! Please TRY AGAIN: \n";
        }
        std::cin>>size;
    }while(RAM_Size % size != 0 || size == 0);

    Frame_Size = size;
}
void Physical_Memory::set_page_size(){
    Page_Size = Frame_Size;
}
void Physical_Memory::set_number_of_frames(){
    Number_of_Frames = RAM_Size/Frame_Size;
}
void Physical_Memory::set_total_memory_used(const int &memory){
    Total_Used_Memory += memory;
}
int Physical_Memory::get_ram_size() const{
    return RAM_Size;
}
int Physical_Memory::get_frame_size() const{
    return Frame_Size;
}
int Physical_Memory::get_page_size() const{
    return Page_Size;
}
int Physical_Memory::get_number_of_frames() const{
    return Frame_Size;
}
int Physical_Memory::get_total_used_memory() const{
    return Total_Used_Memory;
}
