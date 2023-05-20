#include<iostream>

enum Sex {MALE, FEMALE};

struct Person{
    Person(){
        this->name = "";
        this->age = -1;
        this->height = -1;
        this->gender = MALE;
        this->nationality = "";
    }
    
    Person(std::string name, int age, float height, Sex gender, std::string country){
        (*this).name = name;
        this->age = age;
        this->height = height;
        this->gender = gender;
        this->nationality = country;
    }
    
    void set_Name(std::string name){
        this->name = name;
    }
    
    std::string get_Name(){
        return this->name;
    }
    
    void display_info(){
        std::cout << ".............Person Info............." << std::endl;
        std::cout << "Name: " << this->name << std::endl;
        std::cout << "Age: " << this->age << std::endl;
        std::cout << "Height: " << this->height << std::endl;
        std::cout << "Gender: " << this->gender << std::endl;
        std::cout << "nationality: " << this->nationality << std::endl;
    }
    
    // Members Data
    std::string name;
    int age;
    float height;
    Sex gender;
    std::string nationality;
};

int main(){
    
    Person p1("seun", 25, 1.7, MALE, "Nigerian");
    Person *obj = new Person("ayomikun", 23, 1.4, FEMALE, "Ghana");
    Person *people = new Person[10];
    
    p1.display_info();
    p1.set_Name("Ojeleye");
    p1.display_info();
    
    obj->set_Name(p1.get_Name());
    obj->display_info(); // (*obj).display_info();
    
    /*
    for(int i = 0; i < 3; i++){
        people[i].display_info();
    }
    */
    
    std::cout << p1.name <<std::endl;

    return 0;
}
