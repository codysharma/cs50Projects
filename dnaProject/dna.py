import csv
import sys

def main():

    # TODO: Check for command-line usage
    if len(sys.argv) != 3:
        sys.exit("Error: number of arguments")

    # TODO: Read database file into a variable
    database = {}
    if sys.argv[1] == "databases/small.csv":
        with open(sys.argv[1]) as f:
            reader1 = csv.DictReader(f)
            for row in reader1:
                #print(f"{row['AGATC']}")
                database[int(row['AGATC']), int(row['AATG']), int(row['TATC'])] = row['name']
    if sys.argv[1] == "databases/large.csv":
        with open(sys.argv[1]) as f:
            reader1 = csv.DictReader(f)
            for row in reader1:
                database[int(row['AGATC']), int(row['TTTTTTCT']), int(row['AATG']), int(row['TCTAG']), int(row['GATA']), int(row['TATC']), int(row['GAAA']), int(row['TCTG'])] = row['name']
    #print(f"{database}")

    # TODO: Read DNA sequence file into a variable. done.
    from pathlib import Path
    sequence = Path(sys.argv[2]).read_text()

    # TODO: Find longest match of each STR in DNA sequence. Done for "small". Easy scale up for "large".
    results = []

    if sys.argv[1] == "databases/small.csv":
        subsequence = "AGATC"
        AGATC = longest_match(sequence, subsequence)
        subsequence = "AATG"
        AATG = longest_match(sequence, subsequence)
        subsequence = "TATC"
        TATC = longest_match(sequence, subsequence)

        results.extend((AGATC, AATG, TATC))

    if sys.argv[1] == "databases/large.csv":
        subsequence = "AGATC"
        AGATC = longest_match(sequence, subsequence)
        subsequence = "TTTTTTCT"
        TTTTTTCT = longest_match(sequence, subsequence)
        subsequence = "AATG"
        AATG = longest_match(sequence, subsequence)
        subsequence = "TCTAG"
        TCTAG = longest_match(sequence, subsequence)
        subsequence = "GATA"
        GATA = longest_match(sequence, subsequence)
        subsequence = "TATC"
        TATC = longest_match(sequence, subsequence)
        subsequence = "GAAA"
        GAAA = longest_match(sequence, subsequence)
        subsequence = "TCTG"
        TCTG = longest_match(sequence, subsequence)

        results.extend((AGATC, TTTTTTCT, AATG, TCTAG, GATA, TATC, GAAA, TCTG))

    #print(results)

    # TODO: Check database for matching profiles
    success = 0
    for x in database.keys():
        for i in range(len(results)):
            if x[i] != results[i]:
                break
            if i == len(results) - 1:
                success = 1
                print(database[x])
    if success == 0:
        print("No match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()
