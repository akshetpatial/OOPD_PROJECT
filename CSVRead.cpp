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

public:
    spectrumRangeClass(){
    }

    spectrumRangeClass(string date, string company, string spectrumRange){
        this->date = date;
        this->company = company;
        this->spectrumRange = spectrumRange;
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

        getline(ss, date, ',');
        getline(ss, company, ',');
        getline(ss, spectrumRange, ',');

        data[i] = spectrumRangeClass(date, company, spectrumRange); 
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
    cout<<"\t\t\t\t\t\t\t\tspectrumRange"<<endl;
    for(int i=0;i<index_spectrumRange;i++){
        cout<<spectrumRange[i].get_date()<<" "<<spectrumRange[i].get_company()<<" "<<spectrumRange[i].get_spectrumRange()<<endl;
    }

    // printing the subscribers CSV file
    cout<<"\t\t\t\t\t\t\tsubscribers"<<endl;
    for(int i=0;i<index_subscribers;i++){
        cout<<subscribers[i].get_date()<<" "<<subscribers[i].get_company()<<" "<<subscribers[i].get_Location()<<" "<<subscribers[i].get_Subscribers()<<endl;
    }

     // printing the spectrumRequest CSV file
     cout<<"\t\t\t\t\t\t\tspectrumRequest"<<endl;
    for(int i=0;i<index_spectrumRequest;i++){
        cout<<spectrumRequest[i].get_date()<<" "<<spectrumRequest[i].get_company()<<" "<<spectrumRequest[i].get_Location()<<" "<<spectrumRequest[i].get_Request()<<endl;
    }

    return 0;
}
