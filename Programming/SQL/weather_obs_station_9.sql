SELECT DISTINCT s.city
FROM STATION AS s
WHERE UPPER(s.city) NOT RLIKE '^[AEIOU]';
