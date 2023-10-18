class Project:
    def __init__(self, name, description, technologies):
        self.name = name
        self.description = description
        self.technologies = technologies

class Portfolio:
    def __init__(self):
        self.projects = []

    def add_project(self, project):
        self.projects.append(project)

    def display_portfolio(self):
        print("Portfolio:")
        for project in self.projects:
            print("Project Name:", project.name)
            print("Description:", project.description)
            print("Technologies:", ', '.join(project.technologies))
            print()

# Create some projects
project1 = Project("Project 1", "A web application for tracking tasks", ["Python", "Django", "HTML", "CSS"])
project2 = Project("Project 2", "Mobile app for managing finances", ["React Native", "JavaScript"])
project3 = Project("Project 3", "Data analysis tool for sales data", ["Python", "Pandas", "Matplotlib"])

# Create a portfolio and add projects
my_portfolio = Portfolio()
my_portfolio.add_project(project1)
my_portfolio.add_project(project2)
my_portfolio.add_project(project3)

# Display the portfolio
my_portfolio.display_portfolio()
