# Write your MySQL query statement below
select stock_name, sum(if(operation = 'Sell', price, 0)) - sum(if(operation = 'Buy', price, 0)) as capital_gain_loss
from Stocks
group by stock_name

select stock_name, sum(case operation when 'Sell' then price else -price end) as capital_gain_loss
from Stocks
group by stock_name