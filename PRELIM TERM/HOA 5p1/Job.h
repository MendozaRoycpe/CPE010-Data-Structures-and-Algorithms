//
// Created by royga on 8/11/2026.
//

#ifndef UNTITLED1_JOB_H
#define UNTITLED1_JOB_H
#include <iostream>
#include <string>

class Job {
private:
    int identi;
    int pages;
    std::string name;
    public:
    //prototyping
    //constructor
    Job(int id=0, std::string name="", int pages=0) {
        identi = id;
        this->pages = pages;
        this->name = name;
    }
    //Job Info
    void Display() const {
        std::cout<<"Job Id Number: "<<identi<<std::endl;
        std::cout<<"Pages: "<<pages<<std::endl;
        std::cout<<"Name: "<<name<<std::endl;
    }
    //Getter
    int GetId() const {
        return identi;
    }
    int getPages() const {
        return pages;
    }
    std::string getName() const {
        return name;
    }
};

#endif //UNTITLED1_JOB_H
