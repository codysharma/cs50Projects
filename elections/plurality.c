#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max number of candidates
#define MAX 9

// Candidates have name and vote count
typedef struct
{
    string name;
    int votes;
}
candidate;

// Array of candidates
candidate candidates[MAX];

// Number of candidates
int candidate_count;

// Function prototypes
bool vote(string name);
void print_winner(void);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: plurality [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX)
    {
        printf("Maximum number of candidates is %i\n", MAX);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
    }

    int voter_count = get_int("Number of voters: ");

    // Loop over all voters
    for (int i = 0; i < voter_count; i++)
    {
        string name = get_string("Voter %i: ", i+1);

        // Check for invalid vote
        if (!vote(name))
        {
            printf("Invalid vote.\n");
        }
    }

    // Display winner of election
    print_winner();
}

// Update vote totals given a new vote
bool vote(string name)
{
    // TODO - look for candidate.name matching the input
        for (int i = 0; i < MAX; i++)
        {
                if (strcmp(name, candidates[i].name) == 0)
                {
                candidates[i].votes++;
                    //printf("Current votes: %i\n", candidates[i].votes);
                    //return true;
                }
                else
                {
                    return false;
                }
        }
        return false;
}

// Print the winner (or winners) of the election
void print_winner(void)
{
    // TODO - comapre candidate.votes totals to each other. Then display the highest, or if equal multiple.
    candidate candidates2[candidate_count];

    for (int i = 0; i < candidate_count; i++)//go through each element of array
    {
        for (int j = 0; j < candidate_count; j++)//loop for comparing ind values of .votes
        {
            if(candidates[j].votes < candidates[j+1].votes)//bubble sorted. if second element is larger, should go into loop in order to be switched.
            {
                candidates2[j] = candidates[j];
                candidates[j] = candidates[j+1];
                candidates[j+1] = candidates2[j];
            }
        }
    }
    int numberwinners = 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > candidates[i+1].votes)
        {
            //printf("%s\n", candidates[0].name);
            break;
        }
        else
        {
        numberwinners++;
        }
    }
    for (int i = 0; i < numberwinners; i++)
    {
        if (candidates[i].name != NULL)
        {
            printf("%s\n", candidates[i].name);
        }
    }
}