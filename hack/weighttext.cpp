#include <iostream>
#include <stdio.h>
#include <string>

#include "ai.h"

std::string stripinput(std::string text){
    for (int i = 0, len = text.size(); i < len; i++)
    {
        if (ispunct(text[i]))
        {
            text.erase(i--, 1);
            len = text.size();
        }
    }
    std::string b="";
    for(int i=0; i<text.size();++i){
        b+=tolower(text[i]);
    }
    return b;
}

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
    std::string name = "article";
    char asdf[100] = "";
    sprintf(asdf,"%d",articleNum);
    name += asdf;
    name += ".txt";
    f=fopen(name.c_str(),"r");
    int a=0;
    s="";

    if(f==NULL){
        perror("Error opening file");
    }else do{
        c=fgetc(f);
        if(isspace(c)){
            a+=weight(stripinput(s),wordList,i);
            s="";
        }else{
            s+=c;
        }
    }while(c!=EOF);

    fclose(f);
    return a;
}/*
int article(int articleNum){
    char c;
    std::string s="";
    FILE *wf;
    wf=fopen("weights.txt", "r");

    int i;
    fscanf(wf, "%d", &i);
    KeyWords wordList[i];
    for(int j=0;j<i;j++){
        // get int
        fscanf(wf,"%d", &(wordList[j].weight));
        // get string
        fscanf(wf,"%s", &(wordList[j].word));
    }
    fclose(wf);

    FILE *f;
    f=fopen("article1.txt","r");
    int a=0;
    s="";

    if(f==NULL){
        printf("Error opening file");
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
*/



