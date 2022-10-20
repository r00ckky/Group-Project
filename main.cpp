#include <iostream>
#include <unordered_map>
#include <string>
#include <windows.h>
#include <fstream>
#include <ctime>

using namespace std;

int head_count=0;
int count=10;

int end_prog(){
    return 0;
}

class User
{
    string name, GSTin;
    int age,taxPerct;
    double income,incomeTax;
    int returnTaxPercentage()
    {
        int taxPercentage; 
        if(age<=60)
        {
            if (income<=250000)
                taxPercentage = 0;
            else if (income<=500000)
                taxPercentage = 5;
            else if (income<=1000000)
                taxPercentage = 20;
            else
                taxPercentage = 30;
        }
        
        else if(age<=80)
        {
            if (income<=300000)
                taxPercentage = 0;
            else if (income<=500000)
                taxPercentage = 5;
            else if (income<=1000000)
                taxPercentage = 20;
            else
                taxPercentage = 30;
        }
        
        else{
            if (income<=500000)
                taxPercentage = 0;
            else if (income<=1000000)
                taxPercentage = 20;
            else
                taxPercentage = 30;
        }  
        return taxPercentage;
    } 

    double calculateIncomeTax()
    {
        double rer=(income*taxPerct)/100;
        income-=rer;
        return rer;
    }

    public:
        void display(){
            taxPerct = returnTaxPercentage();
            incomeTax = calculateIncomeTax();
            cout<<"Age: "<<age<<endl;
            cout<<"Income: "<<income<<endl;
            cout<<"Tax Percentage: "<<taxPerct<<"%"<<endl;
            cout<<"Income Tax: "<<incomeTax<<endl;
        }
        void getid(){
            cout<<"Enter Name: ";
            cin>>name;
            cout<<"Enter GST: ";
            cin>>GSTin;
            cout<<"Enter age: ";
            cin>>age;
            cout<<"Enter income: ";
            cin>>income;
        }
        void calculateElectronicTax();
};

class Agent{
    protected:
        unordered_map <string, string> agent_id;
        string agent_pass="hehe lmao";
    public:
        Agent()
        {
            agent_id.insert({"Chaitanya","21bma015"});
            agent_id.insert({"Mehul","21bma003"});
            agent_id.insert({"Sarthak","21bma045"});
            agent_id.insert({"Komal","21bma035"});
        }
        void pass_corr(){
            string name,id;
            cout<<"Enter name:";
            cin>>name;
            cout<<"Enter ID: ";
            cin>>id;
            if(agent_id[name]!=id){
                cout<<"Information is incorrect\nTerminating process in: ";
                while(count!=0){
                    cout<<count<<"...";
                    Sleep(1000);
                    count--;
                }
                end_prog();
            }
            else{
                cout<<"Password is correct\n";
            }
        }
        void defaulter(string name, string id){
            time_t now = time(0);
            char* dt = ctime(&now);
            fstream def;
            def.open("defaulters.txt",ios::app);
            def<<dt<<"::"<<name<<"::"<<id<<endl;
            def.close();
        }
};

class Head: public Agent{
    public:
        string head_name, head_pass="bruh haha";
        Head(){
            string pass;
            cout<<"Enter Password: ";
            cin>>pass;
            if(pass!=head_pass){
                cout<<"Password is incorrect\nTerminating process in: ";
                while(count!=0){
                    cout<<count<<"...";
                    Sleep(1000);
                    count--;
                }
                end_prog();
            }
            else{
                cout<<"Enter Head Name";
                cin>>head_name;
            }
        }
        void add_agent(string name, string id, string pass){
                if(agent_pass==pass){
                    agent_id.insert({name,id});
                }
                else{
                    cout<<"Password is incorrect\nTerminating the process in: ";
                    while(count!=0){
                        cout<<count<<"...";
                        Sleep(1000);
                        count--;
                    }
                    end_prog();
                }
        }
        void delete_agent(string name,string pass){
            if(pass!=agent_pass){
                cout<<"Password is incorrect\nTerminating the process in: ";
                while(count!=0){
                    cout<<count<<"...";
                    Sleep(1000);
                    count--;
                }
                end_prog();
            }
            else{
                agent_id.erase(name);
                cout<<"Process completed\n";
            }
        }
};

void User::calculateElectronicTax()
{
    int category;
    float gstPerct;
    char isChoosing='y';
    double amt;
    double totalTax =0;
    double sum=0;
    cout<<"The Electronics Categories are as follows: "<<endl;
    cout<<"Category1: 5%"<<endl<<"Category2: 12%"<<endl<<"Category3: 18%"<<endl<<"Category4: 28%"<<endl;
    while(isChoosing=='y')
    {
        cout<<"Choose category from 1,2,3,4: ";
        cin>>category;
        cout<<"How much do you spend on the selected category? ";
        cin>>amt;
        sum+=amt;
        switch(category) 
        {
            case 1:
                cout<<"Case1";
                gstPerct = 5;
                break;
            
            case 2:
                cout<<"Case2";
                gstPerct = 12;
                break;
            
            case 3:
                cout<<"Case3";
                gstPerct = 18;
                break;
            
            case 4:
                cout<<"Case4";
                gstPerct = 28;
                break;
            default:
                cout<<"Wrong Input";
        }
        totalTax += (gstPerct/100)*amt;
        cout<<"Do you wish to continue? [y/n]: ";
        cin>>isChoosing;
    }
    if(sum>income){
        Agent k;
        k.defaulter(name,GSTin);
    }
    cout<<"The total tax (GST) you spend on electronics: "<<totalTax<<endl;
}

int main() {
    int ini;
    cout<<"Type 1 for user\nType 2 for Agent\nType 3 for Head";
    cin>>ini;
    if(ini==1){
        User binod;
        binod.getid();
        binod.calculateElectronicTax();
        binod.display();
    }
    else if(ini==2){
        Agent perry_the_platypus;
        string a,b;
        int g;
        perry_the_platypus.pass_corr();
        cout<<"Enter 1 if you wish to enter a defaulter\nElse enter 2";
        cin>>g;
        if(g==1){
            cout<<"Enter defaulter name and GST number";
            cin>>a>>b;
            perry_the_platypus.defaulter(a,b);
        }
    }
    else if(ini==3){
        Head nirmla;
        int k;
        cout<<"Press 1 to add an agent\nPress 2 to delete an agent\nPress 3 to add a defaulter";
        cin>>k;
        if(k==1){
            string name;
            string id;
            string pass;
            cout<<"Enter Name of agent";
            cin>>name;
            cout<<"Enter id";
            cin>>id;
            cout<<"Enter pass";
            cin>>pass;
            nirmla.add_agent(name,id,pass);
        }
        else if(k==2){
            string name;
            string pass;
            cout<<"Enter Name of agent";
            cin>>name;
            cout<<"Enter pass";
            cin>>pass;
            nirmla.delete_agent(name,pass);
        }
        else if(k==3){
            string a,b;
            cout<<"Enter defaulter name";
            cin>>a;
            cout<<"Enter defaulter GSTin";
            cin>>b;
            nirmla.defaulter(a,b);
        }
    }
    return 0;
}