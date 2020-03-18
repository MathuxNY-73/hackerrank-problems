


-- OR

SELECT s.city, CHAR_LENGTH(s.city)
FROM STATION AS s
ORDER BY CHAR_LENGTH(s.city), s.city
LIMIT 1;

SELECT s.city, CHAR_LENGTH(s.city)
FROM STATION AS s
ORDER BY CHAR_LENGTH(s.city) DESC, s.city ASC
LIMIT 1;

-- OR

SELECT cl.name, cl.length
FROM (
    SELECT s.city AS name, CHAR_LENGTH(s.city) AS length
    FROM STATION AS s
    ORDER BY s.city
) AS cl
WHERE cl.length=(SELECT MIN(CHAR_LENGTH(s.city)) FROM STATION AS s)
LIMIT 1;

SELECT cl.name, cl.length
FROM (
    SELECT s.city AS name, CHAR_LENGTH(s.city) AS length
    FROM STATION AS s
    ORDER BY s.city
) AS cl
WHERE cl.length=(SELECT MAX(CHAR_LENGTH(s.city)) FROM STATION AS s)
LIMIT 1;
