

#include<iostream>
#include<string>
using namespace std;

int main(){
    int i,j,k;
    string s,encrypt, decrypt;
    int key;
    cout<<"Enter the message\n";
    cin>>s;
    for(i=0;i<s.length();i++)
    {
        s[i] = toupper(s[i]);
    }
    cout<<"Enter the key\n";
    cin>>key;
    for(i=0;i<s.size();i++){
        encrypt+=(s[i]-'A'+key)%26+'A';
    }
    cout<<"\n\nEncrypted message is "<<encrypt<<'\n';

    
    for(i=0;i<encrypt.size();i++){
        decrypt+=(encrypt[i]-'A'-key+26)%26+'A';
    }
    cout<<"\n\nDecrypted message is "<<decrypt<<'\n';
    return 0;
}



/*int main()
{
    cout << "Enter the message: " << endl;
    char message[100];
    cin.getline(message,100);
    int len = strlen(message);

    int key;
    cout << "Enter the key: " << endl;
    cin >> key;
    char ch;
    for (int i = 0; message[i] != '\0'; ++i)
    {
        ch = message[i];
        // encrypt for lowercase letter
        if (ch >= 'a' && ch <= 'z')
        {
            ch = ch + key;
            if (ch > 'z')
            {
                ch = ch - 'z' + 'a' - 1;
            }
            message[i] = ch;
        }
        else if (ch >= 'A' && ch <= 'Z')
        {
            ch = ch + key;
            if (ch > 'Z')
            {
                ch = ch - 'Z' + 'A' - 1;
            }
            message[i] = ch;
        }
    }
    printf("Encrypted message: %s", message);
}*/
