select e.name as employee from Employee e join Employee m
on e.managerId = m.id where e.salary > m.salary;