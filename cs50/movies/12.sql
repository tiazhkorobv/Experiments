-- In 12.sql, write a SQL query to list the titles of all movies in which both Johnny Depp
--   and Helena Bonham Carter starred.
-- Your query should output a table with a single column for the title of each movie.
-- You may assume that there is only one person in the database with the name Johnny Depp.
-- You may assume that there is only one person in the database with the name Helena Bonham Carter.

-- SELECT title
-- FROM movies
-- JOIN stars ON movies.id = stars.movie_id
-- JOIN people ON people.id = stars.person_id
-- WHERE name = 'Chadwick Boseman' AND 'Helena Bonham Carter';

SELECT title FROM movies
JOIN stars s1 ON movies.id = s1.movie_id AND s1.person_id IN (SELECT id FROM people WHERE name = 'Johnny Depp')
JOIN stars s2 ON movies.id = s2.movie_id AND s2.person_id IN (SELECT id FROM people WHERE name = 'Helena Bonham Carter')
--Each join condition specifies that the movie_id in the stars table matches the id of the movie in the movies table,
--and that the person_id in the stars table matches the id of Johnny Depp or Helena Bonham Carter in the people table.
WHERE s1.movie_id = s2.movie_id;--checking that the movie_id in the stars table for Johnny Depp matches the movie_id in
--the stars table for Helena Bonham Carter.

