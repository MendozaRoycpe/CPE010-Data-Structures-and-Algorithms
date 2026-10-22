//
// Created by royga on 8/11/2026.
//

#ifndef UNTITLED1_PRINTER_H
#define UNTITLED1_PRINTER_H
#include <string>
#include <iostream>
#include "sup5.1.h"
#include "Job.h"

class printer {
    private:
    // make a list containing all the queued print
    queueArr<Job> jobQueue;
    public:
    //constructor
    printer(int capacity = 15)
        : jobQueue(capacity) {
        std::cout<<"Ready to Print";
    }
    //Add Job
    void AddPrint(Job newJob) {
        if (jobQueue.full()) {
            std::cout<<"Print Limit already full";
            std::cout<< "Get A new Job:)";
            return;
        }
        jobQueue.enqueue(newJob);
        std::cout<<"Paper of: "<<newJob.GetId()<<" was added successfully";
        std::cout<<"\nUser: "<<newJob.getName();
        std::cout<<"\nPages: "<<newJob.getPages();
    }
    //single
    void Print() {
        if (jobQueue.empty()) {
            std::cout<<"Print Limit already full";
            return;
        }
        //Getting of the next job
        Job current = jobQueue.dequeue();
        std::cout<<"\n Processing Job";
        current.Display();
        std::cout<<"\n Job Complete";
    }
    //Multiple
    void PrinAll() {
        std::cout<<"\nPrint All Jobs";
        while (!jobQueue.empty()) {
            Print();
        }
        std::cout<<"\n All jobs complete";
    }
    //Queue Info
    void ShowStats() {
        std::cout<<"\n Queue Information:";
        std::cout<<"\n Pendings:"<<jobQueue.size();

        if (jobQueue.empty()) {
            std::cout<<"\n Empty Job Queue";
        } else {
            std::cout<<"\n Next Job Queue:"<<std::endl;
            Job nextJob = jobQueue.front();
            nextJob.Display();
        }
    }
};
#endif //UNTITLED1_PRINTER_H