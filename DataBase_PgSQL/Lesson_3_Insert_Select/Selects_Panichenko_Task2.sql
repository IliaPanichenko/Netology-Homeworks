SELECT track_name,track_duration
FROM tracks
WHERE track_duration = (SELECT MAX(track_duration) FROM tracks);

SELECT track_name
FROM tracks
WHERE track_duration >= '00:03:30';

SELECT collection_name, year_release_collection
FROM collections
WHERE year_release_collection >= '2018'
AND year_release_collection <= '2020';

SELECT artist_name
FROM musicians
WHERE artist_name NOT LIKE '% %';

SELECT track_name
FROM tracks
WHERE track_name LIKE '%my%'
OR track_name LIKE '%мой%';

