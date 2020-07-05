# TextMatching
Match a text file against a repository of text files, sorting by similarity.

Here is a program for finding the most similar file (to a sample file) in a repository of candidate files. 

Below is the output for sample "FAIRY TALES By The Brothers Grimm" against a repository of 10 other books.
```
0.0320757 Repo\THE ADVENTURES OF TOM SAWYER.txt
0.0363329 Repo\A TALE OF TWO CITIES - A STORY OF THE FRENCH REVOLUTION.txt
0.0388528 Repo\ALICEТS ADVENTURES IN WONDERLAND.txt
0.0440605 Repo\MOBY-DICK or, THE WHALE.txt
0.046679 Repo\THE ADVENTURES OF SHERLOCK HOLMES.txt
0.0472574 Repo\The Iliad of Homer.txt
0.0511793 Repo\The Romance of Lust.txt
0.053746 Repo\PRIDE AND PREJUDICE.txt
0.0543531 Repo\BEOWULF - AN ANGLO-SAXON EPIC POEM.txt
0.0557194 Repo\Frankenstein; or, the Modern Prometheus.txt
```

Here the whole repository is listed, starting from most similar texts down to least similar. As you can see, fairy-tales come first and a horror book comes last.

Commercially this can be used for matching the current page a user is viewing against a repository of advertisement pages, so to find the most relevant advertisement.

Another application is for matching the job description or a resume of a relevant but unwilling to join candidate, against a repository of resumes so to find a similar candidate.

# Usage
```MatchText.exe <Sample File> <Repository Directory>```
