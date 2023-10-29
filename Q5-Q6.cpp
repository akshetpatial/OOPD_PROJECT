#include<iostream>
#include<fstream>
#include<sstream>
#include<string>
#include "classes.h"
using namespace std;

//Class For Mvno_Secret_Hash_Code - Sheet1.csv
class mvno_hash{
    public:
    string company;
    string location;
    int code;

    //Default Constructor.
    mvno_hash(){

    }

    //Creating User Defined Constructor.
    mvno_hash(string company,string location,int code){
        this->company=company;
        this->location=location;
        this->code=code;
    }

};

//Reading the Mvno_Secret_Hash_Code - Sheet1.csv
void read_mvno_hash(mvno_hash *hash_read){
    
    //Defining variables.
    string company;
    string location;
    string code;
    string line;
    int row=0;

    //Reading the csv file.
    ifstream read("Mvno_Secret_Hash_Code - Sheet1.csv");

    //Read the first line.
    getline(read,line);
    line=" ";

    //Read the reamaining lines.
    while(getline(read,line) && row<18){

        stringstream linestream(line);

        getline(linestream,company,',');
        getline(linestream,location,',');
        getline(linestream,code,',');

        //Constructor call and storing the data.
        hash_read[row]=mvno_hash(company,location,stoi(code));
        row++;
        line=" ";

    }

}

//Printing the Mvno_Secret_Hash_Code - Sheet1.csv
void info_mvno_hash(mvno_hash *hash_read){
    cout<<"COMPANY"<<"  "<<"LOCATION"<<"  "<<"HASH_CODE"<<endl;
    cout<<endl;
    for(int i=0;i<18;i++){
        if(hash_read[i].location =="Lucknow" || hash_read[i].location =="Kolkata" || hash_read[i].location =="Chandigarh")
            cout<<hash_read[i].company<<" \t "<<hash_read[i].location<<"\t"<<hash_read[i].code<<endl;
        else
            cout<<hash_read[i].company<<" \t "<<hash_read[i].location<<"\t\t"<<hash_read[i].code<<endl;
    }
    cout<<endl;
}

//Class For Mvno_Subscribers - Sheet1.csv
class mvno_subscribers{
    public:
    string company;
    string location;
    float sub;

    //Default Constructor.
    mvno_subscribers(){

    }

    //Creating User Defined Constructor.
    mvno_subscribers(string company,string location,float sub){
        this->company=company;
        this->location=location;
        this->sub=sub;
    }

};

//Reading the Mvno_Subscribers - Sheet1.csv
void read_mvno_subscribers(mvno_subscribers *sub_read){
    
    //Defining variables.
    string company;
    string location;
    string sub;
    string line;
    int row=0;

    //Reading the csv file.
    ifstream read("Mvno_Subscribers - Sheet1.csv");

    //Read the first line.
    getline(read,line);
    line=" ";

    //Read the reamaining lines.
    while(getline(read,line) && row<18){

        stringstream linestream(line);

        getline(linestream,company,',');
        getline(linestream,location,',');
        getline(linestream,sub,',');

        //Constructor call and storing the data.
        sub_read[row]=mvno_subscribers(company,location,stof(sub));
        row++;
        line=" ";

    }

}

//Printing the Mvno_Subscribers - Sheet1.csv
void info_mvno_subscribers(mvno_subscribers *sub_read){
    cout<<"COMPANY"<<"  "<<"LOCATION"<<"  "<<"SUBSCRIBERS"<<endl;
    cout<<endl;
    for(int i=0;i<18;i++){
         if(sub_read[i].location =="Lucknow" || sub_read[i].location =="Kolkata" || sub_read[i].location =="Chandigarh")
            cout<<sub_read[i].company<<" \t "<<sub_read[i].location<<"\t"<<sub_read[i].sub<<endl;
        else
            cout<<sub_read[i].company<<" \t "<<sub_read[i].location<<"\t\t"<<sub_read[i].sub<<endl;
        // cout<<sub_read[i].company<<" "<<sub_read[i].location<<" "<<sub_read[i].sub<<endl;
    }
    cout<<endl;
}

//Using the Inheritance to store the sharing of spectrum by companies in a circle
class spectrum_sharing:public licensed_allocation{
    public:
    string mvno_company;
};

//Method For Spectrum Allocation.
void spectrum_first_check(mvno_hash *hash_read,mvno_subscribers *sub_read,mvno_request_upd *req_read,bool *spectrum_check,float *spec_density){

    //Define the variables
    bool check;
    float subscribers;
    float spectral_density;

    //For loop to iterate through all the entries i.e all the 20 entries given.
    for(int i=0;i<20;i++){

        //Checking the hash code.(First condition)
        for(int j=0;j<18;j++){
            if(req_read[i].company==hash_read[j].company  && req_read[i].location==hash_read[j].location && req_read[i].h_code==hash_read[j].code){
                    check=true;
                    break;
            }
            else{
                check=false;
            }

        }

        //If first check is varied then move ahead.
        if(check){
            //Making spectrum_check=true;
            spectrum_check[i]=true;

            //Counting the number of the subscribers.
            for(int k=0;k<18;k++){
                if(req_read[i].company==sub_read[k].company && req_read[i].location==sub_read[k].location){
                    subscribers=sub_read[k].sub;
                    break;
                }
            }

            //Finding the spectral density.
            spectral_density=req_read[i].request/subscribers;
            spec_density[i]=spectral_density;

        }

        //If first check failed then value of array at the ith entry is false.
        else{
            spectrum_check[i]=false;
            spec_density[i]=0;

        }
        
    }

}

//Function for second check.
void spectrum_second_check(float *spec_density,bool *spectrum_check,float thershold){
        for(int i=0;i<20;i++){
            if(spec_density[i]>0 && spec_density[i]<thershold){
                spectrum_check[i]=true;
            }
            else{
                spectrum_check[i]=false;
            }
        }
}

//Methods to calculate the sharing of the spectrum.

//Check function used in the main share function.
bool check_sharing(string l1,string l2,int r1,int r2){
    if(l1==l2 && r1==r2){
        return true;
    }
    else{
        return false;
    }
}

//Main function that will calculate the sharing of the spectrum..
void sharing(licensed_allocation *licensed_read,mvno_request_upd *req_read,spectrum_sharing *spec_share,bool *spectrum_check){
    bool check;
    int k=0;
    for(int i=0;i<18;i++){
        if(spectrum_check[i]==1){
        for(int j=0;j<24;j++){
                check=check_sharing(req_read[i].location,licensed_read[j].location,req_read[i].request,licensed_read[j].request );
                if(check==true){
                    spec_share[k].company=licensed_read[j].company;
                    spec_share[k].mvno_company=req_read[i].company;
                    spec_share[k].location=req_read[i].location;
                    spec_share[k].request=req_read[i].request;
                    k++;
                }   
           }
        }   
    }
}

//Function to print the sharing of the spectrum..........
void info_sharing(spectrum_sharing *spec_share){
        cout<<"LOCATION"<<"\t"<<"REQUEST"<<"   "<<"LICENSED_COMPANY"<<"   "<<"MVNO_COMPANY"<<endl;
        cout<<endl;
        for(int i=0;i<9;i++){
        //cout<<spec_share[i].location<<" "<<spec_share[i].request<<" "<<spec_share[i].company<<" "<<spec_share[i].mvno_company<<endl;
        if(spec_share[i].location =="Lucknow" || spec_share[i].location =="Kolkata" || spec_share[i].location =="Chandigarh " || spec_share[i].location =="Chandigarh")
            cout<<spec_share[i].location<<" \t"<<spec_share[i].request<<"\t  ";
        if(spec_share[i].location =="Patna" || spec_share[i].location =="Jaipur" || spec_share[i].location =="Delhi")
            cout<<spec_share[i].location<<" \t\t"<<spec_share[i].request<<"\t  ";
        if(spec_share[i].company=="Vodafone" || spec_share[i].company =="Airtel")
            cout<<spec_share[i].company<<"\t\t"<<spec_share[i].mvno_company<<endl;
        else
            cout<<spec_share[i].company<<"\t\t\t"<<spec_share[i].mvno_company<<endl;
    }
}

//Start Of The Main Function.
int main(){
    //Variables
    float thershold;
    string temp;

    //Dynamic Memory allocation of an array of class(mvno_hash).
    mvno_hash *hash_read=new mvno_hash[18];

    //Function call for reading the csv file.
    read_mvno_hash(hash_read);

    cout<<"-------------------------------------COMPANY---------HASHCODE----------MAPPING------------------------------------"<<endl;
    //Function call for printing the csv file.
    info_mvno_hash(hash_read);

    //Dynamic Memory allocation of an array of class(mvno_subscribers).
    mvno_subscribers *sub_read=new mvno_subscribers[18];

    //Function call for reading the csv file.
    read_mvno_subscribers(sub_read);

    cout<<"-------------------------------------COMPANY--------SUBSCRIBERS----------MAPPING------------------------------------"<<endl;
    //Function call for printing the csv file.
    info_mvno_subscribers(sub_read);

    //Dynamic Memory allocation of an array of class(mvno_request_updated).
    mvno_request_upd *req_read=new mvno_request_upd[20];

    //Function call for reading the csv file.
    read_mvno_request_upd(req_read);

    cout<<"-------------------------------------COMPANY---------REQUESTS----------MAPPING------------------------------------"<<endl;
    //Function call for printing the csv file.
    info_mvno_request_upd(req_read);

    //Dynamic Memory Allocation Of an Array To check whether each request is accepted or not.
    bool *spectrum_check=new bool[20];

    //Dynamic Memory allocation of array of values of spectral density.
    float *spec_density=new float[20];

    //Dynamic Memory allocation of array of values of spectral density.
    licensed_allocation *licensed_read=new licensed_allocation[24];

    //Function call for reading the csv file.
    read_licensed_allocation(licensed_read);

    // //Function call for printing the csv file.
    // info_licensed_allocation(licensed_read);

    //Function For First check.
    spectrum_first_check(hash_read,sub_read,req_read,spectrum_check,spec_density);

    //Dynamic memory allocation of the shared spectrum class
    spectrum_sharing *spec_share=new spectrum_sharing[30];

    // //Function to show sharing of the spectrum by two companies.
    // sharing(licensed_read,req_read,spec_share,spectrum_check);

    //Decide the Threshold by inspecting the spectral density value.
    cout<<"-----------------------------SPECTRAL DENSITY VALUES -------------------------------------"<<endl;
    cout<<"-----------------------------------CAUTION------------------------------------------------"<<endl;
    cout<<"--------ZERO SPECTRAL DENSITY INFERS THAT COMPANY IS DEBARRED FROM THE ALLOCATION---------"<<endl;
    cout<<endl;

    //Printing the values using for loop
    for(int i=0;i<20;i++){
        //cout<<req_read[i].company<<"\t"<<req_read[i].location<<"\t\t"<<spec_density[i]<<endl;
        if(req_read[i].location =="Lucknow" || req_read[i].location =="Kolkata" || req_read[i].location =="Chandigarh")
            cout<<req_read[i].company<<" \t "<<req_read[i].location<<"\t"<<spec_density[i]<<endl;
        else
            cout<<req_read[i].company<<" \t "<<req_read[i].location<<"\t\t"<<spec_density[i]<<endl;
    }

    cout<<"----------------------------ENTER THE THRESHOLD VALUE--------------------------------------"<<endl;
    cout<<"ENTER THE THRESHOLD VALUE: ";
    cin>>thershold;
    cout<<"----------------------------SPECTRUM ALLOCATION---------------------------------------------"<<endl;
    cout<<endl;

    //Function for thershold check.
    spectrum_second_check(spec_density,spectrum_check,thershold);

    //Printing whether spectrum is allocated or not.
    for(int i=0;i<20;i++){
        if(spectrum_check[i]==1){
            temp="ALLOCATED";
        }
        else{
            temp="NOT ALLOCATED";
        }
        //cout<<req_read[i].company<<" "<<req_read[i].location<<" "<<req_read[i].request<<" "<<temp<<endl;
        if(req_read[i].location =="Lucknow" || req_read[i].location =="Kolkata" || req_read[i].location =="Chandigarh")
            cout<<req_read[i].company<<" \t "<<req_read[i].location<<"\t"<<req_read[i].request<<"\t"<<temp<<endl;
        else
            cout<<req_read[i].company<<" \t "<<req_read[i].location<<"\t\t"<<req_read[i].request<<"\t"<<temp<<endl;
    }

    cout<<endl;
    //Function call for printing the csv file.
    info_licensed_allocation(licensed_read);

    //Function to show sharing of the spectrum by two companies.
    sharing(licensed_read,req_read,spec_share,spectrum_check);

    //Function call for printing the sharing of the spectrum.
    info_sharing(spec_share);
}





