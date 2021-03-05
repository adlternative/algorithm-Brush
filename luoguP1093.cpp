//
// Created by adl on 2020/12/9.
//

#include<bits/stdc++.h>

using namespace std;
struct stu {
public:
    int chinese;
    int math;
    int english;
    int id;
    int sum;
};

int main(int argc, char *argv[]) {
    int i;
    cin >> i;
    vector<shared_ptr<stu>> student;
    student.resize(i);
    for (int j = 0; j != i; ++j) {
        student[j] = make_shared<stu>();
        cin >> student[j]->chinese >> student[j]->math >> student[j]->english;
        student[j]->id = j + 1;
        student[j]->sum = student[j]->chinese + student[j]->math + student[j]->english;
    }

    sort(student.begin(), student.end(), [](const shared_ptr<stu> &lhs, const shared_ptr<stu> &rhs) {
        if (lhs->sum > rhs->sum) {
            return true;
        } else if (lhs->sum == rhs->sum && lhs->chinese > rhs->chinese) {
            return true;
        } else if (lhs->sum == rhs->sum && lhs->chinese == rhs->chinese && lhs->id < rhs->id) {
            return true;
        }
        return false;
    });
    for (int j = 0; j != 5; ++j) {
        std::cout << student[j]->id << " " << student[j]->sum << std::endl;
    }
    return 0;

}