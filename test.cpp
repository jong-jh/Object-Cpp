#include<iostream>
#include<string>
using namespace std;

void swap(struct St *);
struct St{
    int name;
    int num;
};

int main(){


struct St s[2];
s[0].num=5;
s[0].name=1;



swap(s);

printf("%d",s[0].num);
}

void swap(struct St * st){
    printf("%d\n",st[0].num);
    st[0].num=10;
}