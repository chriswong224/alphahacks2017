#include <iostream>
#include <string>

struct KeyWords{
    int weight;
    std::string word;
};

int weight(std::string s, KeyWords a[],int numWords){
    for(int i=0;i<numWords;i++){
        if(a[i].word==s){
            return a[i].weight;
        }
    }
    return 0;
}

int article(int articleNum){
    char c;
    std::string s="";
    FILE *wf;
    wf=fopen("weights.txt", "r");

    while(true){
        c=fgetc(wf);
        if(isspace(c)){break;}
        s+=c;
    }
    int i=std::stoi(s);
    KeyWords wordList[i];
    for(int j=0;j<i;j++){
        // get int
        s="";
        while(true){
            c=fgetc(wf);
            if(isspace(c)){break;}
            s+=(c);
        }
        wordList[j].weight=std::stoi(s);
        s="";
        // get string
        while(true){
            c=fgetc(wf);
            if(isspace(c)){break;}
            s+=(c);
        }
        wordList[j].word=s;
    }
    fclose(wf);

    FILE *f;
    f=fopen("article1.txt","r");
    int a=0;
    s="";

    if(f==NULL){
        perror("Error opening file");
    }else do{
        c=fgetc(f);
        if(isspace(c)){
            a+=weight(s,wordList,i);
            s="";
        }else{
            s+=c;
        }
    }while(c!=EOF);

    fclose(f);
    return a;
}


int main(){

    std::cout <<article(1);

    return 0;
}



