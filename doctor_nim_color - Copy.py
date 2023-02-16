"""
A script to reproduce the gameplay of Dr. Nim

Dr. Nim is a two-player, deterministic game based on a mathematical game 
called NIM, which starts with 12 tokens.

There is a fixed number of starting tokens, this number is usually a multiple
of four.

Each player takes 1,2 or 3 tokens in turn. When played human versus computer, 
the human player goes first.

The player that takes the last token is the winner.

This was inspired by https://www.youtube.com/watch?v=9KABcmczPdg .

With the values as configured, the computer will always win.
"""

# Pre-load ASCII codes and colours used
RESET = '\033[0m'
RED = '\033[31m'
BLUE = '\033[34m'
YELLOW = '\033[93m'
GREEN = '\033[32m'
CYAN = '\033[36m'

# Define rules
# Use an object that returns True with 1, 2 or 3 using the `in` operator.
valid_moves = range(1,4)

# Start with a fixed number of tokens. Hard-coded here for ease of editing.
n_tokens = 12

# Copy version to check in game loops
start_tokens = n_tokens

# Print information for players.

introduction = \
"""RULES:

    There are two players, you and the computer. You go first and take 
    1, 2 or 3 tokens. The computer then takes its turn with the same rules. 
    The player that withdraws the last token is the winner!
"""
print(CYAN, introduction, RESET)

# Start of Game Loop.
"""
The game continues until all the tokens are taken. Therefore, the game loop 
will run while there are tokens that remain to be taken. Once there are no 
tokens left, the game loop will automatically stop.
"""
while n_tokens > 0:
    # Human player goes first, takes 1-3 tokens
    # Input to be taken, keep repeating until input acceptable
    
    # At the start of each round, print a blank line for clarity
    print()

    # Initialise variable with a value that will force a `while` #loop to always run on the first iteration:
    tokens_taken = 0
    
    # Obtain number of tokens taken by player. This will be validated by 
    # comparison to a range object using the `in` keyword, such that any of 
    # `1`, `2` or `3` evaluate to true and others to false.
    while tokens_taken not in valid_moves:
        tokens_taken = int(
            input(
                f"{RESET}Do you want to take 1, 2 or 3 tokens?:"
                ))

    # Subtract number of tokens from `n_tokens`
    n_tokens -= tokens_taken
    
    # Work out if singular or plural:
    plural = "s" if tokens_taken > 1 else ""

    # Print desciption of move to screen
    print (BLUE,
        f"You have taken {tokens_taken} token{plural}.", end = " "
        )

    # Print remaining tokens on same line if game not over.
    # If game over, announce result by printing to screen
    if n_tokens > 1:
        print (
        f"There are {n_tokens} tokens remaining.", RESET)
    elif n_tokens == 1:
        print ("There is 1 token remaining.", RESET)
    else:
        print(GREEN, "There are no tokens left. Human wins!")
        print()
        print("CONGRATULATIONS You have beaten the computer!", RESET)
        break # End game and break out of game loop if human wins.
        
    # Determine computer move, store in variable `tokens_taken`.
    # If possible, use n_tokens%4 (computer is playing to win)
    # Otherwise, computer takes 1 token.
    tokens_taken = n_tokens % 4 if n_tokens % 4 > 0 else 1

    # Calculate number of remaining tokens by subtracting `tokens_taken` from `n_tokens`
    n_tokens -= tokens_taken
    
    # Work out if singular or plural:
    plural = "s" if tokens_taken > 1 else ""

    # Print desciption of move to screen
    print (YELLOW,
        f"The computer has taken {tokens_taken} token{plural}.", end = " "
        )
    # Print remaining tokens on same line if game not over.
    # If game over, announce result by printing to screen

    if n_tokens > 0:
        print (f"There are {n_tokens} tokens remaining.")
    else:
        print("There are no tokens left. The computer wins!")
        print()
        print(RED, "YOU LOSE. GAME OVER", RESET)
        
    # End of game loop. If there are no tokens left, another iteration 
    # will not occur. If tokens are left, game repeats.
    
print(RESET) # Resets display colour etc...