# Write your MySQL query statement below
select employee_id, 
if(employee_id % 2 = 0 or name like 'M%', 0, salary) as bonus
from Employees