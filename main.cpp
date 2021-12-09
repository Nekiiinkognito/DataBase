#include <iostream>
#include <iomanip>
#include <fstream>
#include <typeinfo>
#include <cstdlib>
#include <string.h>

using namespace std;

struct Student {
    int yearOfBirth = 0;
    int yearOfEnrollment = 0;
    int kurs = 0;
    char *name = new char[15];
    char *surname = new char[15];
    char *group = new char[15];
};

void PrintMenu();
int GetUserVariant(int);
void AddStudent(Student *, int &, int &);
void StudentSortMain(Student *, int);
void StudentsSortUp(Student *, int);
void StudentsSortDown(Student *, int);
void AllInformation(Student *, int);
void ChangeInformation(Student *, int);
void DeleteInforamtion(Student *, int &);
void MainSortOfStudent(Student *, int);
void NameSortUp(Student *, int);
void NameSortDown(Student *, int);
void NameSortMain(Student *, int);
void SurnameSortUp(Student *, int);
void SurnameSortDown(Student *, int);
void SurnameSortMain(Student *, int);
void GroupSortUp(Student *, int);
void GroupSortDown(Student *, int);
void GroupSortMain(Student *, int);
void WriteToFile(Student *, int);
void ReadData(Student *, int &);
void WriteToFileBin(Student *, int);
char *UserInputText();
void ReadDataBin(Student *, int &);

int main()
{
    int n = 0, g = 0;
    Student *smf = new Student[100];
    int punkti = 11, variant = 0;
    while (variant != punkti)
    {
        PrintMenu();

        variant = GetUserVariant(punkti);

        switch (variant)
        {
        case 1:
            system("cls");
            AddStudent(smf, n, g);
            break;
        case 2:
            system("cls");
            StudentSortMain(smf, g);
            break;
        case 3:
            system("cls");
            AllInformation(smf, g);
            break;
        case 4:
            system("cls");
            ChangeInformation(smf, g);
            break;
        case 5:
            system("cls");
            MainSortOfStudent(smf, g);
            break;
        case 6:
            system("cls");
            DeleteInforamtion(smf, g);
            break;
        case 7:
            system("cls");
            WriteToFile(smf, g);
            break;
        case 8:
            system("cls");
            ReadData(smf, g);
            break;
        case 9:
            system("cls");
            WriteToFileBin(smf, g);
            break;
        case 10:
            system("cls");
            ReadDataBin(smf, g);
            break;
        default:
            break;
        }
        if(variant != punkti)
        {
            system("pause");
            system("cls");
        }
    }
    return 0;
}

void AllInformation(Student *massive, int z)
{
    cout << "+---+------------+-------------+---------------+------------+------------+------------+" << endl;
    cout << "| N |    Name    |   Surname   | Year of birth | Enrollment |   Course   |    Group   |" << endl;
    cout << "+---+------------+-------------+---------------+------------+------------+------------+" << endl;
    int j = 1;
    for(int i = 0; i < z; i++)
    {
        cout << "|" << setw(3) << j << "|" << setw(12) << massive[i].name << "|" << setw(13) << massive[i].surname << "|" << setw(15) << massive[i].yearOfBirth << "|" << setw(12) << massive[i].yearOfEnrollment << "|" << setw(12) << massive[i].kurs << "|" << setw(12) << massive[i].group << "|" << endl;
        cout << "+---+------------+-------------+---------------+------------+------------+------------+" << endl;
        j++;
    }
}

int GetUserVariant(int cnt)
{
    int v = 0;
    cin >> v;
    if (v <= cnt && v >= 1) return v;
    else cout << "Incorrect value, please, try again.\n";
}

void PrintMenu()
{
    cout << "What do you like to do?" << endl;
    cout << "1. Add a new student." << endl;
    cout << "2. Request." << endl;
    cout << "3. Get information about all students." << endl;
    cout << "4. Change information." << endl;
    cout << "5. Sort." << endl;
    cout << "6. Delete information." << endl;
    cout << "7. Write Information into file(text)." << endl;
    cout << "8. Read data(text version)." << endl;
    cout << "9. Write Information into file(bin)." << endl;
    cout << "10. Read data(bin version)." << endl;
    cout << "11. Exit." << endl;
    cout << "> ";
}

void AddStudent(Student *massive, int &z, int &a)
{
    int tt = z, h = 0;
    cout << "Enter name of Student: ";
    massive[tt].name = UserInputText();
    cout << "Enter surname of Student: ";
    massive[tt].surname  = UserInputText();
    cout << "Enter year of birth of Student: ";
    cin >> h;
    massive[tt].yearOfBirth = h;
    cout << "Enter year of Enrollment of Student: ";
    cin >> h;
    massive[tt].yearOfEnrollment = h;
    cout << "Enter year of course of Student: ";
    cin >> h;
    massive[tt].kurs = h;
    cout << "Enter group of Student: ";
    cin >> massive[tt].group;
    z++;
    a++;
}

void StudentSortMain(Student *massive, int z)
{
    int h = 0;
    cout << "How do you want sort students?" << endl;
    cout << "1. Up." << endl;
    cout << "2. Down." << endl;
    cout << "> ";
    cin >> h;
    if(h == 1 || h == 2)
    {
            switch(h)
            {
            case 1:
                StudentsSortUp(massive, z);
                break;
            case 2:
                StudentsSortDown(massive, z);
                break;
            }
    }
    else
    {
        cout << "Please, enter correct value!" << endl;
        system("pause");
        system("cls");
        StudentSortMain(massive, z);
    }
}

void StudentsSortUp(Student *massive, int z)
{
    for(int i = 0; i < z; i++)
    {
        for(int j = 0; j < z; j++)
        {
            if(massive[j].yearOfBirth < massive[i].yearOfBirth)
            {
                Student year = massive[j];
                massive[j] = massive[i];
                massive[i] = year;
            }
        }
    }
}

void StudentsSortDown(Student *massive, int z)
{
    for(int i = 0; i < z; i++)
    {
        for(int j = 0; j < z; j++)
        {
            if(massive[j].yearOfBirth > massive[i].yearOfBirth)
            {
                int year = massive[j].yearOfBirth;
                massive[j].yearOfBirth = massive[i].yearOfBirth;
                massive[i].yearOfBirth = year;
            }
        }
    }
}

void ChangeInformation(Student *massive, int z)
{
    system("cls");
    int t = 0, y = 0;
    AllInformation(massive, z);
    cout << "Enter the number of the student you want to change information about. \n0. Exit. \n";
    cin >> t;
    if(t != 0)
    {
    if(t <= z + 1)
    {
        system("cls");
        cout << "What do you want to change?" << endl;
        cout << "1. Name." << endl;
        cout << "2. Surname." << endl;
        cout << "3. Year of birth." << endl;
        cout << "4. Year of enrollment." << endl;
        cout << "5. Course." << endl;
        cout << "6. Group." << endl;
        cout << "> ";
        cin >> y;
        cout << "Enter new value: ";
        switch(y)
        {
        case 1:
            massive[t - 1].name = UserInputText();
            break;
        case 2:
            massive[t - 1].surname = UserInputText();
            break;
        case 3:
            cin >> massive[t - 1].yearOfBirth;
            break;
        case 4:
            cin >> massive[t - 1].yearOfEnrollment;
            break;
        case 5:
            cin >> massive[t - 1].kurs;
            break;
        case 6:
            cin >> massive[t - 1].group;
            break;
        }
    }

    else
    {
        cout << "Enter correct value!";
        system("pause");
        system("cls");
        ChangeInformation(massive, z);
    }
    }
}

void DeleteInforamtion(Student *massive, int &z)
{
    system("cls");
    int t = 0, y = 0;
    AllInformation(massive, z);
    cout << "What do you want to delete?\n> ";
    cin >> t;
    for(int i = t - 1; i < z; i++)
    {
        massive[i].name = massive[i + 1].name;
        massive[i].surname = massive[i + 1].surname;
        massive[i].yearOfBirth = massive[i + 1].yearOfBirth;
        massive[i].yearOfEnrollment = massive[i + 1].yearOfEnrollment;
        massive[i].kurs = massive[i + 1].kurs;
        massive[i].group = massive[i + 1].group;
    }
    if(t <= z) z--;
}

void MainSortOfStudent(Student *massive, int z)
{
    cout << "How you want to sort students?" << endl;
    cout << "1. Name." << endl;
    cout << "2. Surname." << endl;
    cout << "3. Group." << endl;
    int t = 0;
    cout << "> ";
    cin >> t;
    switch(t)
    {
    case 1:
        system("cls");
        NameSortMain(massive, z);
        break;
    case 2:
        system("cls");
        SurnameSortMain(massive, z);
        break;
    case 3:
        system("cls");
        GroupSortMain(massive, z);
        break;
    }
}

void NameSortMain(Student *massive, int z)
{
    int h = 0;
    cout << "How do you want sort students?" << endl;
    cout << "1. Up." << endl;
    cout << "2. Down." << endl;
    cout << "> ";
    cin >> h;
    if(h == 1 || h == 2)
    {
            switch(h)
            {
            case 1:
                NameSortUp(massive, z);
                break;
            case 2:
                NameSortDown(massive, z);
                break;
            }
    }
    else
    {
        cout << "Please, enter correct value!" << endl;
        system("pause");
        system("cls");
        NameSortMain(massive, z);
    }
}

void NameSortDown(Student *massive, int z)
{
    for(int i = 0; i < z; i++)
    {
        for(int j = 0; j < z; j++)
        {
            if(massive[j].name[0] < massive[i].name[0])
            {
                Student nm = massive[j];
                massive[j] = massive[i];
                massive[i] = nm;
            }
        }
    }
}

void NameSortUp(Student *massive, int z)
{
    for(int i = 0; i < z; i++)
    {
        for(int j = 0; j < z; j++)
        {
            if(massive[j].name[0] > massive[i].name[0])
            {
                Student nm = massive[j];
                massive[j] = massive[i];
                massive[i] = nm;
            }
        }
    }
}

void SurnameSortMain(Student *massive, int z)
{
    int h = 0;
    cout << "How do you want sort students?" << endl;
    cout << "1. Up." << endl;
    cout << "2. Down." << endl;
    cout << "> ";
    cin >> h;
    if(h == 1 || h == 2)
    {
            switch(h)
            {
            case 1:
                SurnameSortUp(massive, z);
                break;
            case 2:
                SurnameSortDown(massive, z);
                break;
            }
    }
    else
    {
        cout << "Please, enter correct value!" << endl;
        system("pause");
        system("cls");
        NameSortMain(massive, z);
    }
}

void SurnameSortDown(Student *massive, int z)
{
    for(int i = 0; i < z; i++)
    {
        for(int j = 0; j < z; j++)
        {
            if(massive[j].surname[0] < massive[i].surname[0])
            {
                Student snm = massive[j];
                massive[j] = massive[i];
                massive[i] = snm;
            }
        }
    }
}

void SurnameSortUp(Student *massive, int z)
{
    for(int i = 0; i < z; i++)
    {
        for(int j = 0; j < z; j++)
        {
            if(massive[j].surname[0] > massive[i].surname[0])
            {
                Student snm = massive[j];
                massive[j] = massive[i];
                massive[i] = snm;
            }
        }
    }
}

void GroupSortMain(Student *massive, int z)
{
    int h = 0;
    cout << "How do you want sort students?" << endl;
    cout << "1. Up." << endl;
    cout << "2. Down." << endl;
    cout << "> ";
    cin >> h;
    if(h == 1 || h == 2)
    {
            switch(h)
            {
            case 1:
                GroupSortUp(massive, z);
                break;
            case 2:
                GroupSortDown(massive, z);
                break;
            }
    }
    else
    {
        cout << "Please, enter correct value!" << endl;
        system("pause");
        system("cls");
        NameSortMain(massive, z);
    }
}

void GroupSortDown(Student *massive, int z)
{
    for(int i = 0; i < z; i++)
    {
        for(int j = 0; j < z; j++)
        {
            if(massive[j].group[0] < massive[i].group[0])
            {
                Student grp = massive[j];
                massive[j] = massive[i];
                massive[i] = grp;
            }
        }
    }
}

void GroupSortUp(Student *massive, int z)
{
    for(int i = 0; i < z; i++)
    {
        for(int j = 0; j < z; j++)
        {
            if(massive[j].group[0] > massive[i].group[0])
            {
                Student grp = massive[j];
                massive[j] = massive[i];
                massive[i] = grp;
            }
        }
    }
}

void WriteToFile(Student *massive, int z)
{
    ofstream someFile;
    someFile.open("test.TXT");
    if(someFile.is_open())
    {
        for(int i = 0; i < z; i++)
        {
            someFile << massive[i].name << " " << massive[i].surname << " " << massive[i].yearOfBirth << " " << massive[i].yearOfEnrollment << " " << massive[i].kurs << " " << massive[i].group;
            if(i + 1 == z) someFile << "\n";
            else someFile << "\n ";
        }
        cout << "Success!" << endl;
    }
    someFile.close();
}

void ReadData(Student *massive, int &z)
{
    ifstream someFile;
    someFile.open("test.TXT");
    int n = 0;
    z = 0;
    if(someFile.is_open())
    {
        while(!someFile.eof())
        {
            char what[15];
            someFile.getline(massive[n].name, 255, ' ');
            someFile.getline(massive[n].surname, 255, ' ');
            someFile.getline(what, 255, ' ');
            massive[n].yearOfBirth = atoi(what);
            someFile.getline(what, 255, ' ');
            massive[n].yearOfEnrollment = atoi(what);
            someFile.getline(what, 255, ' ');
            massive[n].kurs = atoi(what);
            someFile.getline(massive[n].group, 255, ' ');
            massive[n].group[strlen(massive[n].group) - 1] = ' ';
            n++;
            z++;
        }
    }
    cout << "Done!\n";
    someFile.close();
}

void WriteToFileBin(Student *massive, int z)
{
    ReadData(massive, z);
    system("cls");
    ofstream out("testBin.bin", ios::out|ios::binary);
    int n = 0;
    out.write((char *)&massive, sizeof(massive));
    out.close();
}

void ReadDataBin(Student *massive, int &z)
{
    ReadData(massive, z);
    WriteToFileBin(massive, z);
    ifstream someFile;
    someFile.open("testBin.bin", ios::binary);
    int n = 0;
    Student *s = new Student[100];
    if(someFile.is_open())
    {
        someFile.read((char *)&s, sizeof(s));
    }
    for(int i = 0; i < z; i++)
    {
        massive[i] = s[i];
    }
    cout << "Done!\n";
    someFile.close();
}

char *UserInputText()
{
    char *possibleSimbol = new char[15];
    possibleSimbol = "123456789;:'/?.>,<!@#$%^&*)(";
    char *smf = new char[15];
    bool flg = false;
    cin >> smf;
    for(int i = 0; i < strlen(smf); i++)
    {
        for(int j = 0; j < strlen(possibleSimbol); j++)
        {
            if(smf[i] == possibleSimbol[j]) flg = true;
        }
    }
    if(!flg) return smf;
    else
    {
        cout << "Incorrect value!\nPlease, enter again\n> ";
        UserInputText();
    }
}
