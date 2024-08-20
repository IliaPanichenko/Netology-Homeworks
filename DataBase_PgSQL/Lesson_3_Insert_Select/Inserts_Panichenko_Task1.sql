INSERT INTO musicians (id, artist_name) VALUES
(1, 'Queen'),
(2, 'The Beatles'),
(3, 'Pink Floyd'),
(4, 'Metallica');

INSERT INTO musical_genres (id, genre_name) VALUES
(1, 'Rock'),
(2, 'Pop'),
(3, 'Metal');

INSERT INTO albums (id, album_name, year_release) VALUES
(1, 'Bohemian Rhapsody', 1975),
(2, 'Abbey Road', 1969),
(3, 'Dark Side of the Moon', 2019);

INSERT INTO tracks (id, track_name, album_id, track_duration) VALUES
(1, 'Bohemian Rhapsody', 1, '00:06:00'),
(2, 'Another One Bites the Dust', 1, '00:04:00'),
(3, 'Come Together', 2, '00:04:00'),
(4, 'Here Comes the Sun', 2, '00:03:00'),
(5, 'Time мой', 3, '00:07:00'),
(6, 'Money my', 3, '00:06:00');

INSERT INTO collections (id, collection_name, year_release_collection) VALUES
(1, 'Greatest Hits', 1981),
(2, 'The Very Best of',	2000),
(3, 'Legends of Rock', 2005),
(4, 'Classic Rock Anthems',	2018),
(5, 'New Compilation', 2020);

INSERT INTO musicians_to_genres (musiciant_id, genre_id) VALUES
(1, 1), 
(2, 1), 
(3, 1),  
(4, 3); 

INSERT INTO musicians_to_albums (musiciant_id, album_id) VALUES
(1, 1),  
(2, 2),  
(3, 3); 

INSERT INTO tracks_to_collections (track_id, collection_id) VALUES
(1, 1),  
(1, 3),  
(2, 4),  
(2, 5),  
(3, 1),  
(3, 2),  
(4, 3),  
(4, 5); 