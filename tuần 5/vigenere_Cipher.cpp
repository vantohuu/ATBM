#include<iostream>
#include<vector>
#include<string>
using namespace std;
int main(){
    int k,n;
    // Ma trận bảng  26 chữ cái
    vector<vector<char> > a(26,vector<char>(26));
    k=0;
    n=26;
    for(int i=0;i<n;i++){
        k=i;
        for(int j=0;j<n;j++){
            a[i][j]='A'+k;
            k++;
            if(k==26)
                k=0;
        }
    }
    for(int c=0;c<n;c++)
    {
        for(int b=0;b<n;b++)
        {
            cout<<a[c][b]<<" ";
        }
        cout<<endl;
    }
    cout<<"Enter the message\n";
    string s = "we are discovered save yourself";

    // xóa khoảng trắng
    for(int i = 0; i <  s.size(); i++)
    {
        if(s[i] == ' ')
        {
            s.erase(s.begin()+i);
        }
        s[i] = toupper(s[i]);
    }
    // cout<<s<<endl;
    // cout<<s.length()<<endl;
    //cin>>s;
    cout<<"Enter the key\n";
    string key= "deceptive";
    //cin>>key;
    for (int i = 0; i < key.length(); i++)
    {
        key[i] = toupper(key[i]);
    }

    // Encryption
    // điền hết lặp hết chuỗi key sao cho độ dài hai string bằng nhau
    k=0;
    int mod = key.size();
    for(int i=key.size();i<s.size();i++){
        key+=key[k%mod];
        k++;
    }
    // cout<<key<<endl;
    // cout<<key.length()<<endl;
    string encrypt;
    for(int i=0;i<s.size();i++){
        encrypt+= a[s[i]-'A'][key[i]-'A'];
        //cout<<s[i]-'A'<<" "<<key[i]-'A'<<endl;
    }
    cout<<"Encrypted message: "<<encrypt<<'\n';

    //decrytion
    k=0;
    for(int i=key.size();i<s.size();i++){
        key+=key[k];
        k++;
    }

    // lấy đoạn mã encryption
    s = encrypt;
    string decrypt;
    for(int i=0;i<s.size();i++){
        for(int j=0;j<n;j++){
            if(a[j][key[i]-'A']==s[i]){
                decrypt += 'A'+j;
                break;
            }
        }
    }
    cout<<"Decrypted message: "<<decrypt<<'\n';
    return 0;
}