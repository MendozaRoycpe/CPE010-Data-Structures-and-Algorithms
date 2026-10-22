//
// Created by royga on 8/11/2026.
//
#include <iostream>
#include <string>
#include "sup5.1.h"
#include "Job.h"
#include "printer.h"

int main() {
    std::cout<<" PRINTER SIMULATION.exe ";
    std::cout<<"\n===============================================================\n";

    printer printer(15);

    //queue of jobs
    Job job1(609, "Roy", 20);
    Job job2(420, "Bien", 67);
    Job job3(034, "Carl", 007);
    Job job4(678, "Twain", 911);

    printer.AddPrint(job1);
    printer.AddPrint(job2);
    printer.AddPrint(job3);
    printer.AddPrint(job4);

    //status info
    printer.ShowStats();

    //one job process
    std::cout<<"\n Process One Job:";
    printer.Print();

    //add while have already started
    std::cout<<"\n Queue more Job:";
    Job job5(911, "Stephen", 80);
    Job job6(676, "Amiel", 456);
    Job job7(906, "Jerry",159);

    printer.AddPrint(job5);
    printer.AddPrint(job6);
    printer.AddPrint(job7);
    printer.ShowStats();

    //process all
    printer.PrinAll();

    //final status check
    printer.ShowStats();

    std::cout<<"\n=================================================";
    std::cout<<"\nPrinter Simulation End";

    return 0;
}