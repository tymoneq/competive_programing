#include <iostream>
#include <string>

using namespace std;

int h,m,s;
string h_s, m_s, s_s;
int main(){
    cin >> h >> m >> s;
    if(s<59){
        s++;
        if(s<10){
            s_s = to_string(s);
            s_s.insert(0, 1, '0');
            
        }
        else {
             s_s = to_string(s);
        }

       if(m<10){
                m_s = to_string(m);
                m_s.insert(0,1,'0');
            }
        else {
            m_s = to_string(m);
        }

        if(h < 10 ){
                    h_s = to_string(h);
                    h_s.insert(0,1,'0');
                }
                else{
                    h_s = to_string(h);
                }
       
     
    }
    else if(s==59){
        s_s = "00";
        if(m<59){
            m++;
            if(m<10){
                m_s = to_string(m);
                m_s.insert(0,1,'0');
            }
            else {
                m_s = to_string(m);
            }
            if(h < 10 ){
                    h_s = to_string(h);
                    h_s.insert(0,1,'0');
                }
                else{
                    h_s = to_string(h);
                }
            
        }
        else if(m == 59){
            m_s = "00";
            if( h < 23){
                h++;
                if(h <10 ){
                    h_s = to_string(h);
                    h_s.insert(0,1,'0');
                }
                else{
                    h_s = to_string(h);
                }
               
            }
            if(h == 23){
                h_s = "00";
                m_s = "00";
                s_s = "00";
            }
        }
    }
    cout << h_s << ":" << m_s <<":"<< s_s;
    
    return 0;
}