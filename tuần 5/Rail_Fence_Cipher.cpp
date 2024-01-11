//https://japp.io/cryptography/rail-fence-cipher-algorithm-program-in-c-c/

#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,i,j;
    string s;
    cout<<"Enter the message"<<'\n';
    cin>>s;
    cout<<"Enter key"<<'\n';
    cin>>n;
    vector<vector<char>> a(n,vector<char>(s.size(),' '));
    j=0;
    int flag=0;
    for(i=0;i<s.size();i++){
        a[j][i] = s[i];
         if(j==n-1){
            flag=1;
        }
        else if(j==0)
            flag=0;

        if(flag==0){
            j++;
        }
        else j--;
    }
    string encrypt;
    cout<<"Encrypted message:  ";
    for(i=0;i<n;i++){
        for(j=0;j<s.size();j++){
            if(a[i][j]!=' ')
                cout<<a[i][j];
                encrypt+=a[i][j];
        }
    }
    cout<<'\n';  

    //decrypt message
    s = encrypt;
    //cout<<s<<endl;
    // xóa khoảng trắng
    for(int i = 0; i <  s.size(); i++)
    {
        if(s[i] == ' ')
        {
            s.erase(s.begin()+i);
        }
    }
    vector<vector<char>> b(n,vector<char>(s.size(),' '));
    j=0;
    i = 0;
    flag=0;
    for(i=0;i<s.size();i++){
        b[j][i] = '0';
         if(j==n-1){
            flag=1;
        }
        else if(j==0)
            flag=0;
        if(flag==0){
            j++;
        }
        else j--;
    }
    int temp =0;
    cout<<"Ma tran thuat toan: "<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<s.size();j++){
                if(b[i][j]=='0')
                    b[i][j]= s[temp++];
                cout<<b[i][j]<<" ";
        }
        cout<<endl;
    }
    flag=0;
    j=0;
    string decrypt;
    cout<<"Decrypt message : ";
    for(i=0;i<s.size();i++){
        //cout<<b[j][i];
        decrypt+=b[j][i];
         if(j==n-1){
            flag=1;
        }
        else if(j==0)
            flag=0;
        if(flag==0){
            j++;
        }
        else j--;
    }
    cout<<decrypt;  
    return 0;
}