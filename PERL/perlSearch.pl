#!/usr/bin/perl
use strict;

print "Enter a file for input: ";
my $perlInput = <STDIN>;
chomp $perlInput; 

print "Enter a string to search: ";
my $stringSearch = <STDIN>;
chomp $stringSearch;

open(my $searchFile, '<', $perlInput)
	or die "Error: Unable to open input file. $!"; 

while (<$searchFile>)
{
    while (/$stringSearch/g)
    {
        print "$.: $stringSearch\n";
    }
}

close $searchFile;
