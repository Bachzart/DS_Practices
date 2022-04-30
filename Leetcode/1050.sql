# Write your MySQL query statement below
# method 1
select actor_id, director_id
from (
	select actor_id, director_id, count(director_id) as cnt
	from ActorDirector as ad
	group by actor_id, director_id
) as t
where t.cnt > 2

# method 2
select actor_id, director_id
from ActorDirector as ad
group by actor_id, director_id
having count(director_id) > 2