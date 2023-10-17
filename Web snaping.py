import requests
from bs4 import BeautifulSoup

# URL of the website you want to scrape
url = 'https://example.com'

# Send an HTTP GET request to the URL
response = requests.get(url)

# Check if the request was successful
if response.status_code == 200:
    # Parse the HTML content of the page
    soup = BeautifulSoup(response.text, 'html.parser')

    # Example: Extract and print the title of the webpage
    title = soup.title.string
    print("Title:", title)

    # Example: Find and print all links on the webpage
    links = soup.find_all('a')
    print("Links:")
    for link in links:
        print(link.get('href'))
else:
    print("Failed to retrieve the webpage. Status code:", response.status_code)
