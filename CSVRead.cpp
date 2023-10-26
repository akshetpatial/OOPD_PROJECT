#include <iostream>
#include <fstream>
#include <sstream>
#include <string>

using namespace std;

class spectrumRangeClass{

private:
    string date;
    string company;
    string spectrumRange;
    string circle;
    string revenue;

public:
    spectrumRangeClass(){
    }

    spectrumRangeClass(string date, string company, string spectrumRange,string circle,string revenue){
        this->date = date;
        this->company = company;
        this->spectrumRange = spectrumRange;
        this->circle = circle;
        this->revenue = revenue;
    }

    string get_date() {
        return date;
    }
    string get_company() {
        return company;
    }
    string get_spectrumRange() {
        return spectrumRange;
    }
    string get_circle() {
        return circle;
    }
    string get_revenue() {
        return revenue;
    }
};


class subscribersClass{

private:
    string date;
    string company;
    string Location;
    string Subscribers;

public:
    subscribersClass(){
    }

    subscribersClass(string date, string company, string Location, string Subscribers){
        this->date = date;
        this->company = company;
        this->Location = Location;
        this->Subscribers = Subscribers;
    }

    string get_date() {
        return date;
    }
     string get_company() {
        return company;
    }
    string get_Location() {
        return Location;
    }
    string get_Subscribers() {
        return Subscribers;
    }

};

class spectrumRequestClass{

private:
    string date;
    string company;
    string Location;
    string Request;

public:
    spectrumRequestClass(){
    }

    spectrumRequestClass(string date, string company, string Location, string Request){
        this->date = date;
        this->company = company;
        this->Location = Location;
        this->Request = Request;
    }

    string get_date() {
        return date;
    }
     string get_company() {
        return company;
    }
    string get_Location() {
        return Location;
    }
    string get_Request() {
        return Request;
    }

};


spectrumRangeClass* readCSVFileRange(const string& filename) {

    spectrumRangeClass* data =  new spectrumRangeClass[100];

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open the CSV file." << endl;
        exit(1);
    }

    string line;
    int i=0;

    getline(file, line);

    while (getline(file, line)) {
        istringstream ss(line);
        string date;
        string company;
        string spectrumRange;
        string circle;
        string revenue;

        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, spectrumRange, ',');
        getline(ss, circle, ',');
        getline(ss, revenue, ',');

        data[i] = spectrumRangeClass(date, company, spectrumRange,circle,revenue); 
        // cout<<data[i].get_date()<<" "<<data[i].get_company()<<" "<<data[i].get_spectrumRange()<<endl;
        i++;
    }
    file.close();
    return data;
}


subscribersClass* readCSVFileSub(const string& filename) {

    subscribersClass* data =  new subscribersClass[100];

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open the CSV file." << endl;
        exit(1);
    }

    string line;
    int i=0;

    getline(file, line);

    while (getline(file, line)) {
        istringstream ss(line);
        string date;
        string company;
        string Location;
        string Subscribers;

        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, Location, ',');
        getline(ss, Subscribers, ',');

        data[i] = subscribersClass(date, company, Location, Subscribers); 
        i++;
    }
    file.close();
    return data;
}

spectrumRequestClass* readCSVFileReq(const string& filename) {

    spectrumRequestClass* data =  new spectrumRequestClass[100];

    ifstream file(filename);

    if (!file.is_open()) {
        cerr << "Error: Could not open the CSV file." << endl;
        exit(1);
    }

    string line;
    int i=0;

    getline(file, line);

    while (getline(file, line)) {
        istringstream ss(line);
        string date;
        string company;
        string Location;
        string Request;

        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, Location, ',');
        getline(ss, Request, ',');

        data[i] = spectrumRequestClass(date, company, Location, Request); 
        i++;
    }
    file.close();
    return data;
}


int main(){

    int index_spectrumRange = 100 ;
    int index_subscribers = 100 ;
    int index_spectrumRequest = 100 ;

    spectrumRangeClass* spectrumRange = readCSVFileRange("spectrumRange.csv");

    subscribersClass* subscribers = readCSVFileSub("subscribers.csv");

    spectrumRequestClass* spectrumRequest = readCSVFileReq("spectrumRequest.csv");
    
    // printing the spectrumRange CSV file
    cout<<"\t\t\t\tSpectrum Range\n"<<endl;
    for(int i=0;i<index_spectrumRange;i++){
        if(spectrumRange[i].get_company()!="Vodafone")
            cout<<spectrumRange[i].get_date()<<" \t"<<spectrumRange[i].get_company()<<" \t\t"<<spectrumRange[i].get_spectrumRange()<<" \t";
        if(spectrumRange[i].get_company()=="Vodafone")
            cout<<spectrumRange[i].get_date()<<" \t"<<spectrumRange[i].get_company()<<" \t"<<spectrumRange[i].get_spectrumRange()<<" \t";
        if(spectrumRange[i].get_circle()=="Kolkata" || spectrumRange[i].get_circle()=="Chandigarh" || spectrumRange[i].get_circle()=="Lucknow" )
            cout<<spectrumRange[i].get_circle()<<" \t"<<spectrumRange[i].get_revenue()<<endl;
        else
            cout<<spectrumRange[i].get_circle()<<" \t\t"<<spectrumRange[i].get_revenue()<<endl;

    }

    // printing the subscribers CSV file
    cout<<"\n\t\t  Subscribers\n"<<endl;
    for(int i=0;i<index_subscribers;i++){
        if(subscribers[i].get_company()!="Vodafone")
            cout<<subscribers[i].get_date()<<" \t"<<subscribers[i].get_company()<<" \t\t";
        if(subscribers[i].get_company()=="Vodafone")
            cout<<subscribers[i].get_date()<<" \t"<<subscribers[i].get_company()<<" \t";
        if(subscribers[i].get_Location()=="Kolkata" || subscribers[i].get_Location()=="Chandigarh" || subscribers[i].get_Location()=="Lucknow" )
             cout<<subscribers[i].get_Location()<<" \t"<<subscribers[i].get_Subscribers()<<endl;
        else
            cout<<subscribers[i].get_Location()<<" \t\t"<<subscribers[i].get_Subscribers()<<endl;
    }

     // printing the spectrumRequest CSV file
     cout<<"\n\t\t  Spectrum Request\n"<<endl;
    for(int i=0;i<index_spectrumRequest;i++){
        if(spectrumRequest[i].get_company()!="Vodafone")
            cout<<spectrumRequest[i].get_date()<<" \t"<<spectrumRequest[i].get_company()<<" \t\t";
        if(spectrumRequest[i].get_company()=="Vodafone")
            cout<<spectrumRequest[i].get_date()<<" \t"<<spectrumRequest[i].get_company()<<" \t";
        if(spectrumRequest[i].get_Location()=="Kolkata" || spectrumRequest[i].get_Location()=="Chandigarh" || spectrumRequest[i].get_Location()=="Lucknow" )
            cout<<spectrumRequest[i].get_Location()<<" \t"<<spectrumRequest[i].get_Request()<<endl;
        else
            cout<<spectrumRequest[i].get_Location()<<" \t\t"<<spectrumRequest[i].get_Request()<<endl;

    }

    return 0;
}
