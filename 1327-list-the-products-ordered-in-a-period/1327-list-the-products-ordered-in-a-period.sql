# Write your MySQL query statement below
SELECT  p.product_name,
        SUM(o.unit) as unit
FROM Products p
JOIN Orders o
ON p.product_id = o.product_id
WHERE DATE_FORMAT(o.order_date, '%M %Y') = 'February 2020'
GROUP BY p.product_id
HAVING unit >= 100