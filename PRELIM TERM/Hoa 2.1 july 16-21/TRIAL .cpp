#include <iostream>
#include <string>

class stdt {
private:
    std::string stdtNAME;
    int stdtAGE;
public:
    //CONSTRUCTOR
    stdt(std::string newNAME = "John Doe", int newAGE = 18) {
        stdtNAME = std::move(newNAME);
        stdtAGE = newAGE;
        std::cout<<"The CONSTRUCTOR was CALLED"<<std::endl;
    };
    //DESTRUCTOR
    ~stdt() {
        std::cout<<"The DESTRUCTOR was CALLED"<<std::endl;
    }
    //COPY CONSTRUCTOR
    stdt(const stdt &copySTUDENT) {
        std::cout<<"Copy Constructor was called"<<std::endl;
        stdtNAME = copySTUDENT.stdtNAME;
        stdtAGE = copySTUDENT.stdtAGE;
    }
    //DISPLAY ATTRIBUTES
    void prtdtls() {
        std::cout<<this->stdtNAME<<" "<<this->stdtAGE<<std::endl;

    }
};

int main(){
    const size_t j = 5;

    stdt stdtLIST[j] = {};
    std::string nameLIST[j] = {"Roy", "Bien", "Shin", "Carl", "Jomz"};
    int ageLIST[j] = {18,19,19,20,19};

    for(int i=0; i<j;i++) {
        //loop A
        stdt *ptr = new stdt(nameLIST[i], ageLIST[i]);
        stdtLIST[i] = *ptr;
        delete ptr;
    }
    for(int i=0; i<j; i++){
        //loop B
        stdtLIST[i].prtdtls();
    }

    return 0;
}