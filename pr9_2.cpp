#include <iostream>
#include <iomanip>
#include <string>
#include <Windows.h>
using namespace std;

enum Spec { KOMPUTERNINAUKY, INFORMATIKA, MATEMATIKAIEKONOMIKA, FIZUKAIINFORMATIKA, TRUDOVENAVCHANNA };

string spec_str[] = { "Computer Science", "Informatics", "Mathematics and Economics", "Physics and Informatics", "Handicraft" };

struct Student
{
	string last_name;
	int cource;
	Spec speciality;
	int fizuka;
	int matematika;
	union {
		int programuvanna;
		int chuselni_metody;
		int pedagogika;
	};
};

void Create(Student* s, const int N);
void Print(Student* s, const int N);
void Menu(Student* s, const int N);
void Sort(Student* s, const int N);
int *IndexArray(Student* s, const int N);
void PrintIndexArray(Student* s, int* I, const int N);
int BinarySearch(Student* s, const int N, const string blast_name, const int bcource, const int bfizuka);

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int N;
	cout << "Insert N: "; cin >> N;
	Student* s = new Student[N];

	Create(s, N);
	Print(s, N);
	Menu(s, N);
}
void Create(Student* s, const int N) {
	int speciality;
	for (int i = 0; i < N; i++)
	{
		cout << "Student № " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();
		cout << " Last Name: "; getline(cin, s[i].last_name);
		cout << " Cource : "; cin >> s[i].cource;
		cout << " Speciality (0 - Computer Science, 1 - Informatics, 2 - Mathematics and Economics, 3 - Physics and Informatics, 4 - Handicraft): ";
		cin >> speciality;
		s[i].speciality = (Spec)speciality;
		switch (s[i].speciality) {
		case KOMPUTERNINAUKY:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Programming : "; cin >> s[i].programuvanna;
			break;
		case INFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Numerical Methods : "; cin >> s[i].chuselni_metody;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].pedagogika;
			break;
		case FIZUKAIINFORMATIKA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].pedagogika;
			break;
		case TRUDOVENAVCHANNA:
			cout << " Physics : "; cin >> s[i].fizuka;
			cout << " Mathematics : "; cin >> s[i].matematika;
			cout << " Pedagogy : "; cin >> s[i].pedagogika;
			break;
		}
		cout << endl;
	}
}
void Print(Student* s, const int N)
{
	cout << "============================================================================="
		<< endl;
	cout << "| № | Last Name | Course | Speciality | Phy | Math | Prog | Num Met | Ped |"
		<< endl;
	cout << "-----------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << s[i].last_name
			<< "| " << setw(6) << right << s[i].cource << " "
			<< "| " << setw(10) << left << spec_str[s[i].speciality];
		switch (s[i].speciality) {
		case KOMPUTERNINAUKY:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << "|" << " " << setw(3) << right << s[i].programuvanna << " |"
				<< " " << setw(3) << right << " |" << " " << setw(3) << right << " |" << endl;
			break;
		case INFORMATIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< s[i].chuselni_metody << " |" << setw(3) << right << "|" << endl;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].pedagogika << " |" << endl;
			break;
		case FIZUKAIINFORMATIKA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].pedagogika << " |" << endl;
			break;
		case TRUDOVENAVCHANNA:
			cout << "| " << setw(3) << right << s[i].fizuka << "|" << " " << setw(3) << right
				<< s[i].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[i].pedagogika << " |" << endl;
			break;
		}
	}
	cout << "============================================================================="
		<< endl;
	cout << endl;
}
void Menu(Student* s, const int N)
{

	int choice;

	do {
		cout << "--------------------------\n";
		cout << "Main Menu\n";
		cout << "Please make your selection\n";
		cout << "1 - Sort\n";
		cout << "2 - Index Array\n";
		cout << "3 - Binary Search\n";
		cout << "4 - Quit\n";
		cout << "--------------------------\n";
		cout << "Selection: ";
		cin >> choice;

		switch (choice) {
		case 1:
			cout << "You Chosen 1 - Sort:\n";
			Sort(s, N);
			Print(s, N);
			break;
		case 2:
			cout << "You Chosen 2 - Index Array:\n";
			PrintIndexArray(s, IndexArray(s, N), N);
			break;
		case 3:
		{
			cout << "You Chosen 3 - Binary Search:\n";

			string blast_name;
			int bcource;
			int bfizuka;
			int found;

			cout << "Enter Keys For Binary Search:" << endl;
			cout << " Last Name Of Student: ";
			cin >> blast_name;
			cout << " Course: ";
			cin >> bcource;
			cout << " Physics Grade: ";
			cin >> bfizuka;
			cout << endl;
			if ((found = BinarySearch(s, N, blast_name, bcource, bfizuka)) != -1) {
				cout << "Student Found On Position: " << found + 1 << endl;
			}
			else {
				cout << "Student Not Found" << endl;
			}
			break;
		}
		case 4:
			cout << "Goodbye! See Ya Later, Aligator!!!";
			break;
		default:
			cout << "--------------------------\n";
			cout << "Main Menu\n";
			cout << "Please make your selection\n";
			cout << "1 - Sort\n";
			cout << "2 - Index Array\n";
			cout << "3 - Binary Search\n";
			cout << "4 - Quit\n";
			cout << "--------------------------\n";
			cout << "Selection: ";
			cin >> choice;
		}
	} while (choice != 4);
}
void Sort(Student* s, const int N) 
{
	Student tmp;
	for (int i0 = 0; i0 < N - 1; i0++) {
		for (int i1 = 0; i1 < N - i0 - 1; i1++) {
			if (s[i1].fizuka < s[i1 + 1].fizuka) {
				tmp = s[i1];
				s[i1] = s[i1 + 1];
				s[i1 + 1] = tmp;
			}
			else if (s[i1].fizuka == s[i1 + 1].fizuka) {
				if (s[i1].cource < s[i1 + 1].cource) {
					tmp = s[i1];
					s[i1] = s[i1 + 1];
					s[i1 + 1] = tmp;
				}
				else if (s[i1].cource == s[i1 + 1].cource)
				{
					if (s[i1].last_name < s[i1 + 1].last_name) {
						tmp = s[i1];
						s[i1] = s[i1 + 1];
						s[i1 + 1] = tmp;
					}
				}
			}
		}
	}
}
int *IndexArray(Student* s, const int N) {
	int* I = new int[N];
	for (int i = 0; i < N; i++)
		I[i] = i;
	int i, j, value;
	for (i = 1; i < N; i++)
	{
		value = I[i];
		for (j = i - 1; j >= 0 && ((s[I[j]].last_name < s[value].last_name) || (s[I[j]].last_name == s[value].last_name && s[I[j]].cource < s[value].cource) || (s[I[j]].last_name == s[value].last_name && s[I[j]].cource == s[value].cource && s[I[j]].fizuka < s[value].fizuka)); j--)
		{
			I[j + 1] = I[j];
		}
		I[j + 1] = value;
	}
	return I;
}
void PrintIndexArray(Student* s, int* I, const int N) {
	cout << "============================================================================="
		<< endl;
	cout << "| № | Last Name | Course | Speciality | Phy | Math | Prog | Num Met | Ped |"
		<< endl;
	cout << "-----------------------------------------------------------------------------"
		<< endl;
	for (int i = 0; i < N; i++) {
		cout << "| " << setw(1) << right << i + 1 << " ";
		cout << "| " << setw(10) << left << s[I[i]].last_name
			<< "| " << setw(6) << right << s[I[i]].cource << " "
			<< "| " << setw(10) << left << spec_str[s[I[i]].speciality];
		switch (s[i].speciality) {
		case KOMPUTERNINAUKY:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << "|" << " " << setw(3) << right << s[I[i]].programuvanna << " |"
				<< " " << setw(3) << right << " |" << " " << setw(3) << right << " |" << endl;
			break;
		case INFORMATIKA:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< s[I[i]].chuselni_metody << " |" << setw(3) << right << "|" << endl;
			break;
		case MATEMATIKAIEKONOMIKA:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[I[i]].pedagogika << " |" << endl;
			break;
		case FIZUKAIINFORMATIKA:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[I[i]].pedagogika << " |" << endl;
			break;
		case TRUDOVENAVCHANNA:
			cout << "| " << setw(3) << right << s[I[i]].fizuka << "|" << " " << setw(3) << right
				<< s[I[i]].matematika << " " << setw(3) << right << "|" << " " << setw(3) << right
				<< " |" << " " << setw(3) << right << s[I[i]].pedagogika << " |" << endl;
			break;
		}
	}
	cout << "============================================================================="
		<< endl;
	cout << endl;
}
int BinarySearch(Student* s, const int N, const string blast_name, const int bcource, const int bfizuka) {
	int L = 0, R = N - 1, m;
	do {
		m = (L + R) / 2;
		if (s[m].last_name == blast_name && s[m].cource == bcource && s[m].fizuka == bfizuka)
			return m;
		if ((s[m].last_name < blast_name) || (s[m].last_name == blast_name && s[m].cource < bcource) || (s[m].last_name == blast_name && s[m].cource == bcource && s[m].fizuka < bfizuka))
		{
			L = m + 1;
		}
		else
		{
			R = m - 1;
		}
	} while (L <= R);
	return -1;
}