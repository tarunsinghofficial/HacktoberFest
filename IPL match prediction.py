import random

# Sample historical data (in reality, this data would be more comprehensive)
historical_data = [
    {"team1": "CSK", "team2": "MI", "winner": "MI"},
    {"team1": "KKR", "team2": "RCB", "winner": "KKR"},
    {"team1": "SRH", "team2": "KXIP", "winner": "SRH"},
    # Add more historical match data here
]

def predict_match_winner(team1, team2):
    # In this simplified example, we randomly choose a winner
    winner = random.choice([team1, team2])
    return winner

if __name__ == "__main__":
    # Enter the team names for the upcoming match
    team1 = "CSK"
    team2 = "RCB"

    winner = predict_match_winner(team1, team2)
    print(f"In the upcoming IPL match between {team1} and {team2}, the predicted winner is: {winner}")
