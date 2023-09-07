#include <iostream>
#include <thread>
#include <mutex>
#include <windows.h>

std::mutex mtx;

void print_thread_id(int id){
    mtx.lock();
    std::cout<<"thread :: #"<<id<<"\n";
    mtx.unlock();
}

int main(){
    std::thread threads[10];
    for (int i = 0; i < 10; i++)
        threads[i] = std::thread(print_thread_id, i+1);
    for (int i = 0; i < 5; i++) 
        threads[i].join();
    return 0;
}