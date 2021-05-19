/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
   public:
    unordered_map<int, Employee*> employeesMap;

    void dfs(Employee* employee, int& tot) {
        vector<int> subs = employee->subordinates;
        tot += employee->importance;

        if (subs.size() == 0) return;
        for (int sub : subs) {
            dfs(employeesMap[sub], tot);
        }
    }
    int getImportance(vector<Employee*> employees, int id) {
        for (auto em : employees) {
            employeesMap[em->id] = em;
        }

        Employee* employee = employeesMap[id];
        int tot = 0;
        dfs(employee, tot);

        return tot;
    }
};