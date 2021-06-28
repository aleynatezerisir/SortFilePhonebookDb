# SortFilePhonebookDb
In this programming project, it simulate a sorted file that contains a “phone book” database
with the schema:

 LName: Last name of the contact (String),
FName: First name of the contact (String),
PhoneNo: Phone number (String of numeric characters that optionally begin with ‘+’)
Records stored in ASCII (i.e., not binary). Fields of a record will be separated with
comma and records will be terminated with a new line character.
Sample record: “Doe,John,+903224550000\n”
Every page of the simulated sorted file corresponds to an ASCII file of up to 5 records. The
first page of the simulated sorted file will be named “phone1.txt”. 
 it started with an empty page. As records are inserted, new files representing additional
pages will be named incrementally as “phone2.txt”, “phone3.txt” etc.
 All files representing such pages reside at the same directory. 
 The records in the simulated file sorted on <LName, FName>. 
 The file kept compact – when a record is deleted, all records below the deleted one will
move up. When a record is to be inserted, all records beyond the insertion point move
down to make space.
1. Full file scan – reads all page contents and displays the records in sorted order.
2. Search – a record lookup on <LName, FName>.
3. Insert single contact.
4. Delete single contact given <LName, FName>.
5. Bulk load the simulated sorted file from an existing file of contacts.
