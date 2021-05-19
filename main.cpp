//
//  main.cpp
//  formulation_in_cpp
//
//  Created by Ch Muhammad Wahab on 17/05/2021.
//  Copyright © 2021 Ch Muhammad Wahab. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
using namespace std;

struct country{
    string name;
    int points;
    int year;
    int rank;
    friend ostream& operator << (ostream& out, country& obj){
        out<<obj.name<<"\t"<<obj.year<<"\t"<<obj.points<<endl;
        return out;
    }
    bool operator > (country c){
        if(points > c.points)
            return true;
        else
            return false;
    }
};
vector<country> private_wealth;
vector<country> economic_power;
vector<country> enery_power;
vector<country> military_power;
vector<country> people_power;
vector<country> smart_power;

void read_economic_power(){
    ifstream inFile;
    inFile.open("Smart power index data - Economic Power.csv");
    string s;
    getline ( inFile, s, '\n' );
    while (!inFile.eof()) {
        country input;
        getline ( inFile, input.name, ',' );
        getline ( inFile, s, ',' );
        getline ( inFile, s, ',' );
        input.year = atoi(s.c_str());
        getline ( inFile, s, '\n' );
        input.points = atoi(s.c_str());
        economic_power.push_back(input);
    }
}
void read_enery_power(){
    ifstream inFile;
    inFile.open("Smart power index data - Energy Power.csv");
    string s;
    getline ( inFile, s, '\n' );
    while (!inFile.eof()) {
        country input;
        getline ( inFile, input.name, ',' );
        getline ( inFile, s, ',' );
        getline ( inFile, s, ',' );
        getline ( inFile, s, ',' );
        input.year = atoi(s.c_str());
        getline ( inFile, s, '\n' );
        input.points = atoi(s.c_str());
        enery_power.push_back(input);
    }
}
void read_military_power(){
    ifstream inFile;
    inFile.open("Smart power index data - Military Power.csv");
    string s;
    getline ( inFile, s, '\n' );
    while (!inFile.eof()) {
        country input;
        getline ( inFile, input.name, ',' );
        getline ( inFile, s, ',' );
        getline ( inFile, s, ',' );
        input.year = atoi(s.c_str());
        getline ( inFile, s, '\n' );
        input.points = atoi(s.c_str());
        military_power.push_back(input);
    }
}
void read_people_power(){
    ifstream inFile;
    inFile.open("Smart power index data - People Power League.csv");
    string s;
    getline ( inFile, s, '\n' );
    while (!inFile.eof()) {
        country input;
        getline ( inFile, input.name, ',' );
        getline ( inFile, s, ',' );
        getline ( inFile, s, ',' );
        getline ( inFile, s, ',' );
        input.year = atoi(s.c_str());
        getline ( inFile, s, '\n' );
        input.points = atoi(s.c_str());
        people_power.push_back(input);
    }
}
void read_smart_power(){
    ifstream inFile;
    inFile.open("Smart power index data - Smart Power Index.csv");
    string s;
    getline ( inFile, s, '\n' );
    while (!inFile.eof()) {
        country input;
        getline ( inFile, input.name, ',' );
        getline ( inFile, s, ',' );
        getline ( inFile, s, ',' );
        input.year = atoi(s.c_str());
        getline ( inFile, s, '\n' );
        input.points = atoi(s.c_str());
        smart_power.push_back(input);
    }
}
void read_files(){
    read_smart_power();
    read_enery_power();
    read_people_power();
    read_economic_power();
    read_military_power();
}

int year_selection(){
    for(int i =1 ;i<=29 ;i++)
        {
            if( i <= 9)
                cout<<"\n199"<<i;
            else if(i <= 19)
                cout<<"\n200"<<i-10;
            else
                cout<<"\n20"<<i-10;
        }
    int y;cout<<"\n_";cin>>y;
    return y;
}

void RightSelectionSort(vector<country>& a){
    for (int i=0 ; i< a.size()-1 ; i++) {
        int max=i;
        for (int j=i+1; j< a.size() ; j++) {
            if(a[j]>a[max]){
                max=j;
            }
        }
        if(max!=i){
            swap(a[i],a[max]);
        }
    }
}
vector<country> economic_power_yearly;
vector<country> enery_power_yearly;
vector<country> military_power_yearly;
vector<country> people_power_yearly;
vector<country> state_power_yearly;
vector<country> smart_power_yearly;

void sort_by_points(){
    RightSelectionSort(smart_power_yearly);
    RightSelectionSort(private_wealth);
    RightSelectionSort(economic_power_yearly);
    RightSelectionSort(state_power_yearly);
    RightSelectionSort(people_power_yearly);
    RightSelectionSort(military_power_yearly);
    RightSelectionSort(enery_power_yearly);
}

string country_names[] = {"Brazil", "Canada", "US", "China", "France", "Germany", "India", "Italy", "Japan", "Russia", "UK"};

void award_rank(int year){
    for (auto i = 0; i < 11; i++) {
        country st;
        st.name = country_names[i];
        if( i == 0)
            cin.ignore();
        cout<<"Enter rank for "<<st.name<<" for year "<<year<< " :"; cin>>st.rank;
        st.points = 10*st.rank;
        private_wealth.push_back(st);
        for (auto i = 0; i < enery_power.size(); i++) {
            if(enery_power[i].year == year && enery_power[i].name == st.name){
                country val = enery_power[i];
                val.points += st.points;
                enery_power_yearly.push_back(val);
            }
        }
        
        for (auto i = 0; i < economic_power.size(); i++) {
            if(economic_power[i].year == year && economic_power[i].name == st.name){
                country val = economic_power[i];
                val.points += (st.points * .1);
                economic_power_yearly.push_back(val);
            }
        }
        
        for (auto i = 0; i < smart_power.size(); i++) {
            if(smart_power[i].year == year && smart_power[i].name == st.name){
                country val = smart_power[i];
                val.points += 1;
                smart_power_yearly.push_back(val);
            }
        }
        
        for (auto i = 0; i < military_power.size(); i++) {
            if(military_power[i].year == year && military_power[i].name == st.name){
                country val = military_power[i];
                country plus = smart_power_yearly.back();
                val.points += (plus.points*.2);
                military_power_yearly.push_back(val);
            }
        }
        
        
        for (auto i = 0; i < people_power.size(); i++) {
            if(people_power[i].year == year && people_power[i].name == st.name){
                country val = people_power[i];
                country plus = smart_power_yearly.back();
                val.points += (plus.points*.1);
                people_power_yearly.push_back(val);
            }
        }
        
        country st2;
        st2 = smart_power_yearly.back();
        st2.points *= .4;
        state_power_yearly.push_back(st2);
    }
}

void display(int year){
    cout<<"For the year "<<year<<" here's how countries are ranking\n";
    cout<<"Smart Power Index\n";
    cout<<"Name"<<"\t"<<"Year"<<"\t"<<"Points"<<endl;
    for (auto i = 0; i < smart_power_yearly.size(); i++) {
        cout<<smart_power_yearly[i];
    }
    cout<<"\nPrivate Wealth\n";
    cout<<"Name"<<"\t"<<"Year"<<"\t"<<"Points"<<endl;
    for (auto i = 0; i < private_wealth.size(); i++) {
        cout<<private_wealth[i];
    }
    cout<<"\nEconomical Power\n";
    cout<<"Name"<<"\t"<<"Year"<<"\t"<<"Points"<<endl;
    for (auto i = 0; i < economic_power_yearly.size(); i++) {
        cout<<economic_power_yearly[i];
    }
    cout<<"\nEnergy Power\n";
    cout<<"Name"<<"\t"<<"Year"<<"\t"<<"Points"<<endl;
    for (auto i = 0; i < enery_power_yearly.size(); i++) {
        cout<<enery_power_yearly[i];
    }
    cout<<"\nMilitary Power\n";
    cout<<"Name"<<"\t"<<"Year"<<"\t"<<"Points"<<endl;
    for (auto i = 0; i < military_power_yearly.size(); i++) {
        cout<<military_power_yearly[i];
    }
    cout<<"\nPeople Power\n";
    cout<<"Name"<<"\t"<<"Year"<<"\t"<<"Points"<<endl;
    for (auto i = 0; i < people_power_yearly.size(); i++) {
        cout<<people_power_yearly[i];
    }
    cout<<"\nState Power\n";
    cout<<"Name"<<"\t"<<"Year"<<"\t"<<"Points"<<endl;
    for (auto i = 0; i < state_power_yearly.size(); i++) {
        cout<<state_power_yearly[i];
    }

}


int main(int argc, const char * argv[]) {
    read_files();
    cout<<"Select a year:";
    int year = year_selection();
    award_rank(year);
    sort_by_points();
    display(year);
}
