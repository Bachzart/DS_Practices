# Write your MySQL query statement below
select Weather.id
from Weather
join Weather as w on datediff(Weather.recordDate, w.recordDate) = 1 and Weather.temperature > w.temperature