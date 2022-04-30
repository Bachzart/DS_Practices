# Write your MySQL query statement below
# method 1
select Email
from Person
where not in (
	select distinct Email
	from Person
)

# method 2
select email as Email
from Person
group by Email
having count(email) > 1