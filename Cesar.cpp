#include <iostream>
#include <string>

std::string toupp(std::string text){
    for (int i = 0; i < text.size(); i++){
            if(islower(text[i])){
                text[i] = toupper(text[i]);
            }
    }
    return text;
}
int main(){
    char al[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int key = 1;
    int mode;
    std::string text;
    char crypt_text[text.size()];
    char decrypt_text[text.size()];
    std::cout << "[1]Encrypt - [2]Decrypt - ";
    std::cin >> mode;
    if (mode == 1){
        std::cout << "Enter the key - ";
        std::cin >> key;
        std::cout << "Enter the text - ";
        std::cin.ignore();
        std::getline(std::cin,text);
        text = toupp(text);
        std::cout << text.size();
        for(int i = 0; i < text.size(); i++){
            if(text[i] == ' '){
                text.erase(i,1);
            }
            for(int a = 0; a <= 25; a++){
                if(al[a] == text[i]){
                    crypt_text[i] = al[(a + key) % 26];
                    break;
                }
            }       
        }
        std::cout << "Encrypt message - ";
        std::cout << crypt_text << std::endl;
    }
    else if(mode == 2){
        std::cout << "Enter the text - ";
        std::cin.ignore();
        std::getline(std::cin,text);
        text = toupp(text);
        for(int i = 0; i <= 24; i++){
            for(int j = 0; j < text.size();j++){
                if(text[j] == ' '){
                    text.erase(i,1);
                }
                for(int a = 0; a <= 24; a++){
                    if(al[a] == text[j]){
                        decrypt_text[j] = al[(a + key) % 26];
                        break;
                    }
                }
            }
            std::cout << key << " : "; 
            std::cout << decrypt_text << std::endl;
            key++;
        }
    }
    else{
        std::cout << "Please, enter legal number [1] or [2]";
    }
    return 0;
}