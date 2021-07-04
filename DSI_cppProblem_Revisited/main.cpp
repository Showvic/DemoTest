#include <bits/stdc++.h>

using namespace std;

int Earnings = 0;

class Student
{
protected:
    string name;
    bool subject[3];
    double avgMarks;
    int totalDayTaught;
    int totalEarning;
    int factor;
    int examDays;
public:
    //Student();
    //Student(string name,bool *ptr);

    string getName(){
        return this->name;
    }
    bool * getSubject(){
        return this->subject;
    }
    void setAvgMarks(double avgmrks){
        this->avgMarks=avgmrks;
    }
    double getAvgMarks(){
        return this->avgMarks;
    }
    void setTotalDayTaught(int d){
        this->totalDayTaught = d;
    }
    int getTotalDayTaught(){
        return this->totalDayTaught;
    }
    void setTotalEarning(int e){
        this->totalEarning = e;
    }
    int getTotalEarning(){
        return this->totalEarning;
    }
    int getFactor(){
        return this->factor;
    }
    void setFactor(int f){
        this->factor = f;
    }
    int getExamDays(){
        return this->examDays;
    }
    void setExamDays(int ex){
    this->examDays = ex;
    }

    void editstudent(Student&);
};

void Student::editstudent( Student &st){
    int day,mark;
    cout<<"Add day(usually 1) and Marks(-1, if exam not taken) : "<<endl;
    cout<<"Day  : ";
    cin>>day;
    cout<<"Mark : ";
    cin>>mark;

    int daysTaught = st.getTotalDayTaught();
    int earnings = st.getTotalEarning();
    int factor = st.getFactor();
    double avgmarks = st.getAvgMarks();
    int examdays = st.getExamDays();

    st.setTotalDayTaught((daysTaught+day));
    st.setTotalEarning((earnings + (day*factor)));
    Earnings += (day*factor);

    if(mark != -1){
        double totalMarks = (avgmarks*examdays);
        totalMarks += (double)mark;
        st.setExamDays((examdays+1));
        st.setAvgMarks((totalMarks/st.getExamDays()));
    }

    return;
}
string SubjectMerge(bool *p){
    string s="";
    for(int i=0; i<3; i++)
    {
        if(*(p+i)==1 && i==0)
        {
            s+="Math ";
        }
        else if(*(p+i)==1 && i==1)
        {
            s+="English ";
        }
        else if(*(p+i)==1 && i==2)
        {
            s+="Bangla ";
        }
    }
    return s;
}


//Student::Student()
//{
//
//}
//
//Student::Student(string name, bool *p)
//{
//    cout<<"Initializing and Adding Student"<<endl;
//    this->name = name;
//    for(int i=0; i<3; i++)
//    {
//        this->subject[i] = *(p+i);
//    }
//    this->avgMarks = 0;
//    this->totalDayTaught = 0;
//    this->totalEarning = 0;
//    this->factor = 0;
//    this->examDays = 0;
//
//
//}

class Class_8: public Student
{
public:
    Class_8();
    Class_8(string name, bool *ptr,int f);
};



Class_8::Class_8(string name, bool *p,int factor)
{
    cout<<"Initializing and Adding Student of Class 8"<<endl;
    this->name = name;
    for(int i=0; i<3; i++)
    {
        this->subject[i] = *(p+i);
    }
    this->avgMarks = 0;
    this->totalDayTaught = 0;
    this->totalEarning = 0;
    this->factor = factor;
    this->examDays = 0;

}

vector <Class_8> class_8;

class Class_9: public Student
{
public:
    Class_9();
    Class_9(string name, bool *ptr,int f);
};

Class_9::Class_9(string name, bool *p,int factor)
{
    cout<<"Initializing and Adding Student of Class 9"<<endl;
    this->name = name;
    for(int i=0; i<3; i++)
    {
        this->subject[i] = *(p+i);
    }
    this->avgMarks = 0;
    this->totalDayTaught = 0;
    this->totalEarning = 0;
    this->factor = factor;
    this->examDays = 0;

}

vector <Class_9> class_9;


class Class_10: public Student
{
public:
    Class_10();
    Class_10(string name, bool *ptr,int f);
};

Class_10::Class_10(string name, bool *p,int factor)
{
    cout<<"Initializing and Adding Student of Class 10"<<endl;
    this->name = name;
    for(int i=0; i<3; i++)
    {
        this->subject[i] = *(p+i);
    }
    this->avgMarks = 0;
    this->totalDayTaught = 0;
    this->totalEarning = 0;
    this->factor = factor;
    this->examDays = 0;
}

vector <Class_10> class_10;


void AddStudent(int cls){
    string name;
    bool arr[3];
    memset(arr,false,3);
    int factor=0;
    cout<<"Enter Name: ";
    cin>>name;
    cout<<"Enter Subject(s) Math, English, Bangla(0 as false & 1 as true): ";
    for(int i=0; i<3; i++)
    {
        cin>>arr[i];
        if(arr[i]==1)
            factor++;
    }
    if(cls==8)
        class_8.push_back(Class_8(name, arr, factor));
    else if(cls==9)
        class_9.push_back(Class_9(name, arr, factor));
    else if(cls==10){
        class_10.push_back(Class_10(name, arr,factor));
    }
}



void editStudent(){
    cout<<"Edit Student"<<endl;
    string name;
    int cls;
    cout<<"Enter student's class & name whose info you want to edit"<<endl;
    cout<<"Class : ";
    cin>>cls;
    cout<<"Name  : ";
    cin>>name;
    int n;
    if(cls==8){
        n=class_8.size();
        for(int i=0;i<n;i++){
            if(name == class_8[i].getName()){
                class_8[i].editstudent(class_8[i]);
                break;
            }
        }
    }
    else if(cls == 9)
    {
        n=class_9.size();
        for(int i=0;i<n;i++){
            if(name == class_9[i].getName()){
                class_9[i].editstudent(class_9[i]);
                break;
            }
        }
    }
    else if(cls == 10)
    {
        n=class_10.size();
        for(int i=0;i<n;i++){
            if(name == class_10[i].getName()){
                class_10[i].editstudent(class_10[i]);
                break;
            }
        }
    }

}

void deleteStudent(){
    int cls;
    string name;
    cout<<"Enter Class : ";
    cin>>cls;
    cout<<"Enter Name  : ";
    cin>>name;
    int n;
    deletelavel:if(cls==8){
        n=class_8.size();
        for(int i=0;i<n;i++){
            if(name == class_8[i].getName()){
                class_8.erase(class_8.begin()+i);
                break;
            }
        }
    }
    else if(cls == 9)
    {
        n=class_9.size();
        for(int i=0;i<n;i++){
            if(name == class_9[i].getName()){
                class_9.erase(class_9.begin()+i);
                break;
            }
        }
    }
    else if(cls == 10)
    {
        n=class_10.size();
        for(int i=0;i<n;i++){
            if(name == class_10[i].getName()){
                class_10.erase(class_10.begin()+i);
                break;
            }
        }
    }
    else{
        cout<<"Not Found. Please enter valid class and name"<<endl;
        goto deletelavel;
    }

}

void PrintClasswise_8(vector<Class_8> vct,string name, char ch){
    if(ch == 'c'||ch=='C'){
    int n = vct.size();
    if(n==0){
        cout<<"Sorry!There is no Students in class 8"<<endl;
        return;
    }
    cout<<setw(20)<<"Name"<<setw(25)<<"Subject(s)"<<setw(10)<<"Avg_marks"<<setw(20)<<"TotalDayTaught"<<setw(15)<<"TotalEarnings"<<endl;

    for(int i = 0;i<n;i++){
        string s = SubjectMerge(vct[i].getSubject());
        cout<<setw(20)<<vct[i].getName()<<setw(25)<<s<<setw(10)<<vct[i].getAvgMarks()<<setw(20)<<vct[i].getTotalDayTaught()<<setw(15)<<vct[i].getTotalEarning()<<endl;
    }
    }
    else{
        int n = vct.size();
        bool flag = false;
        cout<<setw(20)<<"Name"<<setw(25)<<"Subject(s)"<<setw(10)<<"Avg_marks"<<setw(20)<<"TotalDayTaught"<<setw(15)<<"TotalEarnings"<<endl;

        for(int i = 0;i<n;i++){
            if(vct[i].getName() == name){
            string s = SubjectMerge(vct[i].getSubject());
            cout<<setw(5)<<8<<setw(25)<<s<<setw(10)<<vct[i].getAvgMarks()<<setw(20)<<vct[i].getTotalDayTaught()<<setw(15)<<vct[i].getTotalEarning()<<endl;
            flag = true;
            break;
            }
        }
        if(!flag){
            cout<<"No Student exists in class 8 name as "<<name<<endl;
            return;
        }
    }
}

void PrintClasswise_9(vector<Class_9> vct,string name,char ch){
    if(ch == 'c'||ch=='C'){
    int n = vct.size();
    if(n==0){
        cout<<"Sorry!There is no Students in class 9"<<endl;
        return;
    }
    cout<<setw(20)<<"Name"<<setw(25)<<"Subject(s)"<<setw(10)<<"Avg_marks"<<setw(20)<<"TotalDayTaught"<<setw(15)<<"TotalEarnings"<<endl;

    for(int i = 0;i<n;i++){
        string s = SubjectMerge(vct[i].getSubject());
        cout<<setw(20)<<vct[i].getName()<<setw(25)<<s<<setw(10)<<vct[i].getAvgMarks()<<setw(20)<<vct[i].getTotalDayTaught()<<setw(15)<<vct[i].getTotalEarning()<<endl;
    }
    }
    else{
        int n = vct.size();
        bool flag = false;
        cout<<setw(20)<<"Name"<<setw(25)<<"Subject(s)"<<setw(10)<<"Avg_marks"<<setw(20)<<"TotalDayTaught"<<setw(15)<<"TotalEarnings"<<endl;

        for(int i = 0;i<n;i++){
            if(vct[i].getName() == name){
            string s = SubjectMerge(vct[i].getSubject());
            cout<<setw(5)<<8<<setw(25)<<s<<setw(10)<<vct[i].getAvgMarks()<<setw(20)<<vct[i].getTotalDayTaught()<<setw(15)<<vct[i].getTotalEarning()<<endl;
            flag = true;
            break;
            }
        }
        if(!flag){
            cout<<"No Student exists in class 9 name as "<<name<<endl;
            return;
        }
    }
}

void PrintClasswise_10(vector<Class_10> vct,string name, char ch){
    if(ch == 'c'||ch=='C'){
    int n = vct.size();
    if(n==0){
        cout<<"Sorry!There is no Students in class 10"<<endl;
        return;
    }
    cout<<setw(20)<<"Name"<<setw(25)<<"Subject(s)"<<setw(10)<<"Avg_marks"<<setw(20)<<"TotalDayTaught"<<setw(15)<<"TotalEarnings"<<endl;

    for(int i = 0;i<n;i++){
        string s = SubjectMerge(vct[i].getSubject());
        cout<<setw(20)<<vct[i].getName()<<setw(25)<<s<<setw(10)<<vct[i].getAvgMarks()<<setw(20)<<vct[i].getTotalDayTaught()<<setw(15)<<vct[i].getTotalEarning()<<endl;
    }
    }
    else{
        int n = vct.size();
        bool flag = false;
        cout<<setw(20)<<"Name"<<setw(25)<<"Subject(s)"<<setw(10)<<"Avg_marks"<<setw(20)<<"TotalDayTaught"<<setw(15)<<"TotalEarnings"<<endl;

        for(int i = 0;i<n;i++){
            if(vct[i].getName() == name){
            string s = SubjectMerge(vct[i].getSubject());
            cout<<setw(5)<<8<<setw(25)<<s<<setw(10)<<vct[i].getAvgMarks()<<setw(20)<<vct[i].getTotalDayTaught()<<setw(15)<<vct[i].getTotalEarning()<<endl;
            flag = true;
            break;
            }
        }
        if(!flag){
            cout<<"No Student exists in class 10 name as "<<name<<endl;
            return;
        }
    }
}
void listOfStudents(){
    ///implement here ........................*************************

    int cls;
    string name;
    char ch;
    cout<<"What you want to choose: Class(press c/C) or Name(press n/N): ";
    labelch: cin>>ch;
    if(ch =='c' || ch =='C'){
        label:cout<<"Enter Class of the student : ";
        cin>>cls;
        if(cls == 8){
            PrintClasswise_8(class_8,name,ch);
        }
        else if(cls == 9){
            PrintClasswise_9(class_9,name,ch);
        }
        else if(cls == 10){
            PrintClasswise_10(class_10,name,ch);
        }
        else{
            cout<<"Invalid Class. Please enter valid class"<<endl;
            goto label;
        }
    }
    else if(ch =='n' || ch == 'N'){
        cout<<"Enter Name of the student : ";
        cin>>name;
        cout<<"Enter Class of the student : ";
        cin>>cls;
        if(cls == 8){
            PrintClasswise_8(class_8,name,ch);
        }
        else if(cls == 9){
            PrintClasswise_9(class_9,name,ch);
        }
        else if(cls == 10){
            PrintClasswise_10(class_10,name,ch);
        }
        else{
            cout<<"Invalid Class. Please enter valid class"<<endl;
            goto label;
        }
    }
    else{
        cout<<"Invalid choice. Please press valid character."<<endl;
        goto labelch;
    }
}
int main()
{
    int choice;
    cout<<"Press 1 for AddStudent\n2 for Edit\n3 for Delete\n4 for getting individual list of Student\n5 for See overall Info"<<endl;
    cout<<"Enter Choice:";
    while(cin>>choice)
    {

        switch (choice)
        {
        case 1:
        {
                int cls;
                cout<<"Enter Class: ";
                cin>>cls;
                class_level:
                if(cls==8)
                {
                    AddStudent(8);
                }
                else if(cls==9)
                {
                    AddStudent(9);
                }
                else if(cls==10)
                {
                    AddStudent(10);
                }
                else
                {
                    cout<<"Invalid Class. Please enter valid class(8,9 or 10)"<<endl;
                    cout<<"Enter Class: ";
                    cin>>cls;
                    goto class_level;
                }
                break;
        }
        case 2:
            {
                editStudent();
                break;
            }
        case 3:
            {
                deleteStudent();
                break;
            }
        case 4:
            {
                listOfStudents();
                break;
            }
        case 6:
        {
            cout<<"Printing all Information"<<endl;
            cout<<setw(5)<<"Class"<<setw(20)<<"Name"<<setw(25)<<"Subject(s)"<<setw(10)<<"Average_Marks"<<setw(20)<<"Total_Day_Taught"<<setw(15)<<"Total_Earning"<<setw(8)<<"factor"<<setw(8)<<"ExamDays"<<endl;
            int n = class_8.size();
            for(int i=0; i<n; i++)
            {
                string s="";
                Class_8 tem = class_8[i];
                //bool *p = class_8[i].getSubject();
                string s1 = SubjectMerge(tem.getSubject());

                cout<<setw(5)<<8<<setw(20)<<tem.getName()<<setw(25)<<s1<<setw(10)<<tem.getAvgMarks()<<setw(20)<<tem.getTotalDayTaught()<<setw(15)<<tem.getTotalEarning()<<setw(8)<<tem.getFactor()<<setw(8)<<tem.getExamDays()<<endl;
            }

            n = class_9.size();
            for(int i=0; i<n; i++)
            {
                string s="";
                Class_9 tem = class_9[i];
                //bool *p = class_9[i].getSubject();
                string s1 = SubjectMerge(tem.getSubject());

                cout<<setw(5)<<9<<setw(20)<<tem.getName()<<setw(25)<<s1<<setw(10)<<tem.getAvgMarks()<<setw(20)<<tem.getTotalDayTaught()<<setw(15)<<tem.getTotalEarning()<<setw(8)<<tem.getFactor()<<setw(8)<<tem.getExamDays()<<endl;
            }

            n = class_10.size();
            for(int i=0; i<n; i++)
            {
                string s="";
                Class_10 tem = class_10[i];
                //bool *p = class_10[i].getSubject();
                string s1 = SubjectMerge(tem.getSubject());

                cout<<setw(5)<<10<<setw(20)<<tem.getName()<<setw(25)<<s1<<setw(10)<<tem.getAvgMarks()<<setw(20)<<tem.getTotalDayTaught()<<setw(15)<<tem.getTotalEarning()<<setw(8)<<tem.getFactor()<<setw(8)<<tem.getExamDays()<<endl;
            }
            break;
        }
        }



    }

    return 0;
}
