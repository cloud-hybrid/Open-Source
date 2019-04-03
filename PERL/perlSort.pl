#!/usr/bin/perl
use strict;
use warnings;

print "Enter a Perl, parent-sort filename: ";
my $perlInputFile = <STDIN>;
chomp $perlInputFile;
print "$perlInputFile\n"; 

print "Enter a Perl, child-sort filename: ";
my $perlOutputFile = <STDIN>; 
chomp $perlOutputFile; 
print "$perlOutputFile\n";

open(perlRead, '<', $perlInputFile)
	or die "Error: Unable to open input file. $!"; 
my @perlInput = <perlRead>;

open(perlWrite, '>', $perlOutputFile)
	or die "Error: Unable to open output file. $!";
my @perlOutput = <perlWrite>;

@perlOutput = sort @perlInput; 

print perlWrite @perlOutput;

close(perlRead);
close(perlWrite); 
