# Write your MySQL query statement below
# method 1
select customer_id, count(customer_id) as count_no_trans
from Visits
where Visits.visit_id not in (select visit_id from Transactions)
group by customer_id

# method 2
select customer_id, count(customer_id) as count_no_trans
from Visits left join Transactions
on Visits.visit_id = Transactions.visit_id
where amount is null
group by customer_id