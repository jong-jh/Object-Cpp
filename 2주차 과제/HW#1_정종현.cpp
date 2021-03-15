/*******************************************************************************************************************************/
/*             HW#1 : C++ 시작하기                                                   */
/*  작성자 : 정종현                                날짜 : 2021년 3월 12일  */
/*                                                                                                     */
/* 문제 정의 : 학생 정보를 저장하는 구조체 Student 와 과목 및 성적 정보를 입력하는 Subject구조체를 이욯해  */
/*            두 명의 학생에 대한 정보와 학점을 입력받은 뒤 학점을 점수로 환산해 과목 평점과 교과목 평균 평점을 출력받는 문제   */
/*            구조체를 함수인자로 받아, 구조체 배열의 레퍼런스을 전달하기 위한 표현이 주요 문제*/
/******************************************************************************************************************************/
#include<iostream>
#include<string> //string 문자열을 사용하기 위해 사용하였다.
using namespace std;

/*학생 정보와 각 수업의 성적 정보를 담는 구조체를 정의해준다
struct Student 에 struct Subject 배열을 선언함으로써
따로 Subject를 선언하지 않아도 각 학생에 대한 시험정보를 담을 수 있게 된다.
*/
struct Subject{// 과목 정보
    char SubName[30];//과목이름
    int Hakjum;     //과목 학점수
    string Grade; //과목 등급, char Grade[10]으로 했으나, string함수의 compare 기능을 이용하기 위해 string으로 선언
    float GPA;      //과목 평점
};

struct Student{//학생 정보
    char StdName[30];//학생 이름
    int StdNum;     //학번
    Subject Sub[3]; //과목
    float AveGPA;   //교과목 평균 평점
    //int sample; //마지막 항목에 nan 값 방지를 위한 의미없는 변수 하나 선언
};

/*사용하는 함수 정의*/
int menu(); //메뉴 출력 및 번호를 입력는 함수
void menu_1(struct Student*); //메뉴 1번 실행 함수
void menu_2(struct Student*); //메뉴 2번 실행 함수
void convert_GPA(struct Student*);//과목 등급 -> 평점 변환 함수



int main(){
  /* 2명의 학생의 성적을 받기 때문에 크기 2의 Student 구조체 배열을 선언한다(Student Std[2];)
  main문의 동작은 while(1) 안에서, 사용자에게 '3'을 입력받기 전 까지 실행된다.
  switch문을 사용하여 num이 1번일 경우의 케이스, 2번일 경우인 케이스를 나누었고, 
  3번을 입력받으면 while문이 끝나기 때문에 따로 입력하지 않았다.
  */
  Student Std[2];//2명의 학생을 받을 크기가 2인 구조체 배열 선언
  
  Std[1].AveGPA=0.0;//구조체의 마지막 항목인 Std[1].AveGPA에 쓰레기값이 들어가고, 결과 출력물엔 nan이 발생해 초기화를 해주었더니 발생하지 않았다.

while(1){
  int num=menu();//메뉴 출력 및 기능 선택
  if (num==3) {cout<<"프로그램이 종료되었습니다"; break;}//3번을 누르면 while루프 탈출

  switch(num){
    case 1:
      cout<<"\n1번이 선택되었습니다."<<endl<<endl;
      menu_1(Std);//구조체 배열을 함수에 전달
      break;
    case 2:
      cout<<"\n2번이 선택되었습니다.\n\n";
      convert_GPA(Std); //학점 변환 함수 실행
      menu_2(Std); //메뉴 2 실행
      break;
    }
}
return 0;
}




int menu(){//메뉴출력 함수
/*메뉴출력함수는 메뉴판을 출력한 뒤 사용자에게 메뉴사용에 따른 num을 입력받아
  입력받은 num을 return 해준다.
  기능을 벗어나는 숫자를 입력받을 시, 다른 숫자를 입력하라는 경고문을 띄운 뒤 menu기능을 실행시켰다.
*/
  cout<<"~~~~menu~~~~"<<endl;//메뉴판 출력
  cout<<"1. 학생 성적 입력"<<endl;
  cout<<"2. 전체 학생 성적 보기"<<endl;
  cout<<"3. 프로그램 종료"<<endl<<endl;
  cout<<"원하는 기능을 입력하세요 : ";
  int num;
  cin>>num;//번호를 입력받는다
  
  if(num<=3) //예외처리 3보다 작은 수를 입력하면 그대로 리턴한다.
    return num;
  else{//3보다 큰 숫자를 입력하면
      cout<<"다른 번호를 입력해주세요"<<endl<<endl;
      menu(); //메뉴를 다시 불러오기
  }
}


void convert_GPA(struct Student* st){//학점 GPA 변환 함수
/* 점수를 사용자에게 입력을 받을 때 문자열로 입력을 받기 때문에, 프로그램에서 따로
  문자열에 따른 점수를 입력해주었다.
  2중 for문을 사용해, 한 학생의 성적변환이 끝나면 그 다음 학생의 성적변환을 진행한다.
  성적입력을 받을 시 대문자와 소문자 상관없이 받기 위해 OR연산자를 사용하였다.

  2번째 for문 안에서는 입력받은 성적을 AveGPA에 축적하여 for문을 탈출했을 때
  축적된 값(더해준 값)들을 전체 학점수로 나누어 GPA의 평균을 구해주었다.
*/

  for(int i=0;i<2;i++){

    for(int j=0;j<3;j++){//string 함수의 문자열 비교 기능인 compare 사용
    if(st[0].Sub[j].Grade.compare("A+")==0||(st+i)->Sub[j].Grade.compare("a+")==0)
      (st+i)->Sub[j].GPA=4.5;//a+ 혹은 A+을 입력하면 구조체의 GPA에 4.5점수 입력
    else if((st+i)->Sub[j].Grade.compare("A")==0||(st+i)->Sub[j].Grade.compare("a")==0)
      (st+i)->Sub[j].GPA=4.0;//대소문자 상관없이 점수를 받기위해 OR연산자 사용
    else if((st+i)->Sub[j].Grade.compare("B+")==0||(st+i)->Sub[j].Grade.compare("b+")==0)
      (st+i)->Sub[j].GPA=3.5;
    else if((st+i)->Sub[j].Grade.compare("B")==0||(st+i)->Sub[j].Grade.compare("b")==0)
      (st+i)->Sub[j].GPA=3.0;
    else if((st+i)->Sub[j].Grade.compare("C+")==0||(st+i)->Sub[j].Grade.compare("c+")==0)
      (st+i)->Sub[j].GPA=2.5;
    else if((st+i)->Sub[j].Grade.compare("C")==0||(st+i)->Sub[j].Grade.compare("c")==0)
      (st+i)->Sub[j].GPA=2.0;
    else if((st+i)->Sub[j].Grade.compare("D+")==0||(st+i)->Sub[j].Grade.compare("d+")==0)
      (st+i)->Sub[j].GPA=1.5;
    else if((st+i)->Sub[j].Grade.compare("D")==0||(st+i)->Sub[j].Grade.compare("d")==0)
      (st+i)->Sub[j].GPA=1.0;
    else if ((st+i)->Sub[j].Grade.compare("F")==0||(st+i)->Sub[j].Grade.compare("f")==0)
      {(st+i)->Sub[j].GPA=0.0;}
    
    (st+i)->AveGPA+=((st+i)->Sub[j].GPA)*((st+i)->Sub[j].Hakjum); //과목별 평점을 AveGPA에 합산한다.(GPA총 합)=(n번 과목 GPA점수)*(n번 과목 학점 수) * n
    }
    (st+i)->AveGPA=((st+i)->AveGPA)/(((st+i)->Sub[0].Hakjum)+((st+i)->Sub[1].Hakjum)+((st+i)->Sub[2].Hakjum));//AveGPA의 값을 (전체학점수)로 나누어 평균을 구한다.
  }
}




void menu_1(struct Student* st){//학생 성접 입력 함수
  /*menu 1번의 기능은 사용자가 직접 학생의 정보와 성적을 입력할 수 있게 해주는 것이다.
    한 학생의 정보와 성적입력이 끝나면 다음 학생의 정보를 입력하는 순서이다.
    구조체배열의 주소값 이용해 입력을 받기 위해, 구조체 주소에 접근하는 표현이 중요하다.
    
  */

    for(int i=0;i<2;i++){//2명의 학생을 입력하기 때문에 2번 반복
      cout<<i+1<<"번째 학생 이름과 학번을 입력하세요.\n"<<endl;
      cout<<"이름 : ";
      cin>>(st+i)->StdName;//구조체 배열의 주소에 접근하는 표현, 학생의 이름을 입력
      cout<<"학번 : "; 
      cin>>(st+i)->StdNum;//학생의 학번을 입력
      cout<<"\n\n";
        
      cout<<"수강한 과목 3개와 각 교과목명, 과목학점, 과목등급을 입력하세요."<<endl<<endl;
  int j=0;
        for(j=0;j<3;j++){//성적[0],[1],[2]에 받는다.
            
            cout<<"교과목명 : ";
            cin>>(st+i)->Sub[j].SubName;// 과목명 입력
            cout<<"과목학점수 (숫자 입력!!) : "; //숫자를 입력하지 않으면 프로그램이 잘 동작하지 않기 때문에 강조를 해주었다.
            cin>>(st+i)->Sub[j].Hakjum;// 해당 과목의 학점 수 입력
            cout<<"과목등급(A+ ~ F) :";
            cin>>(st+i)->Sub[j].Grade; //해당 과목의 성적 입력
            cout<<"\n";
        }
    }

    cout<<"\n입력이 완료 되었습니다\n"<<endl;
}


void menu_2(struct Student* st){
/*메뉴 2번은 입력받은 학생들의 정보와 성적을 출력해주는 기능을 한다.
  보다 정갈하게 출력하기 위해 cout의 width와 fill을 사용해 칸을 만들고, 공백을 채워주었다.
 */

cout.width(30); cout.fill(' ');
cout<<"전체 학생 성적 보기"<<endl;//2번 메뉴 기능 설명
cout.width(70); cout.fill('='); cout<<'='; //밑줄 출력
cout<<endl;

for(int i=0;i<2;i++){
  cout<<"이름 : "<<(st+i)->StdName<<"  학번 : "<<(st+i)->StdNum<<endl;
  cout.width(50); cout.fill('='); cout<<'='<<endl; //밑줄 출력 공간 50, 공백 = 출력
  cout.width(20); cout.fill(' '); cout<<"과목명 "; //공백 빈칸 출력
  cout.width(10); cout<<"과목학점 ";
  cout.width(10); cout<<"과목등급 ";
  cout.width(10); cout<<"과목평점 "<<endl;
  cout.width(50); cout.fill('='); cout<<'='<<endl; //밑줄 출력
  for(int j=0;j<3;j++){
    cout.width(20); cout.fill(' '); cout<<(st+i)->Sub[j].SubName; //과목 출력
    cout.width(10); cout<<(st+i)->Sub[j].Hakjum; //과목학점 수 출력
    cout.width(10); cout<<(st+i)->Sub[j].Grade; // 과목등급 출력
    cout.width(10); cout<<((st+i)->Sub[j].GPA)*((st+i)->Sub[j].Hakjum)<<endl; //과목당 점수 * 학점 수 -> 과목평점 출력
    }
  cout.width(50); cout.fill('='); cout<<'='<<endl; //밑줄 출력
  cout.width(35); cout.fill(' '); cout<<"평균평점";
  cout.precision(2); cout<<fixed; cout.width(10); cout.fill(' '); cout<<(st+i)->AveGPA<<endl;//평균평점 출력, 소수점 이하 2자리만 출력하도록 고정.
  cout<<endl;
  cout.width(70); cout.fill('='); cout<<'='<<endl; //밑줄 출력
  }

}

