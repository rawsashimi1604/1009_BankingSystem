#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

//This is the userCredential struct used to store the user credentials from the csv file
struct userCredentials {
    string userName;
    string pinNo;
    string firstName;
    string lastName;
    string decryptionKey;
    float Balance;
    float amountSpent;
    float amountSaved;
};   

//This function reads fileName's csv file and stores every line as items in the uCArray as userCredentials structs
//returns the number of lines read if success, -1 if failed
int credentialReader(string fileName, userCredentials uCArray[]) {
    ifstream cFile(fileName);
    int count = 0;
    string uName;
    string pNo;
    string fName;
    string lName;
    string dKey;
    string Bal;
    string aSpent;
    string aSaved;
    
    if(!cFile.is_open()) {
        std::cout << "Error opening " << fileName;
        return -1;
    }
    
    while(cFile.good()) {
        getline(cFile,uName,',');
        getline(cFile,pNo,',');
        getline(cFile,fName,',');
        getline(cFile,lName,',');
        getline(cFile,dKey,',');
        getline(cFile,Bal,',');
        getline(cFile,aSpent,',');
        getline(cFile,aSaved,'\n');
        
        uCArray[count].userName = uName;
        uCArray[count].pinNo = pNo;
        uCArray[count].firstName = fName;
        uCArray[count].lastName = lName;
        uCArray[count].decryptionKey = dKey;
        uCArray[count].Balance = stof(Bal);
        uCArray[count].amountSpent = stof(aSpent);
        uCArray[count].amountSaved = stof(aSaved);
        count++;
    }
    cFile.close();
    return count;
}

//This function writes the userCredential struct to the given fileName's csv file
//returns true if success, false if failed
bool credentialWriter(string fileName, userCredentials ucInput) {
    ofstream cFile(fileName);
    if (!cFile.is_open()) return false;
    cFile << ucInput.userName << ',' << ucInput.pinNo << ',' << ucInput.firstName << ',' << ucInput.lastName << ',' << ucInput.decryptionKey << ',' << fixed << setprecision(2) << ucInput.Balance << ',' << ucInput.amountSpent << ',' << ucInput.amountSaved << endl;
    cFile.close();
    return true;
}
