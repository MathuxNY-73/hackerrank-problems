SELECT DISTINCT s.city
FROM STATION AS s
WHERE UPPER(LEFT(s.city,1)) NOT IN ('A','E','I','O','U')
AND UPPER(RIGHT(s.city,1)) NOT IN ('A','E','I','O','U');
