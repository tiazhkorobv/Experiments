
--In 13.sql, write a SQL query to list the names of all people who starred in a movie in which Kevin Bacon also starred.
-- Your query should output a table with a single column for the name of each person.
-- There may be multiple people named Kevin Bacon in the database. Be sure to only select the Kevin Bacon born in 1958.
-- Kevin Bacon himself should not be included in the resulting list. should output a table with a single column for the title of each movie.

SELECT DISTINCT p.name
FROM people p
JOIN stars s1 ON s1.person_id = p.id
JOIN movies m1 ON m1.id = s1.movie_id
JOIN stars s2 ON s2.movie_id = m1.id
JOIN people kb ON kb.name = 'Kevin Bacon' AND kb.birth = 1958
WHERE s2.person_id = kb.id AND p.name != 'Kevin Bacon';

-- The SELECT statement selects the distinct name column from the people table.
-- The FROM clause specifies that the data should be retrieved from the movies table.
-- The JOIN clause is used to join the movies table to the stars table twice, using the s1 and s2 aliases.
-- The first join links the movies table to the stars table on the id column of the movies table and the movie_id column of the stars table, for the movie that Kevin Bacon starred in.
-- The second join links the movies table to the stars table on the id column of the movies table and the movie_id column of the stars table, for the movie that the other actor starred in.
-- The JOIN clause is used to join the people table twice, using the p and kb aliases.
-- The first join links the stars table to the people table on the person_id column of the stars table and the id column of the people table, for the other actor.
-- The second join links the stars table to the people table on the person_id column of the stars table and the id column of the people table, for Kevin Bacon.
-- The WHERE clause filters the results to only include actors who are not Kevin Bacon himself and who did not star in the same movie as Kevin Bacon.
-- The != operator is used to exclude Kevin Bacon himself from the results.
-- The ALL keyword is used with a subquery to exclude movies where Kevin Bacon also starred, by comparing the movie_id column of the stars table to the id column of the movies table.

-- SELECT COUNT(DISTINCT p.name)
-- FROM people p
-- JOIN stars s1 ON s1.person_id = p.id
-- JOIN movies m1 ON m1.id = s1.movie_id
-- JOIN stars s2 ON s2.movie_id = m1.id
-- JOIN people kb ON kb.name = 'Kevin Bacon' AND kb.birth = 1958
-- WHERE s2.person_id = kb.id AND p.name != 'Kevin Bacon';