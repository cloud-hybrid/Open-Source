#!/usr/bin/perl
use strict;
use warnings;

print "Enter a Perl, parent-sort filename: ";
my $perlInputFile = <STDIN>;
chomp $perlInputFile;
print "$perlInputFile\n"; 

open(perlRead, '<', $perlInputFile)
	or die "Error: Unable to open input file. $!"; 
	
my @perlInputFile = <perlRead>;

for(<perlRead>){}
print "perlParentRead contains $. lines\n"; 
