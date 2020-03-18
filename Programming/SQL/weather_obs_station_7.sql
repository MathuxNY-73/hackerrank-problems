SELECT DISTINCT s.city
FROM STATION AS s
WHERE LOWER(RIGHT(s.city, 1)) IN ('a', 'e', 'i', 'o', 'u');
