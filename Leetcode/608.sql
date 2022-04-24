# Write your MySQL query statement below
# method 1
select id, 'Root' as type
from Tree
where p_id is null

union

select id, 'Leaf' as type
from Tree
where id not in (
	select distinct p_id
	from Tree
	where p_id is not null
) and p_id is not null

union

select id, 'Inner' as type
from Tree
where id in (
	select distinct p_id
	from tree
	where p_id is not null
) and p_id is not null

# method 2
select id as 'id',
	case
		when tree.id = (select atree.id from tree atree where atree.p_id is null)
		then 'Root'
		when tree.id in (select atree.p_id from tree atree)
		then 'Inner'
		else 'Leaf'
	end as type
from tree
order by 'id'

# method 3
select atree.id,
	if(isnull(atree.p_id),
		'Root',
		if(atree.id in (select p_id from tree), 'Inner', 'Leaf')) type
from tree atree
order by atree.id