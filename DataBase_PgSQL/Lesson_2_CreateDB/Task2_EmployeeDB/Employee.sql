CREATE TABLE Employee (
  id serial PRIMARY KEY,
  name VARCHAR(255) NOT NULL,
  department VARCHAR(255),
  manager_id INT,
  FOREIGN KEY (manager_id) REFERENCES Employee(id)
);