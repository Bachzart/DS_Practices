# Write your MySQL query statement below
# method 1
select customer_number
from (
	select distinct customer_number, count(order_number) as order_number
	from Orders
	group by customer_number
	order by order_number desc
	) as t1
limit 1

select distinct customer_number
from Orders
group by customer_number
order by count(order_number) desc
limit 1

# method 2
with t1 as (select customer_number, count(order_number) as order_number from Orders group by customer_number)
select customer_number
from t1
where t1.order_number = (select max(order_number) from t1)