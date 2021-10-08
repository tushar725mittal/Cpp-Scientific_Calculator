# include<iostream>
# include<cmath>
using namespace std;

float fact(float number){
    if( number == 1){
        return 1;
    }
    else{
        return number*fact(number - 1);
    }
}
char operation[5];

class number{
    protected:
    float a, b, res;    
    public:
    void setnumb(float num1, float num2){
        a = num1;
        b = num2;        
    }
    void setnumb(float num1){
        a = num1;
    }  
};
class simplecalculator : virtual public number{
    protected:
    float res;    
    public:
    void processsim(void){
        if(*(operation) == '+'){
            res = a+b;
        }
        else if(*(operation) == '-'){
            res = a-b;
        }
        else if(*(operation) == '*'){
            res = a*b;
        }
        else if(*(operation) == '/'){
            res = a/b;
        }
        cout<<"Your result is "<<res<<endl;        
    }
};
class scientificcalculator : virtual public number{
    protected:
    float resu;    
    public:
    void processsci(void){
        if(*(operation) == 'r'){
            resu = pow(a, (1/b));
        }
        else if(*(operation) == '^'){
            resu = pow(a, (b));
        }
        else if(*(operation) == 'u'){
            resu = (1.0/a);
        }
        else if(*(operation) == '!'){
            resu = fact(a);
        }
        else if(*(operation) == '%'){
            resu = (int(a))%(int(b));
        }
        else if(*(operation) == 'L'){
            int base;
            cout<<"Enter Base(Not e) : ";
            cin>>base;
            resu = ((log(a))/(log(base)));
        }
        else if(*(operation) == 'N'){
            resu = log(a);
        }
        cout<<"Your result is "<<resu<<endl;        
    }
};
class calculator : public scientificcalculator, public simplecalculator{
    // This is calculator class
   };

int main(){
    cout<<"Please select the operation you want to perform from below list :-\n"
    <<"Operation     Press key\n"
    <<"Addition           +\n"
    <<"Subtraction        -\n"
    <<"Multiplication     *\n"
    <<"Division           /\n"
    <<"Power              ^\n"
    <<"Reciprocal         u\n"
    <<"Root               r\n"
    <<"Factorial          !\n"
    <<"Mod                %\n"
    <<"Log                L\n"
    <<"Natural Log        N\n";
    cin>>operation;
    calculator cal;
    float a, b;
    if(*(operation) == '!' || *(operation) == 'u' || *(operation) == 'L' || *(operation) == 'N' ){
        cout<<"Input the number\n";
        cin>>a;
        cal.setnumb(a);
        cal.processsci(); 
    }
    else if(*(operation) == '^' || *(operation) == 'r' || *(operation) == '%'){
        cout<<"Input the number\n";
        cin>>a;
        cout<<"Input the power(or root) factor number\n";
        cin>>b;
        cal.setnumb(a, b); 
        cal.processsci();      
    }
    else{
       cout<<"Input the first number\n";
        cin>>a;
        cout<<"Input the second number\n";
        cin>>b;
        cal.setnumb(a, b);
        cal.processsim();
    }    
    return 0;
}