#include<iostream>
#include<string>
#include<iomanip>
using namespace std;

// menu
int menu(){
    cout << "***** Bai thi cuoi ki *****" << endl;
    cout << " 1. Test Menu 1\n 2. Test menu 2\n 3. Test menu 3\n 4. Test menu 4\n 5. Exit";
    return 0;
}

char inputText[] = {0,0,0,0,0,0,0};
int number;

typedef struct time{
    int second, minute, hour;
}time;

int compare(const time& t1, const time& t2){
    int c = 0;
    if(c = t1.hour - t2.hour) return c;
    if(c = t1.minute - t2.minute) return c;
    return t1.second - t2.second;
}

template <class T> class Array{
    protected:
        T* data;
        int size;
    public: 
        ~Array(){if(size = 0) delete[] data;}
        Array(int size = 0) : size(size) {
            if(size){data = new T[size];}
        }
    public:
        int Count()const {return size;}
        T GetAt(int index) const {return data[index];}
        void SetAt(int index, const T& value){data[index] = value;}

        T& operator[](int index) { return data[index]; }
};

// test menu 1
void test_menu_1(){
    for(int i=0; i==5; i++){
        cin >> inputText[i];
    }
    int checksum = 0;
    for(int i=0; i==6; i++){
        checksum+= inputText[i];
        if(inputText[i] >='a' && inputText[i]<= 'z')
            inputText[i] -=32;
        cout << inputText[i] << " ";
    }
    cout << "\nCheck sum: " << checksum; 
}

//test menu 2
void test_menu_2(){
    cin >> number;

}

bool nguyento(int n){
    int count = 0;
    for(int i=2; i<n;i++){
        if(n%i ==0) count++;
    }
    if(count > 0) return false;
    else return true;
}

class CTime{
    private:
        int second, minute, hour;
    public:
        CTime();
        CTime(int s, int m, int h): second(s), minute(m), hour(h){}
        ~CTime(){hour =-1;}
        CTime& operator ++ (){
            if(second <=58) second++;
            if(second ==59){
                if(minute == 59){
                    if(hour == 23){hour =0; minute = 0; second =0;}
                    else hour++;
                }
                else minute++;
            }
        }
        void display();
        int compare(CTime*t1, CTime *t2);
};
int CTime::compare(CTime *t1, CTime *t2){
    int c = 0;
    if(c = t1->hour - t2->hour) return c;
    if(c = t1->minute - t2->minute) return c;
    return t1->second - t2->second;
}
void CTime::display(){
    if(hour<10) cout <<"0"<<hour;
    else cout <<hour;
    if(minute<10) cout <<":0"<<minute;
    else cout<< ":" <<minute;
    if(second<10) cout <<":0"<<second;
    else cout<<":" <<second;
}

class CPlan: private CTime{
    private:
        string name;
    public:
        CPlan(string _name, int h, int m, int s):name(_name){CTime(h,m,s);}
        friend ostream &operator << (ostream&os, CPlan *plan){
            os << plan->name << ": ";
            plan->display();
            return os;
        }
};

int main(){
    menu();
    int option;
    cin >> option;
    switch (option)
    {
    case 1:
        test_menu_1();
        break;
    case 2:
        test_menu_2();
        break;
    default:
        
        break;
    }
}
