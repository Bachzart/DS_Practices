# Write your MySQL query statement below
# method 1
select distinct user_id, max(time_stamp) as last_stamp
from Logins
where time_stamp >= '2020-01-01 00:00:00' and time_stamp < '2021-01-01 00:00:00'
group by user_id

# method 2
select user_id, max(time_stamp) as last_stamp
from Logins
where year(time_stamp) = 2020
group by user_id