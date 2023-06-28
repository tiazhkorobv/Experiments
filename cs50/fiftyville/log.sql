-- Thief stole the duck and then, shortly afterwards, took a flight out of town with the help of an accomplice.
-- Your goal is to identify:
--     Who the thief is,
--     What city the thief escaped to, and
--     Who the thief’s accomplice is who helped them escape
-- All you know is that the theft took place on July 28, 2021 and that it took place on Humphrey Street.
-- Keep a log of any SQL queries you execute as you solve the mystery.

-- Looking for a crime scene report that matches the date and the location of the crime:
SELECT *
FROM  crime_scene_reports
WHERE street = 'Humphrey Street'
AND day = 28;

--Theft took place at 10:15am at the Humphrey Street bakery. Interviews were conducted today with three
--witnesses who were present at the time – each of their interview transcripts mentions the bakery.
SELECT *
FROM  interviews
WHERE year = 2021
AND day = 28
AND month = 7
AND transcript LIKE '%bakery%';

--Sometime within ten minutes of the theft, I saw the thief get into a car in the bakery
--parking lot and drive away. If you have security footage from the bakery parking lot,
--you might want to look for cars that left the parking lot in that time frame.
SELECT p.name, c.license_plate
FROM people p
JOIN bakery_security_logs c ON p.license_plate = c.license_plate
WHERE c.license_plate IN (
  SELECT license_plate
  FROM bakery_security_logs)
AND year = 2021
AND day = 28
AND month = 7
AND hour = 10
AND minute BETWEEN 15 AND 25
AND activity = 'exit';

-- Earlier this morning, before I arrived at Emma's bakery, I was walking
-- by the ATM on Leggett Street and saw the thief there withdrawing some money.
SELECT b.account_number, amount, p.license_plate, p.name, phone_number, passport_number
FROM atm_transactions a
JOIN bank_accounts b ON b.account_number = a.account_number
JOIN bakery_security_logs l ON p.license_plate = l.license_plate
JOIN people p ON p.id = b.person_id
WHERE a.year = 2021
AND a.day = 28
AND a.month = 7
AND l.day = 28
AND l.month = 7
AND l.hour = 10
AND l.minute BETWEEN 15 AND 25
AND activity = 'exit'
AND atm_location = 'Leggett Street'
AND  transaction_type = 'withdraw';

-- As the thief was leaving the bakery, they called someone who talked to them for less than a minute.
-- In the call, I heard the thief say that they were planning to take the earliest flight tomorrow.
-- The thief then asked the person on the other end of the phone to purchase the flight ticket.

--Who run out from bakery and made call, i.e. is thief? - Bruce
SELECT pc.caller, pc.receiver, p.name, p.passport_number
FROM phone_calls pc
JOIN people p ON p.phone_number = pc.caller--receiver
JOIN bakery_security_logs l ON p.license_plate = l.license_plate
WHERE l.year = 2021
AND l.day = 28
AND l.month = 7
AND l.hour = 10
AND l.minute BETWEEN 15 AND 18
AND activity = 'exit'
AND (
    caller LIKE '%555-5533'
    OR caller LIKE '%555-1861'
    OR caller LIKE '%555-5269'
    OR caller LIKE '%555-5198'
)
AND duration < 60;

--Who received call and bought ticket, i.e. was accomplice? -- Robin
SELECT pc.caller, pc.receiver, p.name
FROM phone_calls pc
JOIN people p ON p.phone_number = pc.receiver
WHERE pc.year = 2021
AND pc.day = 28
AND pc.month = 7
AND (
    caller LIKE '%555-5533'
    OR caller LIKE '%555-1861'
    OR caller LIKE '%555-5269'
    OR caller LIKE '%555-5198'
)
AND duration < 60;

--Destination airport: New York City
SELECT city
FROM airports a
JOIN flights f ON f.destination_airport_id = a.id
JOIN passengers p ON p.flight_id = f.id
WHERE p.passport_number = 5773159633
;