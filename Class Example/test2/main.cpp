<<<<<<< HEAD
#include <iostream>
#include<memory.h>
#include <memory>
#include<vector>
#include<string>
using namespace std;

class Plant{
protected:
    string name;
    string family;
public:
    Plant(string name,string family):name(name),family(family){}
    void display(){
        cout<<"Name :"<<name<<" Family :"<<family<<endl;
    }
};

class Flower : public Plant {
protected:
    string color;
public:
    Flower(string name,string family,string color):Plant(name,family),color(color){}
    void display(){
        cout<<"Name :"<<name<<" Family :"<<family<<" Color"<<color<<endl;
    }
};

class Cactus : public Plant{
protected:
    bool hasFlower;
public:
    Cactus(string name,string family,bool hasFlower):Plant(name,family),hasFlower(hasFlower){}
    void display(){
        if(hasFlower){
            cout<<"Name :"<<name<<" Family :"<<family<<" it has Flower"<<endl;
        }else{
            cout<<"Name :"<<name<<" Family :"<<family<<" No flower"<<endl;
        }
    }
};
 class Tree : public Plant {
 protected:
     int height;
 public:
     Tree(string name,string family,int height):Plant(name,family),height(height){}
     void display(){
         cout<<"Name :"<<name<<" Family :"<<family<<" Height :"<<height <<endl;
     }
 };

class FruitTree : public Tree{
protected:
    string fruitName;
public:
    FruitTree(string name,string family,int height,string fruitName):Tree(name,family,height),fruitName(fruitName){}
    void display(){
        cout<<"Name :"<<name<<" Family :"<<family<<" Height :"<<height <<" Fruit Name :"<<fruitName<<endl;
    }
};

class Garden{
private:
    vector<unique_ptr<Plant>> plants;
public:
    void addplant(unique_ptr<Plant> plant){
        plants.emplace_back(std::move(plant));
    }
    void displayplants(){
        for(auto &plant:plants){
            plant->display();
        }
    }
};

int main()
{
   Garden garden;
   auto flower=make_unique<Flower>("Rose","rosetumanum","Black");
   auto cactus =make_unique<Cactus>("Cactus","cactumanum",true);
   auto tree = make_unique<Tree>("Mango Tree","mangtumanum",154);
   auto tree2 = make_unique<Tree>("Apple Tree","lappetumanum",144);
   auto fruittree=make_unique<FruitTree>("Banana Plant","rosetumanum",199,"Banana");

   garden.addplant(std::move(flower));
   garden.addplant(std::move(cactus));
   garden.addplant(std::move(tree));
   garden.addplant(std::move(tree2));
   garden.addplant(std::move(fruittree));

   garden.displayplants();



    return 0;
}
=======
#include <iostream>
#include<memory.h>
#include <memory>
#include<vector>
#include<string>
using namespace std;

class Plant{
protected:
    string name;
    string family;
public:
    Plant(string name,string family):name(name),family(family){}
    void display(){
        cout<<"Name :"<<name<<" Family :"<<family<<endl;
    }
};

class Flower : public Plant {
protected:
    string color;
public:
    Flower(string name,string family,string color):Plant(name,family),color(color){}
    void display(){
        cout<<"Name :"<<name<<" Family :"<<family<<" Color"<<color<<endl;
    }
};

class Cactus : public Plant{
protected:
    bool hasFlower;
public:
    Cactus(string name,string family,bool hasFlower):Plant(name,family),hasFlower(hasFlower){}
    void display(){
        if(hasFlower){
            cout<<"Name :"<<name<<" Family :"<<family<<" it has Flower"<<endl;
        }else{
            cout<<"Name :"<<name<<" Family :"<<family<<" No flower"<<endl;
        }
    }
};
 class Tree : public Plant {
 protected:
     int height;
 public:
     Tree(string name,string family,int height):Plant(name,family),height(height){}
     void display(){
         cout<<"Name :"<<name<<" Family :"<<family<<" Height :"<<height <<endl;
     }
 };

class FruitTree : public Tree{
protected:
    string fruitName;
public:
    FruitTree(string name,string family,int height,string fruitName):Tree(name,family,height),fruitName(fruitName){}
    void display(){
        cout<<"Name :"<<name<<" Family :"<<family<<" Height :"<<height <<" Fruit Name :"<<fruitName<<endl;
    }
};

class Garden{
private:
    vector<unique_ptr<Plant>> plants;
public:
    void addplant(unique_ptr<Plant> plant){
        plants.emplace_back(std::move(plant));
    }
    void displayplants(){
        for(auto &plant:plants){
            plant->display();
        }
    }
};

int main()
{
   Garden garden;
   auto flower=make_unique<Flower>("Rose","rosetumanum","Black");
   auto cactus =make_unique<Cactus>("Cactus","cactumanum",true);
   auto tree = make_unique<Tree>("Mango Tree","mangtumanum",154);
   auto tree2 = make_unique<Tree>("Apple Tree","lappetumanum",144);
   auto fruittree=make_unique<FruitTree>("Banana Plant","rosetumanum",199,"Banana");

   garden.addplant(std::move(flower));
   garden.addplant(std::move(cactus));
   garden.addplant(std::move(tree));
   garden.addplant(std::move(tree2));
   garden.addplant(std::move(fruittree));

   garden.displayplants();



    return 0;
}
>>>>>>> 429ad4f3fd2fda088bb36b3a44e619d7a2fd6592
