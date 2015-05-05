#include <algorithm>
#include <iomanip>
#include <ios>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "grade.h"
#include "Student_info.h"

using std::cin;
using std::cout;
using std::domain_error;
using std::endl;
using std::max;
using std::setprecision;
using std::sort;
using std::streamsize;
using std::string;
using std::vector;

int main()
{
    vector<Student_info> students;
    Student_info record;
    string::size_type maxlen = 0;

    //Read and store all students data
    while (read(cin, record))
    {
        //Find longest name
        maxlen = max(maxlen, record.name.size());
        students.push_back(record);
    }

    //Alphabetize student records
    sort(students.begin(), students.end(), compare);

    //Write names and grades
    for (vector<Student_info>::size_type i = 0;
         i != students.size(); ++i)
    {
        //write name padded to right
        cout << students[i].name
        << string(maxlen + 1 - students[i].name.size(), ' ');

        //Compute and write grades
        try
        {
            double final_grade = grade(students[i]);
            streamsize prec = cout.precision();
            cout << setprecision(3) << final_grade
            << setprecision(prec);
        }
        catch (domain_error e)
        {
            cout << e.what();
        }
        cout << endl;
    }
    return 0;
}