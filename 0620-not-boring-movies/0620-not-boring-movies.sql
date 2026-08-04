# Write your MySQL query statement below
select *
FROM Cinema
Where id % 2 = 1
AND description <> 'boring' 
order by rating desc;