SELECT s.city
FROM STATION AS s
WHERE LOWER(SUBSTR(s.city FROM 1 FOR 1)) IN ('a', 'e', 'i', 'o', 'u');

-- OR

SELECT s.city
FROM STATION AS s
WHERE s.city RLIKE '^[aeiou]';
