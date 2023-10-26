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


class subscriberPerComp : public subscribersClass{
    private:
    string Location;
    int Subscribers;

    public:
    subscriberPerComp(){
    }

    subscriberPerComp(string Location, int Subscribers){
        this->Location = Location;
        this->Subscribers = Subscribers;
    }

    string get_Location() {
        return Location;
    }
    int get_Subscribers() {
        return Subscribers;
    }


    void findSubscriberAirtel(subscribersClass* subs,subscriberPerComp* Airtelsubscriber){
        int ind1 = 0;
        for( int i =0;i<100;i++){
            if(subs[i].get_company()=="Airtel"){
                Airtelsubscriber[ind1] = subscriberPerComp(subs[i].get_Location(), stoi(subs[i].get_Subscribers()));
                ind1++;
            }
        }
    }

    void findSubscriberBSNL(subscribersClass* subs,subscriberPerComp* BSNLsubscriber){
        int ind2 = 0;
        for( int i =0;i<100;i++){
            if(subs[i].get_company()=="BSNL"){
            BSNLsubscriber[ind2] = subscriberPerComp(subs[i].get_Location(), stoi(subs[i].get_Subscribers()));
            ind2++;
            }
        }
    }

    void findSubscriberJio(subscribersClass* subs,subscriberPerComp* Jiosubscriber){
        int ind3 = 0;
            for( int i =0;i<100;i++){
            if(subs[i].get_company()=="Jio"){
            Jiosubscriber[ind3] = subscriberPerComp(subs[i].get_Location(), stoi(subs[i].get_Subscribers()));
            ind3++;
            }
        }
    }

    void findSubscriberVodafone(subscribersClass* subs,subscriberPerComp* Vodafonesubscriber){
        int ind4 = 0;
        for( int i =0;i<100;i++){
             if(subs[i].get_company()=="Vodafone"){
            Vodafonesubscriber[ind4] = subscriberPerComp(subs[i].get_Location(), stoi(subs[i].get_Subscribers()));
            ind4++;
            }
        }
    }

    int* findSubscriberLocation(subscriberPerComp* Airtelsubscriber,int size){
        int* location = new int[6];
        int subscribers = 0 ;
        for(int i =0;i<size;i++){
            if(Airtelsubscriber[i].get_Location()=="Delhi")
               subscribers+=Airtelsubscriber[i].get_Subscribers(); 
        }
        location[0] = subscribers;
        subscribers = 0 ;
        for(int i =0;i<size;i++){
            if(Airtelsubscriber[i].get_Location()=="Chandigarh")
                subscribers+=Airtelsubscriber[i].get_Subscribers(); 
        }
        location[1] = subscribers;
        subscribers = 0 ;
        for(int i =0;i<size;i++){
            if(Airtelsubscriber[i].get_Location()=="Jaipur")
                subscribers+=Airtelsubscriber[i].get_Subscribers(); 
        }
        location[2] = subscribers;
        subscribers = 0 ;
        for(int i =0;i<size;i++){
            if(Airtelsubscriber[i].get_Location()=="Kolkata")
                subscribers+=Airtelsubscriber[i].get_Subscribers(); 
        }
        location[3] = subscribers;
        subscribers = 0 ;
        for(int i =0;i<size;i++){
            if(Airtelsubscriber[i].get_Location()=="Lucknow")
                subscribers+=Airtelsubscriber[i].get_Subscribers(); 
        }
        location[4] = subscribers;
        subscribers = 0 ;
        for(int i =0;i<size;i++){
            if(Airtelsubscriber[i].get_Location()=="Patna")
                subscribers+=Airtelsubscriber[i].get_Subscribers(); 
        }
        location[5] = subscribers;
        return location;
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
    cout<<"\n\t\t\t\tSpectrum Range\n"<<endl;
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

    //  // printing the spectrumRequest CSV file
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


    // Find Number of Subscriber per Company
    subscriberPerComp* subs = new subscriberPerComp();
   
    subscriberPerComp* Airtelsubscriber= new subscriberPerComp[24];
    subscriberPerComp* BSNLsubscriber= new subscriberPerComp[31];
    subscriberPerComp* Jiosubscriber= new subscriberPerComp[18];
    subscriberPerComp* Vodafonesubscriber= new subscriberPerComp[27];
 
        
    subs->findSubscriberAirtel(subscribers,Airtelsubscriber);
    subs->findSubscriberBSNL(subscribers,BSNLsubscriber);
    subs->findSubscriberJio(subscribers,Jiosubscriber);
    subs->findSubscriberVodafone(subscribers,Vodafonesubscriber);


    // Print the Subscibers per Company
    cout<<"\n\t  Airtel Subscriber\n"<<endl;
    for(int i=0;i<24;i++){
            cout<<Airtelsubscriber[i].get_Subscribers()<<" \t"<<Airtelsubscriber[i].get_Location()<<endl;
    }
    cout<<"\n\t  BSNL Subscriber\n"<<endl;
    for(int i=0;i<31;i++){
            cout<<BSNLsubscriber[i].get_Subscribers()<<" \t"<<BSNLsubscriber[i].get_Location()<<endl;
    }
    cout<<"\n\t  Jio Subscriber\n"<<endl;
    for(int i=0;i<18;i++){
            cout<<Jiosubscriber[i].get_Subscribers()<<" \t"<<Jiosubscriber[i].get_Location()<<endl;
    }
    cout<<"\n\t  Vodafone Subscriber\n"<<endl;
    for(int i=0;i<27;i++){
            cout<<Vodafonesubscriber[i].get_Subscribers()<<" \t"<<Vodafonesubscriber[i].get_Location()<<endl;
    }

    // Find Subscribers for Each Location
    int* subsAirtel = subs->findSubscriberLocation(Airtelsubscriber,24);
    int* subsBSNL = subs->findSubscriberLocation(BSNLsubscriber,31);
    int* subsJio = subs->findSubscriberLocation(Jiosubscriber,18);
    int* subsVoda= subs->findSubscriberLocation(Vodafonesubscriber,27);

    string location[] = {"Delhi","Chandigarh","Jaipur","Kolkata","Lucknow","Patna"}; 

    cout<<"\n  Airtel Subscriber per Location\n"<<endl;
    for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
            cout<<location[i]<<"\t   ---------->\t"<<subsAirtel[i]<<endl;
        else
            cout<<location[i]<<" ---------->\t"<<subsAirtel[i]<<endl;
    }

    cout<<"\n  BSNL Subscriber per Location\n"<<endl;
    for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
            cout<<location[i]<<"\t   ---------->\t"<<subsBSNL[i]<<endl;
        else
            cout<<location[i]<<" ---------->\t"<<subsBSNL[i]<<endl;
    }

    cout<<"\n  Jio Subscriber per Location\n"<<endl;
    for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
            cout<<location[i]<<"\t   ---------->\t"<<subsJio[i]<<endl;
        else
            cout<<location[i]<<" ---------->\t"<<subsJio[i]<<endl;
    }

    cout<<"\n  Vodafone Subscriber per Location\n"<<endl;
    for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
            cout<<location[i]<<"\t   ---------->\t"<<subsVoda[i]<<endl;
        else
            cout<<location[i]<<" ---------->\t"<<subsVoda[i]<<endl;
    }
    
    return 0;
}
