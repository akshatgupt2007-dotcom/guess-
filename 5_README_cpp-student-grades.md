# Student Grade Manager (C++)

Takes marks for multiple students, calculates each student's average and grade, and prints a ranked report card.

## Concepts Used
- `struct` with member functions
- `std::vector`
- Lambda function with `std::sort`
- Output formatting with `<iomanip>`

## Grading Scale
| Average | Grade |
|---------|-------|
| 90+     | A     |
| 75-89   | B     |
| 60-74   | C     |
| 40-59   | D     |
| < 40    | F     |

## Requirements
- g++ with C++11 or higher

## How to Run
```bash
g++ grades.cpp -o grades
./grades
```
