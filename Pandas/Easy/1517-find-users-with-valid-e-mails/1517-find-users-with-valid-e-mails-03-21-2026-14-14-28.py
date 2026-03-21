import pandas as pd

def valid_emails(users: pd.DataFrame) -> pd.DataFrame:
    # Define the regex pattern for a valid email
    pattern = r'^[a-zA-Z][a-zA-Z0-9_.-]*@leetcode\.com$'
    
    # Filter the dataframe where the 'mail' column matches the pattern
    valid_users = users[users['mail'].str.match(pattern)]
    
    return valid_users