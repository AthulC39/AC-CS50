-- Keep a log of any SQL queries you execute as you solve the mystery.

SELECT * FROM crime_scene_reports WHERE month=7 AND day=28;
SELECT * FROM interviews WHERE month=7 AND day=28;
SELECT * FROM bakery_security_logs WHERE month=7 AND day=28;
SELECT name FROM people WHERE license_plate=5P2BI95;
SELECT * FROM atm_transactions WHERE month=7 AND day=28 AND atm_location = Leggett Street;
SELECT * FROM bank_accounts WHERE account_number=26013199;
SELECT name FROM people
JOIN bank_accounts ON people.id = bank_accounts.person_id
WHERE person_id = 514354;
SELECT * FROM phone_calls WHERE month=7 AND day=28 AND duration<60;
SELECT name FROM people WHERE phone_number=(130) 555-0289;
SELECT * FROM flights WHERE month=7 AND day=29;
SELECT * FROM passengers WHERE flight_id=36;
SELECT * FROM people WHERE passport_number=8294398571;
SELECT * FROM airports WHERE id=4;
