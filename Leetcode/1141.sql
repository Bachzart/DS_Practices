# Write your MySQL query statement below
# method 1
select distinct activity_date as day, count(distinct user_id) as active_users
from (
      select *
      from Activity as act
      where datediff(act.activity_date, '2019-07-27')>-30
      ) as t1
group by activity_date

# method 2
select activity_date as day, count(distinct user_id) as active_users
from Activity
where datediff('2019-07-27', Activity.activity_date) < 30
group by activity_date