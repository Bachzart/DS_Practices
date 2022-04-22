# Please write a DELETE statement and DO NOT write a SELECT statement.
# Write your MySQL query statement below
# method 1
delete p1.*
from Person p1, Person p2
where p1.Email = p2.Email and p1.id > p2.id

# method 2
delete from Person
where id not in (select dt.id from (select min(id) as id from Person group by email) dt)