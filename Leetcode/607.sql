# Write your MySQL query statement below
select S.name
from SalesPerson as S
where 
	s.sales_id not in (
		select O.sales_id
		from Orders as O
		left join Company as C on O.com_id = C.com_id
		where C.name = 'RED')