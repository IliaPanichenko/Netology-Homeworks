CREATE TABLE IF NOT EXISTS musical_genres (id serial PRIMARY KEY, genre_name VARCHAR(255) NOT NULL);
CREATE TABLE IF NOT EXISTS musicians (id serial PRIMARY KEY, artist_name VARCHAR(255) NOT NULL);
CREATE TABLE IF NOT EXISTS musicians_to_genres (musiciant_id integer NOT NULL, genre_id integer NOT NULL, FOREIGN KEY(musiciant_id) REFERENCES musicians(id), FOREIGN KEY (genre_id) REFERENCES musical_genres(id));
CREATE TABLE IF NOT EXISTS albums (id serial PRIMARY KEY NOT NULL, album_name VARCHAR(255) NOT NULL, year_release smallint NOT NULL);
CREATE TABLE IF NOT EXISTS musicians_to_albums (musiciant_id integer NOT NULL, FOREIGN KEY (musiciant_id) REFERENCES musicians(id), album_id integer NOT NULL, FOREIGN KEY (album_id) REFERENCES albums(id));
CREATE TABLE IF NOT EXISTS tracks(id serial PRIMARY KEY NOT NULL, track_name VARCHAR(255) NOT NULL, album_id integer NOT NULL, track_duration time NOT NULL, FOREIGN KEY (album_id) REFERENCES albums(id));
CREATE TABLE IF NOT EXISTS collections (id serial NOT NULL PRIMARY KEY, collection_name VARCHAR(255) NOT NULL, year_release_collection integer NOT NULL);
CREATE TABLE IF NOT EXISTS tracks_to_collections (track_id integer NOT NULL, FOREIGN KEY (track_id) REFERENCES tracks(id), collection_id integer NOT NULL, FOREIGN KEY (collection_id) REFERENCES collections(id));