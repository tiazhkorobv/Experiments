CREATE TABLE students (
    id INTEGER,
    student_name TEXT,
    house TEXT,
    head TEXT,
    PRIMARY KEY(id)
);

-- NO!    UPDATE students SET house = FOREIGN KEY;

CREATE TABLE house (
    id INTEGER,
    name TEXT NOT NULL,
    location TEXT NOT NULL,
    PRIMARY KEY(id)
);

ALTER TABLE students
ADD CONSTRAINT fk_house
FOREIGN KEY (house_id)
REFERENCES house(id);