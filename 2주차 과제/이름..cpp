#include <iostream>
using namespace std;

float TotalGrade(struct Student*);

	struct Subject {   // ���� ����
		char SubName[30];   // �����̸�
		int Hakjum;   // ��������
		char Grade[10];   // ������
		float GPA;   // ���� ����
	};

	struct Student {   // �л� ����
		char StdName[30];    // �л��̸�
		int Hakbun;    // �й�
		Subject Sub[3];   // ����
		float AveGPA;   // ������ ��� ����
	};

int main(void) {

	

     struct Student student[2];

	while (1) {

		cout << "===== �޴� =====\n";
		cout << "1.  �л� ���� �Է�\n";
		cout << "2.  ��ü �л� ���� ����\n";
		cout << "3.  ���α׷� ����\n\n";
		cout << "���ϴ� ����� �Է��ϼ��� : ";

		int num;
		cin >> num;

		if (num == 1) {

			for (int j = 1; j < 3; j++) {
				cout << "* " << j << " ��° �л� �̸��� �й��� �Է��ϼ���.\n";
				cout << "�̸� : ";

				if (j == 1) {
					cin >> student[0].StdName;
					cout << "�й� : ";
					cin >> student[0].Hakbun;
					cout << "\n\n\n\n";
					cout << "* ������ ����3���� �� �������, ��������, �������� �Է��ϼ���.\n";
				}

				else if (j == 2) {
					cin >> student[1].StdName;
					cout << "�й� : ";
					cin >> student[1].Hakbun;
					cout << "\n\n\n\n";
					cout << "* ������ ����3���� �� �������, ��������, �������� �Է��ϼ���.\n";
				}

				if (j == 1) {
					for (int i = 0; i < 3; i++) {
						cout << "������� : ";
						cin >> student[0].Sub[i].SubName;
						cout << "���������� : ";
						cin >> student[0].Sub[i].Hakjum;
						cout << "������<A+ ~ F> : ";
						cin >> student[0].Sub[i].Grade;
						cout << '\n';
					}
					cout << "\n\n\n\n";
				}

				else if (j == 2) {
					for (int i = 0; i < 3; i++) {
						cout << "������� : ";
						cin >> student[1].Sub[i].SubName;
						cout << "���������� : ";
						cin >> student[1].Sub[i].Hakjum;
						cout << "������<A+ ~ F> : ";
						cin >> student[1].Sub[i].Grade;
						cout << '\n';
					}
				}
			}
		}

		else if (num == 2) {

		TotalGrade(student);

		cout << "\n";
		cout << "            ��ü �л� ���� ����\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "�̸� : " << student[0].StdName << "  �й� : " << student[0].Hakbun << "\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "             �����  ��������  ������  �������� \n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "           " << student[0].Sub[0].SubName << "      " << student[0].Sub[0].Hakjum << "             " << student[0].Sub[0].Grade << "          " << student[0].Sub[0].GPA<<"\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "                               �������        "<<student[0].AveGPA<<"\n";
		cout << "�̸� : " << student[1].StdName << "  �й� : " << student[1].Hakbun << "\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "             �����  ��������  ������  �������� \n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "           " << student[1].Sub[0].SubName << "      " << student[1].Sub[0].Hakjum << "             " << student[1].Sub[0].Grade << "          " << student[0].Sub[0].GPA << "\n";
		cout.width(70); cout.fill('=');  cout << "\n";
		cout << "                               �������        " << student[1].AveGPA << "\n";
		}

		else if (num == 3) {
			cout << "\n";
			cout << "���α׷��� �����մϴ�.";
			break;
		}
	}
	}
	


float TotalGrade(struct Student* student) {
	
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {

			switch ((student+i)->Sub[j].Grade)
			{
			case "A+": student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 4.5;
				break;
			case 'a+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 4.5;
				break;
			case 'A0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 4.0;
				break;
			case 'a0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 4.0;
				break;
			case 'B+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 3.5;
				break;
			case 'b+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 3.5;
				break;
			case 'B0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 3.0;
				break;
			case 'b0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 3.0;
				break;
			case 'C+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 2.5;
				break;
			case 'c+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 2.5;
				break;
			case 'C0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 2.0;
				break;
			case 'c0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 2.0;
				break;
			case 'D+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 1.5;
				break;
			case 'd+': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 1.5;
				break;
			case 'D0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 1.0;
				break;
			case 'd0': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 1.0;
				break;
			case 'F': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 0.0;
				break;
			case 'f': student[i].Sub[j].GPA = student[i].Sub[j].Hakjum * 0.0;
				break;
			}
		}
	}
	student[0].AveGPA = (student[0].Sub[0].GPA + student[0].Sub[1].GPA + student[0].Sub[2].GPA) / (student[0].Sub[0].Hakjum + student[0].Sub[1].Hakjum + student[0].Sub[2].Hakjum);
	student[1].AveGPA = (student[1].Sub[0].GPA + student[1].Sub[1].GPA + student[1].Sub[2].GPA) / (student[1].Sub[0].Hakjum + student[1].Sub[1].Hakjum + student[1].Sub[2].Hakjum);
}