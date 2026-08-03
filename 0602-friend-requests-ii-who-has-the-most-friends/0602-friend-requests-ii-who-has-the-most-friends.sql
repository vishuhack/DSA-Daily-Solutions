# Write your MySQL query statement below
SELECT t.num as id, 
        COUNT(num) as num
FROM (
    SELECT requester_id as num
    FROM RequestAccepted

    UNION ALL

    SELECT accepter_id  
    FROM RequestAccepted 
) t
GROUP BY id
ORDER BY num DESC
LIMIT 1