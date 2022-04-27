# Write your MySQL query statement below
select distinct event_day as day, emp_id, sum(diff) as total_time
from (
	select event_day, emp_id, (out_time - in_time) as diff
	from Employees
	) as t1
group by event_day, emp_id