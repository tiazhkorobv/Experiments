#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Max voters and candidates
#define MAX_VOTERS 100
#define MAX_CANDIDATES 9

// preferences[i][j] is jth preference for voter i
int preferences[MAX_VOTERS][MAX_CANDIDATES];

// Candidates have name, vote count, eliminated status
typedef struct
{
    string name;
    int votes;
    bool eliminated;
}
candidate;

// Array of candidates
candidate candidates[MAX_CANDIDATES];

// Numbers of voters and candidates
int voter_count;
int candidate_count;

// Function prototypes
bool vote(int voter, int rank, string name);
void tabulate(void);
bool print_winner(void);
int find_min(void);
bool is_tie(int min);
void eliminate(int min);

int main(int argc, string argv[])
{
    // Check for invalid usage
    if (argc < 2)
    {
        printf("Usage: runoff [candidate ...]\n");
        return 1;
    }

    // Populate array of candidates
    candidate_count = argc - 1;
    if (candidate_count > MAX_CANDIDATES)
    {
        printf("Maximum number of candidates is %i\n", MAX_CANDIDATES);
        return 2;
    }
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].name = argv[i + 1];
        candidates[i].votes = 0;
        candidates[i].eliminated = false;
    }

    voter_count = get_int("Number of voters: ");
    if (voter_count > MAX_VOTERS)
    {
        printf("Maximum number of voters is %i\n", MAX_VOTERS);
        return 3;
    }

    // Keep querying for votes
    for (int i = 0; i < voter_count; i++)
    {
        // Query for each rank
        for (int j = 0; j < candidate_count; j++)
        {
            string name = get_string("Rank %i: ", j + 1);

            // Record vote, unless it's invalid
            if (!vote(i, j, name))
            {
                printf("Invalid vote.\n");
                return 4;
            }
        }

        printf("\n");
    }

    // Keep holding runoffs until winner exists
    while (true)
    {
        // Calculate votes given remaining candidates
        tabulate();

        // Check if election has been won
        bool won = print_winner();
        if (won)
        {
            break; // winner has arisen - stop iteration!
        }

        // Eliminate last-place candidates
        int min = find_min(); //service function. it need for next steps
        bool tie = is_tie(min);

        // If tie, everyone wins
        if (tie)
        {
            for (int i = 0; i < candidate_count; i++)
            {
                if (!candidates[i].eliminated)
                {
                    printf("%s\n", candidates[i].name);
                }
            }
            break;
        }

        // Eliminate anyone with minimum number of votes
        eliminate(min);

        // Reset vote counts back to zero
        for (int i = 0; i < candidate_count; i++)
        {
            candidates[i].votes = 0;
        }
    }
    return 0;
}

// Record preference if vote is valid
bool vote(int voter, int rank, string name)
{
    for (int i = 0; i < candidate_count; i++) // Iterate over the candidates and find the one with the given name
    {
        if (strcmp(candidates[i].name, name) == 0)// If the candidate (i.e. his index - i) is found,
        {
            preferences[voter][rank] = i;
            return true;// return true and candidate (i.e. his index - i). So to say making matrix tt'll be common for all
        }
    }
    return false;// return false if no such candidate
}

// Tabulate votes for non-eliminated candidates
void tabulate(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        candidates[i].votes = 0;// Initialize the vote counts to zero
    }

    // Iterate over the voters' preferences and add their votes to the candidates' vote counts
    for (int i = 0; i < voter_count; i++)
    {
        for (int j = 0; j < candidate_count; j++)
        {
            int candidate_index = preferences[i][j];// initialize candidate for putting into matrix
            if (!candidates[candidate_index].eliminated)// if candidate is still in process
            {
                candidates[candidate_index].votes++;// than count votes for him
                break; //... in this iteration
            }
        }
    }
    return;
}

// Print the winner of the election, if there is one
bool print_winner(void)
{
    for (int i = 0; i < candidate_count; i++)
    {
        if (candidates[i].votes > voter_count / 2)//If candidate has more than half of votes,
        {
            printf("%s\n", candidates[i].name);
            return true;
        }
    }
    return false;
}

// Return the minimum number of votes any remaining candidate has
int find_min(void)
{
    int min = voter_count + 1;
    for (int i = 0; i < candidate_count; i++)
    {
        if (!candidates[i].eliminated
            && candidates[i].votes <= min)//loop to find who is both still in the election and has the fewest number of votes
        {
            min = candidates[i].votes;//
        }
    }
    return min;
}

// Return true if the election is tied between all candidates, false otherwise
bool is_tie(int min)
{
    int eliminated = 0;
    int tie = 0;

    for (int i = 0; i < candidate_count; i++)// Count number of candidates with min_votes
    {
        if (candidates[i].votes == min)
        {
            tie = tie + 1; // count if tie
        }
        if (candidates[i].eliminated)
        {
            eliminated = eliminated + 1; //count losers
        }
    }

    // If number of tied candidates equals number of candidates remaining (w/o losers0), it's a tie
    if (tie == candidate_count - eliminated)
    {
        return true;
    }
    else
    {
        return false;
    }
}

// Eliminate the candidate (or candidates) in last place
void eliminate(int min)
{
    for (int i = 0; i < candidate_count; i++)// Eliminate those who has minimum votes n didn't elim. yet
    {
        if (candidates[i].votes == min && candidates[i].eliminated == false)
        {
            candidates[i].eliminated = true;
        }
    }
    return;
}