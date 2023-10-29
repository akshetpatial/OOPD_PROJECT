#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
using namespace std;
#ifndef CLASSES_H
#define CLASSES_H

//Class For MVNOSpectrum_Updated - MVNOSpectrum.csv
class mvno_request_upd{
    public:
    string date;
    string company;
    string location;
    float request;
    int h_code;

    //Default Constructor.
    mvno_request_upd(){

    }

    //Creating User Defined Constructor.
    mvno_request_upd(string date,string company,string location,float request,int h_code){
        this->date=date;
        this->company=company;
        this->location=location;
        this->request=request;
        this->h_code=h_code;
    }

};

//Reading the MVNOSpectrum_Updated - MVNOSpectrum.csv
void read_mvno_request_upd(mvno_request_upd *req_read){
    
    //Defining variables.
    string date;
    string company;
    string location;
    string request;
    string h_code;
    string line;
    int row=0;

    //Reading the csv file.
    ifstream read("MVNOSpectrum_Updated - MVNOSpectrum.csv");

    //Read the first line.
    getline(read,line);
    line=" ";

    //Read the reamaining lines.
    while(getline(read,line) && row<20){

        stringstream linestream(line);

        getline(linestream,date,',');
        getline(linestream,company,',');
        getline(linestream,location,',');
        getline(linestream,request,',');
        getline(linestream,h_code,',');

        //Constructor call and storing the data.
        req_read[row]=mvno_request_upd(date,company,location,stof(request),stoi(h_code));
        row++;
        line=" ";

    }

}

//Printing the MVNOSpectrum_Updated - MVNOSpectrum.csv
void info_mvno_request_upd(mvno_request_upd *req_read){
    cout<<"\nDATE"<<" \t"<<"COMPANY"<<"   "<<"LOCATION"<<" \t"<<"REQUEST"<<"   "<<"HASH_CODE"<<endl;
    cout<<endl;
    for(int i=0;i<20;i++){
        cout<<req_read[i].date<<" \t"<<req_read[i].company<<"\t  "<<req_read[i].location<<" \t"<<req_read[i].request<<" \t  "<<req_read[i].h_code<<endl;
    }
    cout<<endl;
}

//Class For AllocationSpectrum.csv
class licensed_allocation{
    public:
    string company;
    string location;
    int request;

    //Default Constructor.
    licensed_allocation(){

    }

    //Creating User Defined Constructor.
    licensed_allocation(string company,string location,int request){
        this->company=company;
        this->location=location;
        this->request=request;
    }

};

//Reading the AllocationSpectrum.csv
void read_licensed_allocation(licensed_allocation *licensed_read){
    
    //Defining variables.
    string company;
    string location;
    string request;
    string line;
    int row=0;

    //Reading the csv file.
    ifstream read("AllocationSpectrum.csv");

    //Read the first line.
    getline(read,line);
    line=" ";

    //Read the reamaining lines.
    while(getline(read,line) && row<24){

        stringstream linestream(line);

        getline(linestream,location,',');
        getline(linestream,request,',');
        getline(linestream,company,',');

        //Constructor call and storing the data.
        licensed_read[row]=licensed_allocation(company,location,stoi(request));
        row++;
        line=" ";

    }

}

//Printing the AllocationSpectrum.csv
void info_licensed_allocation(licensed_allocation *licensed_read){
    cout<<"LOCATION"<<" "<<"REQUEST"<<" "<<"COMPANY"<<endl;
    cout<<endl;
    for(int i=0;i<18;i++){
        cout<<licensed_read[i].location<<" "<<licensed_read[i].request<<" "<<licensed_read[i].company<<endl;
    }
    cout<<endl;
}

#endif 