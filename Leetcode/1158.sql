# Write your MySQL query statement below
select u.user_id as buyer_id, join_date, ifnull(t1.cnt, 0) as orders_in_2019
from Users as u
left join (
	select buyer_id, count(order_id) as cnt
	from Orders as o
	where o.order_date >= '2019-01-01' and o.order_date <= "2019-12-31"
	group by buyer_id
) as t1
on u.user_id = t1.buyer_id