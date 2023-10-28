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
    int revenue;

public:
    spectrumRangeClass(){
    }

    spectrumRangeClass(string date, string company, string spectrumRange,string circle,int revenue){
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
    int get_revenue() {
        return revenue;
    }
};

class spectrumRangePerComp : public spectrumRangeClass{
    private:
    string Location;
    string spectrum;
    int revenue;

    public:
    spectrumRangePerComp(){
    }

    spectrumRangePerComp(string Location, string spectrum,int revenue){
        this->Location = Location;
        this->spectrum = spectrum;
        this->revenue=revenue;
    }

    string get_Location() {
        return Location;
    }
    string get_spectrum() {
        return spectrum;
    }
    int get_revenue(){
        return revenue;
    }


    void findSpectrumAirtel(spectrumRangeClass* spect,spectrumRangePerComp* Airtelspectrum){
        int ind1 = 0;
        for( int i =0;i<100;i++){
            if(spect[i].get_company()=="Airtel"){
                Airtelspectrum[ind1] = spectrumRangePerComp(spect[i].get_circle(), spect[i].get_spectrumRange(), spect[i].get_revenue());
                ind1++;
            }
        }
    }

    void findSpectrumBSNL(spectrumRangeClass* spect,spectrumRangePerComp* BSNLspectrum){
        int ind2 = 0;
        for( int i =0;i<100;i++){
            if(spect[i].get_company()=="BSNL"){
            BSNLspectrum[ind2] = spectrumRangePerComp(spect[i].get_circle(), spect[i].get_spectrumRange(), spect[i].get_revenue());
            ind2++;
            }
        }
    }

    void findSpectrumJio(spectrumRangeClass* spect,spectrumRangePerComp* Jiospectrum){
        int ind3 = 0;
            for( int i =0;i<100;i++){
            if(spect[i].get_company()=="Jio"){
            Jiospectrum[ind3] = spectrumRangePerComp(spect[i].get_circle(), spect[i].get_spectrumRange(), spect[i].get_revenue());
            ind3++;
            }
        }
    }

    void findSpectrumVodafone(spectrumRangeClass* spect,spectrumRangePerComp* Vodafonespectrum){
        int ind4 = 0;
        for( int i =0;i<100;i++){
             if(spect[i].get_company()=="Vodafone"){
            Vodafonespectrum[ind4] = spectrumRangePerComp(spect[i].get_circle(),spect[i].get_spectrumRange(), spect[i].get_revenue());
            ind4++;
            }
        }
    }

    string* findSpectrumLocation(spectrumRangePerComp* spectrum,int size){
        string* location = new string[6];
        string spect = "";
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Delhi")
               spect+=spectrum[i].get_spectrum()+" "; 
        }
        location[0] = spect;
        spect = "" ;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Chandigarh")
                spect+=spectrum[i].get_spectrum()+" "; 
        }
        location[1] = spect;
        spect = "" ;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Jaipur")
                spect+=spectrum[i].get_spectrum()+" "; 
        }
        location[2] = spect;
        spect = "" ;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Kolkata")
                spect+=spectrum[i].get_spectrum()+" "; 
        }
        location[3] = spect;
        spect = "" ;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Lucknow")
                spect+=spectrum[i].get_spectrum()+" "; 
        }
        location[4] = spect;
        spect = "" ;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Patna")
                spect+=spectrum[i].get_spectrum()+" "; 
        }
        location[5] = spect;
        return location;
    }

     int* findSpectrumRevenue(spectrumRangePerComp* spectrum,int size){
        int* Revenue = new int[6];
        int sum =0;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Delhi")
               sum+=spectrum[i].get_revenue(); 
        }
        Revenue[0] = sum;
        sum = 0;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Chandigarh")
                sum+=spectrum[i].get_revenue(); 
        }
        Revenue[1] = sum;
        sum = 0;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Jaipur")
                sum+=spectrum[i].get_revenue(); 
        }
        Revenue[2] = sum;
        sum = 0;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Kolkata")
                sum+=spectrum[i].get_revenue(); 
        }
        Revenue[3] = sum;
        sum = 0;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Lucknow")
                sum+=spectrum[i].get_revenue(); 
        }
        Revenue[4] = sum;
        sum = 0;
        for(int i =0;i<size;i++){
            if(spectrum[i].get_Location()=="Patna")
                sum+=spectrum[i].get_revenue(); 
        }
        Revenue[5] = sum;
        return Revenue;
    }


    int findtotalspectrum(string &spect){
        string digits;
        int sum =0;
        for(int i =0;i<spect.length();i++){
            char ch = spect[i];
            if (ch >= '0' && ch <= '9')
                digits += ch;
            else {
                if (!digits.empty()) {
                sum += stoi(digits);  
                digits="";  
                }
            }
        }
        return sum;
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


class spectrumRequestPerSpectrum: public spectrumRequestClass{
    private:
    string Location;
    string company;

    public:
    spectrumRequestPerSpectrum(){
    }

    spectrumRequestPerSpectrum(string Location, string company){
        this->Location = Location;
        this->company = company;
    }

    string get_Location() {
        return Location;
    }
    string get_company() {
        return company;
    }

    void findrequest700(spectrumRequestClass* supectrum,spectrumRequestPerSpectrum* request700){
        int ind1 = 0;
        for( int i =0;i<100;i++){
            if(supectrum[i].get_Request()=="700"){
                request700[ind1] = spectrumRequestPerSpectrum(supectrum[i].get_Location(), supectrum[i].get_company());
                ind1++;
            }
        }
    }

    void findrequest800(spectrumRequestClass* supectrum,spectrumRequestPerSpectrum* request800){
        int ind2 = 0;
        for( int i =0;i<100;i++){
            if(supectrum[i].get_Request()=="800"){
                request800[ind2] = spectrumRequestPerSpectrum(supectrum[i].get_Location(), supectrum[i].get_company());
                ind2++;
            }
        }
    }

    void findrequest1800(spectrumRequestClass* supectrum,spectrumRequestPerSpectrum* request1800){
        int ind3 = 0;
            for( int i =0;i<100;i++){
                if(supectrum[i].get_Request()=="1800"){
                    request1800[ind3] = spectrumRequestPerSpectrum(supectrum[i].get_Location(), supectrum[i].get_company());
                    ind3++;
            }
        }
    }

    void findrequest3500(spectrumRequestClass* supectrum,spectrumRequestPerSpectrum* request3500){
        int ind4 = 0;
        for( int i =0;i<100;i++){
             if(supectrum[i].get_Request()=="3500"){
                request3500[ind4] = spectrumRequestPerSpectrum(supectrum[i].get_Location(), supectrum[i].get_company());
                ind4++;
            }
        }
    }


    string* findRequestLocation(spectrumRequestPerSpectrum* request,int size){
        string* location = new string[6];
        string companyName = "";
        for(int i =0;i<size;i++){
            if(request[i].get_Location()=="Delhi")
               companyName+=request[i].get_company()+" "; 
        }
        location[0] = companyName;
        companyName = "" ;
        for(int i =0;i<size;i++){
            if(request[i].get_Location()=="Chandigarh")
                companyName+=request[i].get_company()+" "; 
        }
        location[1] = companyName;
        companyName = "" ;
        for(int i =0;i<size;i++){
            if(request[i].get_Location()=="Jaipur")
                companyName+=request[i].get_company()+" "; 
        }
        location[2] = companyName;
        companyName = "" ;
        for(int i =0;i<size;i++){
            if(request[i].get_Location()=="Kolkata")
                companyName+=request[i].get_company()+" "; 
        }
        location[3] = companyName;
        companyName = "" ;
        for(int i =0;i<size;i++){
            if(request[i].get_Location()=="Lucknow")
                companyName+=request[i].get_company()+" "; 
        }
        location[4] = companyName;
        companyName = "" ;
        for(int i =0;i<size;i++){
            if(request[i].get_Location()=="Patna")
                companyName+=request[i].get_company()+" "; 
        }
        location[5] = companyName;
        return location;
    }

};

class spectrumDensity{

public:
    float findspectrumDensityforEachLocation(int &subscriber, int spectrum){
        float spect =  spectrum;
        return spect/subscriber;
    }

    string allocateSpectrum(string &req,float AirtelspecDensityLocation[],float BSNLspecDensityLocation[],float JiospecDensityLocation[],float VodafonespecDensityLocation[], int index){

        float min = INT_MAX;
        float min1 = 0.0 ;
        float min2 = 0.0 ;
        float min3 = 0.0 ;
        float min4 = 0.0 ;

        if(req.find("Vodafone")!= std::string::npos){
            min4 = VodafonespecDensityLocation[index];
            if(min > VodafonespecDensityLocation[index])
                min = VodafonespecDensityLocation[index];
        }
        if(req.find("Jio")!= std::string::npos){
            min3 = JiospecDensityLocation[index];
            if(min > JiospecDensityLocation[index])
                min = JiospecDensityLocation[index];
        }
        if(req.find("Airtel")!= std::string::npos){
            min1 = AirtelspecDensityLocation[index];
            if(min > AirtelspecDensityLocation[index])
                min = AirtelspecDensityLocation[index]; 
        }
        if(req.find("BSNL")!= std::string::npos){
            min2 = BSNLspecDensityLocation[index];
            if(min > BSNLspecDensityLocation[index])
                min = BSNLspecDensityLocation[index];
        }

        if(min == min1)
            return "Airtel";
        if(min == min2)
            return "BSNL";
        if(min == min3)
            return "Jio";  
        else
            return "Vodafone";  
    }
};

class revenueGenerated{
public:

    int RevenueGeneratedSpectrum(string SpectrumperAllocated,int AirtelRevenue[],int BSNLRevenue[],int JioRevenue[],int VodafoneRevenue[], int index){

        if(SpectrumperAllocated=="Airtel"){
            return AirtelRevenue[index];
        }
        if(SpectrumperAllocated=="BSNL"){
            return BSNLRevenue[index];
        }
        if(SpectrumperAllocated=="Jio"){
            return JioRevenue[index];
        }
        return VodafoneRevenue[index];     
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

        data[i] = spectrumRangeClass(date, company, spectrumRange,circle,stoi(revenue)); 
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

class print{
    
    public: 

    void printSpectrumRange(spectrumRangeClass spectrumRange[],int index_spectrumRange){
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
    }

    void printSubscribers(subscribersClass subscribers[],int index_subscribers){
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
    }

    void printSpectrumRequest(spectrumRequestClass spectrumRequest[],int index_spectrumRequest){
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
    }

    void printSubscibersperCompany(subscriberPerComp Airtelsubscriber[],subscriberPerComp BSNLsubscriber[],subscriberPerComp Jiosubscriber[],subscriberPerComp Vodafonesubscriber[]){
    // Print the Subscibers per Company
        cout<<"\n   Airtel Subscriber\n"<<endl;
        for(int i=0;i<24;i++){
                cout<<Airtelsubscriber[i].get_Subscribers()<<" \t"<<Airtelsubscriber[i].get_Location()<<endl;
        }
        cout<<"\n   BSNL Subscriber\n"<<endl;
        for(int i=0;i<31;i++){
                cout<<BSNLsubscriber[i].get_Subscribers()<<" \t"<<BSNLsubscriber[i].get_Location()<<endl;
        }
        cout<<"\n   Jio Subscriber\n"<<endl;
        for(int i=0;i<18;i++){
                cout<<Jiosubscriber[i].get_Subscribers()<<" \t"<<Jiosubscriber[i].get_Location()<<endl;
        }
        cout<<"\n   Vodafone Subscriber\n"<<endl;
        for(int i=0;i<27;i++){
                cout<<Vodafonesubscriber[i].get_Subscribers()<<" \t"<<Vodafonesubscriber[i].get_Location()<<endl;
        }
    }

    void printSubscibersperLocation(string location[], int subsAirtel[],int subsBSNL[],int subsJio[],int subsVoda[]){
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
    }

    void printSpectrumRequestperCompany(spectrumRequestPerSpectrum request700[],spectrumRequestPerSpectrum request800[],spectrumRequestPerSpectrum request1800[], spectrumRequestPerSpectrum request3500[]){
    // Print the Spectrum per Company
        cout<<"\n    Spectrum 700\n"<<endl;
        for(int i=0;i<20;i++){
            if(request700[i].get_company()!="Vodafone")
                cout<<request700[i].get_company()<<" \t\t"<<request700[i].get_Location()<<endl;
            else
                cout<<request700[i].get_company()<<" \t"<<request700[i].get_Location()<<endl;
        }
        cout<<"\n    Spectrum 800\n"<<endl;
        for(int i=0;i<22;i++){
            if(request800[i].get_company()!="Vodafone")
                cout<<request800[i].get_company()<<" \t\t"<<request800[i].get_Location()<<endl;
            else   
                cout<<request800[i].get_company()<<" \t"<<request800[i].get_Location()<<endl;
        }
        cout<<"\n    Spectrum 1800\n"<<endl;
        for(int i=0;i<28;i++){
            if(request1800[i].get_company()!="Vodafone")
            cout<<request1800[i].get_company()<<" \t\t"<<request1800[i].get_Location()<<endl;
            else   
                cout<<request1800[i].get_company()<<" \t"<<request1800[i].get_Location()<<endl;
        }
        cout<<"\n   Spectrum 3500\n"<<endl;
        for(int i=0;i<30;i++){
            if(request3500[i].get_company()!="Vodafone")
            cout<<request3500[i].get_company()<<" \t\t"<<request3500[i].get_Location()<<endl;
            else   
                cout<<request3500[i].get_company()<<" \t"<<request3500[i].get_Location()<<endl;
        }
    }

    void printSpectrumRequestperLocation(string location[], string req700[], string req800[],string req1800[],string req3500[]){
    cout<<"\n  700 Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<req700[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<req700[i]<<endl;
        }

        cout<<"\n  800 Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<req800[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<req800[i]<<endl;
        }

        cout<<"\n  1800 Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<req1800[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<req1800[i]<<endl;
        }

        cout<<"\n  3500 Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<req3500[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<req3500[i]<<endl;
        }
    }

    void printSpectrumRangeperCompany(spectrumRangePerComp Airtelspectrum[], spectrumRangePerComp BSNLspectrum[],spectrumRangePerComp Jiospectrum[],spectrumRangePerComp Vodafonespectrum[]){
    // Print the Spectrum per Company
        cout<<"\n\t  Airtel Spectrum\n"<<endl;
        cout<<"Location"<<"\tSpectrum"<<"\tRevenue(Crores)\n"<<endl;
        for(int i=0;i<22;i++){
            if(Airtelspectrum[i].get_Location()=="Kolkata" || Airtelspectrum[i].get_Location()=="Chandigarh" || Airtelspectrum[i].get_Location()=="Lucknow" )
                cout<<Airtelspectrum[i].get_Location()<<" \t"<<Airtelspectrum[i].get_spectrum()<<" \t"<<Airtelspectrum[i].get_revenue()<<endl;
            else
                cout<<Airtelspectrum[i].get_Location()<<" \t\t"<<Airtelspectrum[i].get_spectrum()<<" \t"<<Airtelspectrum[i].get_revenue()<<endl;
        }
        cout<<"\n\t  BSNL Spectrum\n"<<endl;
        cout<<"Location"<<"\tSpectrum"<<"\tRevenue(Crores)\n"<<endl;
        for(int i=0;i<24;i++){
                if(BSNLspectrum[i].get_Location()=="Kolkata" || BSNLspectrum[i].get_Location()=="Chandigarh" || BSNLspectrum[i].get_Location()=="Lucknow" )
                cout<<BSNLspectrum[i].get_Location()<<" \t"<<BSNLspectrum[i].get_spectrum()<<" \t"<<BSNLspectrum[i].get_revenue()<<endl;
            else
                cout<<BSNLspectrum[i].get_Location()<<" \t\t"<<BSNLspectrum[i].get_spectrum()<<" \t"<<BSNLspectrum[i].get_revenue()<<endl;
        }
        cout<<"\n\t  Jio Spectrum\n"<<endl;
        cout<<"Location"<<"\tSpectrum"<<"\tRevenue(Crores)\n"<<endl;
        for(int i=0;i<27;i++){
                if(Jiospectrum[i].get_Location()=="Kolkata" || Jiospectrum[i].get_Location()=="Chandigarh" || Jiospectrum[i].get_Location()=="Lucknow" )
                cout<<Jiospectrum[i].get_Location()<<" \t"<<Jiospectrum[i].get_spectrum()<<" \t"<<Jiospectrum[i].get_revenue()<<endl;
            else
                cout<<Jiospectrum[i].get_Location()<<" \t\t"<<Jiospectrum[i].get_spectrum()<<" \t"<<Jiospectrum[i].get_revenue()<<endl;
        }
        cout<<"\n\t  Vodafone Spectrum\n"<<endl;
        cout<<"Location"<<"\tSpectrum"<<"\tRevenue(Crores)\n"<<endl;
        for(int i=0;i<27;i++){
                if(Vodafonespectrum[i].get_Location()=="Kolkata" || Vodafonespectrum[i].get_Location()=="Chandigarh" || Vodafonespectrum[i].get_Location()=="Lucknow" )
                cout<<Vodafonespectrum[i].get_Location()<<" \t"<<Vodafonespectrum[i].get_spectrum()<<" \t"<<Vodafonespectrum[i].get_revenue()<<endl;
            else
                cout<<Vodafonespectrum[i].get_Location()<<" \t\t"<<Vodafonespectrum[i].get_spectrum()<<" \t"<<Vodafonespectrum[i].get_revenue()<<endl;
        }
    }

    void printRevenueperLocation(string location[], int AirtelRevenue[], int BSNLRevenue[],int JioRevenue[],int VodafoneRevenue[], string Airtelspect[],string BSNLspect[], string Jiospect[], string Vodafonespect[]){
    cout<<"\n\t Airtel Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<AirtelRevenue[i]<<"\t"<<Airtelspect[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<AirtelRevenue[i]<<"\t"<<Airtelspect[i]<<endl;
        }
        
        cout<<"\n\t BSNL Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<BSNLRevenue[i]<<"\t"<<BSNLspect[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<BSNLRevenue[i]<<"\t"<<BSNLspect[i]<<endl;
        }

        cout<<"\n\t Jio Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<JioRevenue[i]<<"\t"<<Jiospect[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<JioRevenue[i]<<"\t"<<Jiospect[i]<<endl;
        }

        cout<<"\n\t Vodafone Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<VodafoneRevenue[i]<<"\t"<<Vodafonespect[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<VodafoneRevenue[i]<<"\t"<<Vodafonespect[i]<<endl;
        }
    }

    void printTotalSpectrumRangeperLocation(string location[],int TotalAirtelSpectrumperLocation[], int TotalBSNLSpectrumperLocation[], int TotalJioSpectrumperLocation[], int TotalVodafoneSpectrumperLocation[] ){
    cout<<"\n Total Airtel Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    cout<<location[i]<<"\t   ---------->\t"<<TotalAirtelSpectrumperLocation[i]<<" MHz"<<endl;
                else
                    cout<<location[i]<<" ---------->\t"<<TotalAirtelSpectrumperLocation[i]<<" MHz"<<endl;
        }

        cout<<"\n Total BSNL Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    cout<<location[i]<<"\t   ---------->\t"<<TotalBSNLSpectrumperLocation[i]<<" MHz"<<endl;
                else
                    cout<<location[i]<<" ---------->\t"<<TotalBSNLSpectrumperLocation[i]<<" MHz"<<endl;
        }

        cout<<"\n Total Jio Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    cout<<location[i]<<"\t   ---------->\t"<<TotalJioSpectrumperLocation[i]<<" MHz"<<endl;
                else
                    cout<<location[i]<<" ---------->\t"<<TotalJioSpectrumperLocation[i]<<" MHz"<<endl;
        }

        cout<<"\n Total Vodafone Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<TotalVodafoneSpectrumperLocation[i]<<" MHz"<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<TotalVodafoneSpectrumperLocation[i]<<" MHz"<<endl;
        }
    }

    void printSpectrumDesityperLocation(string location[], float AirtelspecDensityLocation[], float BSNLspecDensityLocation[],float JiospecDensityLocation[],float VodafonespecDensityLocation[]){
        cout<<"\n  Airtel Spectrum Density per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    cout<<location[i]<<"\t   ---------->\t"<<AirtelspecDensityLocation[i]<<endl;
                else
                    cout<<location[i]<<" ---------->\t"<<AirtelspecDensityLocation[i]<<endl;
        }

        cout<<"\n  BSNL Spectrum Density per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    cout<<location[i]<<"\t   ---------->\t"<<BSNLspecDensityLocation[i]<<endl;
                else
                cout<<location[i]<<" ---------->\t"<<BSNLspecDensityLocation[i]<<endl;
        }

        cout<<"\n  Jio Spectrum Density per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    cout<<location[i]<<"\t   ---------->\t"<<JiospecDensityLocation[i]<<endl;
                else
                cout<<location[i]<<" ---------->\t"<<JiospecDensityLocation[i]<<endl;
        }

        cout<<"\n  Vodafone Spectrum Density per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<VodafonespecDensityLocation[i]<<endl;
            else
            cout<<location[i]<<" ---------->\t"<<VodafonespecDensityLocation[i]<<endl;
        }
    }

    void printSpectrumAllocatedperSpectrum(string location[], string SpectrumperAllocated700[],string SpectrumperAllocated800[],string SpectrumperAllocated1800[],string SpectrumperAllocated3500[]){
    cout<<"\n  Spectrum 700 MHZ Allocated to Requested Company per Location\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<SpectrumperAllocated700[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<SpectrumperAllocated700[i]<<endl;
        }
        cout<<"\n  Spectrum 800 MHZ Allocated to Requested Company per Location\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<SpectrumperAllocated800[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<SpectrumperAllocated800[i]<<endl;
        }
        cout<<"\n  Spectrum 1800 MHZ Allocated to Requested Company per Location\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<SpectrumperAllocated1800[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<SpectrumperAllocated1800[i]<<endl;
        }
        cout<<"\n  Spectrum 3500 MHZ Allocated to Requested Company per Location\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<SpectrumperAllocated3500[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<SpectrumperAllocated3500[i]<<endl;
        }
    }

    void printRevenueGeneratedperAllocation(string location[], int RevenueGenerated700[], int RevenueGenerated800[], int RevenueGenerated1800[], int RevenueGenerated3500[]){
    cout<<"\n  700 Spectrum Revenue in Crores\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<RevenueGenerated700[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<RevenueGenerated700[i]<<endl;
        }
        cout<<"\n  800 Spectrum Revenue in Crores\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<RevenueGenerated800[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<RevenueGenerated800[i]<<endl;
        }
        cout<<"\n  1800 Spectrum Revenue in Crores\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<RevenueGenerated1800[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<RevenueGenerated1800[i]<<endl;
        }
        cout<<"\n  3500 Spectrum Revenue in Crores\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                cout<<location[i]<<"\t   ---------->\t"<<RevenueGenerated3500[i]<<endl;
            else
                cout<<location[i]<<" ---------->\t"<<RevenueGenerated3500[i]<<endl;
        }
    }

    void saveinFile(string location[], int subsAirtel[],int subsBSNL[],int subsJio[],int subsVoda[],string req700[], string req800[],
    string req1800[],string req3500[],int AirtelRevenue[], int BSNLRevenue[],int JioRevenue[],int VodafoneRevenue[], string Airtelspect[],
    string BSNLspect[], string Jiospect[], string Vodafonespect[],int TotalAirtelSpectrumperLocation[], int TotalBSNLSpectrumperLocation[], 
    int TotalJioSpectrumperLocation[], int TotalVodafoneSpectrumperLocation[],float AirtelspecDensityLocation[], float BSNLspecDensityLocation[],
    float JiospecDensityLocation[],float VodafonespecDensityLocation[],string SpectrumperAllocated700[],string SpectrumperAllocated800[],
    string SpectrumperAllocated1800[],string SpectrumperAllocated3500[],int RevenueGenerated700[], int RevenueGenerated800[], 
    int RevenueGenerated1800[], int RevenueGenerated3500[]){
    // Saving the Data in output file
        ofstream outputFile("SpectrumandRevenue.txt");

        if (!outputFile.is_open()) {
            cerr<< "Failed to open the file for writing." <<endl;
        }else{

            outputFile<<"\n  Airtel Subscriber per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<subsAirtel[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<subsAirtel[i]<<endl;
        }

        outputFile<<"\n  BSNL Subscriber per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<subsBSNL[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<subsBSNL[i]<<endl;
        }

        outputFile<<"\n  Jio Subscriber per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<subsJio[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<subsJio[i]<<endl;
        }

        outputFile<<"\n  Vodafone Subscriber per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<subsVoda[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<subsVoda[i]<<endl;
        }

        outputFile<<"\n  700 Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<req700[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<req700[i]<<endl;
        }

        outputFile<<"\n  800 Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<req800[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<req800[i]<<endl;
        }

        outputFile<<"\n  1800 Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<req1800[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<req1800[i]<<endl;
        }

        outputFile<<"\n  3500 Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<req3500[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<req3500[i]<<endl;
        }

        outputFile<<"\n\t Airtel Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<AirtelRevenue[i]<<"\t"<<Airtelspect[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<AirtelRevenue[i]<<"\t"<<Airtelspect[i]<<endl;
        }
        
        outputFile<<"\n\t BSNL Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<BSNLRevenue[i]<<"\t"<<BSNLspect[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<BSNLRevenue[i]<<"\t"<<BSNLspect[i]<<endl;
        }

        outputFile<<"\n\t Jio Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<JioRevenue[i]<<"\t"<<Jiospect[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<JioRevenue[i]<<"\t"<<Jiospect[i]<<endl;
        }

        outputFile<<"\n\t Vodafone Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<VodafoneRevenue[i]<<"\t"<<Vodafonespect[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<VodafoneRevenue[i]<<"\t"<<Vodafonespect[i]<<endl;
        }

        outputFile<<"\n Total Airtel Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    outputFile<<location[i]<<"\t   ---------->\t"<<TotalAirtelSpectrumperLocation[i]<<" MHz"<<endl;
                else
                    outputFile<<location[i]<<" ---------->\t"<<TotalAirtelSpectrumperLocation[i]<<" MHz"<<endl;
        }

        outputFile<<"\n Total BSNL Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    outputFile<<location[i]<<"\t   ---------->\t"<<TotalBSNLSpectrumperLocation[i]<<" MHz"<<endl;
                else
                    outputFile<<location[i]<<" ---------->\t"<<TotalBSNLSpectrumperLocation[i]<<" MHz"<<endl;
        }

        outputFile<<"\n Total Jio Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    outputFile<<location[i]<<"\t   ---------->\t"<<TotalJioSpectrumperLocation[i]<<" MHz"<<endl;
                else
                    outputFile<<location[i]<<" ---------->\t"<<TotalJioSpectrumperLocation[i]<<" MHz"<<endl;
        }

        outputFile<<"\n Total Vodafone Spectrum per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<TotalVodafoneSpectrumperLocation[i]<<" MHz"<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<TotalVodafoneSpectrumperLocation[i]<<" MHz"<<endl;
        }

        outputFile<<"\n  Airtel Spectrum Density per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    outputFile<<location[i]<<"\t   ---------->\t"<<AirtelspecDensityLocation[i]<<endl;
                else
                    outputFile<<location[i]<<" ---------->\t"<<AirtelspecDensityLocation[i]<<endl;
        }

        outputFile<<"\n  BSNL Spectrum Density per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    outputFile<<location[i]<<"\t   ---------->\t"<<BSNLspecDensityLocation[i]<<endl;
                else
                    outputFile<<location[i]<<" ---------->\t"<<BSNLspecDensityLocation[i]<<endl;
        }

        outputFile<<"\n  Jio Spectrum Density per Location\n"<<endl;
        for(int i =0;i<6;i++){
                if(location[i]!="Chandigarh")
                    outputFile<<location[i]<<"\t   ---------->\t"<<JiospecDensityLocation[i]<<endl;
                else
                    outputFile<<location[i]<<" ---------->\t"<<JiospecDensityLocation[i]<<endl;
        }

        outputFile<<"\n  Vodafone Spectrum Density per Location\n"<<endl;
        for(int i =0;i<6;i++){
            if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<VodafonespecDensityLocation[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<VodafonespecDensityLocation[i]<<endl;
        }

        outputFile<<"\n  Spectrum 700 MHZ Allocated to Requested Company per Location\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<SpectrumperAllocated700[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<SpectrumperAllocated700[i]<<endl;
        }
        outputFile<<"\n  Spectrum 800 MHZ Allocated to Requested Company per Location\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<SpectrumperAllocated800[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<SpectrumperAllocated800[i]<<endl;
        }
        outputFile<<"\n  Spectrum 1800 MHZ Allocated to Requested Company per Location\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<SpectrumperAllocated1800[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<SpectrumperAllocated1800[i]<<endl;
        }
        outputFile<<"\n  Spectrum 3500 MHZ Allocated to Requested Company per Location\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<SpectrumperAllocated3500[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<SpectrumperAllocated3500[i]<<endl;
        }

        outputFile<<"\n  700 Spectrum Revenue in Crores\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<RevenueGenerated700[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<RevenueGenerated700[i]<<endl;
        }
        outputFile<<"\n  800 Spectrum Revenue in Crores\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<RevenueGenerated800[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<RevenueGenerated800[i]<<endl;
        }
        outputFile<<"\n  1800 Spectrum Revenue in Crores\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<RevenueGenerated1800[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<RevenueGenerated1800[i]<<endl;
        }
        outputFile<<"\n  3500 Spectrum Revenue in Crores\n"<<endl;
        for(int i =0;i<6;i++){
        if(location[i]!="Chandigarh")
                outputFile<<location[i]<<"\t   ---------->\t"<<RevenueGenerated3500[i]<<endl;
            else
                outputFile<<location[i]<<" ---------->\t"<<RevenueGenerated3500[i]<<endl;
        }

    }
    outputFile.close(); 
    cout<< "\nRecord has been stored Successfully to the file.\n" <<endl;
    }
};


int main(){

    int index_spectrumRange = 100 ;
    int index_subscribers = 100 ;
    int index_spectrumRequest = 100 ;

    spectrumRangeClass* spectrumRange = readCSVFileRange("spectrumRange.csv");

    subscribersClass* subscribers = readCSVFileSub("subscribers.csv");

    spectrumRequestClass* spectrumRequest = readCSVFileReq("spectrumRequest.csv");

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

    // Find Subscribers for Each Location
    int* subsAirtel = subs->findSubscriberLocation(Airtelsubscriber,24);
    int* subsBSNL = subs->findSubscriberLocation(BSNLsubscriber,31);
    int* subsJio = subs->findSubscriberLocation(Jiosubscriber,18);
    int* subsVoda= subs->findSubscriberLocation(Vodafonesubscriber,27);

    string location[] = {"Delhi","Chandigarh","Jaipur","Kolkata","Lucknow","Patna"}; 

    // Find Number of Request per spectrum
    spectrumRequestPerSpectrum* spectrum = new spectrumRequestPerSpectrum();
   
    spectrumRequestPerSpectrum* request700= new spectrumRequestPerSpectrum[20];
    spectrumRequestPerSpectrum* request800= new spectrumRequestPerSpectrum[22];
    spectrumRequestPerSpectrum* request1800= new spectrumRequestPerSpectrum[28];
    spectrumRequestPerSpectrum* request3500= new spectrumRequestPerSpectrum[30];

    spectrum->findrequest700(spectrumRequest,request700);
    spectrum->findrequest800(spectrumRequest,request800);
    spectrum->findrequest1800(spectrumRequest,request1800);
    spectrum->findrequest3500(spectrumRequest,request3500);

    // Find Request for Each Location
    string* req700 = spectrum->findRequestLocation(request700,20);
    string* req800 = spectrum->findRequestLocation(request800,22);
    string* req1800 = spectrum->findRequestLocation(request1800,28);
    string* req3500= spectrum->findRequestLocation(request3500,30);

    // Find Number of Spectrum per Company
    spectrumRangePerComp* spect = new spectrumRangePerComp();
   
    spectrumRangePerComp* Airtelspectrum= new spectrumRangePerComp[22];
    spectrumRangePerComp* BSNLspectrum= new spectrumRangePerComp[24];
    spectrumRangePerComp* Jiospectrum= new spectrumRangePerComp[27];
    spectrumRangePerComp* Vodafonespectrum= new spectrumRangePerComp[27];
 
    spect->findSpectrumAirtel(spectrumRange,Airtelspectrum);
    spect->findSpectrumBSNL(spectrumRange,BSNLspectrum);
    spect->findSpectrumJio(spectrumRange,Jiospectrum);
    spect->findSpectrumVodafone(spectrumRange,Vodafonespectrum);

    // Find Spectrum for Each Location
    string* Airtelspect = spect->findSpectrumLocation(Airtelspectrum,22);
    string* BSNLspect = spect->findSpectrumLocation(BSNLspectrum,24);
    string* Jiospect = spect->findSpectrumLocation(Jiospectrum,27);
    string* Vodafonespect= spect->findSpectrumLocation(Vodafonespectrum,27);

    // Find Revenue for Each Location
    int* AirtelRevenue = spect->findSpectrumRevenue(Airtelspectrum,22);
    int* BSNLRevenue = spect->findSpectrumRevenue(BSNLspectrum,24);
    int* JioRevenue = spect->findSpectrumRevenue(Jiospectrum,27);
    int* VodafoneRevenue= spect->findSpectrumRevenue(Vodafonespectrum,27);
    
    int TotalAirtelSpectrumperLocation[6];
    int TotalBSNLSpectrumperLocation[6];
    int TotalJioSpectrumperLocation[6];
    int TotalVodafoneSpectrumperLocation[6];

    for(int i =0;i<6;i++){
            TotalAirtelSpectrumperLocation[i] = spect->findtotalspectrum (Airtelspect[i]);
    }

    for(int i =0;i<6;i++){
            TotalBSNLSpectrumperLocation[i] = spect->findtotalspectrum (BSNLspect[i]);
    }

    for(int i =0;i<6;i++){
            TotalJioSpectrumperLocation[i] = spect->findtotalspectrum (Jiospect[i]);
    }

    for(int i =0;i<6;i++){
            TotalVodafoneSpectrumperLocation[i] = spect->findtotalspectrum (Vodafonespect[i]);
    }

    // spectrum Density
    spectrumDensity* specDensity = new spectrumDensity();

    float AirtelspecDensityLocation[6];
    float BSNLspecDensityLocation[6];
    float JiospecDensityLocation[6];
    float VodafonespecDensityLocation[6];

    for(int i =0;i<6;i++){
            AirtelspecDensityLocation[i] = specDensity->findspectrumDensityforEachLocation(subsAirtel[i],TotalAirtelSpectrumperLocation[i]);
    }
    for(int i =0;i<6;i++){
            BSNLspecDensityLocation[i] = specDensity->findspectrumDensityforEachLocation(subsBSNL[i],TotalBSNLSpectrumperLocation[i]);
    }

    for(int i =0;i<6;i++){
            JiospecDensityLocation[i] = specDensity->findspectrumDensityforEachLocation(subsJio[i],TotalJioSpectrumperLocation[i]);
    }

    for(int i =0;i<6;i++){
            VodafonespecDensityLocation[i] = specDensity->findspectrumDensityforEachLocation(subsVoda[i],TotalVodafoneSpectrumperLocation[i]);
    }

    // Allocate spectrum
    string SpectrumperAllocated700[6];
    string SpectrumperAllocated800[6];
    string SpectrumperAllocated1800[6];
    string SpectrumperAllocated3500[6];

    for(int i =0;i<6;i++){
       SpectrumperAllocated700[i] = specDensity->allocateSpectrum(req700[i], AirtelspecDensityLocation, BSNLspecDensityLocation, JiospecDensityLocation, VodafonespecDensityLocation,i);
    }
    for(int i =0;i<6;i++){
       SpectrumperAllocated800[i] = specDensity->allocateSpectrum(req800[i], AirtelspecDensityLocation, BSNLspecDensityLocation, JiospecDensityLocation, VodafonespecDensityLocation,i);
    }
    for(int i =0;i<6;i++){
       SpectrumperAllocated1800[i] = specDensity->allocateSpectrum(req1800[i], AirtelspecDensityLocation, BSNLspecDensityLocation, JiospecDensityLocation, VodafonespecDensityLocation,i);
    }
    for(int i =0;i<6;i++){
       SpectrumperAllocated3500[i] = specDensity->allocateSpectrum(req3500[i], AirtelspecDensityLocation, BSNLspecDensityLocation, JiospecDensityLocation, VodafonespecDensityLocation,i);
    }

    revenueGenerated* revGenerated = new revenueGenerated();

    int RevenueGenerated700[6];
    int RevenueGenerated800[6];
    int RevenueGenerated1800[6];
    int RevenueGenerated3500[6];

    for(int i =0;i<6;i++){
       RevenueGenerated700[i] = revGenerated->RevenueGeneratedSpectrum(SpectrumperAllocated700[i],AirtelRevenue,BSNLRevenue,JioRevenue,VodafoneRevenue,i);
    }
    for(int i =0;i<6;i++){
       RevenueGenerated800[i] = revGenerated->RevenueGeneratedSpectrum(SpectrumperAllocated800[i],AirtelRevenue,BSNLRevenue,JioRevenue,VodafoneRevenue,i);
    }
    for(int i =0;i<6;i++){
       RevenueGenerated1800[i] = revGenerated->RevenueGeneratedSpectrum(SpectrumperAllocated1800[i],AirtelRevenue,BSNLRevenue,JioRevenue,VodafoneRevenue,i);
    }
    for(int i =0;i<6;i++){
       RevenueGenerated3500[i] = revGenerated->RevenueGeneratedSpectrum(SpectrumperAllocated3500[i],AirtelRevenue,BSNLRevenue,JioRevenue,VodafoneRevenue,i);
    }

    print* pt = new print();
    cout<<"Enter your choice from below options: "<<endl;
	cout<<"Menu:"<<endl;
    cout<<"\nPress 1. to See SpectrumRange csv File: "<<endl;
    cout<<"Press 2. to See Subscribers csv File: "<<endl;
    cout<<"Press 3. to See SpectrumRequest csv File: "<<endl;
    cout<<"Press 4. to see Subscibers per Company: "<<endl;
    cout<<"Press 5. to see Subscibers per Location: "<<endl;
    cout<<"Press 6. to see SpectrumRequest per Company: "<<endl;
    cout<<"Press 7. to see SpectrumRequest per Location: "<<endl;
    cout<<"Press 8. to see SpectrumRange per Company: "<<endl;
    cout<<"Press 9. to see Total SpectrumRange per Location: "<<endl;
    cout<<"Press 10. to see Revenue per Location: "<<endl;
    cout<<"Press 11. to see Spectrum Desity per Location: "<<endl;
    cout<<"Press 12. to see Spectrum Allocated per Spectrum: "<<endl;
    cout<<"Press 13. to see Revenue Generated per Allocation: "<<endl;
    cout<<"Press 14. to Save in the File:  "<<endl;
    cout<<"Press 0 to exit"<<endl;
    cout<<"Enter your Choice: \n"<<endl;
    int choice;
    bool check = true;
    cin>>choice;
    try{
    while(check){
        if (cin.fail()){
            throw 505;
        }
        switch(choice)
        {
            case 1 :
            {   
                    pt->printSpectrumRange(spectrumRange,index_spectrumRange);
                    break;
            }
            case 2 : 
            {
                    pt->printSubscribers(subscribers,index_subscribers);
                    break;
            }
            case 3 : 
            {
                    pt->printSpectrumRequest(spectrumRequest,index_spectrumRequest);
                    break;
            }
            case 4 :
            {
                    pt->printSubscibersperCompany(Airtelsubscriber,BSNLsubscriber,Jiosubscriber,Vodafonesubscriber);
                    break;
            }  
            case 5 : 
            {
                    pt->printSubscibersperLocation(location,subsAirtel,subsBSNL,subsJio,subsVoda);
                    break;
            } 
            case 6 : 
            {
                    pt->printSpectrumRequestperCompany(request700,request800,request1800,request3500);
                    break; 
            }
            case 7 : 
            {
                    pt->printSpectrumRequestperLocation(location,req700,req800,req1800,req3500);
                    break; 
            }
            case 8 : 
            {
                    pt->printSpectrumRangeperCompany(Airtelspectrum,BSNLspectrum,Jiospectrum,Vodafonespectrum);
                    break; 
            }
            case 9:
            {   
                    pt->printTotalSpectrumRangeperLocation(location,TotalAirtelSpectrumperLocation,TotalBSNLSpectrumperLocation,TotalJioSpectrumperLocation,TotalVodafoneSpectrumperLocation);    
                    break;
            }
            case 10:
            {
                    pt->printRevenueperLocation(location,AirtelRevenue,BSNLRevenue,JioRevenue,VodafoneRevenue,Airtelspect,BSNLspect,Jiospect,Vodafonespect);
                    break;
            }
            case 11:
            {
                    pt->printSpectrumDesityperLocation(location,AirtelspecDensityLocation,BSNLspecDensityLocation,JiospecDensityLocation,VodafonespecDensityLocation);
                    break;
            }
            case 12:
            {
                    pt->printSpectrumAllocatedperSpectrum(location,SpectrumperAllocated700,SpectrumperAllocated800,SpectrumperAllocated1800,SpectrumperAllocated3500);
                    break;
            }
            case 13:
            {
                    pt->printRevenueGeneratedperAllocation(location,RevenueGenerated700,RevenueGenerated800,RevenueGenerated1800,RevenueGenerated3500);
                    break;
            }
            case 14:
            {
                    pt->saveinFile(location, subsAirtel, subsBSNL,subsJio, subsVoda, req700,  req800, req1800, req3500, AirtelRevenue,  
                    BSNLRevenue, JioRevenue, VodafoneRevenue, Airtelspect, BSNLspect,  Jiospect,  Vodafonespect, TotalAirtelSpectrumperLocation,
                    TotalBSNLSpectrumperLocation, TotalJioSpectrumperLocation,  TotalVodafoneSpectrumperLocation, AirtelspecDensityLocation,  
                    BSNLspecDensityLocation, JiospecDensityLocation, VodafonespecDensityLocation, SpectrumperAllocated700, SpectrumperAllocated800,
                    SpectrumperAllocated1800, SpectrumperAllocated3500, RevenueGenerated700,  RevenueGenerated800, RevenueGenerated1800, 
                    RevenueGenerated3500);
                    break;
            }
            case 0 :
            {
                
                    break;
            }
            default:
                    cout<<"\nPlease Enter from the given options only\n"<<endl;
        }
        cout<<"\nEnter your Choice: \n"<<endl;
		cin>>choice;
    }
    }catch(...){
        cout << "\n Invalid input! Please enter integers only!\n" << endl;
    }
    return 0;
}
