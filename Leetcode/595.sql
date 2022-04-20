# Write your MySQL query statement below
# method 1
select name, area, population from World where area >= 3000000 or population >= 25000000

# method 2
select name, area, population from World where area >= 3000000 
union 
select name, area, population from World where population >= 25000000