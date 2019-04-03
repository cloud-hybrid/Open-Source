#!/bin/bash

title="Program Title" 
prompt="Enter a selection:"
options=("Shell: Alphabetical Sort" "Perl: Alphabetical Sort" "Perl: Dictionary Search" "Shell: File-Directory Search" "Perl: Read Total Lines in File" "Exit()")

echo "$title"
PS3="$prompt"
select selection in "${options[@]}"
do
    case $selection in
        "Shell: Alphabetical Sort")
			echo "Enter the parent-sort filename: "
			read inputFile
			echo "Enter a file to save the parent-sort to: "
			read outputFile
			sort $inputFile > $outputFile
            ;;
        "Perl: Alphabetical Sort")
            /home/jsanders4129/perlSort.pl
            ;;
        "Perl: Dictionary Search")
            /home/jsanders4129/perlSearch.pl
            ;;
		"Shell: File-Directory Search")
            echo "Enter the filename in the working directory: "
            read fileDirectory
            dirname $fileDirectory
            ;;
        "Perl: Read Total Lines in File")
            /home/jsanders4129/perlTotalLines.pl
            ;;
        "Exit()")
            break
            ;;
        *) echo invalid option;;
    esac
done
