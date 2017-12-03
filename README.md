##Frequency Analyzer
This program exists to determine how often each letter in the English alphabet occurs. It is capable of analyzing custom data sets supplied as file names in the arguments to the program. Usage is as follows:

`usage: ./frequencyanalyzer <file1> [file2 [file3]...]`

The program will read every character from each file and maintain a count of the ones that are English letters, without discriminating between upper and lower case characters. Once finished, it will produce a result in tabular format displaying the letter, the number of occurrences, and the percentage of the text that is that character.

This result is also saved in a file named `frequencydata`, and will have the following form:

`etaonihsrdlumcwfygpbvkjxqz`

This file is created so that the `frequencycrack` program can operate.

##Frequency-based Cracker
This portion of the project is functional, but ineffective because of the nature of frequency analysis. It works by analyzing and sorting an enciphered text file, mapping its most popular characters to the reference set generated with `frequencyanalyzer`, and replacing each one. The results are sporadic at best and this code should not be relied on for any serious cipher breaking. At this stage, it is merely a reference implementation illustrating how frequency analysis works. It could be improved in the following ways

* analyze not only characters, but digraphs and trigraphs.
* use a spell checking library like the one provided by aspell to correct small errors
* report on how effective the analysis was using statistical means

The usage for this program is as follows:

`usage: ./frequencycrack datafile textfile`

Where `datafile` is the file that `frequencyanalyze` created and `textfile` is the enciphered text to crack.
