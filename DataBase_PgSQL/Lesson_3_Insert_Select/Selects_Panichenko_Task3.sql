SELECT mg.genre_id, COUNT(m.id) AS count_musicians
FROM musicians_to_genres mg
INNER JOIN musicians m ON mg.musiciant_id = m.id
GROUP BY mg.genre_id;

SELECT COUNT(*) AS count_tracks
FROM tracks t
INNER JOIN albums a ON t.album_id = a.id
WHERE a.year_release >= 2019
AND a.year_release <= 2020;

SELECT a.album_name, AVG(t.track_duration) AS average_duration
FROM tracks t
INNER JOIN albums a ON t.album_id = a.id
GROUP BY a.album_name;

SELECT m.artist_name
FROM musicians m
LEFT JOIN musicians_to_albums ma ON m.id = ma.musiciant_id
LEFT JOIN albums a ON ma.album_id = a.id
WHERE a.year_release IS NULL OR a.year_release <> 2020;

SELECT c.collection_name
FROM collections c
INNER JOIN tracks_to_collections ttc ON c.id = ttc.collection_id
INNER JOIN tracks t ON ttc.track_id = t.id
INNER JOIN albums a ON t.album_id = a.id
INNER JOIN musicians_to_albums ma ON a.id = ma.album_id
INNER JOIN musicians m ON ma.musiciant_id = m.id
WHERE m.artist_name = 'The Beatles';