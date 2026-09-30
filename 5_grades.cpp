#include <iostream>
#include <vector>
#include <string>
#include <iomanip>
#include <algorithm>

struct Student {
    std::string name;
    std::vector<double> marks;

    double average() const {
        double sum = 0;
        for (double m : marks) sum += m;
        return marks.empty() ? 0 : sum / marks.size();
    }

    char grade() const {
        double a = average();
        if (a >= 90) return 'A';
        if (a >= 75) return 'B';
        if (a >= 60) return 'C';
        if (a >= 40) return 'D';
        return 'F';
    }
};

int main() {
    int n, subjects;
    std::cout << "Number of students: ";
    std::cin >> n;
    std::cout << "Number of subjects: ";
    std::cin >> subjects;

    std::vector<Student> students(n);
    for (auto &s : students) {
        std::cout << "\nStudent name: ";
        std::cin >> s.name;
        for (int i = 1; i <= subjects; i++) {
            double m;
            std::cout << "  Marks in subject " << i << ": ";
            std::cin >> m;
            s.marks.push_back(m);
        }
    }

    // Sort by average marks (highest first)
    std::sort(students.begin(), students.end(),
              [](const Student &a, const Student &b) { return a.average() > b.average(); });

    std::cout << "\n" << std::left << std::setw(15) << "Name"
              << std::setw(10) << "Average" << "Grade\n";
    std::cout << std::string(32, '-') << "\n";
    for (const auto &s : students) {
        std::cout << std::left << std::setw(15) << s.name
                  << std::setw(10) << std::fixed << std::setprecision(2) << s.average()
                  << s.grade() << "\n";
    }
    return 0;
}
