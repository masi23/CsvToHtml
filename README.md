# CSV to HTML Table Converter

This project is a **C++ console application** that reads data from a CSV file, processes it, and generates an HTML file with a table displaying the data. It also allows the user to input or modify values directly within the HTML table using text input fields.

## Features

- Reads CSV data and splits it into rows and columns.
- Ignores commas that are part of the data (e.g., within quoted fields).
- Generates an HTML file with a styled table.
- Includes editable text fields for each cell in the generated table.

## Example

The program reads from a CSV file like the one below:

## CSV Format Requirements
- Each row should contain data separated by commas (,).
- Commas dividing data such as names or descriptions should be followed with space/white character.
- Your CSV file can contain (") characters, but please try to not use special characters in order to avoid unexpected behavior

  Example of valid CSV format (data generated randomly) :
  1,dE014d010c7ab0c,Andrew,Goodman,Stewart-Flynn,Rowlandberg,Macao,846-790-4623x4715,(422)787-2331x71127,marieyates@gomez-spencer.info,2021-07-26,http://www.shea.biz/

## License
This project is licensed under the MIT License - see the LICENSE file for details.
