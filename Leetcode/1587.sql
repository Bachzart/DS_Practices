# Write your MySQL query statement below
select name as NAME, balance as BALANCE
from (
	select name, balance
	from Users as u
	left join (
		select account, sum(amount) as balance
		from Transactions
		group by account
	) as t
	on t.balance > 10000 and t.account = u.account
) as a
where balance is not null


select name, balance
from Users as u
left join (
	select account, sum(amount) as balance
	from Transactions
	group by account
) as t
on t.account = u.account
where balance > 10000