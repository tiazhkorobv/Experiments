-- In 8.sql, write a SQL query to list the names of all people who starred in Toy Story.
-- Your query should output a table with a single column for the name of each person.
-- You may assume that there is only one movie in the database with the title Toy Story.


SELECT name
FROM people
JOIN stars ON person_id = people.id
JOIN movies ON movie_id = movies.id
WHERE title = 'Toy Story';

--!!! if encounter same id it necessary point them aditionaly their mother table with (.)















