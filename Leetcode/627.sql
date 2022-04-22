# Write your MySQL query statement below
# method 1
update Salary set sex = if(sex = 'm', 'f', 'm')

# method 2
update Salary
set
	sex = CASE sex
		WHEN 'm' THEN 'f'
		ELSE 'm'
	END;