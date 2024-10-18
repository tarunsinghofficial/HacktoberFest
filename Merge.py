# Python program to perform mail merger

# open names.txt for reading
with open("names.txt", 'r', encoding='utf-8') as names_file:
    
    # open body.txt for reading
    with open("body.txt", 'r', encoding='utf-8') as body_file:
        
        # read the entire content of the body
        body = body_file.read()
        
        # iterate over names
        for name in names_file:
            # Strip the name of extra whitespace
            name = name.strip()
            
            # Skip empty lines in names.txt
            if not name:
                continue
            
            # Create the email body
            mail = f"Hello {name}\n{body}"
            
            # Generate a valid filename (replace spaces or special characters if needed)
            filename = f"{name.replace(' ', '_')}.txt"
            
            # write the mails to individual files
            with open(filename, 'w', encoding='utf-8') as mail_file:
                mail_file.write(mail)
